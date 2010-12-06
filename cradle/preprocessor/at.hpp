#if !defined(CRADLE_PREPROCESSOR_AT_HPP_INCLUDE_GUARD)
#define CRADLE_PREPROCESSOR_AT_HPP_INCLUDE_GUARD

#include <cradle/preprocessor/arity.hpp>

#include <boost/preprocessor/arithmetic/sub.hpp>
#include <boost/preprocessor/comparison/less.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>
#include <boost/preprocessor/debug/assert.hpp>


#define CRADLE_PP_AT_IMPL_2(                         \
  P0,P1,P2,P3,P4,P5,P6,P7,P8,P9,                     \
  P10,P11,P12,P13,P14,P15,P16,P17,P18,P19,           \
  P20,P21,P22,P23,P24,P25,P26,P27,P28,P29,           \
  P30,P31,P32,P33,P34,P35,P36,P37,P38,P39,           \
  P40,P41,P42,P43,P44,P45,P46,P47,P48,P49,           \
  P50,P51,P52,P53,P54,P55,P56,P57,P58,P59,           \
  P60,P61,P62,P63,P64,P65,P66,P67,P68,P69,           \
  P70,P71,P72,P73,P74,P75,P76,P77,P78,P79,           \
  P80,P81,P82,P83,P84,P85,P86,P87,P88,P89,           \
  P90,P91,P92,P93,P94,P95,P96,P97,P98,P99,           \
  P100,P101,P102,P103,P104,P105,P106,P107,P108,P109, \
  P110,P111,P112,P113,P114,P115,P116,P117,P118,P119, \
  P120,P121,P122,P123,P124,P125,P126,...) P126       \
  /**/

#define CRADLE_PP_AT_IMPL_1(...) CRADLE_PP_AT_IMPL_2(__VA_ARGS__)

#define CRADLE_PP_AT_IMPL_HELPER(Z, INDEX, DATA) _,

#define CRADLE_PP_AT_IMPL_0(OFFSET, ...)                                              \
CRADLE_PP_AT_IMPL_1(BOOST_PP_REPEAT(OFFSET, CRADLE_PP_AT_IMPL_HELPER, _) __VA_ARGS__) \
  /**/

#define CRADLE_PP_AT(INDEX, ...)                                    \
BOOST_PP_ASSERT(BOOST_PP_LESS(INDEX, CRADLE_PP_ARITY(__VA_ARGS__))) \
CRADLE_PP_AT_IMPL_0(BOOST_PP_SUB(126, INDEX), __VA_ARGS__)          \
  /**/


#endif // !defined(CRADLE_PREPROCESSOR_AT_HPP_INCLUDE_GUARD)
