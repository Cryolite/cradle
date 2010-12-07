#if !defined(CRADLE_PREPROCESSOR_VA_SIZE_HPP_INCLUDE_GUARD)
#define CRADLE_PREPROCESSOR_VA_SIZE_HPP_INCLUDE_GUARD

#include <cradle/preprocessor/config.hpp>

#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/comparison/equal.hpp>
#include <boost/preprocessor/debug/assert.hpp>


BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_LIMIT_VA, 25))

#define CRADLE_PP_VA_SIZE_IMPL_3(                    \
  P0,P1,P2,P3,P4,P5,P6,P7,P8,P9,                     \
  P10,P11,P12,P13,P14,P15,P16,P17,P18,P19,           \
  P20,P21,P22,P23,P24,P25,P26,...) P26               \
  /**/

#define CRADLE_PP_VA_SIZE_IMPL_2(...) CRADLE_PP_VA_SIZE_IMPL_3(__VA_ARGS__)

#define CRADLE_PP_VA_SIZE_IMPL_1(HEAD, ...)            \
CRADLE_PP_VA_SIZE_IMPL_2(                              \
  BOOST_PP_CAT(CRADLE_PP_VA_SIZE_, HEAD), __VA_ARGS__) \
/**/

#define CRADLE_PP_VA_SIZE_IMPL_REVERSED_IOTA() \
0,25,24,23,22,21,20,                           \
19,18,17,16,15,14,13,12,11,10,                 \
9,8,7,6,5,4,3,2,1                              \
  /**/

#define CRADLE_PP_VA_SIZE_IMPL_NULLARY_DUMMY \
_,_,_,_,_,_,_,_,_,_,                         \
_,_,_,_,_,_,_,_,_,_,                         \
_,_,_,_,_,_                                  \
  /**/

#define CRADLE_PP_VA_SIZE_IMPL_0(...)                                        \
CRADLE_PP_VA_SIZE_IMPL_1(                                                    \
  IMPL_NULLARY_DUMMY ## __VA_ARGS__, CRADLE_PP_VA_SIZE_IMPL_REVERSED_IOTA()) \
  /**/

// In GCC, a macro invocation of a variadic macro could be weird when an
// argument is a macro invocation that produces texts with commas. In such
// situation, the number of arguments in __VA_ARGS__ is undercounted, and the
// invoked macro behaves as if the number of arguments passed were less than
// it is. By an indirect invocation like the following, the macro is invoked
// with the actual number of arguments.
#define CRADLE_PP_VA_SIZE(...) CRADLE_PP_VA_SIZE_IMPL_0(__VA_ARGS__)


#endif // !defined(CRADLE_PREPROCESSOR_VA_SIZE_HPP_INCLUDE_GUARD)
