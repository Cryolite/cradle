#include <cradle/type_traits/remove_rvalue_reference.hpp>

#include <boost/test/unit_test.hpp>
#include <type_traits>


#define ASSERT(TYPE_ID, EXPECTED_TYPE_ID)             \
static_assert(                                        \
  std::is_same<                                       \
    cradle::remove_rvalue_reference< TYPE_ID >::type, \
    EXPECTED_TYPE_ID >::value, "")                    \
/**/

BOOST_AUTO_TEST_SUITE(type_traits)

BOOST_AUTO_TEST_SUITE(remove_rvalue_reference)

BOOST_AUTO_TEST_CASE(main)
{
  ASSERT(int, int);
  ASSERT(int const, int const);
  ASSERT(int[1], int[1]);
  ASSERT(int const[1], int const[1]);
  ASSERT(int &, int &);
  ASSERT(int const &, int const &);
  ASSERT(int const (&)[1], int const (&)[1]);
  ASSERT(int &&, int);
  ASSERT(int const &&, int const);
  ASSERT(int const (&&)[1], int const[1]);
  ASSERT(int(), int());
  ASSERT(int (&)(), int (&)());
  ASSERT(int (&&)(), int());
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
