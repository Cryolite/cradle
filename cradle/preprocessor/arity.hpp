#if !defined(CRADLE_PREPROCESSOR_ARITY_HPP_INCLUDE_GUARD)
#define CRADLE_PREPROCESSOR_ARITY_HPP_INCLUDE_GUARD

#include <boost/preprocessor/cat.hpp>

#define CRADLE_PP_ARITY_IMPL_HELPER(                 \
  A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,                     \
  A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,           \
  A20,A21,A22,A23,A24,A25,A26,A27,A28,A29,           \
  A30,A31,A32,A33,A34,A35,A36,A37,A38,A39,           \
  A40,A41,A42,A43,A44,A45,A46,A47,A48,A49,           \
  A50,A51,A52,A53,A54,A55,A56,A57,A58,A59,           \
  A60,A61,A62,A63,A64,A65,A66,A67,A68,A69,           \
  A70,A71,A72,A73,A74,A75,A76,A77,A78,A79,           \
  A80,A81,A82,A83,A84,A85,A86,A87,A88,A89,           \
  A90,A91,A92,A93,A94,A95,A96,A97,A98,A99,           \
  A100,A101,A102,A103,A104,A105,A106,A107,A108,A109, \
  A110,A111,A112,A113,A114,A115,A116,A117,A118,A119, \
  A120,A121,A122,A123,A124,A125,A126,A127,           \
  N,...) N                                           \
  /**/

#define CRADLE_PP_ARITY_IMPL_B(...) CRADLE_PP_ARITY_IMPL_HELPER(__VA_ARGS__)

#define CRADLE_PP_ARITY_IMPL_A(HEAD, ...)                                 \
CRADLE_PP_ARITY_IMPL_B(BOOST_PP_CAT(CRADLE_PP_ARITY_, HEAD), __VA_ARGS__) \
/**/

#define CRADLE_PP_ARITY_IMPL_REVERSED_IOTA() \
0,127,126,125,124,123,122,121,               \
120,119,118,117,116,115,114,113,112,111,     \
110,109,108,107,106,105,104,103,102,101,     \
100,99,98,97,96,95,94,93,92,91,              \
90,89,88,87,86,85,84,83,82,81,               \
80,79,78,77,76,75,74,73,72,71,               \
70,69,68,67,66,65,64,63,62,61,               \
60,59,58,57,56,55,54,53,52,51,               \
50,49,48,47,46,45,44,43,42,41,               \
40,39,38,37,36,35,34,33,32,31,               \
30,29,28,27,26,25,24,23,22,21,               \
20,19,18,17,16,15,14,13,12,11,               \
10,9,8,7,6,5,4,3,2,1                         \
  /**/

#define CRADLE_PP_ARITY_IMPL_NULLARY_DUMMY \
_,_,_,_,_,_,_,_,_,_,                       \
_,_,_,_,_,_,_,_,_,_,                       \
_,_,_,_,_,_,_,_,_,_,                       \
_,_,_,_,_,_,_,_,_,_,                       \
_,_,_,_,_,_,_,_,_,_,                       \
_,_,_,_,_,_,_,_,_,_,                       \
_,_,_,_,_,_,_,_,_,_,                       \
_,_,_,_,_,_,_,_,_,_,                       \
_,_,_,_,_,_,_,_,_,_,                       \
_,_,_,_,_,_,_,_,_,_,                       \
_,_,_,_,_,_,_,_,_,_,                       \
_,_,_,_,_,_,_,_,_,_,                       \
_,_,_,_,_,_,_,_                            \
  /**/

#define CRADLE_PP_ARITY(...)                                 \
CRADLE_PP_ARITY_IMPL_A(IMPL_NULLARY_DUMMY ## __VA_ARGS__,    \
                       CRADLE_PP_ARITY_IMPL_REVERSED_IOTA()) \
  /**/

#endif // !defined(CRADLE_PREPROCESSOR_ARITY_HPP_INCLUDE_GUARD)
