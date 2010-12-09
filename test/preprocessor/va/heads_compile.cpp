#include <cradle/preprocessor/va/heads.hpp>

#include <cradle/preprocessor/config.hpp>
#include <cradle/preprocessor/va/iota.hpp>

#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/arithmetic/inc.hpp>
#include <boost/preprocessor/comparison/equal.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>
#include <boost/preprocessor/tuple/elem.hpp>
#include <boost/preprocessor/facilities/expand.hpp>
#include <boost/preprocessor/debug/assert.hpp>


#define MACRO_D(I, M, N)                                                       \
BOOST_PP_ASSERT(                                                               \
  BOOST_PP_EQUAL(                                                              \
    BOOST_PP_TUPLE_ELEM(M, I, (CRADLE_PP_VA_HEADS(M)(CRADLE_PP_VA_IOTA(N)))),  \
    I))                                                                        \
////////////////////////////////////////////////////////////////////////////////

#define MACRO_C(Z, I, DATA)                                                  \
MACRO_D(I, BOOST_PP_TUPLE_ELEM(2, 0, DATA), BOOST_PP_TUPLE_ELEM(2, 1, DATA)) \
//////////////////////////////////////////////////////////////////////////////

#define MACRO_B(Z, I, N) BOOST_PP_CAT(BOOST_PP_REPEAT_, Z)(I, MACRO_C, (I, N))

#define MACRO_A(Z, I, DATA)                                    \
BOOST_PP_CAT(BOOST_PP_REPEAT_, Z)(BOOST_PP_INC(I), MACRO_B, I) \
////////////////////////////////////////////////////////////////

BOOST_PP_REPEAT(BOOST_PP_INC(CRADLE_PP_LIMIT_VA), MACRO_A, DATA)


#define MACRO_I(M, ...) CRADLE_PP_VA_HEADS(M)(__VA_ARGS__)

#define MACRO_H(I, M, N)                                           \
BOOST_PP_ASSERT(                                                   \
  BOOST_PP_EQUAL(                                                  \
    BOOST_PP_TUPLE_ELEM(M, I, (MACRO_I(M, CRADLE_PP_VA_IOTA(N)))), \
    I))                                                            \
////////////////////////////////////////////////////////////////////

#define MACRO_G(Z, I, DATA)                                                  \
MACRO_H(I, BOOST_PP_TUPLE_ELEM(2, 0, DATA), BOOST_PP_TUPLE_ELEM(2, 1, DATA)) \
//////////////////////////////////////////////////////////////////////////////

#define MACRO_F(Z, I, N) BOOST_PP_CAT(BOOST_PP_REPEAT_, Z)(I, MACRO_G, (I, N))

#define MACRO_E(Z, I, DATA)                                    \
BOOST_PP_CAT(BOOST_PP_REPEAT_, Z)(BOOST_PP_INC(I), MACRO_F, I) \
////////////////////////////////////////////////////////////////

BOOST_PP_REPEAT(BOOST_PP_INC(CRADLE_PP_LIMIT_VA), MACRO_E, DATA)


#define MACRO_N(M, VA_TUPLE) BOOST_PP_EXPAND(CRADLE_PP_VA_HEADS(M) VA_TUPLE)

#define MACRO_M(I, M, N)                                             \
BOOST_PP_ASSERT(                                                     \
  BOOST_PP_EQUAL(                                                    \
    BOOST_PP_TUPLE_ELEM(M, I, (MACRO_N(M, (CRADLE_PP_VA_IOTA(N))))), \
    I))                                                              \
//////////////////////////////////////////////////////////////////////

#define MACRO_L(Z, I, DATA)                                                  \
MACRO_M(I, BOOST_PP_TUPLE_ELEM(2, 0, DATA), BOOST_PP_TUPLE_ELEM(2, 1, DATA)) \
//////////////////////////////////////////////////////////////////////////////

#define MACRO_K(Z, I, N) BOOST_PP_CAT(BOOST_PP_REPEAT_, Z)(I, MACRO_L, (I, N))

#define MACRO_J(Z, I, DATA)                                    \
BOOST_PP_CAT(BOOST_PP_REPEAT_, Z)(BOOST_PP_INC(I), MACRO_K, I) \
////////////////////////////////////////////////////////////////

BOOST_PP_REPEAT(BOOST_PP_INC(CRADLE_PP_LIMIT_VA), MACRO_J, DATA)
