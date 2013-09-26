#include <cradle/container/index_facade.hpp>

#include <cradle/utility/as_const.hpp>

#include <boost/test/unit_test.hpp>

#include <cstddef>
#include <limits>


BOOST_AUTO_TEST_SUITE(container)

BOOST_AUTO_TEST_SUITE(index_facade)

namespace{

namespace detail_{

template<typename T, typename U, typename = decltype(std::declval<T const &>() == std::declval<U const &>())>
constexpr bool has_equal_to_test_(int) noexcept
{
  return true;
}

template<typename T, typename U>
constexpr bool has_equal_to_test_(bool) noexcept
{
  return false;
}

} // namespace detail_

template<typename T, typename U = T>
constexpr bool has_equal_to() noexcept
{
  return detail_::has_equal_to_test_<T, U>(0);
}

namespace detail_{

template<typename T, typename U, typename = decltype(std::declval<T const &>() != std::declval<U const &>())>
constexpr bool has_not_equal_to_test_(int) noexcept
{
  return true;
}

template<typename T, typename U>
constexpr bool has_not_equal_to_test_(bool) noexcept
{
  return false;
}

} // namespace detail_

template<typename T, typename U = T>
constexpr bool has_not_equal_to() noexcept
{
  return detail_::has_not_equal_to_test_<T, U>(0);
}

namespace detail_{

template<typename T, typename U, typename = decltype(std::declval<T const &>() < std::declval<U const &>())>
constexpr bool has_less_than_test_(int) noexcept
{
  return true;
}

template<typename T, typename U>
constexpr bool has_less_than_test_(bool) noexcept
{
  return false;
}

} // namespace detail_

template<typename T, typename U = T>
constexpr bool has_less_than() noexcept
{
  return detail_::has_less_than_test_<T, U>(0);
}

namespace detail_{

template<typename T, typename U, typename = decltype(std::declval<T const &>() > std::declval<U const &>())>
constexpr bool has_greater_than_test_(int) noexcept
{
  return true;
}

template<typename T, typename U>
constexpr bool has_greater_than_test_(bool) noexcept
{
  return false;
}

} // namespace detail_

template<typename T, typename U = T>
constexpr bool has_greater_than() noexcept
{
  return detail_::has_greater_than_test_<T, U>(0);
}

namespace detail_{

template<typename T, typename U, typename = decltype(std::declval<T const &>() <= std::declval<U const &>())>
constexpr bool has_less_than_equal_test_(int) noexcept
{
  return true;
}

template<typename T, typename U>
constexpr bool has_less_than_equal_test_(bool) noexcept
{
  return false;
}

} // namespace detail_

template<typename T, typename U = T>
constexpr bool has_less_than_equal() noexcept
{
  return detail_::has_less_than_equal_test_<T, U>(0);
}

namespace detail_{

template<typename T, typename U, typename = decltype(std::declval<T const &>() >= std::declval<U const &>())>
constexpr bool has_greater_than_equal_test_(int) noexcept
{
  return true;
}

template<typename T, typename U>
constexpr bool has_greater_than_equal_test_(bool) noexcept
{
  return false;
}

} // namespace detail_

template<typename T, typename U = T>
constexpr bool has_greater_than_equal() noexcept
{
  return detail_::has_greater_than_equal_test_<T, U>(0);
}

namespace detail_{

template<typename T, typename = decltype(std::declval<T const &>().is_null())>
constexpr bool has_is_null_test_(int) noexcept
{
  return true;
}

template<typename T>
constexpr bool has_is_null_test_(bool) noexcept
{
  return false;
}

} // namespace detail_

template<typename T>
constexpr bool has_is_null() noexcept
{
  return detail_::has_is_null_test_<T>(0);
}

} // namespace *unnamed*

BOOST_AUTO_TEST_SUITE(equality_comparable_index)

namespace{

class equality_comparable_index
  : public cradle::index_facade<equality_comparable_index>
{
private:
  friend class cradle::index_core_access;

public:
  constexpr equality_comparable_index() noexcept
    : i_(std::numeric_limits<std::size_t>::max())
  {}

  constexpr explicit equality_comparable_index(std::size_t i) noexcept
    : i_(i)
  {}

private:
  constexpr bool is_equal_to_(equality_comparable_index const &x) const noexcept
  {
    return i_ == x.i_;
  }

private:
  std::size_t i_;
}; // class equality_comparable_index

} // namespace *unnamed*

BOOST_AUTO_TEST_CASE(null)
{
  {
    equality_comparable_index i;
    BOOST_CHECK((noexcept(i.is_null())));
    BOOST_CHECK((i.is_null()));
    BOOST_CHECK((noexcept(cradle::as_const(i).is_null())));
    BOOST_CHECK((cradle::as_const(i).is_null()));
  }
  BOOST_CHECK((noexcept(equality_comparable_index().is_null())));
  BOOST_CHECK((equality_comparable_index().is_null()));
  static_assert(equality_comparable_index().is_null(), "");
  {
    equality_comparable_index i(0);
    BOOST_CHECK((!i.is_null()));
    BOOST_CHECK((!cradle::as_const(i).is_null()));
  }
  BOOST_CHECK((!equality_comparable_index(0).is_null()));
  static_assert(!equality_comparable_index(0).is_null(), "");
}

BOOST_AUTO_TEST_CASE(equality_comparison)
{
  {
    equality_comparable_index i;

    BOOST_CHECK((noexcept(i == i)));
    BOOST_CHECK((i == i));
    BOOST_CHECK((noexcept(i == cradle::as_const(i))));
    BOOST_CHECK((i == cradle::as_const(i)));
    BOOST_CHECK((noexcept(i == equality_comparable_index())));
    BOOST_CHECK((i == equality_comparable_index()));
    BOOST_CHECK((noexcept(cradle::as_const(i) == i)));
    BOOST_CHECK((cradle::as_const(i) == i));
    BOOST_CHECK((noexcept(cradle::as_const(i) == cradle::as_const(i))));
    BOOST_CHECK((cradle::as_const(i) == cradle::as_const(i)));
    BOOST_CHECK((noexcept(cradle::as_const(i) == equality_comparable_index())));
    BOOST_CHECK((cradle::as_const(i) == equality_comparable_index()));
    BOOST_CHECK((noexcept(equality_comparable_index() == i)));
    BOOST_CHECK((equality_comparable_index() == i));
    BOOST_CHECK((noexcept(equality_comparable_index() == cradle::as_const(i))));
    BOOST_CHECK((equality_comparable_index() == cradle::as_const(i)));
    BOOST_CHECK((noexcept(equality_comparable_index() == equality_comparable_index())));
    BOOST_CHECK((equality_comparable_index() == equality_comparable_index()));
    static_assert(equality_comparable_index() == equality_comparable_index(), "");

    BOOST_CHECK((noexcept(i != i)));
    BOOST_CHECK((!(i != i)));
    BOOST_CHECK((noexcept(i != cradle::as_const(i))));
    BOOST_CHECK((!(i != cradle::as_const(i))));
    BOOST_CHECK((noexcept(i != equality_comparable_index())));
    BOOST_CHECK((!(i != equality_comparable_index())));
    BOOST_CHECK((noexcept(cradle::as_const(i) != i)));
    BOOST_CHECK((!(cradle::as_const(i) != i)));
    BOOST_CHECK((noexcept(cradle::as_const(i) != cradle::as_const(i))));
    BOOST_CHECK((!(cradle::as_const(i) != cradle::as_const(i))));
    BOOST_CHECK((noexcept(cradle::as_const(i) != equality_comparable_index())));
    BOOST_CHECK((!(cradle::as_const(i) != equality_comparable_index())));
    BOOST_CHECK((noexcept(equality_comparable_index() != i)));
    BOOST_CHECK((!(equality_comparable_index() != i)));
    BOOST_CHECK((noexcept(equality_comparable_index() != cradle::as_const(i))));
    BOOST_CHECK((!(equality_comparable_index() != cradle::as_const(i))));
    BOOST_CHECK((noexcept(equality_comparable_index() != equality_comparable_index())));
    BOOST_CHECK((!(equality_comparable_index() != equality_comparable_index())));
    static_assert(!(equality_comparable_index() != equality_comparable_index()), "");
  }
}

BOOST_AUTO_TEST_CASE(total_order)
{
  BOOST_CHECK((!has_less_than<equality_comparable_index>()));
  BOOST_CHECK((!has_greater_than<equality_comparable_index>()));
  BOOST_CHECK((!has_less_than_equal<equality_comparable_index>()));
  BOOST_CHECK((!has_greater_than_equal<equality_comparable_index>()));
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(less_than_comparable_index)

namespace{

class less_than_comparable_index
  : public cradle::index_facade<less_than_comparable_index>
{
private:
  friend class cradle::index_core_access;

public:
  constexpr less_than_comparable_index() noexcept
    : i_(std::numeric_limits<std::size_t>::max())
  {}

  constexpr explicit less_than_comparable_index(std::size_t i) noexcept
    : i_(i)
  {}

private:
  constexpr bool is_less_than_(less_than_comparable_index const &x) const noexcept
  {
    return i_ < x.i_;
  }

private:
  std::size_t i_;
}; // class less_than_comparable_index

} // namespace *unnamed*

BOOST_AUTO_TEST_CASE(null)
{
  BOOST_CHECK((!has_is_null<less_than_comparable_index>()));
}

BOOST_AUTO_TEST_CASE(equality_comparison)
{
  BOOST_CHECK((!has_equal_to<less_than_comparable_index>()));
  BOOST_CHECK((!has_not_equal_to<less_than_comparable_index>()));
}

BOOST_AUTO_TEST_CASE(total_order)
{
  BOOST_CHECK((!has_less_than<less_than_comparable_index>()));
  BOOST_CHECK((!has_greater_than<less_than_comparable_index>()));
  BOOST_CHECK((!has_less_than_equal<less_than_comparable_index>()));
  BOOST_CHECK((!has_greater_than_equal<less_than_comparable_index>()));
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(totally_orderable_index)

namespace {

class totally_orderable_index
  : public cradle::index_facade<totally_orderable_index>
{
private:
  friend class cradle::index_core_access;

public:
  constexpr totally_orderable_index() noexcept
    : i_(std::numeric_limits<std::size_t>::max())
  {}

  constexpr explicit totally_orderable_index(std::size_t i) noexcept
    : i_(i)
  {}

private:
  constexpr bool is_equal_to_(totally_orderable_index const &x) const noexcept
  {
    return i_ == x.i_;
  }

  constexpr bool is_less_than_(totally_orderable_index const &x) const noexcept
  {
    return i_ < x.i_;
  }

private:
  std::size_t i_;
}; // class totally_orderable_index

} // namespace *unnamed

BOOST_AUTO_TEST_CASE(null)
{
  {
    totally_orderable_index i;
    BOOST_CHECK((noexcept(i.is_null())));
    BOOST_CHECK((i.is_null()));
    BOOST_CHECK((noexcept(cradle::as_const(i).is_null())));
    BOOST_CHECK((cradle::as_const(i).is_null()));
  }
  BOOST_CHECK((noexcept(totally_orderable_index().is_null())));
  BOOST_CHECK((totally_orderable_index().is_null()));
  static_assert(totally_orderable_index().is_null(), "");
  {
    totally_orderable_index i(0);
    BOOST_CHECK((!i.is_null()));
    BOOST_CHECK((!cradle::as_const(i).is_null()));
  }
  BOOST_CHECK((!totally_orderable_index(0).is_null()));
  static_assert(!totally_orderable_index(0).is_null(), "");
}

BOOST_AUTO_TEST_CASE(equality_comparison)
{
  totally_orderable_index i;

  BOOST_CHECK((noexcept(i == i)));
  BOOST_CHECK((i == i));
  BOOST_CHECK((noexcept(i == cradle::as_const(i))));
  BOOST_CHECK((i == cradle::as_const(i)));
  BOOST_CHECK((noexcept(i == totally_orderable_index())));
  BOOST_CHECK((i == totally_orderable_index()));
  BOOST_CHECK((noexcept(cradle::as_const(i) == i)));
  BOOST_CHECK((cradle::as_const(i) == i));
  BOOST_CHECK((noexcept(cradle::as_const(i) == cradle::as_const(i))));
  BOOST_CHECK((cradle::as_const(i) == cradle::as_const(i)));
  BOOST_CHECK((noexcept(cradle::as_const(i) == totally_orderable_index())));
  BOOST_CHECK((cradle::as_const(i) == totally_orderable_index()));
  BOOST_CHECK((noexcept(totally_orderable_index() == i)));
  BOOST_CHECK((totally_orderable_index() == i));
  BOOST_CHECK((noexcept(totally_orderable_index() == cradle::as_const(i))));
  BOOST_CHECK((totally_orderable_index() == cradle::as_const(i)));
  BOOST_CHECK((noexcept(totally_orderable_index() == totally_orderable_index())));
  BOOST_CHECK((totally_orderable_index() == totally_orderable_index()));
  static_assert(totally_orderable_index() == totally_orderable_index(), "");

  BOOST_CHECK((noexcept(i != i)));
  BOOST_CHECK((!(i != i)));
  BOOST_CHECK((noexcept(i != cradle::as_const(i))));
  BOOST_CHECK((!(i != cradle::as_const(i))));
  BOOST_CHECK((noexcept(i != totally_orderable_index())));
  BOOST_CHECK((!(i != totally_orderable_index())));
  BOOST_CHECK((noexcept(cradle::as_const(i) != i)));
  BOOST_CHECK((!(cradle::as_const(i) != i)));
  BOOST_CHECK((noexcept(cradle::as_const(i) != cradle::as_const(i))));
  BOOST_CHECK((!(cradle::as_const(i) != cradle::as_const(i))));
  BOOST_CHECK((noexcept(cradle::as_const(i) != totally_orderable_index())));
  BOOST_CHECK((!(cradle::as_const(i) != totally_orderable_index())));
  BOOST_CHECK((noexcept(totally_orderable_index() != i)));
  BOOST_CHECK((!(totally_orderable_index() != i)));
  BOOST_CHECK((noexcept(totally_orderable_index() != cradle::as_const(i))));
  BOOST_CHECK((!(totally_orderable_index() != cradle::as_const(i))));
  BOOST_CHECK((noexcept(totally_orderable_index() != totally_orderable_index())));
  BOOST_CHECK((!(totally_orderable_index() != totally_orderable_index())));
  static_assert(!(totally_orderable_index() != totally_orderable_index()), "");
}

BOOST_AUTO_TEST_CASE(total_order)
{
  totally_orderable_index i;

  BOOST_CHECK((noexcept(i < i)));
  BOOST_CHECK((!(i < i)));
  BOOST_CHECK((noexcept(i < cradle::as_const(i))));
  BOOST_CHECK((!(i < cradle::as_const(i))));
  BOOST_CHECK((noexcept(i < totally_orderable_index())));
  BOOST_CHECK((!(i < totally_orderable_index())));
  BOOST_CHECK((noexcept(cradle::as_const(i) < i)));
  BOOST_CHECK((!(cradle::as_const(i) < i)));
  BOOST_CHECK((noexcept(cradle::as_const(i) < cradle::as_const(i))));
  BOOST_CHECK((!(cradle::as_const(i) < cradle::as_const(i))));
  BOOST_CHECK((noexcept(cradle::as_const(i) < totally_orderable_index())));
  BOOST_CHECK((!(cradle::as_const(i) < totally_orderable_index())));
  BOOST_CHECK((noexcept(totally_orderable_index() < i)));
  BOOST_CHECK((!(totally_orderable_index() < i)));
  BOOST_CHECK((noexcept(totally_orderable_index() < cradle::as_const(i))));
  BOOST_CHECK((!(totally_orderable_index() < cradle::as_const(i))));
  BOOST_CHECK((noexcept(totally_orderable_index() < totally_orderable_index())));
  BOOST_CHECK((!(totally_orderable_index() < totally_orderable_index())));
  static_assert(!(totally_orderable_index() < totally_orderable_index()), "");
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
