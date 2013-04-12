#include <cradle/type_traits/remove_rvalue_reference.hpp>

#include <type_traits>

#define ASSERT(TYPE_ID, EXPECTED_TYPE_ID)             \
static_assert(                                        \
  std::is_same<                                       \
    cradle::remove_rvalue_reference< TYPE_ID >::type, \
    EXPECTED_TYPE_ID >::value, "")                    \
/**/

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
