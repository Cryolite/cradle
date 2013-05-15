#define BOOST_TEST_MAIN
#include <cradle/utility/as_const.hpp>

#include <boost/test/unit_test.hpp>
#include <utility>
#include <type_traits>

#define ASSERT_SAME(EXPRESSION, TYPE_ID)                              \
static_assert(std::is_same<decltype(EXPRESSION), TYPE_ID>::value, "") \
/**/

BOOST_AUTO_TEST_CASE(testLvalue)
{
  int i = 42;
  ASSERT_SAME(cradle::as_const(i), int const &);
  static_assert(noexcept(cradle::as_const(i)), "");
  BOOST_CHECK_EQUAL(&cradle::as_const(i), &i);
}

BOOST_AUTO_TEST_CASE(testConstLvalue)
{
  int const i = 42;
  ASSERT_SAME(cradle::as_const(i), int const &);
  static_assert(noexcept(cradle::as_const(i)), "");
  BOOST_CHECK_EQUAL(&cradle::as_const(i), &i);
}

BOOST_AUTO_TEST_CASE(testXvalue)
{
  int i = 42;
  ASSERT_SAME(cradle::as_const(std::move(i)), int const &&);
  static_assert(noexcept(cradle::as_const(std::move(i))), "");
  BOOST_CHECK_EQUAL(cradle::as_const(std::move(i)), i);
}

BOOST_AUTO_TEST_CASE(testConstXvalue)
{
  int const i = 42;
  ASSERT_SAME(cradle::as_const(std::move(i)), int const &&);
  static_assert(noexcept(cradle::as_const(std::move(i))), "");
  BOOST_CHECK_EQUAL(cradle::as_const(std::move(i)), i);
}

BOOST_AUTO_TEST_CASE(testPrvalue)
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

}

BOOST_AUTO_TEST_CASE(testConstPrvalue)
{
  ASSERT_SAME(cradle::as_const(get()), int const &&);
  static_assert(noexcept(cradle::as_const(get())), "");
  BOOST_CHECK_EQUAL(cradle::as_const(get()), 42);
}
