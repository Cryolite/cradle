#include <cradle/preprocessor/va/for_each_i.hpp>

#include <cradle/preprocessor/config.hpp>
#include <cradle/preprocessor/va/elem.hpp>

#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/arithmetic/add.hpp>
#include <boost/preprocessor/arithmetic/sub.hpp>
#include <boost/preprocessor/comparison/equal.hpp>
#include <boost/preprocessor/repetition/enum_shifted.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>
#include <boost/preprocessor/repetition/repeat_from_to.hpp>
#include <boost/preprocessor/debug/assert.hpp>


#define MACRO_4(Z, I, DATA) I

#define MACRO_3(X, ELEM) BOOST_PP_ASSERT(BOOST_PP_EQUAL(X, 1)) , ELEM

#define MACRO_2(R, DATA, I, ELEM) MACRO_3(BOOST_PP_SUB(ELEM, I), ELEM)

#define MACRO_1(Z, I, N)                                              \
BOOST_PP_ASSERT(                                                      \
  BOOST_PP_EQUAL(                                                     \
    CRADLE_PP_VA_ELEM(                                                \
      I,                                                              \
      0 CRADLE_PP_VA_FOR_EACH_I(                                      \
          MACRO_2,                                                    \
          _,                                                          \
          BOOST_PP_CAT(BOOST_PP_ENUM_SHIFTED_, Z)(N, MACRO_4, _))),   \
    I))                                                               \
  /**/

#define MACRO_0(Z, I, DATA) BOOST_PP_CAT(BOOST_PP_REPEAT_, Z)(I, MACRO_1, I)

BOOST_PP_REPEAT_FROM_TO(1, BOOST_PP_ADD(CRADLE_PP_LIMIT_VA, 1), MACRO_0, _)
