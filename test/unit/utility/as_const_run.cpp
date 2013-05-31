#include <cradle/utility/as_const.hpp>

#include <boost/test/unit_test.hpp>
#include <type_traits>
#include <utility>


#define ASSERT_SAME(EXPRESSION, TYPE_ID)                              \
static_assert(std::is_same<decltype(EXPRESSION), TYPE_ID>::value, "") \
/**/

BOOST_AUTO_TEST_SUITE(utility)

BOOST_AUTO_TEST_SUITE(as_const)

BOOST_AUTO_TEST_CASE(lvalue)
{
  int i = 42;
  ASSERT_SAME(cradle::as_const(i), int const &);
  static_assert(noexcept(cradle::as_const(i)), "");
  BOOST_CHECK_EQUAL(&cradle::as_const(i), &i);
}

BOOST_AUTO_TEST_CASE(const_lvalue)
{
  int const i = 42;
  ASSERT_SAME(cradle::as_const(i), int const &);
  static_assert(noexcept(cradle::as_const(i)), "");
  BOOST_CHECK_EQUAL(&cradle::as_const(i), &i);
}

BOOST_AUTO_TEST_CASE(xvalue)
{
  int i = 42;
  ASSERT_SAME(cradle::as_const(std::move(i)), int const &&);
  static_assert(noexcept(cradle::as_const(std::move(i))), "");
  BOOST_CHECK_EQUAL(cradle::as_const(std::move(i)), i);
}

BOOST_AUTO_TEST_CASE(const_xvalue)
{
  int const i = 42;
  ASSERT_SAME(cradle::as_const(std::move(i)), int const &&);
  static_assert(noexcept(cradle::as_const(std::move(i))), "");
  BOOST_CHECK_EQUAL(cradle::as_const(std::move(i)), i);
}

BOOST_AUTO_TEST_CASE(prvalue)
{
  ASSERT_SAME(cradle::as_const(42), int const &&);
  static_assert(noexcept(cradle::as_const(42)), "");
  BOOST_CHECK_EQUAL(cradle::as_const(42), 42);
}

namespace{

int const get() noexcept
{
  return 42;
}

} // namespace `unnamed'

BOOST_AUTO_TEST_CASE(const_prvalue)
{
  ASSERT_SAME(cradle::as_const(get()), int const &&);
  static_assert(noexcept(cradle::as_const(get())), "");
  BOOST_CHECK_EQUAL(cradle::as_const(get()), 42);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
