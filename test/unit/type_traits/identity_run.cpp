#include <cradle/type_traits/identity.hpp>

#include <boost/test/unit_test.hpp>
#include <type_traits>


#define ASSERT_SAME(TYPE_ID)                                            \
static_assert(                                                          \
  std::is_same<cradle::identity< TYPE_ID >::type, TYPE_ID >::value, "") \
/**/

BOOST_AUTO_TEST_SUITE(type_traits)

BOOST_AUTO_TEST_SUITE(identity)

namespace{

struct S
{};

} // namespace `unnamed'

BOOST_AUTO_TEST_CASE(main)
{
  ASSERT_SAME(int);
  ASSERT_SAME(int const);
  ASSERT_SAME(void());
  ASSERT_SAME(int[]);
  ASSERT_SAME(int S::*);
  ASSERT_SAME(void (S::*)());
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
