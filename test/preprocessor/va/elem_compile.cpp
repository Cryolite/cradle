#include <cradle/preprocessor/config.hpp>
#include <cradle/preprocessor/va/elem.hpp>

#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/arithmetic/add.hpp>
#include <boost/preprocessor/comparison/equal.hpp>
#include <boost/preprocessor/repetition/enum.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>
#include <boost/preprocessor/repetition/repeat_from_to.hpp>
#include <boost/preprocessor/debug/assert.hpp>


BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_VA_ELEM(0,0), 0))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_VA_ELEM(0,0 ), 0))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_VA_ELEM(0, 0), 0))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_VA_ELEM(0 ,0), 0))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_VA_ELEM( 0,0), 0))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_VA_ELEM(0, 0 ), 0))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_VA_ELEM(0 ,0 ), 0))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_VA_ELEM( 0,0 ), 0))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_VA_ELEM(0 , 0), 0))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_VA_ELEM( 0, 0), 0))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_VA_ELEM( 0 ,0), 0))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_VA_ELEM(0 , 0 ), 0))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_VA_ELEM( 0, 0 ), 0))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_VA_ELEM( 0 ,0 ), 0))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_VA_ELEM( 0 , 0), 0))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_VA_ELEM( 0 , 0 ), 0))

#define MACRO_2(Z, I, DATA) I

#define MACRO_1(Z, I, N)                                                      \
BOOST_PP_ASSERT(                                                              \
  BOOST_PP_EQUAL(                                                             \
    CRADLE_PP_VA_ELEM(                                                        \
      I, BOOST_PP_CAT(BOOST_PP_ENUM_, Z)(N, MACRO_2, _)), I))                 \
  /**/

#define MACRO_0(Z, N, DATA) BOOST_PP_CAT(BOOST_PP_REPEAT_, Z)(N, MACRO_1, N)

BOOST_PP_REPEAT_FROM_TO(2, BOOST_PP_ADD(CRADLE_PP_LIMIT_VA, 1), MACRO_0, _)
