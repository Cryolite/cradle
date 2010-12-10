#include <cradle/preprocessor/invoke.hpp>

#include <cradle/preprocessor/va/size.hpp>
#include <cradle/preprocessor/va/elem.hpp>

#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/comparison/equal.hpp>
#include <boost/preprocessor/repetition/enum.hpp>
#include <boost/preprocessor/repetition/enum_shifted.hpp>
#include <boost/preprocessor/tuple/elem.hpp>
#include <boost/preprocessor/tuple/rem.hpp>
#include <boost/preprocessor/list/adt.hpp>
#include <boost/preprocessor/list/enum.hpp>
#include <boost/preprocessor/seq/enum.hpp>
#include <boost/preprocessor/debug/assert.hpp>


#define INVOKE_0(...)                                                       \
ASSERT_EQUAL(BOOST_PP_TUPLE_ELEM(3, 0, (__VA_ARGS__)), 0)                   \
ASSERT_EQUAL(BOOST_PP_TUPLE_ELEM(3, 1, (__VA_ARGS__)), 1)                   \
ASSERT_EQUAL(BOOST_PP_TUPLE_ELEM(3, 2, (__VA_ARGS__)), 2)                   \
ASSERT_EQUAL(CRADLE_PP_INVOKE(BOOST_PP_TUPLE_ELEM, 3, 0, (__VA_ARGS__)), 0) \
ASSERT_EQUAL(CRADLE_PP_INVOKE(BOOST_PP_TUPLE_ELEM, 3, 1, (__VA_ARGS__)), 1) \
ASSERT_EQUAL(CRADLE_PP_INVOKE(BOOST_PP_TUPLE_ELEM, 3, 2, (__VA_ARGS__)), 2) \
ASSERT_EQUAL(CRADLE_PP_VA_SIZE(__VA_ARGS__), 3)                             \
ASSERT_EQUAL(CRADLE_PP_VA_ELEM(0)(__VA_ARGS__), 0)                          \
ASSERT_EQUAL(CRADLE_PP_VA_ELEM(1)(__VA_ARGS__), 1)                          \
ASSERT_EQUAL(CRADLE_PP_VA_ELEM(2)(__VA_ARGS__), 2)                          \
ASSERT_EQUAL(CRADLE_PP_INVOKE(CRADLE_PP_VA_SIZE, __VA_ARGS__), 3)           \
ASSERT_EQUAL(CRADLE_PP_INVOKE(CRADLE_PP_VA_ELEM(0), __VA_ARGS__), 0)        \
ASSERT_EQUAL(CRADLE_PP_INVOKE(CRADLE_PP_VA_ELEM(1), __VA_ARGS__), 1)        \
ASSERT_EQUAL(CRADLE_PP_INVOKE(CRADLE_PP_VA_ELEM(2), __VA_ARGS__), 2)        \
CRADLE_PP_INVOKE(INVOKE_1, __VA_ARGS__)                                     \
/////////////////////////////////////////////////////////////////////////////

#define INVOKE_1(...)                                                       \
ASSERT_EQUAL(BOOST_PP_TUPLE_ELEM(3, 0, (__VA_ARGS__)), 0)                   \
ASSERT_EQUAL(BOOST_PP_TUPLE_ELEM(3, 1, (__VA_ARGS__)), 1)                   \
ASSERT_EQUAL(BOOST_PP_TUPLE_ELEM(3, 2, (__VA_ARGS__)), 2)                   \
ASSERT_EQUAL(CRADLE_PP_INVOKE(BOOST_PP_TUPLE_ELEM, 3, 0, (__VA_ARGS__)), 0) \
ASSERT_EQUAL(CRADLE_PP_INVOKE(BOOST_PP_TUPLE_ELEM, 3, 1, (__VA_ARGS__)), 1) \
ASSERT_EQUAL(CRADLE_PP_INVOKE(BOOST_PP_TUPLE_ELEM, 3, 2, (__VA_ARGS__)), 2) \
ASSERT_EQUAL(CRADLE_PP_VA_SIZE(__VA_ARGS__), 3)                             \
ASSERT_EQUAL(CRADLE_PP_VA_ELEM(0)(__VA_ARGS__), 0)                          \
ASSERT_EQUAL(CRADLE_PP_VA_ELEM(1)(__VA_ARGS__), 1)                          \
ASSERT_EQUAL(CRADLE_PP_VA_ELEM(2)(__VA_ARGS__), 2)                          \
ASSERT_EQUAL(CRADLE_PP_INVOKE(CRADLE_PP_VA_SIZE, __VA_ARGS__), 3)           \
ASSERT_EQUAL(CRADLE_PP_INVOKE(CRADLE_PP_VA_ELEM(0), __VA_ARGS__), 0)        \
ASSERT_EQUAL(CRADLE_PP_INVOKE(CRADLE_PP_VA_ELEM(1), __VA_ARGS__), 1)        \
ASSERT_EQUAL(CRADLE_PP_INVOKE(CRADLE_PP_VA_ELEM(2), __VA_ARGS__), 2)        \
CRADLE_PP_INVOKE(INVOKE_2, __VA_ARGS__)                                     \
/////////////////////////////////////////////////////////////////////////////

#define INVOKE_2(P0, ...)                                                   \
ASSERT_EQUAL(P0, 0)                                                         \
ASSERT_EQUAL(BOOST_PP_TUPLE_ELEM(2, 0, (__VA_ARGS__)), 1)                   \
ASSERT_EQUAL(BOOST_PP_TUPLE_ELEM(2, 1, (__VA_ARGS__)), 2)                   \
ASSERT_EQUAL(CRADLE_PP_INVOKE(BOOST_PP_TUPLE_ELEM, 2, 0, (__VA_ARGS__)), 1) \
ASSERT_EQUAL(CRADLE_PP_INVOKE(BOOST_PP_TUPLE_ELEM, 2, 1, (__VA_ARGS__)), 2) \
ASSERT_EQUAL(CRADLE_PP_VA_SIZE(__VA_ARGS__), 2)                             \
ASSERT_EQUAL(CRADLE_PP_VA_ELEM(0)(__VA_ARGS__), 1)                          \
ASSERT_EQUAL(CRADLE_PP_VA_ELEM(1)(__VA_ARGS__), 2)                          \
ASSERT_EQUAL(CRADLE_PP_INVOKE(CRADLE_PP_VA_SIZE, __VA_ARGS__), 2)           \
ASSERT_EQUAL(CRADLE_PP_INVOKE(CRADLE_PP_VA_ELEM(0), __VA_ARGS__), 1)        \
ASSERT_EQUAL(CRADLE_PP_INVOKE(CRADLE_PP_VA_ELEM(1), __VA_ARGS__), 2)        \
CRADLE_PP_INVOKE(INVOKE_3, P0, __VA_ARGS__)                                 \
/////////////////////////////////////////////////////////////////////////////

#define INVOKE_3(P0, ...)                                                   \
ASSERT_EQUAL(P0, 0)                                                         \
ASSERT_EQUAL(BOOST_PP_TUPLE_ELEM(2, 0, (__VA_ARGS__)), 1)                   \
ASSERT_EQUAL(BOOST_PP_TUPLE_ELEM(2, 1, (__VA_ARGS__)), 2)                   \
ASSERT_EQUAL(CRADLE_PP_INVOKE(BOOST_PP_TUPLE_ELEM, 2, 0, (__VA_ARGS__)), 1) \
ASSERT_EQUAL(CRADLE_PP_INVOKE(BOOST_PP_TUPLE_ELEM, 2, 1, (__VA_ARGS__)), 2) \
ASSERT_EQUAL(CRADLE_PP_VA_SIZE(__VA_ARGS__), 2)                             \
ASSERT_EQUAL(CRADLE_PP_VA_ELEM(0)(__VA_ARGS__), 1)                          \
ASSERT_EQUAL(CRADLE_PP_VA_ELEM(1)(__VA_ARGS__), 2)                          \
ASSERT_EQUAL(CRADLE_PP_INVOKE(CRADLE_PP_VA_SIZE, __VA_ARGS__), 2)           \
ASSERT_EQUAL(CRADLE_PP_INVOKE(CRADLE_PP_VA_ELEM(0), __VA_ARGS__), 1)        \
ASSERT_EQUAL(CRADLE_PP_INVOKE(CRADLE_PP_VA_ELEM(1), __VA_ARGS__), 2)        \
CRADLE_PP_INVOKE(INVOKE_4, P0, __VA_ARGS__)                                 \
/////////////////////////////////////////////////////////////////////////////

#define INVOKE_4(...)                                                       \
ASSERT_EQUAL(BOOST_PP_TUPLE_ELEM(3, 0, (__VA_ARGS__)), 0)                   \
ASSERT_EQUAL(BOOST_PP_TUPLE_ELEM(3, 1, (__VA_ARGS__)), 1)                   \
ASSERT_EQUAL(BOOST_PP_TUPLE_ELEM(3, 2, (__VA_ARGS__)), 2)                   \
ASSERT_EQUAL(CRADLE_PP_INVOKE(BOOST_PP_TUPLE_ELEM, 3, 0, (__VA_ARGS__)), 0) \
ASSERT_EQUAL(CRADLE_PP_INVOKE(BOOST_PP_TUPLE_ELEM, 3, 1, (__VA_ARGS__)), 1) \
ASSERT_EQUAL(CRADLE_PP_INVOKE(BOOST_PP_TUPLE_ELEM, 3, 2, (__VA_ARGS__)), 2) \
ASSERT_EQUAL(CRADLE_PP_VA_SIZE(__VA_ARGS__), 3)                             \
ASSERT_EQUAL(CRADLE_PP_VA_ELEM(0)(__VA_ARGS__), 0)                          \
ASSERT_EQUAL(CRADLE_PP_VA_ELEM(1)(__VA_ARGS__), 1)                          \
ASSERT_EQUAL(CRADLE_PP_VA_ELEM(2)(__VA_ARGS__), 2)                          \
ASSERT_EQUAL(CRADLE_PP_INVOKE(CRADLE_PP_VA_SIZE, __VA_ARGS__), 3)           \
ASSERT_EQUAL(CRADLE_PP_INVOKE(CRADLE_PP_VA_ELEM(0), __VA_ARGS__), 0)        \
ASSERT_EQUAL(CRADLE_PP_INVOKE(CRADLE_PP_VA_ELEM(1), __VA_ARGS__), 1)        \
ASSERT_EQUAL(CRADLE_PP_INVOKE(CRADLE_PP_VA_ELEM(2), __VA_ARGS__), 2)        \
CRADLE_PP_INVOKE(INVOKE_5, __VA_ARGS__)                                     \
/////////////////////////////////////////////////////////////////////////////

#define INVOKE_5(P0, ...)                                                   \
ASSERT_EQUAL(P0, 0)                                                         \
ASSERT_EQUAL(BOOST_PP_TUPLE_ELEM(2, 0, (__VA_ARGS__)), 1)                   \
ASSERT_EQUAL(BOOST_PP_TUPLE_ELEM(2, 1, (__VA_ARGS__)), 2)                   \
ASSERT_EQUAL(CRADLE_PP_INVOKE(BOOST_PP_TUPLE_ELEM, 2, 0, (__VA_ARGS__)), 1) \
ASSERT_EQUAL(CRADLE_PP_INVOKE(BOOST_PP_TUPLE_ELEM, 2, 1, (__VA_ARGS__)), 2) \
ASSERT_EQUAL(CRADLE_PP_VA_SIZE(__VA_ARGS__), 2)                             \
ASSERT_EQUAL(CRADLE_PP_VA_ELEM(0)(__VA_ARGS__), 1)                          \
ASSERT_EQUAL(CRADLE_PP_VA_ELEM(1)(__VA_ARGS__), 2)                          \
ASSERT_EQUAL(CRADLE_PP_INVOKE(CRADLE_PP_VA_SIZE, __VA_ARGS__), 2)           \
ASSERT_EQUAL(CRADLE_PP_INVOKE(CRADLE_PP_VA_ELEM(0), __VA_ARGS__), 1)        \
ASSERT_EQUAL(CRADLE_PP_INVOKE(CRADLE_PP_VA_ELEM(1), __VA_ARGS__), 2)        \
CRADLE_PP_INVOKE(INVOKE_6, P0, __VA_ARGS__)                                 \
/////////////////////////////////////////////////////////////////////////////

#define INVOKE_6(P0, P1, ...)                                               \
ASSERT_EQUAL(P0, 0)                                                         \
ASSERT_EQUAL(P1, 1)                                                         \
ASSERT_EQUAL(BOOST_PP_TUPLE_ELEM(1, 0, (__VA_ARGS__)), 2)                   \
ASSERT_EQUAL(CRADLE_PP_INVOKE(BOOST_PP_TUPLE_ELEM, 1, 0, (__VA_ARGS__)), 2) \
ASSERT_EQUAL(CRADLE_PP_VA_SIZE(__VA_ARGS__), 1)                             \
ASSERT_EQUAL(CRADLE_PP_VA_ELEM(0)(__VA_ARGS__), 2)                          \
ASSERT_EQUAL(CRADLE_PP_INVOKE(CRADLE_PP_VA_SIZE, __VA_ARGS__), 1)           \
ASSERT_EQUAL(CRADLE_PP_INVOKE(CRADLE_PP_VA_ELEM(0), __VA_ARGS__), 2)        \
CRADLE_PP_INVOKE(INVOKE_7, P0, P1, __VA_ARGS__)                             \
/////////////////////////////////////////////////////////////////////////////

#define INVOKE_7(P0, P1, ...)                                               \
ASSERT_EQUAL(P0, 0)                                                         \
ASSERT_EQUAL(P1, 1)                                                         \
ASSERT_EQUAL(BOOST_PP_TUPLE_ELEM(1, 0, (__VA_ARGS__)), 2)                   \
ASSERT_EQUAL(CRADLE_PP_INVOKE(BOOST_PP_TUPLE_ELEM, 1, 0, (__VA_ARGS__)), 2) \
ASSERT_EQUAL(CRADLE_PP_VA_SIZE(__VA_ARGS__), 1)                             \
ASSERT_EQUAL(CRADLE_PP_VA_ELEM(0)(__VA_ARGS__), 2)                          \
ASSERT_EQUAL(CRADLE_PP_INVOKE(CRADLE_PP_VA_SIZE, __VA_ARGS__), 1)           \
ASSERT_EQUAL(CRADLE_PP_INVOKE(CRADLE_PP_VA_ELEM(0), __VA_ARGS__), 2)        \
CRADLE_PP_INVOKE(INVOKE_8, P0, P1, __VA_ARGS__)                             \
/////////////////////////////////////////////////////////////////////////////

#define INVOKE_8(P0, ...)                                                   \
ASSERT_EQUAL(P0, 0)                                                         \
ASSERT_EQUAL(BOOST_PP_TUPLE_ELEM(2, 0, (__VA_ARGS__)), 1)                   \
ASSERT_EQUAL(BOOST_PP_TUPLE_ELEM(2, 1, (__VA_ARGS__)), 2)                   \
ASSERT_EQUAL(CRADLE_PP_INVOKE(BOOST_PP_TUPLE_ELEM, 2, 0, (__VA_ARGS__)), 1) \
ASSERT_EQUAL(CRADLE_PP_INVOKE(BOOST_PP_TUPLE_ELEM, 2, 1, (__VA_ARGS__)), 2) \
ASSERT_EQUAL(CRADLE_PP_VA_SIZE(__VA_ARGS__), 2)                             \
ASSERT_EQUAL(CRADLE_PP_VA_ELEM(0)(__VA_ARGS__), 1)                          \
ASSERT_EQUAL(CRADLE_PP_VA_ELEM(1)(__VA_ARGS__), 2)                          \
ASSERT_EQUAL(CRADLE_PP_INVOKE(CRADLE_PP_VA_SIZE, __VA_ARGS__), 2)           \
ASSERT_EQUAL(CRADLE_PP_INVOKE(CRADLE_PP_VA_ELEM(0), __VA_ARGS__), 1)        \
ASSERT_EQUAL(CRADLE_PP_INVOKE(CRADLE_PP_VA_ELEM(1), __VA_ARGS__), 2)        \
CRADLE_PP_INVOKE(INVOKE_9, P0, __VA_ARGS__)                                 \
/////////////////////////////////////////////////////////////////////////////

#define INVOKE_9(P0, P1, ...)                                               \
ASSERT_EQUAL(P0, 0)                                                         \
ASSERT_EQUAL(P1, 1)                                                         \
ASSERT_EQUAL(BOOST_PP_TUPLE_ELEM(1, 0, (__VA_ARGS__)), 2)                   \
ASSERT_EQUAL(CRADLE_PP_INVOKE(BOOST_PP_TUPLE_ELEM, 1, 0, (__VA_ARGS__)), 2) \
ASSERT_EQUAL(CRADLE_PP_VA_SIZE(__VA_ARGS__), 1)                             \
ASSERT_EQUAL(CRADLE_PP_VA_ELEM(0)(__VA_ARGS__), 2)                          \
ASSERT_EQUAL(CRADLE_PP_INVOKE(CRADLE_PP_VA_SIZE, __VA_ARGS__), 1)           \
ASSERT_EQUAL(CRADLE_PP_INVOKE(CRADLE_PP_VA_ELEM(0), __VA_ARGS__), 2)        \
CRADLE_PP_INVOKE(INVOKE_10, P0, P1, __VA_ARGS__)                            \
/////////////////////////////////////////////////////////////////////////////

#define INVOKE_10(...)                                                      \
ASSERT_EQUAL(BOOST_PP_TUPLE_ELEM(3, 0, (__VA_ARGS__)), 0)                   \
ASSERT_EQUAL(BOOST_PP_TUPLE_ELEM(3, 1, (__VA_ARGS__)), 1)                   \
ASSERT_EQUAL(BOOST_PP_TUPLE_ELEM(3, 2, (__VA_ARGS__)), 2)                   \
ASSERT_EQUAL(CRADLE_PP_INVOKE(BOOST_PP_TUPLE_ELEM, 3, 0, (__VA_ARGS__)), 0) \
ASSERT_EQUAL(CRADLE_PP_INVOKE(BOOST_PP_TUPLE_ELEM, 3, 1, (__VA_ARGS__)), 1) \
ASSERT_EQUAL(CRADLE_PP_INVOKE(BOOST_PP_TUPLE_ELEM, 3, 2, (__VA_ARGS__)), 2) \
ASSERT_EQUAL(CRADLE_PP_VA_SIZE(__VA_ARGS__), 3)                             \
ASSERT_EQUAL(CRADLE_PP_VA_ELEM(0)(__VA_ARGS__), 0)                          \
ASSERT_EQUAL(CRADLE_PP_VA_ELEM(1)(__VA_ARGS__), 1)                          \
ASSERT_EQUAL(CRADLE_PP_VA_ELEM(2)(__VA_ARGS__), 2)                          \
ASSERT_EQUAL(CRADLE_PP_INVOKE(CRADLE_PP_VA_SIZE, __VA_ARGS__), 3)           \
ASSERT_EQUAL(CRADLE_PP_INVOKE(CRADLE_PP_VA_ELEM(0), __VA_ARGS__), 0)        \
ASSERT_EQUAL(CRADLE_PP_INVOKE(CRADLE_PP_VA_ELEM(1), __VA_ARGS__), 1)        \
ASSERT_EQUAL(CRADLE_PP_INVOKE(CRADLE_PP_VA_ELEM(2), __VA_ARGS__), 2)        \
CRADLE_PP_INVOKE(INVOKE_11, __VA_ARGS__)                                    \
/////////////////////////////////////////////////////////////////////////////

#define INVOKE_11(P0, P1, ...)                                              \
ASSERT_EQUAL(P0, 0)                                                         \
ASSERT_EQUAL(P1, 1)                                                         \
ASSERT_EQUAL(BOOST_PP_TUPLE_ELEM(1, 0, (__VA_ARGS__)), 2)                   \
ASSERT_EQUAL(CRADLE_PP_INVOKE(BOOST_PP_TUPLE_ELEM, 1, 0, (__VA_ARGS__)), 2) \
ASSERT_EQUAL(CRADLE_PP_VA_SIZE(__VA_ARGS__), 1)                             \
ASSERT_EQUAL(CRADLE_PP_VA_ELEM(0)(__VA_ARGS__), 2)                          \
ASSERT_EQUAL(CRADLE_PP_INVOKE(CRADLE_PP_VA_SIZE, __VA_ARGS__), 1)           \
ASSERT_EQUAL(CRADLE_PP_INVOKE(CRADLE_PP_VA_ELEM(0), __VA_ARGS__), 2)        \
CRADLE_PP_INVOKE(INVOKE_12, P0, P1, __VA_ARGS__)                            \
/////////////////////////////////////////////////////////////////////////////

#define INVOKE_12(P0, P1, P2)           \
ASSERT_EQUAL(P0, 0)                     \
ASSERT_EQUAL(P1, 1)                     \
ASSERT_EQUAL(P2, 2)                     \
CRADLE_PP_INVOKE(INVOKE_13, P0, P1, P2) \
/////////////////////////////////////////

#define INVOKE_13(P0, P1, P2)           \
ASSERT_EQUAL(P0, 0)                     \
ASSERT_EQUAL(P1, 1)                     \
ASSERT_EQUAL(P2, 2)                     \
CRADLE_PP_INVOKE(INVOKE_14, P0, P1, P2) \
/////////////////////////////////////////

#define INVOKE_14(P0, P1, ...)                                              \
ASSERT_EQUAL(P0, 0)                                                         \
ASSERT_EQUAL(P1, 1)                                                         \
ASSERT_EQUAL(BOOST_PP_TUPLE_ELEM(1, 0, (__VA_ARGS__)), 2)                   \
ASSERT_EQUAL(CRADLE_PP_INVOKE(BOOST_PP_TUPLE_ELEM, 1, 0, (__VA_ARGS__)), 2) \
ASSERT_EQUAL(CRADLE_PP_VA_SIZE(__VA_ARGS__), 1)                             \
ASSERT_EQUAL(CRADLE_PP_VA_ELEM(0)(__VA_ARGS__), 2)                          \
ASSERT_EQUAL(CRADLE_PP_INVOKE(CRADLE_PP_VA_SIZE, __VA_ARGS__), 1)           \
ASSERT_EQUAL(CRADLE_PP_INVOKE(CRADLE_PP_VA_ELEM(0), __VA_ARGS__), 2)        \
CRADLE_PP_INVOKE(INVOKE_15, P0, P1, __VA_ARGS__)                            \
/////////////////////////////////////////////////////////////////////////////

#define INVOKE_15(P0, P1, P2)           \
ASSERT_EQUAL(P0, 0)                     \
ASSERT_EQUAL(P1, 1)                     \
ASSERT_EQUAL(P2, 2)                     \
CRADLE_PP_INVOKE(INVOKE_16, P0, P1, P2) \
/////////////////////////////////////////

#define INVOKE_16(P0, ...)                                                  \
ASSERT_EQUAL(P0, 0)                                                         \
ASSERT_EQUAL(BOOST_PP_TUPLE_ELEM(2, 0, (__VA_ARGS__)), 1)                   \
ASSERT_EQUAL(BOOST_PP_TUPLE_ELEM(2, 1, (__VA_ARGS__)), 2)                   \
ASSERT_EQUAL(CRADLE_PP_INVOKE(BOOST_PP_TUPLE_ELEM, 2, 0, (__VA_ARGS__)), 1) \
ASSERT_EQUAL(CRADLE_PP_INVOKE(BOOST_PP_TUPLE_ELEM, 2, 1, (__VA_ARGS__)), 2) \
ASSERT_EQUAL(CRADLE_PP_VA_SIZE(__VA_ARGS__), 2)                             \
ASSERT_EQUAL(CRADLE_PP_VA_ELEM(0)(__VA_ARGS__), 1)                          \
ASSERT_EQUAL(CRADLE_PP_VA_ELEM(1)(__VA_ARGS__), 2)                          \
ASSERT_EQUAL(CRADLE_PP_INVOKE(CRADLE_PP_VA_SIZE, __VA_ARGS__), 2)           \
ASSERT_EQUAL(CRADLE_PP_INVOKE(CRADLE_PP_VA_ELEM(0), __VA_ARGS__), 1)        \
ASSERT_EQUAL(CRADLE_PP_INVOKE(CRADLE_PP_VA_ELEM(1), __VA_ARGS__), 2)        \
CRADLE_PP_INVOKE(INVOKE_17, P0, __VA_ARGS__)                                \
/////////////////////////////////////////////////////////////////////////////

#define INVOKE_17(P0, P1, P2)           \
ASSERT_EQUAL(P0, 0)                     \
ASSERT_EQUAL(P1, 1)                     \
ASSERT_EQUAL(P2, 2)                     \
CRADLE_PP_INVOKE(INVOKE_18, P0, P1, P2) \
/////////////////////////////////////////

#define INVOKE_18(...)                                                      \
ASSERT_EQUAL(BOOST_PP_TUPLE_ELEM(3, 0, (__VA_ARGS__)), 0)                   \
ASSERT_EQUAL(BOOST_PP_TUPLE_ELEM(3, 1, (__VA_ARGS__)), 1)                   \
ASSERT_EQUAL(BOOST_PP_TUPLE_ELEM(3, 2, (__VA_ARGS__)), 2)                   \
ASSERT_EQUAL(CRADLE_PP_INVOKE(BOOST_PP_TUPLE_ELEM, 3, 0, (__VA_ARGS__)), 0) \
ASSERT_EQUAL(CRADLE_PP_INVOKE(BOOST_PP_TUPLE_ELEM, 3, 1, (__VA_ARGS__)), 1) \
ASSERT_EQUAL(CRADLE_PP_INVOKE(BOOST_PP_TUPLE_ELEM, 3, 2, (__VA_ARGS__)), 2) \
ASSERT_EQUAL(CRADLE_PP_VA_SIZE(__VA_ARGS__), 3)                             \
ASSERT_EQUAL(CRADLE_PP_VA_ELEM(0)(__VA_ARGS__), 0)                          \
ASSERT_EQUAL(CRADLE_PP_VA_ELEM(1)(__VA_ARGS__), 1)                          \
ASSERT_EQUAL(CRADLE_PP_VA_ELEM(2)(__VA_ARGS__), 2)                          \
ASSERT_EQUAL(CRADLE_PP_INVOKE(CRADLE_PP_VA_SIZE, __VA_ARGS__), 3)           \
ASSERT_EQUAL(CRADLE_PP_INVOKE(CRADLE_PP_VA_ELEM(0), __VA_ARGS__), 0)        \
ASSERT_EQUAL(CRADLE_PP_INVOKE(CRADLE_PP_VA_ELEM(1), __VA_ARGS__), 1)        \
ASSERT_EQUAL(CRADLE_PP_INVOKE(CRADLE_PP_VA_ELEM(2), __VA_ARGS__), 2)        \
CRADLE_PP_INVOKE(INVOKE_19, __VA_ARGS__)                                    \
/////////////////////////////////////////////////////////////////////////////

#define INVOKE_19(P0, P1, P2)                                  \
ASSERT_EQUAL(P0, 0) ASSERT_EQUAL(P1, 1) ASSERT_EQUAL(P2, 2) P2 \
////////////////////////////////////////////////////////////////

#define ASSERT_EQUAL(P0, P1) BOOST_PP_ASSERT(BOOST_PP_EQUAL(P0, P1))

static_assert(INVOKE_0(0, 1, 2) == 2, "");


#define ARG_2(P0, P1) ASSERT_EQUAL(P0, 0) ASSERT_EQUAL(P1, 1)

#define MACRO_A(Z, I, DATA) I


CRADLE_PP_INVOKE(ARG_2, 0, 1)
CRADLE_PP_INVOKE(ARG_2, BOOST_PP_ENUM(2, MACRO_A, _))
CRADLE_PP_INVOKE(ARG_2, BOOST_PP_TUPLE_REM(2)(0, 1))
CRADLE_PP_INVOKE(ARG_2, BOOST_PP_LIST_ENUM((0, (1, BOOST_PP_NIL))))
CRADLE_PP_INVOKE(ARG_2, BOOST_PP_SEQ_ENUM((0)(1)))

#define FORWARD_A(P0, P1) CRADLE_PP_INVOKE(ARG_2, P0, P1)

FORWARD_A(0, 1)

#define FORWARD_TUPLE_A(TUPLE) CRADLE_PP_INVOKE(ARG_2, BOOST_PP_TUPLE_REM(2) TUPLE)

FORWARD_TUPLE_A((0, 1))

#define FORWARD_LIST_A(LIST) CRADLE_PP_INVOKE(ARG_2, BOOST_PP_LIST_ENUM(LIST))

FORWARD_LIST_A((0, (1, BOOST_PP_NIL)))

#define FORWARD_SEQ_A(SEQ) CRADLE_PP_INVOKE(ARG_2, BOOST_PP_SEQ_ENUM(SEQ))

FORWARD_SEQ_A((0)(1))

#define FORWARD_VA_A_0(...) CRADLE_PP_INVOKE(ARG_2, __VA_ARGS__)

FORWARD_VA_A_0(0, 1)

#define FORWARD_VA_A_1(FIRST, ...) CRADLE_PP_INVOKE(ARG_2, FIRST, __VA_ARGS__)

FORWARD_VA_A_1(0, 1)

#define FORWARD_VA_A_REV_1(FIRST, ...) CRADLE_PP_INVOKE(ARG_2, __VA_ARGS__, FIRST)

FORWARD_VA_A_REV_1(1, 0)


#define VA_2_1(FIRST, ...) ASSERT_EQUAL(FIRST, 0) ASSERT_EQUAL(__VA_ARGS__, 1)

CRADLE_PP_INVOKE(VA_2_1, 0, 1)
CRADLE_PP_INVOKE(VA_2_1, BOOST_PP_ENUM(2, MACRO_A, _))
CRADLE_PP_INVOKE(VA_2_1, BOOST_PP_TUPLE_REM(2)(0, 1))
CRADLE_PP_INVOKE(VA_2_1, BOOST_PP_LIST_ENUM((0, (1, BOOST_PP_NIL))))
CRADLE_PP_INVOKE(VA_2_1, BOOST_PP_SEQ_ENUM((0)(1)))

#define FORWARD_B(P0, P1) CRADLE_PP_INVOKE(VA_2_1, P0, P1)

FORWARD_B(0, 1)

#define FORWARD_TUPLE_B(TUPLE) CRADLE_PP_INVOKE(VA_2_1, BOOST_PP_TUPLE_REM(2) TUPLE)

FORWARD_TUPLE_B((0, 1))

#define FORWARD_LIST_B(LIST) CRADLE_PP_INVOKE(VA_2_1, BOOST_PP_LIST_ENUM(LIST))

FORWARD_LIST_B((0, (1, BOOST_PP_NIL)))

#define FORWARD_SEQ_B(SEQ) CRADLE_PP_INVOKE(VA_2_1, BOOST_PP_SEQ_ENUM(SEQ))

FORWARD_SEQ_B((0)(1))

#define FORWARD_VA_B_0(...) CRADLE_PP_INVOKE(VA_2_1, __VA_ARGS__)

FORWARD_VA_B_0(0, 1)

#define FORWARD_VA_B_1(FIRST, ...) CRADLE_PP_INVOKE(VA_2_1, FIRST, __VA_ARGS__)

FORWARD_VA_B_1(0, 1)

#define FORWARD_VA_B_REV_1(FIRST, ...) CRADLE_PP_INVOKE(VA_2_1, __VA_ARGS__, FIRST)

FORWARD_VA_B_REV_1(1, 0)


#define ARG_1_2(P0, P1) ASSERT_EQUAL(P0, 1) ASSERT_EQUAL(P1, 2)

#define VA_3_1(FIRST, ...)                                    \
ASSERT_EQUAL(FIRST, 0) CRADLE_PP_INVOKE(ARG_1_2, __VA_ARGS__) \
///////////////////////////////////////////////////////////////

CRADLE_PP_INVOKE(VA_3_1, 0, 1, 2)
CRADLE_PP_INVOKE(VA_3_1, BOOST_PP_ENUM(3, MACRO_A, _))
CRADLE_PP_INVOKE(VA_3_1, BOOST_PP_TUPLE_REM(3)(0, 1, 2))
CRADLE_PP_INVOKE(VA_3_1, BOOST_PP_LIST_ENUM((0, (1, (2, BOOST_PP_NIL)))))
CRADLE_PP_INVOKE(VA_3_1, BOOST_PP_SEQ_ENUM((0)(1)(2)))

#define FORWARD_C(P0, P1, P2) CRADLE_PP_INVOKE(VA_3_1, P0, P1, P2)

FORWARD_C(0, 1, 2)

#define FORWARD_TUPLE_C(TUPLE) CRADLE_PP_INVOKE(VA_3_1, BOOST_PP_TUPLE_REM(3) TUPLE)

FORWARD_TUPLE_C((0, 1, 2))

#define FORWARD_LIST_C(LIST) CRADLE_PP_INVOKE(VA_3_1, BOOST_PP_LIST_ENUM(LIST))

FORWARD_LIST_C((0, (1, (2, BOOST_PP_NIL))))

#define FORWARD_SEQ_C(SEQ) CRADLE_PP_INVOKE(VA_3_1, BOOST_PP_SEQ_ENUM(SEQ))

FORWARD_SEQ_C((0)(1)(2))

#define FORWARD_VA_C_0(...) CRADLE_PP_INVOKE(VA_3_1, __VA_ARGS__)

FORWARD_VA_C_0(0, 1, 2)

#define FORWARD_VA_C_1(P0, ...) CRADLE_PP_INVOKE(VA_3_1, P0, __VA_ARGS__)

FORWARD_VA_C_1(0, 1, 2)

#define FORWARD_VA_C_REV_1(P0, ...) CRADLE_PP_INVOKE(VA_3_1, __VA_ARGS__, P0)

FORWARD_VA_C_REV_1(2, 0, 1)

#define FORWARD_VA_C_2(P0, P1, ...) CRADLE_PP_INVOKE(VA_3_1, P0, P1, __VA_ARGS__)

FORWARD_VA_C_2(0, 1, 2)

#define FORWARD_VA_C_REV_2_1(P0, P1, ...) CRADLE_PP_INVOKE(VA_3_1, P0, __VA_ARGS__, P1)

FORWARD_VA_C_REV_2_1(0, 2, 1)

#define FORWARD_VA_C_REV_2_2(P0, P1, ...) CRADLE_PP_INVOKE(VA_3_1, P1, P0, __VA_ARGS__)

FORWARD_VA_C_REV_2_2(1, 0, 2)

#define FORWARD_VA_C_REV_2_3(P0, P1, ...) CRADLE_PP_INVOKE(VA_3_1, P1, __VA_ARGS__, P0)

FORWARD_VA_C_REV_2_3(2, 0, 1)

#define FORWARD_VA_C_REV_2_4(P0, P1, ...) CRADLE_PP_INVOKE(VA_3_1, __VA_ARGS__, P0, P1)

FORWARD_VA_C_REV_2_4(1, 2, 0)

#define FORWARD_VA_C_REV_2_5(P0, P1, ...) CRADLE_PP_INVOKE(VA_3_1, __VA_ARGS__, P1, P0)

FORWARD_VA_C_REV_2_5(2, 1, 0)


#define VA_3_2(P0, P1, ...)                                          \
ASSERT_EQUAL(P0, 0) ASSERT_EQUAL(P1, 1) ASSERT_EQUAL(__VA_ARGS__, 2) \
//////////////////////////////////////////////////////////////////////

CRADLE_PP_INVOKE(VA_3_2, 0, 1, 2)
CRADLE_PP_INVOKE(VA_3_2, BOOST_PP_ENUM(3, MACRO_A, _))
CRADLE_PP_INVOKE(VA_3_2, BOOST_PP_TUPLE_REM(3)(0, 1, 2))
CRADLE_PP_INVOKE(VA_3_2, BOOST_PP_LIST_ENUM((0, (1, (2, BOOST_PP_NIL)))))
CRADLE_PP_INVOKE(VA_3_2, BOOST_PP_SEQ_ENUM((0)(1)(2)))

#define FORWARD_D(P0, P1, P2) CRADLE_PP_INVOKE(VA_3_2, P0, P1, P2)

FORWARD_D(0, 1, 2)

#define FORWARD_TUPLE_D(TUPLE)                        \
CRADLE_PP_INVOKE(VA_3_2, BOOST_PP_TUPLE_REM(3) TUPLE) \
///////////////////////////////////////////////////////

FORWARD_TUPLE_D((0, 1, 2))

#define FORWARD_LIST_D(LIST)                       \
CRADLE_PP_INVOKE(VA_3_2, BOOST_PP_LIST_ENUM(LIST)) \
////////////////////////////////////////////////////

FORWARD_LIST_D((0, (1, (2, BOOST_PP_NIL))))

#define FORWARD_SEQ_D(SEQ) CRADLE_PP_INVOKE(VA_3_2, BOOST_PP_SEQ_ENUM(SEQ))

FORWARD_SEQ_D((0)(1)(2))

#define FORWARD_VA_D_0(...) CRADLE_PP_INVOKE(VA_3_2, __VA_ARGS__)

FORWARD_VA_D_0(0, 1, 2)

#define FORWARD_VA_D_1(P0, ...) CRADLE_PP_INVOKE(VA_3_2, P0, __VA_ARGS__)

FORWARD_VA_D_1(0, 1, 2)

#define FORWARD_VA_D_REV_1(P0, ...) CRADLE_PP_INVOKE(VA_3_2, __VA_ARGS__, P0)

FORWARD_VA_D_REV_1(2, 0, 1)

#define FORWARD_VA_D_2(P0, P1, ...) CRADLE_PP_INVOKE(VA_3_2, P0, P1, __VA_ARGS__)

FORWARD_VA_D_2(0, 1, 2)

#define FORWARD_VA_D_REV_2_1(P0, P1, ...) CRADLE_PP_INVOKE(VA_3_2, P0, __VA_ARGS__, P1)

FORWARD_VA_D_REV_2_1(0, 2, 1)

#define FORWARD_VA_D_REV_2_2(P0, P1, ...) CRADLE_PP_INVOKE(VA_3_2, P1, P0, __VA_ARGS__)

FORWARD_VA_D_REV_2_2(1, 0, 2)

#define FORWARD_VA_D_REV_2_3(P0, P1, ...) CRADLE_PP_INVOKE(VA_3_2, P1, __VA_ARGS__, P0)

FORWARD_VA_D_REV_2_3(2, 0, 1)

#define FORWARD_VA_D_REV_2_4(P0, P1, ...) CRADLE_PP_INVOKE(VA_3_2, __VA_ARGS__, P0, P1)

FORWARD_VA_D_REV_2_4(1, 2, 0)

#define FORWARD_VA_D_REV_2_5(P0, P1, ...) CRADLE_PP_INVOKE(VA_3_2, __VA_ARGS__, P1, P0)

FORWARD_VA_D_REV_2_5(2, 1, 0)
