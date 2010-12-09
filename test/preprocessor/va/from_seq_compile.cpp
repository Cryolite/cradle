#include <cradle/preprocessor/va/from_seq.hpp>

#include <cradle/preprocessor/config.hpp>
#include <cradle/preprocessor/va/size.hpp>

#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/arithmetic/inc.hpp>
#include <boost/preprocessor/comparison/equal.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>
#include <boost/preprocessor/repetition/repeat_from_to.hpp>
#include <boost/preprocessor/list/adt.hpp>
#include <boost/preprocessor/debug/assert.hpp>


#define ASSERT_HELPER(SEQ, SIZE)                                       \
BOOST_PP_ASSERT(                                                       \
  BOOST_PP_EQUAL(CRADLE_PP_VA_SIZE(CRADLE_PP_VA_FROM_SEQ(SEQ)), SIZE)) \
////////////////////////////////////////////////////////////////////////

#define MACRO_B(Z, I, DATA) (I)

#define MACRO_A(Z, I, DATA)                                        \
ASSERT_HELPER(BOOST_PP_CAT(BOOST_PP_REPEAT_, Z)(I, MACRO_B, _), I) \
////////////////////////////////////////////////////////////////////

BOOST_PP_REPEAT_FROM_TO(1, BOOST_PP_INC(CRADLE_PP_LIMIT_VA), MACRO_A, _)
