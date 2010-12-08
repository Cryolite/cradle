#include <cradle/preprocessor/va/heads.hpp>

#include <cradle/preprocessor/va/iota.hpp>

#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/arithmetic/inc.hpp>
#include <boost/preprocessor/comparison/equal.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>
#include <boost/preprocessor/repetition/repeat_from_to.hpp>
#include <boost/preprocessor/tuple/elem.hpp>
#include <boost/preprocessor/debug/assert.hpp>


#define MACRO_D(I, M, N)                                                      \
BOOST_PP_ASSERT(                                                              \
  BOOST_PP_EQUAL(                                                             \
    BOOST_PP_TUPLE_ELEM(M, I, (CRADLE_PP_VA_HEADS(M, CRADLE_PP_VA_IOTA(N)))), \
    I))                                                                       \
///////////////////////////////////////////////////////////////////////////////

#define MACRO_C(Z, I, DATA)                                                  \
MACRO_D(I, BOOST_PP_TUPLE_ELEM(2, 0, DATA), BOOST_PP_TUPLE_ELEM(2, 1, DATA)) \
//////////////////////////////////////////////////////////////////////////////

#define MACRO_B(Z, I, N) BOOST_PP_CAT(BOOST_PP_REPEAT_, Z)(I, MACRO_C, (I, N))

#define MACRO_A(Z, I, DATA)                                    \
BOOST_PP_CAT(BOOST_PP_REPEAT_, Z)(BOOST_PP_INC(I), MACRO_B, I) \
////////////////////////////////////////////////////////////////

BOOST_PP_REPEAT_FROM_TO(1, 26, MACRO_A, DATA)
