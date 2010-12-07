#include <cradle/preprocessor/va/reverse.hpp>

#include <cradle/preprocessor/config.hpp>
#include <cradle/preprocessor/va/for_each_i.hpp>

#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/arithmetic/inc.hpp>
#include <boost/preprocessor/arithmetic/add.hpp>
#include <boost/preprocessor/comparison/equal.hpp>
#include <boost/preprocessor/repetition/enum.hpp>
#include <boost/preprocessor/repetition/repeat_from_to.hpp>
#include <boost/preprocessor/debug/assert.hpp>


#define MACRO_3(R, SIZE, I, ELEM)                                          \
BOOST_PP_ASSERT(BOOST_PP_EQUAL(BOOST_PP_INC(BOOST_PP_ADD(I, ELEM)), SIZE)) \
  /**/

#define MACRO_2(SIZE, ...)                          \
CRADLE_PP_VA_FOR_EACH_I(MACRO_3, SIZE, __VA_ARGS__) \
  /**/

#define MACRO_1(Z, I, DATA) I

#define MACRO_0(Z, I, DATA)                                             \
MACRO_2(                                                                \
  I,                                                                    \
  CRADLE_PP_VA_REVERSE(BOOST_PP_CAT(BOOST_PP_ENUM_, Z)(I, MACRO_1, _))) \
  /**/

BOOST_PP_REPEAT_FROM_TO(1, BOOST_PP_INC(CRADLE_PP_LIMIT_VA), MACRO_0, _)
