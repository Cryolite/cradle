#if !defined(CRADLE_PREPROCESSOR_VA_DETAIL_SIZE_HPP_INCLUDE_GUARD)
#define CRADLE_PREPROCESSOR_VA_DETAIL_SIZE_HPP_INCLUDE_GUARD

#include <cradle/preprocessor/va/detail/heads.hpp>


#define CRADLE_PP_VA_DETAIL_SIZE_IMPL_E(            \
  P00, P01, P02, P03, P04, P05, P06, P07, P08, P09, \
  P10, P11, P12, P13, P14, P15, P16, P17, P18, P19, \
  P20, P21, P22, P23, P24, P25) P25                 \
/////////////////////////////////////////////////////

#define CRADLE_PP_VA_DETAIL_SIZE_IMPL_D(VA_TUPLE) \
CRADLE_PP_VA_DETAIL_SIZE_IMPL_E VA_TUPLE          \
///////////////////////////////////////////////////

#define CRADLE_PP_VA_DETAIL_SIZE_IMPL_C(...)   \
CRADLE_PP_VA_DETAIL_SIZE_IMPL_D((__VA_ARGS__)) \
////////////////////////////////////////////////

#define CRADLE_PP_VA_DETAIL_SIZE_IMPL_B(VA_TUPLE) \
CRADLE_PP_VA_DETAIL_SIZE_IMPL_C(                  \
  CRADLE_PP_VA_DETAIL_HEADS_IMPL_A_26 VA_TUPLE)   \
///////////////////////////////////////////////////

#define CRADLE_PP_VA_DETAIL_SIZE_IMPL_A(...)   \
CRADLE_PP_VA_DETAIL_SIZE_IMPL_B((__VA_ARGS__)) \
////////////////////////////////////////////////

#define CRADLE_PP_VA_DETAIL_SIZE(...)     \
CRADLE_PP_VA_DETAIL_SIZE_IMPL_A(          \
  __VA_ARGS__,                            \
  25, 24, 23, 22, 21,                     \
  20, 19, 18, 17, 16, 15, 14, 13, 12, 11, \
  10,  9,  8,  7,  6,  5,  4,  3,  2,  1) \
///////////////////////////////////////////


#endif // !defined(CRADLE_PREPROCESSOR_VA_DETAIL_SIZE_HPP_INCLUDE_GUARD)
