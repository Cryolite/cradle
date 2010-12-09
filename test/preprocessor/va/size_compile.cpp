#include <cradle/preprocessor/va/size.hpp>

#include <cradle/preprocessor/config.hpp>
#include <cradle/preprocessor/va/iota.hpp>

#include <boost/preprocessor/arithmetic/inc.hpp>
#include <boost/preprocessor/comparison/equal.hpp>
#include <boost/preprocessor/repetition/repeat_from_to.hpp>
#include <boost/preprocessor/facilities/expand.hpp>
#include <boost/preprocessor/debug/assert.hpp>


BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_VA_SIZE(0), 1))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_VA_SIZE(0 ), 1))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_VA_SIZE( 0), 1))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_VA_SIZE( 0 ), 1))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_VA_SIZE(0,1), 2))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_VA_SIZE(0,1 ), 2))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_VA_SIZE(0, 1), 2))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_VA_SIZE( 0,1), 2))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_VA_SIZE(0, 1 ), 2))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_VA_SIZE( 0,1 ), 2))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_VA_SIZE( 0, 1), 2))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_VA_SIZE( 0, 1 ), 2))


#define MACRO_A(Z, N, DATA)                      \
BOOST_PP_ASSERT(                                 \
  BOOST_PP_EQUAL(                                \
    CRADLE_PP_VA_SIZE(CRADLE_PP_VA_IOTA(N)), N)) \
//////////////////////////////////////////////////

BOOST_PP_REPEAT_FROM_TO(3, BOOST_PP_INC(CRADLE_PP_LIMIT_VA), MACRO_A, _)


#define MACRO_B(...) CRADLE_PP_VA_SIZE(__VA_ARGS__)

#define MACRO_C(Z, N, DATA)                         \
BOOST_PP_ASSERT(                                    \
  BOOST_PP_EQUAL(MACRO_B(CRADLE_PP_VA_IOTA(N)), N)) \
/////////////////////////////////////////////////////

BOOST_PP_REPEAT_FROM_TO(3, BOOST_PP_INC(CRADLE_PP_LIMIT_VA), MACRO_C, _)


#define MACRO_D(VA_TUPLE) BOOST_PP_EXPAND(CRADLE_PP_VA_SIZE VA_TUPLE)

#define MACRO_E(Z, N, DATA)                           \
BOOST_PP_ASSERT(                                      \
  BOOST_PP_EQUAL(MACRO_D((CRADLE_PP_VA_IOTA(N))), N)) \
///////////////////////////////////////////////////////

BOOST_PP_REPEAT_FROM_TO(3, BOOST_PP_INC(CRADLE_PP_LIMIT_VA), MACRO_E, _)
