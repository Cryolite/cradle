#include <cradle/preprocessor/config.hpp>
#include <cradle/preprocessor/va/size.hpp>

#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/arithmetic/add.hpp>
#include <boost/preprocessor/comparison/equal.hpp>
#include <boost/preprocessor/repetition/enum.hpp>
#include <boost/preprocessor/repetition/repeat_from_to.hpp>
#include <boost/preprocessor/debug/assert.hpp>


//BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_VA_SIZE(), 2))
//BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_VA_SIZE( ), 2))
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

#define MACRO_1(Z, I, DATA) _

#define MACRO_0(Z, N, DATA)                                                \
BOOST_PP_ASSERT(                                                           \
  BOOST_PP_EQUAL(                                                          \
    CRADLE_PP_VA_SIZE(BOOST_PP_CAT(BOOST_PP_ENUM_, Z)(N, MACRO_1, _)), N)) \
////////////////////////////////////////////////////////////////////////////

BOOST_PP_REPEAT_FROM_TO(3, BOOST_PP_ADD(CRADLE_PP_LIMIT_VA, 1), MACRO_0, _)
