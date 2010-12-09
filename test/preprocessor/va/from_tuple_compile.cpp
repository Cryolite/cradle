#include <cradle/preprocessor/va/from_tuple.hpp>

#include <cradle/preprocessor/config.hpp>
#include <cradle/preprocessor/va/size.hpp>
#include <cradle/preprocessor/va/iota.hpp>

#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/arithmetic/inc.hpp>
#include <boost/preprocessor/comparison/equal.hpp>
#include <boost/preprocessor/repetition/repeat_from_to.hpp>
#include <boost/preprocessor/debug/assert.hpp>


BOOST_PP_ASSERT(
  BOOST_PP_EQUAL(CRADLE_PP_VA_SIZE(CRADLE_PP_VA_FROM_TUPLE((0))), 1))
BOOST_PP_ASSERT(
  BOOST_PP_EQUAL(CRADLE_PP_VA_SIZE(CRADLE_PP_VA_FROM_TUPLE((0 ))), 1))
BOOST_PP_ASSERT(
  BOOST_PP_EQUAL(CRADLE_PP_VA_SIZE(CRADLE_PP_VA_FROM_TUPLE(( 0))), 1))
BOOST_PP_ASSERT(
  BOOST_PP_EQUAL(CRADLE_PP_VA_SIZE(CRADLE_PP_VA_FROM_TUPLE((0,1))), 2))
BOOST_PP_ASSERT(
  BOOST_PP_EQUAL(CRADLE_PP_VA_SIZE(CRADLE_PP_VA_FROM_TUPLE((0,1 ))), 2))
BOOST_PP_ASSERT(
  BOOST_PP_EQUAL(CRADLE_PP_VA_SIZE(CRADLE_PP_VA_FROM_TUPLE((0, 1))), 2))
BOOST_PP_ASSERT(
  BOOST_PP_EQUAL(CRADLE_PP_VA_SIZE(CRADLE_PP_VA_FROM_TUPLE((0 ,1))), 2))
BOOST_PP_ASSERT(
  BOOST_PP_EQUAL(CRADLE_PP_VA_SIZE(CRADLE_PP_VA_FROM_TUPLE(( 0,1))), 2))
BOOST_PP_ASSERT(
  BOOST_PP_EQUAL(CRADLE_PP_VA_SIZE(CRADLE_PP_VA_FROM_TUPLE((0, 1 ))), 2))
BOOST_PP_ASSERT(
  BOOST_PP_EQUAL(CRADLE_PP_VA_SIZE(CRADLE_PP_VA_FROM_TUPLE((0 ,1 ))), 2))
BOOST_PP_ASSERT(
  BOOST_PP_EQUAL(CRADLE_PP_VA_SIZE(CRADLE_PP_VA_FROM_TUPLE(( 0,1 ))), 2))
BOOST_PP_ASSERT(
  BOOST_PP_EQUAL(CRADLE_PP_VA_SIZE(CRADLE_PP_VA_FROM_TUPLE((0 , 1))), 2))
BOOST_PP_ASSERT(
  BOOST_PP_EQUAL(CRADLE_PP_VA_SIZE(CRADLE_PP_VA_FROM_TUPLE(( 0, 1))), 2))
BOOST_PP_ASSERT(
  BOOST_PP_EQUAL(CRADLE_PP_VA_SIZE(CRADLE_PP_VA_FROM_TUPLE(( 0 ,1))), 2))
BOOST_PP_ASSERT(
  BOOST_PP_EQUAL(CRADLE_PP_VA_SIZE(CRADLE_PP_VA_FROM_TUPLE(( 0 , 1))), 2))
BOOST_PP_ASSERT(
  BOOST_PP_EQUAL(CRADLE_PP_VA_SIZE(CRADLE_PP_VA_FROM_TUPLE(( 0 ,1 ))), 2))
BOOST_PP_ASSERT(
  BOOST_PP_EQUAL(CRADLE_PP_VA_SIZE(CRADLE_PP_VA_FROM_TUPLE(( 0, 1 ))), 2))
BOOST_PP_ASSERT(
  BOOST_PP_EQUAL(CRADLE_PP_VA_SIZE(CRADLE_PP_VA_FROM_TUPLE((0 , 1 ))), 2))
BOOST_PP_ASSERT(
  BOOST_PP_EQUAL(CRADLE_PP_VA_SIZE(CRADLE_PP_VA_FROM_TUPLE(( 0 , 1 ))), 2))


#define MACRO_A(Z, I, DATA)                                             \
BOOST_PP_ASSERT(                                                        \
  BOOST_PP_EQUAL(                                                       \
    CRADLE_PP_VA_SIZE(CRADLE_PP_VA_FROM_TUPLE((CRADLE_PP_VA_IOTA(I)))), \
    I))                                                                 \
/////////////////////////////////////////////////////////////////////////

BOOST_PP_REPEAT_FROM_TO(3, BOOST_PP_INC(CRADLE_PP_LIMIT_VA), MACRO_A, _)


#define T_1 (_)
#define T_2 (_,_)
#define T_3 (_,_,_)
#define T_4 (_,_,_,_)
#define T_5 (_,_,_,_,_)
#define T_6 (_,_,_,_,_,_)
#define T_7 (_,_,_,_,_,_,_)
#define T_8 (_,_,_,_,_,_,_,_)
#define T_9 (_,_,_,_,_,_,_,_,_)
#define T_10 (_,_,_,_,_,_,_,_,_,_)
#define T_11 (_,_,_,_,_,_,_,_,_,_,_)
#define T_12 (_,_,_,_,_,_,_,_,_,_,_,_)
#define T_13 (_,_,_,_,_,_,_,_,_,_,_,_,_)
#define T_14 (_,_,_,_,_,_,_,_,_,_,_,_,_,_)
#define T_15 (_,_,_,_,_,_,_,_,_,_,_,_,_,_,_)
#define T_16 (_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_)
#define T_17 (_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_)
#define T_18 (_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_)
#define T_19 (_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_)
#define T_20 (_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_)
#define T_21 (_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_)
#define T_22 (_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_)
#define T_23 (_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_)
#define T_24 (_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_)
#define T_25 (_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_)

#define MACRO_B(Z, I, DATA)                                          \
BOOST_PP_ASSERT(                                                     \
  BOOST_PP_EQUAL(                                                    \
    CRADLE_PP_VA_SIZE(CRADLE_PP_VA_FROM_TUPLE(BOOST_PP_CAT(T_, I))), \
    I))                                                              \
//////////////////////////////////////////////////////////////////////

BOOST_PP_REPEAT_FROM_TO(1, BOOST_PP_INC(CRADLE_PP_LIMIT_VA), MACRO_B, _)
