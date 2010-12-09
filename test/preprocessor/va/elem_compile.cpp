#include <cradle/preprocessor/va/elem.hpp>

#include <cradle/preprocessor/config.hpp>
#include <cradle/preprocessor/va/iota.hpp>

#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/arithmetic/inc.hpp>
#include <boost/preprocessor/comparison/equal.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>
#include <boost/preprocessor/repetition/repeat_from_to.hpp>
#include <boost/preprocessor/facilities/expand.hpp>
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


#define MACRO_B(Z, I, N)                                         \
BOOST_PP_ASSERT(                                                 \
  BOOST_PP_EQUAL(CRADLE_PP_VA_ELEM(I)(CRADLE_PP_VA_IOTA(N)), I)) \
//////////////////////////////////////////////////////////////////

#define MACRO_A(Z, N, DATA) BOOST_PP_CAT(BOOST_PP_REPEAT_, Z)(N, MACRO_B, N) \
//////////////////////////////////////////////////////////////////////////////

BOOST_PP_REPEAT_FROM_TO(2, BOOST_PP_INC(CRADLE_PP_LIMIT_VA), MACRO_A, _)


#define MACRO_E(I, ...) CRADLE_PP_VA_ELEM(I)(__VA_ARGS__)

#define MACRO_D(Z, I, N)                                             \
BOOST_PP_ASSERT(BOOST_PP_EQUAL(MACRO_E(I, CRADLE_PP_VA_IOTA(N)), I)) \
//////////////////////////////////////////////////////////////////////

#define MACRO_C(Z, N, DATA) BOOST_PP_CAT(BOOST_PP_REPEAT_, Z)(N, MACRO_D, N) \
//////////////////////////////////////////////////////////////////////////////

BOOST_PP_REPEAT_FROM_TO(2, BOOST_PP_INC(CRADLE_PP_LIMIT_VA), MACRO_C, _)


#define MACRO_H(I, VA_TUPLE) BOOST_PP_EXPAND(CRADLE_PP_VA_ELEM(I) VA_TUPLE)

#define MACRO_G(Z, I, N)                                               \
BOOST_PP_ASSERT(BOOST_PP_EQUAL(MACRO_H(I, (CRADLE_PP_VA_IOTA(N))), I)) \
////////////////////////////////////////////////////////////////////////

#define MACRO_F(Z, N, DATA) BOOST_PP_CAT(BOOST_PP_REPEAT_, Z)(N, MACRO_G, N) \
//////////////////////////////////////////////////////////////////////////////

BOOST_PP_REPEAT_FROM_TO(2, BOOST_PP_INC(CRADLE_PP_LIMIT_VA), MACRO_F, _)
