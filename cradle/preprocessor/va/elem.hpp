#if !defined(CRADLE_PREPROCESSOR_VA_ELEM_HPP_INCLUDE_GUARD)
#define CRADLE_PREPROCESSOR_VA_ELEM_HPP_INCLUDE_GUARD

#include <cradle/preprocessor/config.hpp>
#include <cradle/preprocessor/va/size.hpp>

#include <boost/preprocessor/config/limits.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/comparison/less_equal.hpp>
#include <boost/preprocessor/tuple/elem.hpp>
#include <boost/preprocessor/facilities/expand.hpp>
#include <boost/preprocessor/debug/assert.hpp>


BOOST_PP_ASSERT(BOOST_PP_LESS_EQUAL(CRADLE_PP_LIMIT_VA, BOOST_PP_LIMIT_TUPLE))

#define CRADLE_PP_VA_ELEM_IMPL_C_0(VA_TUPLE)               \
(BOOST_PP_EXPAND(CRADLE_PP_VA_SIZE VA_TUPLE), 0, VA_TUPLE) \
////////////////////////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_B_0(VA_TUPLE)                              \
BOOST_PP_EXPAND(BOOST_PP_TUPLE_ELEM CRADLE_PP_VA_ELEM_IMPL_C_0(VA_TUPLE)) \
///////////////////////////////////////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_A_0(...)   \
CRADLE_PP_VA_ELEM_IMPL_B_0((__VA_ARGS__)) \
///////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_C_1(VA_TUPLE)               \
(BOOST_PP_EXPAND(CRADLE_PP_VA_SIZE VA_TUPLE), 1, VA_TUPLE) \
////////////////////////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_B_1(VA_TUPLE)                              \
BOOST_PP_EXPAND(BOOST_PP_TUPLE_ELEM CRADLE_PP_VA_ELEM_IMPL_C_1(VA_TUPLE)) \
///////////////////////////////////////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_A_1(...)   \
CRADLE_PP_VA_ELEM_IMPL_B_1((__VA_ARGS__)) \
///////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_C_2(VA_TUPLE)               \
(BOOST_PP_EXPAND(CRADLE_PP_VA_SIZE VA_TUPLE), 2, VA_TUPLE) \
////////////////////////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_B_2(VA_TUPLE)                              \
BOOST_PP_EXPAND(BOOST_PP_TUPLE_ELEM CRADLE_PP_VA_ELEM_IMPL_C_2(VA_TUPLE)) \
///////////////////////////////////////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_A_2(...)   \
CRADLE_PP_VA_ELEM_IMPL_B_2((__VA_ARGS__)) \
///////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_C_3(VA_TUPLE)               \
(BOOST_PP_EXPAND(CRADLE_PP_VA_SIZE VA_TUPLE), 3, VA_TUPLE) \
////////////////////////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_B_3(VA_TUPLE)                              \
BOOST_PP_EXPAND(BOOST_PP_TUPLE_ELEM CRADLE_PP_VA_ELEM_IMPL_C_3(VA_TUPLE)) \
///////////////////////////////////////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_A_3(...)   \
CRADLE_PP_VA_ELEM_IMPL_B_3((__VA_ARGS__)) \
///////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_C_4(VA_TUPLE)               \
(BOOST_PP_EXPAND(CRADLE_PP_VA_SIZE VA_TUPLE), 4, VA_TUPLE) \
////////////////////////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_B_4(VA_TUPLE)                              \
BOOST_PP_EXPAND(BOOST_PP_TUPLE_ELEM CRADLE_PP_VA_ELEM_IMPL_C_4(VA_TUPLE)) \
///////////////////////////////////////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_A_4(...)   \
CRADLE_PP_VA_ELEM_IMPL_B_4((__VA_ARGS__)) \
///////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_C_5(VA_TUPLE)               \
(BOOST_PP_EXPAND(CRADLE_PP_VA_SIZE VA_TUPLE), 5, VA_TUPLE) \
////////////////////////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_B_5(VA_TUPLE)                              \
BOOST_PP_EXPAND(BOOST_PP_TUPLE_ELEM CRADLE_PP_VA_ELEM_IMPL_C_5(VA_TUPLE)) \
///////////////////////////////////////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_A_5(...)   \
CRADLE_PP_VA_ELEM_IMPL_B_5((__VA_ARGS__)) \
///////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_C_6(VA_TUPLE)               \
(BOOST_PP_EXPAND(CRADLE_PP_VA_SIZE VA_TUPLE), 6, VA_TUPLE) \
////////////////////////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_B_6(VA_TUPLE)                              \
BOOST_PP_EXPAND(BOOST_PP_TUPLE_ELEM CRADLE_PP_VA_ELEM_IMPL_C_6(VA_TUPLE)) \
///////////////////////////////////////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_A_6(...)   \
CRADLE_PP_VA_ELEM_IMPL_B_6((__VA_ARGS__)) \
///////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_C_7(VA_TUPLE)               \
(BOOST_PP_EXPAND(CRADLE_PP_VA_SIZE VA_TUPLE), 7, VA_TUPLE) \
////////////////////////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_B_7(VA_TUPLE)                              \
BOOST_PP_EXPAND(BOOST_PP_TUPLE_ELEM CRADLE_PP_VA_ELEM_IMPL_C_7(VA_TUPLE)) \
///////////////////////////////////////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_A_7(...)   \
CRADLE_PP_VA_ELEM_IMPL_B_7((__VA_ARGS__)) \
///////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_C_8(VA_TUPLE)               \
(BOOST_PP_EXPAND(CRADLE_PP_VA_SIZE VA_TUPLE), 8, VA_TUPLE) \
////////////////////////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_B_8(VA_TUPLE)                              \
BOOST_PP_EXPAND(BOOST_PP_TUPLE_ELEM CRADLE_PP_VA_ELEM_IMPL_C_8(VA_TUPLE)) \
///////////////////////////////////////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_A_8(...)   \
CRADLE_PP_VA_ELEM_IMPL_B_8((__VA_ARGS__)) \
///////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_C_9(VA_TUPLE)               \
(BOOST_PP_EXPAND(CRADLE_PP_VA_SIZE VA_TUPLE), 9, VA_TUPLE) \
////////////////////////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_B_9(VA_TUPLE)                              \
BOOST_PP_EXPAND(BOOST_PP_TUPLE_ELEM CRADLE_PP_VA_ELEM_IMPL_C_9(VA_TUPLE)) \
///////////////////////////////////////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_A_9(...)   \
CRADLE_PP_VA_ELEM_IMPL_B_9((__VA_ARGS__)) \
///////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_C_10(VA_TUPLE)               \
(BOOST_PP_EXPAND(CRADLE_PP_VA_SIZE VA_TUPLE), 10, VA_TUPLE) \
////////////////////////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_B_10(VA_TUPLE)                              \
BOOST_PP_EXPAND(BOOST_PP_TUPLE_ELEM CRADLE_PP_VA_ELEM_IMPL_C_10(VA_TUPLE)) \
///////////////////////////////////////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_A_10(...)   \
CRADLE_PP_VA_ELEM_IMPL_B_10((__VA_ARGS__)) \
///////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_C_11(VA_TUPLE)               \
(BOOST_PP_EXPAND(CRADLE_PP_VA_SIZE VA_TUPLE), 11, VA_TUPLE) \
////////////////////////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_B_11(VA_TUPLE)                              \
BOOST_PP_EXPAND(BOOST_PP_TUPLE_ELEM CRADLE_PP_VA_ELEM_IMPL_C_11(VA_TUPLE)) \
///////////////////////////////////////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_A_11(...)   \
CRADLE_PP_VA_ELEM_IMPL_B_11((__VA_ARGS__)) \
///////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_C_12(VA_TUPLE)               \
(BOOST_PP_EXPAND(CRADLE_PP_VA_SIZE VA_TUPLE), 12, VA_TUPLE) \
////////////////////////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_B_12(VA_TUPLE)                              \
BOOST_PP_EXPAND(BOOST_PP_TUPLE_ELEM CRADLE_PP_VA_ELEM_IMPL_C_12(VA_TUPLE)) \
///////////////////////////////////////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_A_12(...)   \
CRADLE_PP_VA_ELEM_IMPL_B_12((__VA_ARGS__)) \
///////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_C_13(VA_TUPLE)               \
(BOOST_PP_EXPAND(CRADLE_PP_VA_SIZE VA_TUPLE), 13, VA_TUPLE) \
////////////////////////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_B_13(VA_TUPLE)                              \
BOOST_PP_EXPAND(BOOST_PP_TUPLE_ELEM CRADLE_PP_VA_ELEM_IMPL_C_13(VA_TUPLE)) \
///////////////////////////////////////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_A_13(...)   \
CRADLE_PP_VA_ELEM_IMPL_B_13((__VA_ARGS__)) \
///////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_C_14(VA_TUPLE)               \
(BOOST_PP_EXPAND(CRADLE_PP_VA_SIZE VA_TUPLE), 14, VA_TUPLE) \
////////////////////////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_B_14(VA_TUPLE)                              \
BOOST_PP_EXPAND(BOOST_PP_TUPLE_ELEM CRADLE_PP_VA_ELEM_IMPL_C_14(VA_TUPLE)) \
///////////////////////////////////////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_A_14(...)   \
CRADLE_PP_VA_ELEM_IMPL_B_14((__VA_ARGS__)) \
///////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_C_15(VA_TUPLE)               \
(BOOST_PP_EXPAND(CRADLE_PP_VA_SIZE VA_TUPLE), 15, VA_TUPLE) \
////////////////////////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_B_15(VA_TUPLE)                              \
BOOST_PP_EXPAND(BOOST_PP_TUPLE_ELEM CRADLE_PP_VA_ELEM_IMPL_C_15(VA_TUPLE)) \
///////////////////////////////////////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_A_15(...)   \
CRADLE_PP_VA_ELEM_IMPL_B_15((__VA_ARGS__)) \
///////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_C_16(VA_TUPLE)               \
(BOOST_PP_EXPAND(CRADLE_PP_VA_SIZE VA_TUPLE), 16, VA_TUPLE) \
////////////////////////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_B_16(VA_TUPLE)                              \
BOOST_PP_EXPAND(BOOST_PP_TUPLE_ELEM CRADLE_PP_VA_ELEM_IMPL_C_16(VA_TUPLE)) \
///////////////////////////////////////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_A_16(...)   \
CRADLE_PP_VA_ELEM_IMPL_B_16((__VA_ARGS__)) \
///////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_C_17(VA_TUPLE)               \
(BOOST_PP_EXPAND(CRADLE_PP_VA_SIZE VA_TUPLE), 17, VA_TUPLE) \
////////////////////////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_B_17(VA_TUPLE)                              \
BOOST_PP_EXPAND(BOOST_PP_TUPLE_ELEM CRADLE_PP_VA_ELEM_IMPL_C_17(VA_TUPLE)) \
///////////////////////////////////////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_A_17(...)   \
CRADLE_PP_VA_ELEM_IMPL_B_17((__VA_ARGS__)) \
///////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_C_18(VA_TUPLE)               \
(BOOST_PP_EXPAND(CRADLE_PP_VA_SIZE VA_TUPLE), 18, VA_TUPLE) \
////////////////////////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_B_18(VA_TUPLE)                              \
BOOST_PP_EXPAND(BOOST_PP_TUPLE_ELEM CRADLE_PP_VA_ELEM_IMPL_C_18(VA_TUPLE)) \
///////////////////////////////////////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_A_18(...)   \
CRADLE_PP_VA_ELEM_IMPL_B_18((__VA_ARGS__)) \
///////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_C_19(VA_TUPLE)               \
(BOOST_PP_EXPAND(CRADLE_PP_VA_SIZE VA_TUPLE), 19, VA_TUPLE) \
////////////////////////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_B_19(VA_TUPLE)                              \
BOOST_PP_EXPAND(BOOST_PP_TUPLE_ELEM CRADLE_PP_VA_ELEM_IMPL_C_19(VA_TUPLE)) \
///////////////////////////////////////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_A_19(...)   \
CRADLE_PP_VA_ELEM_IMPL_B_19((__VA_ARGS__)) \
///////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_C_20(VA_TUPLE)               \
(BOOST_PP_EXPAND(CRADLE_PP_VA_SIZE VA_TUPLE), 20, VA_TUPLE) \
////////////////////////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_B_20(VA_TUPLE)                              \
BOOST_PP_EXPAND(BOOST_PP_TUPLE_ELEM CRADLE_PP_VA_ELEM_IMPL_C_20(VA_TUPLE)) \
///////////////////////////////////////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_A_20(...)   \
CRADLE_PP_VA_ELEM_IMPL_B_20((__VA_ARGS__)) \
///////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_C_21(VA_TUPLE)               \
(BOOST_PP_EXPAND(CRADLE_PP_VA_SIZE VA_TUPLE), 21, VA_TUPLE) \
////////////////////////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_B_21(VA_TUPLE)                              \
BOOST_PP_EXPAND(BOOST_PP_TUPLE_ELEM CRADLE_PP_VA_ELEM_IMPL_C_21(VA_TUPLE)) \
///////////////////////////////////////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_A_21(...)   \
CRADLE_PP_VA_ELEM_IMPL_B_21((__VA_ARGS__)) \
///////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_C_22(VA_TUPLE)               \
(BOOST_PP_EXPAND(CRADLE_PP_VA_SIZE VA_TUPLE), 22, VA_TUPLE) \
////////////////////////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_B_22(VA_TUPLE)                              \
BOOST_PP_EXPAND(BOOST_PP_TUPLE_ELEM CRADLE_PP_VA_ELEM_IMPL_C_22(VA_TUPLE)) \
///////////////////////////////////////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_A_22(...)   \
CRADLE_PP_VA_ELEM_IMPL_B_22((__VA_ARGS__)) \
///////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_C_23(VA_TUPLE)               \
(BOOST_PP_EXPAND(CRADLE_PP_VA_SIZE VA_TUPLE), 23, VA_TUPLE) \
////////////////////////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_B_23(VA_TUPLE)                              \
BOOST_PP_EXPAND(BOOST_PP_TUPLE_ELEM CRADLE_PP_VA_ELEM_IMPL_C_23(VA_TUPLE)) \
///////////////////////////////////////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_A_23(...)   \
CRADLE_PP_VA_ELEM_IMPL_B_23((__VA_ARGS__)) \
///////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_C_24(VA_TUPLE)               \
(BOOST_PP_EXPAND(CRADLE_PP_VA_SIZE VA_TUPLE), 24, VA_TUPLE) \
////////////////////////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_B_24(VA_TUPLE)                              \
BOOST_PP_EXPAND(BOOST_PP_TUPLE_ELEM CRADLE_PP_VA_ELEM_IMPL_C_24(VA_TUPLE)) \
///////////////////////////////////////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_A_24(...)   \
CRADLE_PP_VA_ELEM_IMPL_B_24((__VA_ARGS__)) \
///////////////////////////////////////////

#define CRADLE_PP_VA_ELEM(I) BOOST_PP_CAT(CRADLE_PP_VA_ELEM_IMPL_A_, I)


#endif // !defined(CRADLE_PREPROCESSOR_VA_ELEM_HPP_INCLUDE_GUARD)
