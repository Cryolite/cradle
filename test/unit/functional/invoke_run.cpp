#include <cradle/functional/invoke.hpp>

#include <cradle/utility/as_const.hpp>
#include <cradle/config/config.hpp>
#include <boost/test/unit_test.hpp>
#include <memory>
#include <type_traits>
#include <utility>

BOOST_AUTO_TEST_SUITE(functional)

BOOST_AUTO_TEST_SUITE(invoke)

namespace {

int gi = 0;

struct S
{
  void mf()
  {
    ++gi;
  }

  void cmf() const
  {
    ++gi;
  }

  void ntmf() noexcept
  {
    ++gi;
  }

  void ntcmf() const noexcept
  {
    ++gi;
  }

  int mf0p()
  {
    return gi * 2;
  }

  int &mf0l()
  {
    return gi;
  }

  int const &mf0cl()
  {
    return gi;
  }

  int &&mf0x()
  {
    return std::move(gi);
  }

  void mf1p(int i)
  {
    BOOST_CHECK_EQUAL(i, 42);
  }

  void mf1l(int &i)
  {
    BOOST_CHECK_EQUAL(&i, &gi);
  }

  void mf1cl(int const &i)
  {
    BOOST_CHECK_EQUAL(&i, &gi);
  }

  void mf1x(int &&i)
  {
    BOOST_CHECK_EQUAL(&i, &gi);
  }

#if 0
  void lmf() &
  {}

  void clmf() const &
  {}

  void xmf() &&
  {}
#endif

  int mv;
  int const cmv = 42;
};

}

#define ASSERT_SAME(EXPRESSION, TYPE_ID)                              \
static_assert(std::is_same<decltype(EXPRESSION), TYPE_ID>::value, "") \
/**/

template<typename F, typename... Args,
         typename = decltype(cradle::invoke(std::declval<F>(), std::declval<Args>()...))>
constexpr bool test(int) noexcept
{
  return true;
}

template<typename F, typename... Args>
constexpr bool test(bool) noexcept
{
  return false;
}

template<typename R, typename F, typename... Args,
         typename = decltype(cradle::invoke<R>(std::declval<F>(), std::declval<Args>()...))>
constexpr bool test_explicit(int) noexcept
{
  return true;
}

template<typename R, typename F, typename... Args>
constexpr bool test_explicit(bool) noexcept
{
  return false;
}

BOOST_AUTO_TEST_CASE(nullary_member_function)
{
  S s;

  {
    void (S::*pmf)() = &S::mf;

    ASSERT_SAME(cradle::invoke(pmf, &s), void);
    static_assert(!noexcept(cradle::invoke(pmf, &s)), "");
    gi = 0;
    cradle::invoke(pmf, &s);
    BOOST_CHECK_EQUAL(gi, 1);

    ASSERT_SAME(cradle::invoke(cradle::as_const(pmf), &s), void);
    static_assert(!noexcept(cradle::invoke(cradle::as_const(pmf), &s)), "");
    gi = 0;
    cradle::invoke(cradle::as_const(pmf), &s);
    BOOST_CHECK_EQUAL(gi, 1);
  }

  ASSERT_SAME(cradle::invoke(&S::mf, s), void);
  static_assert(!noexcept(cradle::invoke(&S::mf, s)), "");
  gi = 0;
  cradle::invoke(&S::mf, s);
  BOOST_CHECK_EQUAL(gi, 1);

  static_assert(!test<void (S::*)(), S const &>(0), "");

  ASSERT_SAME(cradle::invoke(&S::mf, std::move(s)), void);
  static_assert(!noexcept(cradle::invoke(&S::mf, std::move(s))), "");
  gi = 0;
  cradle::invoke(&S::mf, std::move(s));
  BOOST_CHECK_EQUAL(gi, 1);

  ASSERT_SAME(cradle::invoke(&S::mf, &s), void);
  static_assert(!noexcept(cradle::invoke(&S::mf, &s)), "");
  gi = 0;
  cradle::invoke(&S::mf, &s);
  BOOST_CHECK_EQUAL(gi, 1);

  static_assert(!test<void (S::*)(), S const *>(0), "");

  {
    std::shared_ptr<S> p = std::make_shared<S>();

    ASSERT_SAME(cradle::invoke(&S::mf, p), void);
    static_assert(!noexcept(cradle::invoke(&S::mf, p)), "");
    gi = 0;
    cradle::invoke(&S::mf, p);
    BOOST_CHECK_EQUAL(gi, 1);
  }

  static_assert(!test<void (S::*)(), std::shared_ptr<S const> &>(0), "");

  ASSERT_SAME(cradle::invoke<void>(&S::mf, s), void);
  static_assert(!noexcept(cradle::invoke<void>(&S::mf, s)), "");
  gi = 0;
  cradle::invoke<void>(&S::mf, std::move(s));
  BOOST_CHECK_EQUAL(gi, 1);

  static_assert(!test_explicit<int &, void (S::*)(), S &>(0), "");

  static_assert(!test_explicit<int const &, void (S::*)(), S &>(0), "");

  static_assert(!test_explicit<int, void (S::*)(), S &>(0), "");

  static_assert(!test_explicit<int &&, void (S::*)(), S &>(0), "");
}

BOOST_AUTO_TEST_CASE(nullary_const_member_function)
{
  S s;

  {
    void (S::*pcmf)() const = &S::cmf;

    ASSERT_SAME(cradle::invoke(pcmf, s), void);
    static_assert(!noexcept(cradle::invoke(pcmf, s)), "");
    gi = 0;
    cradle::invoke(pcmf, s);
    BOOST_CHECK_EQUAL(gi, 1);

    ASSERT_SAME(cradle::invoke(cradle::as_const(pcmf), s), void);
    static_assert(!noexcept(cradle::invoke(cradle::as_const(pcmf), s)), "");
    gi = 0;
    cradle::invoke(cradle::as_const(pcmf), s);
    BOOST_CHECK_EQUAL(gi, 1);
  }

  ASSERT_SAME(cradle::invoke(&S::cmf, s), void);
  static_assert(!noexcept(cradle::invoke(&S::cmf, s)), "");
  gi = 0;
  cradle::invoke(&S::cmf, s);
  BOOST_CHECK_EQUAL(gi, 1);

  ASSERT_SAME(cradle::invoke(&S::cmf, cradle::as_const(s)), void);
  static_assert(!noexcept(cradle::invoke(&S::cmf, cradle::as_const(s))), "");
  gi = 0;
  cradle::invoke(&S::cmf, cradle::as_const(s));
  BOOST_CHECK_EQUAL(gi, 1);

  ASSERT_SAME(cradle::invoke(&S::cmf, std::move(s)), void);
  static_assert(!noexcept(cradle::invoke(&S::cmf, std::move(s))), "");
  gi = 0;
  cradle::invoke(&S::cmf, std::move(s));
  BOOST_CHECK_EQUAL(gi, 1);

  ASSERT_SAME(cradle::invoke(&S::cmf, &s), void);
  static_assert(!noexcept(cradle::invoke(&S::cmf, &s)), "");
  gi = 0;
  cradle::invoke(&S::cmf, &s);
  BOOST_CHECK_EQUAL(gi, 1);

  ASSERT_SAME(cradle::invoke(&S::cmf, &cradle::as_const(s)), void);
  static_assert(!noexcept(cradle::invoke(&S::cmf, &cradle::as_const(s))), "");
  gi = 0;
  cradle::invoke(&S::cmf, &cradle::as_const(s));
  BOOST_CHECK_EQUAL(gi, 1);

  {
    std::shared_ptr<S> p = std::make_shared<S>();

    ASSERT_SAME(cradle::invoke(&S::cmf, p), void);
    static_assert(!noexcept(cradle::invoke(&S::cmf, p)), "");
    gi = 0;
    cradle::invoke(&S::cmf, p);
    BOOST_CHECK_EQUAL(gi, 1);
  }

  {
    std::shared_ptr<S const> p = std::make_shared<S>();

    ASSERT_SAME(cradle::invoke(&S::cmf, p), void);
    static_assert(!noexcept(cradle::invoke(&S::cmf, p)), "");
    gi = 0;
    cradle::invoke(&S::cmf, p);
    BOOST_CHECK_EQUAL(gi, 1);
  }

  ASSERT_SAME(cradle::invoke<void>(&S::cmf, s), void);
  static_assert(!noexcept(cradle::invoke<void>(&S::cmf, s)), "");
  gi = 0;
  cradle::invoke<void>(&S::cmf, s);
  BOOST_CHECK_EQUAL(gi, 1);

  static_assert(!test_explicit<int &, void (S::*)() const, S &>(0), "");

  static_assert(!test_explicit<int const &, void (S::*)() const, S &>(0), "");

  static_assert(!test_explicit<int &&, void (S::*)() const, S &>(0), "");

  static_assert(!test_explicit<int, void (S::*)() const, S &>(0), "");
}

BOOST_AUTO_TEST_CASE(nullary_nothrow_member_function)
{
  S s;

  {
    void (S::*pmf)() noexcept = &S::ntmf;

    ASSERT_SAME(cradle::invoke(pmf, s), void);
#if !defined(CRADLE_NO_NOEXCEPT_ON_FUNCTION_POINTERS)
    // http://gcc.gnu.org/bugzilla/show_bug.cgi?id=49332
    static_assert(noexcept(cradle::invoke(pmf, s)), "");
#endif
    gi = 0;
    cradle::invoke(pmf, s);
    BOOST_CHECK_EQUAL(gi, 1);

    ASSERT_SAME(cradle::invoke(cradle::as_const(pmf), s), void);
#if !defined(CRADLE_NO_NOEXCEPT_ON_FUNCTION_POINTERS)
    static_assert(noexcept(cradle::invoke(cradle::as_const(pmf), s)), "");
#endif
    gi = 0;
    cradle::invoke(cradle::as_const(pmf), s);
    BOOST_CHECK_EQUAL(gi, 1);
  }

  ASSERT_SAME(cradle::invoke(&S::ntmf, s), void);
#if !defined(CRADLE_NO_NOEXCEPT_ON_FUNCTION_POINTERS)
  static_assert(noexcept(cradle::invoke(&S::ntmf, s)), "");
#endif
  gi = 0;
  cradle::invoke(&S::ntmf, s);
  BOOST_CHECK_EQUAL(gi, 1);

  static_assert(!test<void (S::*)() noexcept, S const &>(0), "");

  ASSERT_SAME(cradle::invoke(&S::ntmf, std::move(s)), void);
#if !defined(CRADLE_NO_NOEXCEPT_ON_FUNCTION_POINTERS)
  static_assert(noexcept(cradle::invoke(&S::ntmf, std::move(s))), "");
#endif
  gi = 0;
  cradle::invoke(&S::ntmf, std::move(s));
  BOOST_CHECK_EQUAL(gi, 1);

  ASSERT_SAME(cradle::invoke(&S::ntmf, &s), void);
#if !defined(CRADLE_NO_NOEXCEPT_ON_FUNCTION_POINTERS)
  static_assert(noexcept(cradle::invoke(&S::ntmf, &s)), "");
#endif
  gi = 0;
  cradle::invoke(&S::ntmf, &s);
  BOOST_CHECK_EQUAL(gi, 1);

  static_assert(!test<void (S::*)() noexcept, S const *>(0), "");

  {
    std::shared_ptr<S> p = std::make_shared<S>();

    ASSERT_SAME(cradle::invoke(&S::ntmf, p), void);
#if !defined(CRADLE_NO_NOEXCEPT_ON_FUNCTION_POINTERS)
    static_assert(noexcept(cradle::invoke(&S::ntmf, p)), "");
#endif
    gi = 0;
    cradle::invoke(&S::ntmf, p);
    BOOST_CHECK_EQUAL(gi, 1);
  }

  static_assert(!test<void (S::*)() noexcept, std::shared_ptr<S const> &>(0), "");

  ASSERT_SAME(cradle::invoke<void>(&S::ntmf, s), void);
#if !defined(CRADLE_NO_NOEXCEPT_ON_FUNCTION_POINTERS)
  static_assert(noexcept(cradle::invoke<void>(&S::ntmf, s)), "");
#endif
  gi = 0;
  cradle::invoke<void>(&S::ntmf, s);
  BOOST_CHECK_EQUAL(gi, 1);

  static_assert(!test_explicit<int &, void (S::*)() noexcept, S &>(0), "");

  static_assert(!test_explicit<int const &, int (S::*)() noexcept, S &>(0), "");

  static_assert(!test_explicit<int, void (S::*)() noexcept, S &>(0), "");

  static_assert(!test_explicit<int &&, void (S::*)() noexcept, S &>(0), "");
}

BOOST_AUTO_TEST_CASE(nothrow_const_member_function)
{
  S s;

  {
    void (S::*pmf)() const noexcept = &S::ntcmf;

    ASSERT_SAME(cradle::invoke(pmf, s), void);
#if !defined(CRADLE_NO_NOEXCEPT_ON_FUNCTION_POINTERS)
    static_assert(noexcept(cradle::invoke(pmf, s)), "");
#endif
    gi = 0;
    cradle::invoke(pmf, s);
    BOOST_CHECK_EQUAL(gi, 1);

    ASSERT_SAME(cradle::invoke(cradle::as_const(pmf), s), void);
#if !defined(CRADLE_NO_NOEXCEPT_ON_FUNCTION_POINTERS)
    static_assert(noexcept(cradle::invoke(cradle::as_const(pmf), s)), "");
#endif
    gi = 0;
    cradle::invoke(cradle::as_const(pmf), s);
    BOOST_CHECK_EQUAL(gi, 1);
  }

  ASSERT_SAME(cradle::invoke(&S::ntcmf, s), void);
#if !defined(CRADLE_NO_NOEXCEPT_ON_FUNCTION_POINTERS)
  static_assert(noexcept(cradle::invoke(&S::ntcmf, s)), "");
#endif
  gi = 0;
  cradle::invoke(&S::ntcmf, s);
  BOOST_CHECK_EQUAL(gi, 1);

  ASSERT_SAME(cradle::invoke(&S::ntcmf, cradle::as_const(s)), void);
#if !defined(CRADLE_NO_NOEXCEPT_ON_FUNCTION_POINTERS)
  static_assert(noexcept(cradle::invoke(&S::ntcmf, cradle::as_const(s))), "");
#endif
  gi = 0;
  cradle::invoke(&S::ntcmf, cradle::as_const(s));
  BOOST_CHECK_EQUAL(gi, 1);

  ASSERT_SAME(cradle::invoke(&S::ntcmf, std::move(s)), void);
#if !defined(CRADLE_NO_NOEXCEPT_ON_FUNCTION_POINTERS)
  static_assert(noexcept(cradle::invoke(&S::ntcmf, std::move(s))), "");
#endif
  gi = 0;
  cradle::invoke(&S::ntcmf, std::move(s));
  BOOST_CHECK_EQUAL(gi, 1);

  ASSERT_SAME(cradle::invoke(&S::ntcmf, &s), void);
#if !defined(CRADLE_NO_NOEXCEPT_ON_FUNCTION_POINTERS)
  static_assert(noexcept(cradle::invoke(&S::ntcmf, &s)), "");
#endif
  gi = 0;
  cradle::invoke(&S::ntcmf, &s);
  BOOST_CHECK_EQUAL(gi, 1);

  ASSERT_SAME(cradle::invoke(&S::ntcmf, &cradle::as_const(s)), void);
#if !defined(CRADLE_NO_NOEXCEPT_ON_FUNCTION_POINTERS)
  static_assert(noexcept(cradle::invoke(&S::ntcmf, &cradle::as_const(s))), "");
#endif
  gi = 0;
  cradle::invoke(&S::ntcmf, &cradle::as_const(s));
  BOOST_CHECK_EQUAL(gi, 1);

  {
    std::shared_ptr<S> p = std::make_shared<S>();

    ASSERT_SAME(cradle::invoke(&S::ntcmf, p), void);
#if !defined(CRADLE_NO_NOEXCEPT_ON_FUNCTION_POINTERS)
    static_assert(noexcept(cradle::invoke(&S::ntcmf, p)), "");
#endif
    gi = 0;
    cradle::invoke(&S::ntcmf, p);
    BOOST_CHECK_EQUAL(gi, 1);
  }

  {
    std::shared_ptr<S const> p = std::make_shared<S>();

    ASSERT_SAME(cradle::invoke(&S::ntcmf, p), void);
#if !defined(CRADLE_NO_NOEXCEPT_ON_FUNCTION_POINTERS)
    static_assert(noexcept(cradle::invoke(&S::ntcmf, p)), "");
#endif
    gi = 0;
    cradle::invoke(&S::ntcmf, p);
    BOOST_CHECK_EQUAL(gi, 1);
  }

  ASSERT_SAME(cradle::invoke<void>(&S::ntcmf, s), void);
#if !defined(CRADLE_NO_NOEXCEPT_ON_FUNCTION_POINTERS)
  static_assert(noexcept(cradle::invoke<void>(&S::ntcmf, s)), "");
#endif
  gi = 0;
  cradle::invoke<void>(&S::ntcmf, s);
  BOOST_CHECK_EQUAL(gi, 1);

  static_assert(!test_explicit<int &, void (S::*)() const noexcept, S &>(0), "");

  static_assert(!test_explicit<int const &, void (S::*)() const noexcept, S &>(0), "");

  static_assert(!test_explicit<int, void (S::*)() const noexcept, S &>(0), "");

  static_assert(!test_explicit<int &&, void (S::*)() const noexcept, S &>(0), "");
}

BOOST_AUTO_TEST_CASE(nullary_member_function_returning_prvaue)
{
  S s;

  {
    int (S::*pmf)() = &S::mf0p;

    ASSERT_SAME(cradle::invoke(pmf, s), int);
    static_assert(!noexcept(cradle::invoke(pmf, s)), "");
    gi = 1;
    BOOST_CHECK_EQUAL(cradle::invoke(pmf, s), 2);

    ASSERT_SAME(cradle::invoke(cradle::as_const(pmf), s), int);
    static_assert(!noexcept(cradle::invoke(cradle::as_const(pmf), s)), "");
    gi = 2;
    BOOST_CHECK_EQUAL(cradle::invoke(cradle::as_const(pmf), s), 4);
  }

  ASSERT_SAME(cradle::invoke(&S::mf0p, s), int);
  static_assert(!noexcept(cradle::invoke(&S::mf0p, s)), "");
  gi = 3;
  BOOST_CHECK_EQUAL(cradle::invoke(&S::mf0p, s), 6);

  static_assert(!test<int (S::*)(), S const &>(0), "");

  ASSERT_SAME(cradle::invoke(&S::mf0p, std::move(s)), int);
  static_assert(!noexcept(cradle::invoke(&S::mf0p, std::move(s))), "");
  gi = 4;
  BOOST_CHECK_EQUAL(cradle::invoke(&S::mf0p, std::move(s)), 8);

  ASSERT_SAME(cradle::invoke(&S::mf0p, &s), int);
  static_assert(!noexcept(cradle::invoke(&S::mf0p, &s)), "");
  gi = 5;
  BOOST_CHECK_EQUAL(cradle::invoke(&S::mf0p, &s), 10);

  static_assert(!test<int (S::*)(), S const * &>(0), "");

  {
    std::shared_ptr<S> p = std::make_shared<S>();

    ASSERT_SAME(cradle::invoke(&S::mf0p, p), int);
    static_assert(!noexcept(cradle::invoke(&S::mf0p, p)), "");
    gi = 6;
    BOOST_CHECK_EQUAL(cradle::invoke(&S::mf0p, p), 12);
  }

  static_assert(!test<int (S::*)(), std::shared_ptr<S const> &>(0), "");

  ASSERT_SAME(cradle::invoke<int>(&S::mf0p, s), int);
  static_assert(!noexcept(cradle::invoke<int>(&S::mf0p, s)), "");
  gi = 7;
  BOOST_CHECK_EQUAL(cradle::invoke<int>(&S::mf0p, s), 14);

  static_assert(!test_explicit<int &, int (S::*)(), S &>(0), "");

  static_assert(!test_explicit<int const &, int (S::*)(), S &>(0), "");

  static_assert(!test_explicit<int &&, int (S::*)(), S &>(0), "");

  ASSERT_SAME(cradle::invoke<void>(&S::mf0p, s), void);
  static_assert(!noexcept(cradle::invoke<void>(&S::mf0p, s)), "");
  cradle::invoke<void>(&S::mf0p, s);

  ASSERT_SAME(cradle::invoke<void const>(&S::mf0p, s), void);
  static_assert(!noexcept(cradle::invoke<void const>(&S::mf0p, s)), "");
  cradle::invoke<void const>(&S::mf0p, s);

  ASSERT_SAME(cradle::invoke<int>(&S::mf0p, &s), int);
  static_assert(!noexcept(cradle::invoke<int>(&S::mf0p, &s)), "");
  gi = 8;
  BOOST_CHECK_EQUAL(cradle::invoke<int>(&S::mf0p, &s), 16);

  ASSERT_SAME(cradle::invoke<void>(&S::mf0p, &s), void);
  static_assert(!noexcept(cradle::invoke<void>(&S::mf0p, &s)), "");
  cradle::invoke<void>(&S::mf0p, &s);

  ASSERT_SAME(cradle::invoke<void const>(&S::mf0p, &s), void);
  static_assert(!noexcept(cradle::invoke<void const>(&S::mf0p, &s)), "");
  cradle::invoke<void const>(&S::mf0p, &s);

  static_assert(!test_explicit<int &, int (S::*)(), S * &>(0), "");

  static_assert(!test_explicit<int const &, int (S::*)(), S * &>(0), "");

  static_assert(!test_explicit<int &&, int (S::*)(), S * &>(0), "");
}

BOOST_AUTO_TEST_CASE(nullary_member_function_returning_lvalue)
{
  S s;

  {
    int &(S::*pmf)() = &S::mf0l;

    ASSERT_SAME(cradle::invoke(pmf, s), int &);
    static_assert(!noexcept(cradle::invoke(pmf, s)), "");
    BOOST_CHECK_EQUAL(&cradle::invoke(pmf, s), &gi);

    ASSERT_SAME(cradle::invoke(cradle::as_const(pmf), s), int &);
    static_assert(!noexcept(cradle::invoke(cradle::as_const(pmf), s)), "");
    BOOST_CHECK_EQUAL(&cradle::invoke(cradle::as_const(pmf), s), &gi);
  }

  ASSERT_SAME(cradle::invoke(&S::mf0l, s), int &);
  static_assert(!noexcept(cradle::invoke(&S::mf0l, s)), "");
  BOOST_CHECK_EQUAL(&cradle::invoke(&S::mf0l, s), &gi);

  static_assert(!test<int &(S::*)(), int const &>(0), "");

  ASSERT_SAME(cradle::invoke(&S::mf0l, std::move(s)), int &);
  static_assert(!noexcept(cradle::invoke(&S::mf0l, std::move(s))), "");
  BOOST_CHECK_EQUAL(&cradle::invoke(&S::mf0l, std::move(s)), &gi);

  ASSERT_SAME(cradle::invoke(&S::mf0l, &s), int &);
  static_assert(!noexcept(cradle::invoke(&S::mf0l, &s)), "");
  BOOST_CHECK_EQUAL(&cradle::invoke(&S::mf0l, &s), &gi);

  static_assert(!test<int &(S::*)(), int const * &>(0), "");

  {
    std::shared_ptr<S> p = std::make_shared<S>();

    ASSERT_SAME(cradle::invoke(&S::mf0l, p), int &);
    static_assert(!noexcept(cradle::invoke(&S::mf0l, p)), "");
    BOOST_CHECK_EQUAL(&cradle::invoke(&S::mf0l, p), &gi);
  }

  static_assert(!test<int &(S::*)(), std::shared_ptr<int const> &>(0), "");

  ASSERT_SAME(cradle::invoke<int &>(&S::mf0l, s), int &);
  static_assert(!noexcept(cradle::invoke<int &>(&S::mf0l, s)), "");
  BOOST_CHECK_EQUAL(&cradle::invoke<int &>(&S::mf0l, s), &gi);

  ASSERT_SAME(cradle::invoke<int const &>(&S::mf0l, s), int const &);
  static_assert(!noexcept(cradle::invoke<int const &>(&S::mf0l, s)), "");
  BOOST_CHECK_EQUAL(&cradle::invoke<int const &>(&S::mf0l, s), &gi);

  ASSERT_SAME(cradle::invoke<int>(&S::mf0l, s), int);
  static_assert(!noexcept(cradle::invoke<int>(&S::mf0l, s)), "");
  gi = 2;
  BOOST_CHECK_EQUAL(cradle::invoke<int>(&S::mf0l, s), gi);

  ASSERT_SAME(cradle::invoke<int &>(&S::mf0l, &s), int &);
  static_assert(!noexcept(cradle::invoke<int &>(&S::mf0l, &s)), "");
  BOOST_CHECK_EQUAL(&cradle::invoke<int &>(&S::mf0l, &s), &gi);

  static_assert(!test_explicit<int &&, int &(S::*)(), int &>(0), "");

  ASSERT_SAME(cradle::invoke<void>(&S::mf0l, s), void);
  static_assert(!noexcept(cradle::invoke<void>(&S::mf0l, s)), "");
  cradle::invoke<void>(&S::mf0l, s);

  ASSERT_SAME(cradle::invoke<void const>(&S::mf0l, s), void);
  static_assert(!noexcept(cradle::invoke<void const>(&S::mf0l, s)), "");
  cradle::invoke<void const>(&S::mf0l, s);

  ASSERT_SAME(cradle::invoke<int const &>(&S::mf0l, &s), int const &);
  static_assert(!noexcept(cradle::invoke<int const &>(&S::mf0l, &s)), "");
  BOOST_CHECK_EQUAL(&cradle::invoke<int const &>(&S::mf0l, &s), &gi);

  ASSERT_SAME(cradle::invoke<int>(&S::mf0l, &s), int);
  static_assert(!noexcept(cradle::invoke<int>(&S::mf0l, &s)), "");
  gi = 3;
  BOOST_CHECK_EQUAL(cradle::invoke<int>(&S::mf0l, &s), gi);

  ASSERT_SAME(cradle::invoke<void>(&S::mf0l, &s), void);
  static_assert(!noexcept(cradle::invoke<void>(&S::mf0l, &s)), "");
  cradle::invoke<void>(&S::mf0l, &s);

  ASSERT_SAME(cradle::invoke<void const>(&S::mf0l, &s), void);
  static_assert(!noexcept(cradle::invoke<void const>(&S::mf0l, &s)), "");
  cradle::invoke<void const>(&S::mf0l, &s);

  static_assert(!test_explicit<int &&, int &(S::*)(), int * &>(0), "");
}

BOOST_AUTO_TEST_CASE(nullary_member_function_returning_const_lvalue)
{
  S s;

  {
    int const &(S::*pmf)() = &S::mf0cl;

    ASSERT_SAME(cradle::invoke(pmf, s), int const &);
    static_assert(!noexcept(cradle::invoke(pmf, s)), "");
    BOOST_CHECK_EQUAL(&cradle::invoke(pmf, s), &gi);

    ASSERT_SAME(cradle::invoke(cradle::as_const(pmf), s), int const &);
    static_assert(!noexcept(cradle::invoke(cradle::as_const(pmf), s)), "");
    BOOST_CHECK_EQUAL(&cradle::invoke(cradle::as_const(pmf), s), &gi);
  }

  ASSERT_SAME(cradle::invoke(&S::mf0cl, s), int const &);
  static_assert(!noexcept(cradle::invoke(&S::mf0cl, s)), "");
  BOOST_CHECK_EQUAL(&cradle::invoke(&S::mf0cl, s), &gi);

  static_assert(!test<int const &(S::*)(), int const &>(0), "");

  ASSERT_SAME(cradle::invoke(&S::mf0cl, std::move(s)), int const &);
  static_assert(!noexcept(cradle::invoke(&S::mf0cl, std::move(s))), "");
  BOOST_CHECK_EQUAL(&cradle::invoke(&S::mf0cl, std::move(s)), &gi);

  ASSERT_SAME(cradle::invoke(&S::mf0cl, &s), int const &);
  static_assert(!noexcept(cradle::invoke(&S::mf0cl, &s)), "");
  BOOST_CHECK_EQUAL(&cradle::invoke(&S::mf0cl, &s), &gi);

  static_assert(!test<int const &(S::*)(), int const * &>(0), "");

  {
    std::shared_ptr<S> p = std::make_shared<S>();

    ASSERT_SAME(cradle::invoke(&S::mf0cl, p), int const &);
    static_assert(!noexcept(cradle::invoke(&S::mf0cl, p)), "");
    BOOST_CHECK_EQUAL(&cradle::invoke(&S::mf0cl, p), &gi);
  }

  static_assert(!test<int const &(S::*)(), std::shared_ptr<int const> &>(0), "");

  ASSERT_SAME(cradle::invoke<int const &>(&S::mf0cl, s), int const &);
  static_assert(!noexcept(cradle::invoke<int const &>(&S::mf0cl, s)), "");
  BOOST_CHECK_EQUAL(&cradle::invoke<int const &>(&S::mf0cl, s), &gi);

  ASSERT_SAME(cradle::invoke<int>(&S::mf0cl, s), int);
  static_assert(!noexcept(cradle::invoke<int>(&S::mf0cl, s)), "");
  gi = 2;
  BOOST_CHECK_EQUAL(cradle::invoke<int>(&S::mf0cl, s), gi);

  static_assert(!test_explicit<int &, int const &(S::*)(), int &>(0), "");

  static_assert(!test_explicit<int &&, int const &(S::*)(), int &>(0), "");

  ASSERT_SAME(cradle::invoke<void>(&S::mf0cl, s), void);
  static_assert(!noexcept(cradle::invoke<void>(&S::mf0cl, s)), "");
  cradle::invoke<void>(&S::mf0cl, s);

  ASSERT_SAME(cradle::invoke<void const>(&S::mf0cl, s), void);
  static_assert(!noexcept(cradle::invoke<void const>(&S::mf0cl, s)), "");
  cradle::invoke<void const>(&S::mf0cl, s);

  ASSERT_SAME(cradle::invoke<int const &>(&S::mf0cl, &s), int const &);
  static_assert(!noexcept(cradle::invoke<int const &>(&S::mf0cl, &s)), "");
  BOOST_CHECK_EQUAL(&cradle::invoke<int const &>(&S::mf0cl, &s), &gi);

  ASSERT_SAME(cradle::invoke<int>(&S::mf0cl, &s), int);
  static_assert(!noexcept(cradle::invoke<int>(&S::mf0cl, &s)), "");
  gi = 3;
  BOOST_CHECK_EQUAL(cradle::invoke<int>(&S::mf0cl, &s), gi);

  static_assert(!test_explicit<int &, int const &(S::*)(), int * &>(0), "");

  static_assert(!test_explicit<int &&, int const &(S::*)(), int * &>(0), "");

  ASSERT_SAME(cradle::invoke<void>(&S::mf0cl, &s), void);
  static_assert(!noexcept(cradle::invoke<void>(&S::mf0cl, &s)), "");
  cradle::invoke<void>(&S::mf0cl, &s);

  ASSERT_SAME(cradle::invoke<void const>(&S::mf0cl, &s), void);
  static_assert(!noexcept(cradle::invoke<void const>(&S::mf0cl, &s)), "");
  cradle::invoke<void const>(&S::mf0cl, &s);
}

BOOST_AUTO_TEST_CASE(nullary_member_function_returning_xvalue)
{
  S s;

  {
    int &&(S::*pmf)() = &S::mf0x;

    ASSERT_SAME(cradle::invoke(pmf, s), int &&);
    static_assert(!noexcept(cradle::invoke(pmf, s)), "");
    BOOST_CHECK_EQUAL(&static_cast<int const &>(cradle::invoke(pmf, s)), &gi);

    ASSERT_SAME(cradle::invoke(cradle::as_const(pmf), s), int &&);
    static_assert(!noexcept(cradle::invoke(cradle::as_const(pmf), s)), "");
    BOOST_CHECK_EQUAL(&static_cast<int const &>(cradle::invoke(cradle::as_const(pmf), s)), &gi);
  }

  ASSERT_SAME(cradle::invoke(&S::mf0x, s), int &&);
  static_assert(!noexcept(cradle::invoke(&S::mf0x, s)), "");
  BOOST_CHECK_EQUAL(&static_cast<int const &>(cradle::invoke(&S::mf0x, s)), &gi);

  static_assert(!test<int &&(S::*)(), int const &>(0), "");

  ASSERT_SAME(cradle::invoke(&S::mf0x, std::move(s)), int &&);
  static_assert(!noexcept(cradle::invoke(&S::mf0x, std::move(s))), "");
  BOOST_CHECK_EQUAL(&static_cast<int const &>(cradle::invoke(&S::mf0x, std::move(s))), &gi);

  ASSERT_SAME(cradle::invoke(&S::mf0x, &s), int &&);
  static_assert(!noexcept(cradle::invoke(&S::mf0x, &s)), "");
  BOOST_CHECK_EQUAL(&static_cast<int const &>(cradle::invoke(&S::mf0x, &s)), &gi);

  static_assert(!test<int &&(S::*)(), int const * &>(0), "");

  {
    std::shared_ptr<S> p = std::make_shared<S>();

    ASSERT_SAME(cradle::invoke(&S::mf0x, p), int &&);
    static_assert(!noexcept(cradle::invoke(&S::mf0x, p)), "");
    BOOST_CHECK_EQUAL(&static_cast<int const &>(cradle::invoke(&S::mf0x, p)), &gi);
  }

  static_assert(!test<int &&(S::*)(), std::shared_ptr<int const> &>(0), "");

  ASSERT_SAME(cradle::invoke<int const &>(&S::mf0x, s), int const &);
  static_assert(!noexcept(cradle::invoke<int const &>(&S::mf0x, s)), "");
  BOOST_CHECK_EQUAL(&cradle::invoke<int const &>(&S::mf0x, s), &gi);

  ASSERT_SAME(cradle::invoke<int>(&S::mf0x, s), int);
  static_assert(!noexcept(cradle::invoke<int>(&S::mf0x, s)), "");
  gi = 2;
  BOOST_CHECK_EQUAL(cradle::invoke<int>(&S::mf0x, s), gi);

  ASSERT_SAME(cradle::invoke<int &&>(&S::mf0x, s), int &&);
  static_assert(!noexcept(cradle::invoke<int &&>(&S::mf0x, s)), "");
  BOOST_CHECK_EQUAL(&static_cast<int const &>(cradle::invoke<int &&>(&S::mf0x, s)), &gi);

  static_assert(!test_explicit<int &, int &&(S::*)(), int &>(0), "");

  ASSERT_SAME(cradle::invoke<void>(&S::mf0x, s), void);
  static_assert(!noexcept(cradle::invoke<void>(&S::mf0x, s)), "");
  cradle::invoke<void>(&S::mf0x, s);

  ASSERT_SAME(cradle::invoke<void const>(&S::mf0x, s), void);
  static_assert(!noexcept(cradle::invoke<void const>(&S::mf0x, s)), "");
  cradle::invoke<void const>(&S::mf0x, s);

  ASSERT_SAME(cradle::invoke<int const &>(&S::mf0x, &s), int const &);
  static_assert(!noexcept(cradle::invoke<int const &>(&S::mf0x, &s)), "");
  BOOST_CHECK_EQUAL(&cradle::invoke<int const &>(&S::mf0x, &s), &gi);

  ASSERT_SAME(cradle::invoke<int>(&S::mf0x, &s), int);
  static_assert(!noexcept(cradle::invoke<int>(&S::mf0x, &s)), "");
  gi = 3;
  BOOST_CHECK_EQUAL(cradle::invoke<int>(&S::mf0x, &s), gi);

  ASSERT_SAME(cradle::invoke<int &&>(&S::mf0x, &s), int &&);
  static_assert(!noexcept(cradle::invoke<int &&>(&S::mf0x, &s)), "");
  BOOST_CHECK_EQUAL(&static_cast<int const &>(cradle::invoke<int &&>(&S::mf0x, &s)), &gi);

  static_assert(!test_explicit<int &, int &&(S::*)(), int * &>(0), "");

  ASSERT_SAME(cradle::invoke<void>(&S::mf0x, &s), void);
  static_assert(!noexcept(cradle::invoke<void>(&S::mf0x, &s)), "");
  cradle::invoke<void>(&S::mf0x, &s);

  ASSERT_SAME(cradle::invoke<void const>(&S::mf0x, &s), void);
  static_assert(!noexcept(cradle::invoke<void const>(&S::mf0x, &s)), "");
  cradle::invoke<void const>(&S::mf0x, &s);
}

BOOST_AUTO_TEST_CASE(unary_member_function_with_prvalue)
{
  S s;

  static_assert(!test<void (S::*)(int), S &>(0), "");

  static_assert(!test<void (S::*)(int), S &, int, int>(0), "");

  {
    void (S::*pmf)(int) = &S::mf1p;

    ASSERT_SAME(cradle::invoke(pmf, s, 42), void);
    static_assert(!noexcept(cradle::invoke(pmf, s, 42)), "");
    cradle::invoke(pmf, s, 42);

    ASSERT_SAME(cradle::invoke(cradle::as_const(pmf), s, 42), void);
    static_assert(!noexcept(cradle::invoke(cradle::as_const(pmf), s, 42)), "");
    cradle::invoke(cradle::as_const(pmf), s, 42);
  }

  ASSERT_SAME(cradle::invoke(&S::mf1p, s, 42), void);
  static_assert(!noexcept(cradle::invoke(&S::mf1p, s, 42)), "");
  cradle::invoke(&S::mf1p, s, 42);

  static_assert(!test<void (S::*)(int), S const &, int>(0), "");

  ASSERT_SAME(cradle::invoke(&S::mf1p, std::move(s), 42), void);
  static_assert(!noexcept(cradle::invoke(&S::mf1p, std::move(s), 42)), "");
  cradle::invoke(&S::mf1p, std::move(s), 42);

  ASSERT_SAME(cradle::invoke(&S::mf1p, &s, 42), void);
  static_assert(!noexcept(cradle::invoke(&S::mf1p, &s, 42)), "");
  cradle::invoke(&S::mf1p, &s, 42);

  static_assert(!test<void (S::*)(int), S const *, int>(0), "");

  {
    std::shared_ptr<S> p = std::make_shared<S>();

    ASSERT_SAME(cradle::invoke(&S::mf1p, p, 42), void);
    static_assert(!noexcept(cradle::invoke(&S::mf1p, p, 42)), "");
    cradle::invoke(&S::mf1p, p, 42);
  }

  static_assert(!test<void (S::*)(int), std::shared_ptr<S const> &, int>(0), "");

  {
    int i = 42;

    ASSERT_SAME(cradle::invoke(&S::mf1p, s, i), void);
    static_assert(!noexcept(cradle::invoke(&S::mf1p, s, i)), "");
    cradle::invoke(&S::mf1p, s, i);

    ASSERT_SAME(cradle::invoke(&S::mf1p, s, cradle::as_const(i)), void);
    static_assert(!noexcept(cradle::invoke(&S::mf1p, s, cradle::as_const(i))), "");
    cradle::invoke(&S::mf1p, s, cradle::as_const(i));
  }

  ASSERT_SAME(cradle::invoke<void>(&S::mf1p, s, 42), void);
  static_assert(!noexcept(cradle::invoke<void>(&S::mf1p, s, 42)), "");
  cradle::invoke<void>(&S::mf1p, s, 42);

  ASSERT_SAME(cradle::invoke<void const>(&S::mf1p, s, 42), void);
  static_assert(!noexcept(cradle::invoke<void const>(&S::mf1p, s, 42)), "");
  cradle::invoke<void const>(&S::mf1p, s, 42);

  static_assert(!test_explicit<int, void (S::*)(int), S &, int>(0), "");

  static_assert(!test_explicit<int &, void (S::*)(int), S &, int>(0), "");

  static_assert(!test_explicit<int const &, void (S::*)(int), S &, int>(0), "");

  static_assert(!test_explicit<int &&, void (S::*)(int), S &, int>(0), "");
}

BOOST_AUTO_TEST_CASE(unary_member_function_with_lvalue)
{
  S s;

  static_assert(!test<void (S::*)(int &), S &>(0), "");

  static_assert(!test<void (S::*)(int &), S &, int &, int &>(0), "");

  {
    void (S::*pmf)(int &) = &S::mf1l;

    ASSERT_SAME(cradle::invoke(pmf, s, gi), void);
    static_assert(!noexcept(cradle::invoke(pmf, s, gi)), "");
    cradle::invoke(pmf, s, gi);

    ASSERT_SAME(cradle::invoke(cradle::as_const(pmf), s, gi), void);
    static_assert(!noexcept(cradle::invoke(cradle::as_const(pmf), s, gi)), "");
    cradle::invoke(cradle::as_const(pmf), s, gi);
  }

  ASSERT_SAME(cradle::invoke(&S::mf1l, s, gi), void);
  static_assert(!noexcept(cradle::invoke(&S::mf1l, s, gi)), "");
  cradle::invoke(&S::mf1l, s, gi);

  static_assert(!test<void (S::*)(int &), S const &, int &>(0), "");

  ASSERT_SAME(cradle::invoke(&S::mf1l, std::move(s), gi), void);
  static_assert(!noexcept(cradle::invoke(&S::mf1l, std::move(s), gi)), "");
  cradle::invoke(&S::mf1l, std::move(s), gi);

  ASSERT_SAME(cradle::invoke(&S::mf1l, &s, gi), void);
  static_assert(!noexcept(cradle::invoke(&S::mf1l, &s, gi)), "");
  cradle::invoke(&S::mf1l, &s, gi);

  static_assert(!test<void (S::*)(int &), S const *, int &>(0), "");

  {
    std::shared_ptr<S> p = std::make_shared<S>();

    ASSERT_SAME(cradle::invoke(&S::mf1l, p, gi), void);
    static_assert(!noexcept(cradle::invoke(&S::mf1l, p, gi)), "");
    cradle::invoke(&S::mf1l, p, gi);
  }

  static_assert(!test<void (S::*)(int &), std::shared_ptr<S const> &, int &>(0), "");

  static_assert(!test<void (S::*)(int &), S &, int const &>(0), "");

  static_assert(!test<void (S::*)(int &), S &, int &&>(0), "");

  ASSERT_SAME(cradle::invoke<void>(&S::mf1l, s, gi), void);
  static_assert(!noexcept(cradle::invoke<void>(&S::mf1l, s, gi)), "");
  cradle::invoke<void>(&S::mf1l, s, gi);

  ASSERT_SAME(cradle::invoke<void const>(&S::mf1l, s, gi), void);
  static_assert(!noexcept(cradle::invoke<void const>(&S::mf1l, s, gi)), "");
  cradle::invoke<void const>(&S::mf1l, s, gi);

  static_assert(!test_explicit<int, void (S::*)(int &), S &, int &>(0), "");

  static_assert(!test_explicit<int &, void (S::*)(int &), S &, int &>(0), "");

  static_assert(!test_explicit<int const &, void (S::*)(int &), S &, int &>(0), "");

  static_assert(!test_explicit<int &&, void (S::*)(int &), S &, int &>(0), "");
}

BOOST_AUTO_TEST_CASE(unary_member_function_with_const_lvalue)
{
  S s;

  static_assert(!test<void (S::*)(int const &), S &>(0), "");

  static_assert(!test<void (S::*)(int const &), S &, int &, int &>(0), "");

  {
    void (S::*pmf)(int const &) = &S::mf1cl;

    ASSERT_SAME(cradle::invoke(pmf, s, gi), void);
    static_assert(!noexcept(cradle::invoke(pmf, s, gi)), "");
    cradle::invoke(pmf, s, gi);

    ASSERT_SAME(cradle::invoke(cradle::as_const(pmf), s, gi), void);
    static_assert(!noexcept(cradle::invoke(cradle::as_const(pmf), s, gi)), "");
    cradle::invoke(cradle::as_const(pmf), s, gi);
  }

  ASSERT_SAME(cradle::invoke(&S::mf1cl, s, gi), void);
  static_assert(!noexcept(cradle::invoke(&S::mf1cl, s, gi)), "");
  cradle::invoke(&S::mf1cl, s, gi);

  static_assert(!test<void (S::*)(int const &), S const &, int &>(0), "");

  ASSERT_SAME(cradle::invoke(&S::mf1cl, std::move(s), gi), void);
  static_assert(!noexcept(cradle::invoke(&S::mf1cl, std::move(s), gi)), "");
  cradle::invoke(&S::mf1cl, std::move(s), gi);

  ASSERT_SAME(cradle::invoke(&S::mf1cl, &s, gi), void);
  static_assert(!noexcept(cradle::invoke(&S::mf1cl, &s, gi)), "");
  cradle::invoke(&S::mf1cl, &s, gi);

  static_assert(!test<void (S::*)(int const &), S const *, int &>(0), "");

  {
    std::shared_ptr<S> p = std::make_shared<S>();

    ASSERT_SAME(cradle::invoke(&S::mf1cl, p, gi), void);
    static_assert(!noexcept(cradle::invoke(&S::mf1cl, p, gi)), "");
    cradle::invoke(&S::mf1cl, p, gi);
  }

  static_assert(!test<void (S::*)(int const &), std::shared_ptr<S const> &, int &>(0), "");

  ASSERT_SAME(cradle::invoke(&S::mf1cl, s, cradle::as_const(gi)), void);
  static_assert(!noexcept(cradle::invoke(&S::mf1cl, s, cradle::as_const(gi))), "");
  cradle::invoke(&S::mf1cl, s, cradle::as_const(gi));

  ASSERT_SAME(cradle::invoke(&S::mf1cl, s, std::move(gi)), void);
  static_assert(!noexcept(cradle::invoke(&S::mf1cl, s, std::move(gi))), "");
  cradle::invoke(&S::mf1cl, s, std::move(gi));

  ASSERT_SAME(cradle::invoke<void>(&S::mf1cl, s, gi), void);
  static_assert(!noexcept(cradle::invoke<void>(&S::mf1cl, s, gi)), "");
  cradle::invoke<void>(&S::mf1cl, s, gi);

  ASSERT_SAME(cradle::invoke<void const>(&S::mf1cl, s, gi), void);
  static_assert(!noexcept(cradle::invoke<void const>(&S::mf1cl, s, gi)), "");
  cradle::invoke<void const>(&S::mf1cl, s, gi);

  static_assert(!test_explicit<int, void (S::*)(int const &), S &, int &>(0), "");

  static_assert(!test_explicit<int &, void (S::*)(int const &), S &, int &>(0), "");

  static_assert(!test_explicit<int const &, void (S::*)(int const &), S &, int &>(0), "");

  static_assert(!test_explicit<int &&, void (S::*)(int const &), S &, int &>(0), "");
}

BOOST_AUTO_TEST_CASE(unary_member_function_with_xvalue)
{
  S s;

  static_assert(!test<void (S::*)(int &&), S &>(0), "");

  static_assert(!test<void (S::*)(int &&), S &, int, int>(0), "");

  {
    void (S::*pmf)(int &&) = &S::mf1x;

    ASSERT_SAME(cradle::invoke(pmf, s, std::move(gi)), void);
    static_assert(!noexcept(cradle::invoke(pmf, s, std::move(gi))), "");
    cradle::invoke(pmf, s, std::move(gi));

    ASSERT_SAME(cradle::invoke(cradle::as_const(pmf), s, std::move(gi)), void);
    static_assert(!noexcept(cradle::invoke(cradle::as_const(pmf), s, std::move(gi))), "");
    cradle::invoke(cradle::as_const(pmf), s, std::move(gi));
  }

  ASSERT_SAME(cradle::invoke(&S::mf1x, s, std::move(gi)), void);
  static_assert(!noexcept(cradle::invoke(&S::mf1x, s, std::move(gi))), "");
  cradle::invoke(&S::mf1x, s, std::move(gi));

  static_assert(!test<void (S::*)(int &&), S const &, int>(0), "");

  ASSERT_SAME(cradle::invoke(&S::mf1x, std::move(s), std::move(gi)), void);
  static_assert(!noexcept(cradle::invoke(&S::mf1x, std::move(s), std::move(gi))), "");
  cradle::invoke(&S::mf1x, std::move(s), std::move(gi));

  ASSERT_SAME(cradle::invoke(&S::mf1x, &s, std::move(gi)), void);
  static_assert(!noexcept(cradle::invoke(&S::mf1x, &s, std::move(gi))), "");
  cradle::invoke(&S::mf1x, &s, std::move(gi));

  static_assert(!test<void (S::*)(int &&), S const *, int>(0), "");

  {
    std::shared_ptr<S> p = std::make_shared<S>();

    ASSERT_SAME(cradle::invoke(&S::mf1x, p, std::move(gi)), void);
    static_assert(!noexcept(cradle::invoke(&S::mf1x, p, std::move(gi))), "");
    cradle::invoke(&S::mf1x, p, std::move(gi));
  }

  static_assert(!test<void (S::*)(int &&), std::shared_ptr<S const> &, int>(0), "");

  static_assert(!test<void (S::*)(int &&), S &, int &>(0), "");

  static_assert(!test<void (S::*)(int &&), S &, int const &>(0), "");

  ASSERT_SAME(cradle::invoke<void>(&S::mf1x, s, std::move(gi)), void);
  static_assert(!noexcept(cradle::invoke<void>(&S::mf1x, s, std::move(gi))), "");
  cradle::invoke<void>(&S::mf1x, s, std::move(gi));

  ASSERT_SAME(cradle::invoke<void const>(&S::mf1x, s, std::move(gi)), void);
  static_assert(!noexcept(cradle::invoke<void const>(&S::mf1x, s, std::move(gi))), "");
  cradle::invoke<void const>(&S::mf1x, s, std::move(gi));

  static_assert(!test_explicit<int, void (S::*)(int &&), S &, int>(0), "");

  static_assert(!test_explicit<int &, void (S::*)(int &&), S &, int>(0), "");

  static_assert(!test_explicit<int const &, void (S::*)(int &&), S &, int>(0), "");

  static_assert(!test_explicit<int &&, void (S::*)(int &&), S &, int>(0), "");
}

BOOST_AUTO_TEST_CASE(member_variable)
{
  S s;

  static_assert(!test<int S::*, S &, int>(0), "");

  {
    int S::*pmv = &S::mv;

    ASSERT_SAME(cradle::invoke(pmv, s), int &);
    static_assert(noexcept(cradle::invoke(pmv, s)), "");
    BOOST_CHECK_EQUAL(&cradle::invoke(pmv, s), &s.mv);

    ASSERT_SAME(cradle::invoke(cradle::as_const(pmv), s), int &);
    static_assert(noexcept(cradle::invoke(cradle::as_const(pmv), s)), "");
    BOOST_CHECK_EQUAL(&cradle::invoke(cradle::as_const(pmv), s), &s.mv);
  }

  ASSERT_SAME(cradle::invoke(&S::mv, s), int &);
  static_assert(noexcept(cradle::invoke(&S::mv, s)), "");
  BOOST_CHECK_EQUAL(&cradle::invoke(&S::mv, s), &s.mv);

  ASSERT_SAME(cradle::invoke(&S::mv, cradle::as_const(s)), int const &);
  static_assert(noexcept(cradle::invoke(&S::mv, cradle::as_const(s))), "");
  BOOST_CHECK_EQUAL(&cradle::invoke(&S::mv, cradle::as_const(s)), &s.mv);

  ASSERT_SAME(cradle::invoke(&S::mv, std::move(s)), int &&);
  static_assert(noexcept(cradle::invoke(&S::mv, std::move(s))), "");
  BOOST_CHECK_EQUAL(&static_cast<int const &>(cradle::invoke(&S::mv, std::move(s))), &s.mv);

  ASSERT_SAME(cradle::invoke(&S::mv, &s), int &);
  static_assert(noexcept(cradle::invoke(&S::mv, &s)), "");
  BOOST_CHECK_EQUAL(&cradle::invoke(&S::mv, &s), &s.mv);

  ASSERT_SAME(cradle::invoke(&S::mv, &cradle::as_const(s)), int const &);
  static_assert(noexcept(cradle::invoke(&S::mv, &cradle::as_const(s))), "");
  BOOST_CHECK_EQUAL(&cradle::invoke(&S::mv, &cradle::as_const(s)), &s.mv);

  {
    std::shared_ptr<S> p = std::make_shared<S>();

    ASSERT_SAME(cradle::invoke(&S::mv, p), int &);
    static_assert(noexcept(cradle::invoke(&S::mv, p)), "");
    BOOST_CHECK_EQUAL(&cradle::invoke(&S::mv, p), &p->mv);
  }

  {
    std::shared_ptr<S const> p = std::make_shared<S>();

    ASSERT_SAME(cradle::invoke(&S::mv, p), int const &);
    static_assert(noexcept(cradle::invoke(&S::mv, p)), "");
    BOOST_CHECK_EQUAL(&cradle::invoke(&S::mv, p), &p->mv);
  }

  ASSERT_SAME(cradle::invoke<int &>(&S::mv, s), int &);
  static_assert(noexcept(cradle::invoke<int &>(&S::mv, s)), "");
  BOOST_CHECK_EQUAL(&cradle::invoke<int &>(&S::mv, s), &s.mv);

  ASSERT_SAME(cradle::invoke<int const &>(&S::mv, s), int const &);
  static_assert(noexcept(cradle::invoke<int const &>(&S::mv, s)), "");
  BOOST_CHECK_EQUAL(&cradle::invoke<int const &>(&S::mv, s), &s.mv);

  ASSERT_SAME(cradle::invoke<int>(&S::mv, s), int);
  static_assert(noexcept(cradle::invoke<int>(&S::mv, s)), "");
  BOOST_CHECK_EQUAL(cradle::invoke<int>(&S::mv, s), s.mv);

  static_assert(!test_explicit<int &&, int S::*, S &>(0), "");

  ASSERT_SAME(cradle::invoke<void>(&S::mv, s), void);
  static_assert(noexcept(cradle::invoke<void>(&S::mv, s)), "");
  cradle::invoke<void>(&S::mv, s);

  ASSERT_SAME(cradle::invoke<void const>(&S::mv, s), void);
  static_assert(noexcept(cradle::invoke<void const>(&S::mv, s)), "");
  cradle::invoke<void const>(&S::mv, s);

  ASSERT_SAME(cradle::invoke<int &>(&S::mv, &s), int &);
  static_assert(noexcept(cradle::invoke<int &>(&S::mv, &s)), "");
  BOOST_CHECK_EQUAL(&cradle::invoke<int &>(&S::mv, &s), &s.mv);

  ASSERT_SAME(cradle::invoke<int const &>(&S::mv, &s), int const &);
  static_assert(noexcept(cradle::invoke<int const &>(&S::mv, &s)), "");
  BOOST_CHECK_EQUAL(&cradle::invoke<int const &>(&S::mv, &s), &s.mv);

  ASSERT_SAME(cradle::invoke<int>(&S::mv, &s), int);
  static_assert(noexcept(cradle::invoke<int>(&S::mv, &s)), "");
  BOOST_CHECK_EQUAL(cradle::invoke<int>(&S::mv, &s), s.mv);

  static_assert(!test_explicit<int &&, int S::*, S *>(0), "");

  ASSERT_SAME(cradle::invoke<void>(&S::mv, &s), void);
  static_assert(noexcept(cradle::invoke<void>(&S::mv, &s)), "");
  cradle::invoke<void>(&S::mv, &s);

  ASSERT_SAME(cradle::invoke<void const>(&S::mv, &s), void);
  static_assert(noexcept(cradle::invoke<void const>(&S::mv, &s)), "");
  cradle::invoke<void const>(&S::mv, &s);
}

BOOST_AUTO_TEST_CASE(const_member_variable)
{
  S s;

  static_assert(!test<int const S::*, S &, int>(0), "");

  {
    int const S::*pmv = &S::cmv;

    ASSERT_SAME(cradle::invoke(pmv, s), int const &);
    static_assert(noexcept(cradle::invoke(pmv, s)), "");
    BOOST_CHECK_EQUAL(&cradle::invoke(pmv, s), &s.cmv);

    ASSERT_SAME(cradle::invoke(cradle::as_const(pmv), s), int const &);
    static_assert(noexcept(cradle::invoke(cradle::as_const(pmv), s)), "");
    BOOST_CHECK_EQUAL(&cradle::invoke(cradle::as_const(pmv), s), &s.cmv);
  }

  ASSERT_SAME(cradle::invoke(&S::cmv, s), int const &);
  static_assert(noexcept(cradle::invoke(&S::cmv, s)), "");
  BOOST_CHECK_EQUAL(&cradle::invoke(&S::cmv, s), &s.cmv);

  ASSERT_SAME(cradle::invoke(&S::cmv, cradle::as_const(s)), int const &);
  static_assert(noexcept(cradle::invoke(&S::cmv, cradle::as_const(s))), "");
  BOOST_CHECK_EQUAL(&cradle::invoke(&S::cmv, cradle::as_const(s)), &s.cmv);

  ASSERT_SAME(cradle::invoke(&S::cmv, std::move(s)), int const &&);
  static_assert(noexcept(cradle::invoke(&S::cmv, std::move(s))), "");
  BOOST_CHECK_EQUAL(&static_cast<int const &>(cradle::invoke(&S::cmv, std::move(s))), &s.cmv);

  ASSERT_SAME(cradle::invoke(&S::cmv, &s), int const &);
  static_assert(noexcept(cradle::invoke(&S::cmv, &s)), "");
  BOOST_CHECK_EQUAL(&cradle::invoke(&S::cmv, &s), &s.cmv);

  ASSERT_SAME(cradle::invoke(&S::cmv, &cradle::as_const(s)), int const &);
  static_assert(noexcept(cradle::invoke(&S::cmv, &cradle::as_const(s))), "");
  BOOST_CHECK_EQUAL(&cradle::invoke(&S::cmv, &cradle::as_const(s)), &s.cmv);

  {
    std::shared_ptr<S> p = std::make_shared<S>();

    ASSERT_SAME(cradle::invoke(&S::cmv, p), int const &);
    static_assert(noexcept(cradle::invoke(&S::cmv, p)), "");
    BOOST_CHECK_EQUAL(&cradle::invoke(&S::cmv, p), &p->cmv);
  }

  {
    std::shared_ptr<S const> p = std::make_shared<S>();

    ASSERT_SAME(cradle::invoke(&S::cmv, p), int const &);
    static_assert(noexcept(cradle::invoke(&S::cmv, p)), "");
    BOOST_CHECK_EQUAL(&cradle::invoke(&S::cmv, p), &p->cmv);
  }

  ASSERT_SAME(cradle::invoke<int const &>(&S::cmv, s), int const &);
  static_assert(noexcept(cradle::invoke<int const &>(&S::cmv, s)), "");
  BOOST_CHECK_EQUAL(&cradle::invoke<int const &>(&S::cmv, s), &s.cmv);

  ASSERT_SAME(cradle::invoke<int>(&S::cmv, s), int);
  static_assert(noexcept(cradle::invoke<int>(&S::cmv, s)), "");
  BOOST_CHECK_EQUAL(cradle::invoke<int>(&S::cmv, s), s.cmv);

  static_assert(!test_explicit<int &, int const S::*, S &>(0), "");

  static_assert(!test_explicit<int &&, int const S::*, S &>(0), "");

  ASSERT_SAME(cradle::invoke<void>(&S::cmv, s), void);
  static_assert(noexcept(cradle::invoke<void>(&S::cmv, s)), "");
  cradle::invoke<void>(&S::cmv, s);

  ASSERT_SAME(cradle::invoke<void const>(&S::cmv, s), void);
  static_assert(noexcept(cradle::invoke<void const>(&S::cmv, s)), "");
  cradle::invoke<void const>(&S::cmv, s);

  ASSERT_SAME(cradle::invoke<int const &>(&S::cmv, &s), int const &);
  static_assert(noexcept(cradle::invoke<int const &>(&S::cmv, &s)), "");
  BOOST_CHECK_EQUAL(&cradle::invoke<int const &>(&S::cmv, &s), &s.cmv);

  ASSERT_SAME(cradle::invoke<int>(&S::cmv, &s), int);
  static_assert(noexcept(cradle::invoke<int>(&S::cmv, &s)), "");
  BOOST_CHECK_EQUAL(cradle::invoke<int>(&S::cmv, &s), s.cmv);

  static_assert(!test_explicit<int &, int const S::*, S *>(0), "");

  static_assert(!test_explicit<int &&, int const S::*, S *>(0), "");

  ASSERT_SAME(cradle::invoke<void>(&S::cmv, &s), void);
  static_assert(noexcept(cradle::invoke<void>(&S::cmv, &s)), "");
  cradle::invoke<void>(&S::cmv, &s);

  ASSERT_SAME(cradle::invoke<void const>(&S::cmv, &s), void);
  static_assert(noexcept(cradle::invoke<void const>(&S::cmv, &s)), "");
  cradle::invoke<void const>(&S::cmv, &s);
}

namespace{

int ntp() noexcept
{
  return 42;
}

int &ntl() noexcept
{
  return gi;
}

int const &ntcl() noexcept
{
  return gi;
}

int &&ntx() noexcept
{
  return static_cast<int &&>(gi);
}

} // namespace `unnamed'

BOOST_AUTO_TEST_CASE(nullary_function)
{
  ASSERT_SAME(cradle::invoke(&ntp), int);
  static_assert(noexcept(cradle::invoke(&ntp)), "");
  BOOST_CHECK_EQUAL(cradle::invoke(&ntp), 42);

  ASSERT_SAME(cradle::invoke<int>(&ntp), int);
  static_assert(noexcept(cradle::invoke<int>(&ntp)), "");
  BOOST_CHECK_EQUAL(cradle::invoke<int>(&ntp), 42);

  static_assert(!test_explicit<int &, int (*)() noexcept>(0), "");

  static_assert(!test_explicit<int const &, int (*)() noexcept>(0), "");

  static_assert(!test_explicit<int &&, int (*)() noexcept>(0), "");

  ASSERT_SAME(cradle::invoke<void>(&ntp), void);
  static_assert(noexcept(cradle::invoke<void>(&ntp)), "");
  cradle::invoke<void>(&ntp);

  ASSERT_SAME(cradle::invoke<void const>(&ntp), void);
  static_assert(noexcept(cradle::invoke<void const>(&ntp)), "");
  cradle::invoke<void const>(&ntp);


  ASSERT_SAME(cradle::invoke(&ntl), int &);
  static_assert(noexcept(cradle::invoke(&ntl)), "");
  BOOST_CHECK_EQUAL(&cradle::invoke(&ntl), &gi);

  ASSERT_SAME(cradle::invoke<int>(&ntl), int);
  static_assert(noexcept(cradle::invoke<int>(&ntl)), "");
  BOOST_CHECK_EQUAL(cradle::invoke<int>(&ntl), gi);

  ASSERT_SAME(cradle::invoke<int &>(&ntl), int &);
  static_assert(noexcept(cradle::invoke<int &>(&ntl)), "");
  BOOST_CHECK_EQUAL(&cradle::invoke<int &>(&ntl), &gi);

  ASSERT_SAME(cradle::invoke<int const &>(&ntl), int const &);
  static_assert(noexcept(cradle::invoke<int const &>(&ntl)), "");
  BOOST_CHECK_EQUAL(&cradle::invoke<int const &>(&ntl), &gi);

  static_assert(!test_explicit<int &&, int & (*)() noexcept>(0), "");

  ASSERT_SAME(cradle::invoke<void>(&ntl), void);
  static_assert(noexcept(cradle::invoke<void>(&ntl)), "");
  cradle::invoke<void>(&ntl);

  ASSERT_SAME(cradle::invoke<void const>(&ntl), void);
  static_assert(noexcept(cradle::invoke<void const>(&ntl)), "");
  cradle::invoke<void const>(&ntl);


  ASSERT_SAME(cradle::invoke(&ntcl), int const &);
  static_assert(noexcept(cradle::invoke(&ntcl)), "");
  BOOST_CHECK_EQUAL(&cradle::invoke(&ntcl), &gi);

  ASSERT_SAME(cradle::invoke<int>(&ntcl), int);
  static_assert(noexcept(cradle::invoke<int>(&ntcl)), "");
  BOOST_CHECK_EQUAL(cradle::invoke<int>(&ntcl), gi);

  static_assert(!test_explicit<int &, int const & (*)() noexcept>(0), "");

  ASSERT_SAME(cradle::invoke<int const &>(&ntcl), int const &);
  static_assert(noexcept(cradle::invoke<int const &>(&ntcl)), "");
  BOOST_CHECK_EQUAL(&cradle::invoke<int const &>(&ntcl), &gi);

  static_assert(!test_explicit<int &&, int const & (*)() noexcept>(0), "");

  ASSERT_SAME(cradle::invoke<void>(&ntcl), void);
  static_assert(noexcept(cradle::invoke<void>(&ntcl)), "");
  cradle::invoke<void>(&ntcl);

  ASSERT_SAME(cradle::invoke<void const>(&ntcl), void);
  static_assert(noexcept(cradle::invoke<void const>(&ntcl)), "");
  cradle::invoke<void const>(&ntcl);


  ASSERT_SAME(cradle::invoke(&ntx), int &&);
  static_assert(noexcept(cradle::invoke(&ntx)), "");
  BOOST_CHECK_EQUAL(&static_cast<int const &>(cradle::invoke(&ntx)), &gi);

  ASSERT_SAME(cradle::invoke<int>(&ntx), int);
  static_assert(noexcept(cradle::invoke<int>(&ntx)), "");
  BOOST_CHECK_EQUAL(cradle::invoke<int>(&ntx), gi);

  static_assert(!test_explicit<int &, int && (*)() noexcept>(0), "");

  ASSERT_SAME(cradle::invoke<int const &>(&ntx), int const &);
  static_assert(noexcept(cradle::invoke<int const &>(&ntx)), "");
  BOOST_CHECK_EQUAL(&cradle::invoke<int const &>(&ntx), &gi);

  ASSERT_SAME(cradle::invoke<int &&>(&ntx), int &&);
  static_assert(noexcept(cradle::invoke<int &&>(&ntx)), "");
  BOOST_CHECK_EQUAL(&static_cast<int const &>(cradle::invoke<int &&>(&ntx)), &gi);

  ASSERT_SAME(cradle::invoke<void>(&ntx), void);
  static_assert(noexcept(cradle::invoke<void>(&ntx)), "");
  cradle::invoke<void>(&ntx);

  ASSERT_SAME(cradle::invoke<void const>(&ntx), void);
  static_assert(noexcept(cradle::invoke<void const>(&ntx)), "");
  cradle::invoke<void const>(&ntx);
}

namespace{

void nt1v(std::unique_ptr<int>) noexcept
{
  gi += 1;
}

void nt1lr(std::unique_ptr<int> &) noexcept
{
  gi += 2;
}

void nt1clr(std::unique_ptr<int> const &) noexcept
{
  gi += 4;
}

void nt1rr(std::unique_ptr<int> &&) noexcept
{
  gi += 8;
}

}

BOOST_AUTO_TEST_CASE(unary_function_move_only)
{
  std::unique_ptr<int> p;

  ASSERT_SAME(cradle::invoke(&nt1v, nullptr), void);
  static_assert(noexcept(cradle::invoke(&nt1v, nullptr)), "");
  gi = 0;
  cradle::invoke(&nt1v, nullptr);
  BOOST_CHECK_EQUAL(gi, 1);

  static_assert(!test<void (*)(std::unique_ptr<int>), std::unique_ptr<int> &>(0), "");

  static_assert(!test<void (*)(std::unique_ptr<int>), std::unique_ptr<int> const &>(0), "");

  ASSERT_SAME(cradle::invoke(&nt1v, std::move(p)), void);
  static_assert(noexcept(cradle::invoke(&nt1v, std::move(p))), "");
  gi = 1;
  cradle::invoke(&nt1v, std::move(p));
  BOOST_CHECK_EQUAL(gi, 2);


  ASSERT_SAME(cradle::invoke(&nt1lr, p), void);
  static_assert(noexcept(cradle::invoke(&nt1lr, p)), "");
  gi = 2;
  cradle::invoke(&nt1lr, p);
  BOOST_CHECK_EQUAL(gi, 4);

  static_assert(!test<void (*)(std::unique_ptr<int> &), std::unique_ptr<int> &&>(0), "");

  static_assert(!test<void (*)(std::unique_ptr<int> &), std::unique_ptr<int> const &>(0), "");


  ASSERT_SAME(cradle::invoke(&nt1clr, p), void);
  static_assert(noexcept(cradle::invoke(&nt1clr, p)), "");
  gi = 3;
  cradle::invoke(&nt1clr, p);
  BOOST_CHECK_EQUAL(gi, 7);

  ASSERT_SAME(cradle::invoke(&nt1clr, cradle::as_const(p)), void);
  static_assert(noexcept(cradle::invoke(&nt1clr, cradle::as_const(p))), "");
  gi = 4;
  cradle::invoke(&nt1clr, cradle::as_const(p));
  BOOST_CHECK_EQUAL(gi, 8);

  ASSERT_SAME(cradle::invoke(&nt1clr, std::unique_ptr<int>()), void);
  static_assert(noexcept(cradle::invoke(&nt1clr, std::unique_ptr<int>())), "");
  gi = 5;
  cradle::invoke(&nt1clr, std::unique_ptr<int>());
  BOOST_CHECK_EQUAL(gi, 9);


  ASSERT_SAME(cradle::invoke(&nt1rr, std::unique_ptr<int>()), void);
  static_assert(noexcept(cradle::invoke(&nt1rr, std::unique_ptr<int>())), "");
  gi = 6;
  cradle::invoke(&nt1rr, std::unique_ptr<int>());
  BOOST_CHECK_EQUAL(gi, 14);

  static_assert(!test<void (*)(std::unique_ptr<int> &&) noexcept, std::unique_ptr<int> &>(0), "");

  static_assert(
    !test<void (*)(std::unique_ptr<int> &&) noexcept, std::unique_ptr<int> const &>(0), "");
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
