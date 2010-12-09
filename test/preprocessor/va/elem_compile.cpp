#include <cradle/preprocessor/va/elem.hpp>

#include <cradle/preprocessor/config.hpp>
#include <cradle/preprocessor/va/iota.hpp>

#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/arithmetic/inc.hpp>
#include <boost/preprocessor/comparison/equal.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>
#include <boost/preprocessor/repetition/repeat_from_to.hpp>
#include <boost/preprocessor/debug/assert.hpp>


BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_VA_ELEM(0)(0), 0))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_VA_ELEM(0)(0 ), 0))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_VA_ELEM(0)( 0), 0))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_VA_ELEM(0 )(0), 0))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_VA_ELEM( 0)(0), 0))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_VA_ELEM(0)( 0 ), 0))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_VA_ELEM(0 )(0 ), 0))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_VA_ELEM( 0)(0 ), 0))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_VA_ELEM(0 )( 0), 0))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_VA_ELEM( 0)( 0), 0))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_VA_ELEM( 0 )(0), 0))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_VA_ELEM(0 )( 0 ), 0))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_VA_ELEM( 0)( 0 ), 0))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_VA_ELEM( 0 )(0 ), 0))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_VA_ELEM( 0 )( 0), 0))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_VA_ELEM( 0 )( 0 ), 0))

#define MACRO_1(Z, I, N)                                         \
BOOST_PP_ASSERT(                                                 \
  BOOST_PP_EQUAL(CRADLE_PP_VA_ELEM(I)(CRADLE_PP_VA_IOTA(N)), I)) \
//////////////////////////////////////////////////////////////////

#define MACRO_0(Z, N, DATA) BOOST_PP_CAT(BOOST_PP_REPEAT_, Z)(N, MACRO_1, N) \
//////////////////////////////////////////////////////////////////////////////

BOOST_PP_REPEAT_FROM_TO(2, BOOST_PP_INC(CRADLE_PP_LIMIT_VA), MACRO_0, _)
