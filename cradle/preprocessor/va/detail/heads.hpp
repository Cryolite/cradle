#if !defined(CRADLE_PREPROCESSOR_VA_DETAIL_HEADS_HPP_INCLUDE_GUARD)
#define CRADLE_PREPROCESSOR_VA_DETAIL_HEADS_HPP_INCLUDE_GUARD

#include <cradle/preprocessor/va/detail/tuple_head.hpp>

#include <boost/preprocessor/cat.hpp>


#define CRADLE_PP_VA_HEADS_IMPL_1( \
  P00, P01, ...)                   \
P01                                \
////////////////////////////////////

#define CRADLE_PP_VA_HEADS_IMPL_2( \
  P00, P01, P02, ...)              \
P01, P02                           \
////////////////////////////////////

#define CRADLE_PP_VA_HEADS_IMPL_3( \
  P00, P01, P02, P03, ...)         \
P01, P02, P03                      \
////////////////////////////////////

#define CRADLE_PP_VA_HEADS_IMPL_4( \
  P00, P01, P02, P03, P04, ...)    \
P01, P02, P03, P04                 \
////////////////////////////////////

#define CRADLE_PP_VA_HEADS_IMPL_5(   \
  P00, P01, P02, P03, P04, P05, ...) \
P01, P02, P03, P04, P05              \
//////////////////////////////////////

#define CRADLE_PP_VA_HEADS_IMPL_6(        \
  P00, P01, P02, P03, P04, P05, P06, ...) \
P01, P02, P03, P04, P05, P06              \
///////////////////////////////////////////

#define CRADLE_PP_VA_HEADS_IMPL_7(             \
  P00, P01, P02, P03, P04, P05, P06, P07, ...) \
P01, P02, P03, P04, P05, P06, P07              \
////////////////////////////////////////////////

#define CRADLE_PP_VA_HEADS_IMPL_8(                  \
  P00, P01, P02, P03, P04, P05, P06, P07, P08, ...) \
P01, P02, P03, P04, P05, P06, P07, P08              \
/////////////////////////////////////////////////////

#define CRADLE_PP_VA_HEADS_IMPL_9(                  \
  P00, P01, P02, P03, P04, P05, P06, P07, P08, P09, \
  ...)                                              \
P01, P02, P03, P04, P05, P06, P07, P08, P09         \
/////////////////////////////////////////////////////

#define CRADLE_PP_VA_HEADS_IMPL_10(                 \
  P00, P01, P02, P03, P04, P05, P06, P07, P08, P09, \
  P10, ...)                                         \
P01, P02, P03, P04, P05, P06, P07, P08, P09, P10    \
/////////////////////////////////////////////////////

#define CRADLE_PP_VA_HEADS_IMPL_11(                 \
  P00, P01, P02, P03, P04, P05, P06, P07, P08, P09, \
  P10, P11, ...)                                    \
P01, P02, P03, P04, P05, P06, P07, P08, P09, P10,   \
P11                                                 \
/////////////////////////////////////////////////////

#define CRADLE_PP_VA_HEADS_IMPL_12(                 \
  P00, P01, P02, P03, P04, P05, P06, P07, P08, P09, \
  P10, P11, P12, ...)                               \
P01, P02, P03, P04, P05, P06, P07, P08, P09, P10,   \
P11, P12                                            \
/////////////////////////////////////////////////////

#define CRADLE_PP_VA_HEADS_IMPL_13(                 \
  P00, P01, P02, P03, P04, P05, P06, P07, P08, P09, \
  P10, P11, P12, P13, ...)                          \
P01, P02, P03, P04, P05, P06, P07, P08, P09, P10,   \
P11, P12, P13                                       \
/////////////////////////////////////////////////////

#define CRADLE_PP_VA_HEADS_IMPL_14(                 \
  P00, P01, P02, P03, P04, P05, P06, P07, P08, P09, \
  P10, P11, P12, P13, P14, ...)                     \
P01, P02, P03, P04, P05, P06, P07, P08, P09, P10,   \
P11, P12, P13, P14                                  \
/////////////////////////////////////////////////////

#define CRADLE_PP_VA_HEADS_IMPL_15(                 \
  P00, P01, P02, P03, P04, P05, P06, P07, P08, P09, \
  P10, P11, P12, P13, P14, P15, ...)                \
P01, P02, P03, P04, P05, P06, P07, P08, P09, P10,   \
P11, P12, P13, P14, P15                             \
/////////////////////////////////////////////////////

#define CRADLE_PP_VA_HEADS_IMPL_16(                 \
  P00, P01, P02, P03, P04, P05, P06, P07, P08, P09, \
  P10, P11, P12, P13, P14, P15, P16, ...)           \
P01, P02, P03, P04, P05, P06, P07, P08, P09, P10,   \
P11, P12, P13, P14, P15, P16                        \
/////////////////////////////////////////////////////

#define CRADLE_PP_VA_HEADS_IMPL_17(                 \
  P00, P01, P02, P03, P04, P05, P06, P07, P08, P09, \
  P10, P11, P12, P13, P14, P15, P16, P17, ...)      \
P01, P02, P03, P04, P05, P06, P07, P08, P09, P10,   \
P11, P12, P13, P14, P15, P16, P17                   \
/////////////////////////////////////////////////////

#define CRADLE_PP_VA_HEADS_IMPL_18(                 \
  P00, P01, P02, P03, P04, P05, P06, P07, P08, P09, \
  P10, P11, P12, P13, P14, P15, P16, P17, P18, ...) \
P01, P02, P03, P04, P05, P06, P07, P08, P09, P10,   \
P11, P12, P13, P14, P15, P16, P17, P18              \
/////////////////////////////////////////////////////

#define CRADLE_PP_VA_HEADS_IMPL_19(                 \
  P00, P01, P02, P03, P04, P05, P06, P07, P08, P09, \
  P10, P11, P12, P13, P14, P15, P16, P17, P18, P19, \
  ...)                                              \
P01, P02, P03, P04, P05, P06, P07, P08, P09, P10,   \
P11, P12, P13, P14, P15, P16, P17, P18, P19         \
/////////////////////////////////////////////////////

#define CRADLE_PP_VA_HEADS_IMPL_20(                 \
  P00, P01, P02, P03, P04, P05, P06, P07, P08, P09, \
  P10, P11, P12, P13, P14, P15, P16, P17, P18, P19, \
  P20, ...)                                         \
P01, P02, P03, P04, P05, P06, P07, P08, P09, P10,   \
P11, P12, P13, P14, P15, P16, P17, P18, P19, P20    \
/////////////////////////////////////////////////////

#define CRADLE_PP_VA_HEADS_IMPL_21(                 \
  P00, P01, P02, P03, P04, P05, P06, P07, P08, P09, \
  P10, P11, P12, P13, P14, P15, P16, P17, P18, P19, \
  P20, P21, ...)                                    \
P01, P02, P03, P04, P05, P06, P07, P08, P09, P10,   \
P11, P12, P13, P14, P15, P16, P17, P18, P19, P20,   \
P21                                                 \
/////////////////////////////////////////////////////

#define CRADLE_PP_VA_HEADS_IMPL_22(                 \
  P00, P01, P02, P03, P04, P05, P06, P07, P08, P09, \
  P10, P11, P12, P13, P14, P15, P16, P17, P18, P19, \
  P20, P21, P22, ...)                               \
P01, P02, P03, P04, P05, P06, P07, P08, P09, P10,   \
P11, P12, P13, P14, P15, P16, P17, P18, P19, P20,   \
P21, P22                                            \
/////////////////////////////////////////////////////

#define CRADLE_PP_VA_HEADS_IMPL_23(                 \
  P00, P01, P02, P03, P04, P05, P06, P07, P08, P09, \
  P10, P11, P12, P13, P14, P15, P16, P17, P18, P19, \
  P20, P21, P22, P23, ...)                          \
P01, P02, P03, P04, P05, P06, P07, P08, P09, P10,   \
P11, P12, P13, P14, P15, P16, P17, P18, P19, P20,   \
P21, P22, P23                                       \
/////////////////////////////////////////////////////

#define CRADLE_PP_VA_HEADS_IMPL_24(                 \
  P00, P01, P02, P03, P04, P05, P06, P07, P08, P09, \
  P10, P11, P12, P13, P14, P15, P16, P17, P18, P19, \
  P20, P21, P22, P23, P24, ...)                     \
P01, P02, P03, P04, P05, P06, P07, P08, P09, P10,   \
P11, P12, P13, P14, P15, P16, P17, P18, P19, P20,   \
P21, P22, P23, P24                                  \
/////////////////////////////////////////////////////

#define CRADLE_PP_VA_HEADS_IMPL_25(                 \
  P00, P01, P02, P03, P04, P05, P06, P07, P08, P09, \
  P10, P11, P12, P13, P14, P15, P16, P17, P18, P19, \
  P20, P21, P22, P23, P24, P25, ...)                \
P01, P02, P03, P04, P05, P06, P07, P08, P09, P10,   \
P11, P12, P13, P14, P15, P16, P17, P18, P19, P20,   \
P21, P22, P23, P24, P25                             \
/////////////////////////////////////////////////////

#define CRADLE_PP_VA_HEADS_IMPL_26(                 \
  P00, P01, P02, P03, P04, P05, P06, P07, P08, P09, \
  P10, P11, P12, P13, P14, P15, P16, P17, P18, P19, \
  P20, P21, P22, P23, P24, P25, P26, ...)           \
P01, P02, P03, P04, P05, P06, P07, P08, P09, P10,   \
P11, P12, P13, P14, P15, P16, P17, P18, P19, P20,   \
P21, P22, P23, P24, P25, P26                        \
/////////////////////////////////////////////////////

#define CRADLE_PP_VA_HEADS_IMPL_B(N, VA_TUPLE)     \
BOOST_PP_CAT(CRADLE_PP_VA_HEADS_IMPL_, N) VA_TUPLE \
////////////////////////////////////////////////////

#define CRADLE_PP_VA_HEADS_IMPL_A(VA_TUPLE)                           \
CRADLE_PP_VA_HEADS_IMPL_B(CRADLE_PP_VA_TUPLE_HEAD VA_TUPLE, VA_TUPLE) \
///////////////////////////////////////////////////////////////////////

#define CRADLE_PP_VA_HEADS_IMPL(...)        \
CRADLE_PP_VA_HEADS_IMPL_A((__VA_ARGS__, _)) \
/////////////////////////////////////////////


#endif // !defined(CRADLE_PREPROCESSOR_VA_DETAIL_HEADS_HPP_INCLUDE_GUARD)
