#if !defined(CRADLE_PREPROCESSOR_VA_DETAIL_SIZE_HPP_INCLUDE_GUARD)
#define CRADLE_PREPROCESSOR_VA_DETAIL_SIZE_HPP_INCLUDE_GUARD

#include <cradle/preprocessor/va/detail/heads.hpp>


#define CRADLE_PP_VA_SIZE_IMPL_B(                   \
  P00, P01, P02, P03, P04, P05, P06, P07, P08, P09, \
  P10, P11, P12, P13, P14, P15, P16, P17, P18, P19, \
  P20, P21, P22, P23, P24, P25) P25                 \
/////////////////////////////////////////////////////

#define CRADLE_PP_VA_SIZE_IMPL_A(TUPLE_26) CRADLE_PP_VA_SIZE_IMPL_B TUPLE_26

#define CRADLE_PP_VA_SIZE_IMPL(...)            \
CRADLE_PP_VA_SIZE_IMPL_A(                      \
  (CRADLE_PP_VA_HEADS_IMPL(                    \
     26,                                       \
     __VA_ARGS__,                              \
     25, 24, 23, 22, 21,                       \
     20, 19, 18, 17, 16, 15, 14, 13, 12, 11,   \
     10,  9,  8,  7,  6,  5,  4,  3,  2,  1))) \
////////////////////////////////////////////////


#endif // !defined(CRADLE_PREPROCESSOR_VA_DETAIL_SIZE_HPP_INCLUDE_GUARD)
