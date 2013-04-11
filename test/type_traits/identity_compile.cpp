#include <cradle/type_traits/identity.hpp>

#include <type_traits>

#define ASSERT_SAME(TYPE_ID)                                            \
static_assert(                                                          \
  std::is_same<cradle::identity< TYPE_ID >::type, TYPE_ID >::value, "") \
/**/

struct S
{};

ASSERT_SAME(int);
ASSERT_SAME(int const);
ASSERT_SAME(void());
ASSERT_SAME(int[]);
ASSERT_SAME(int S::*);
ASSERT_SAME(void (S::*)());
