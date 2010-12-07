#include <cradle/preprocessor/va/cat.hpp>

#include <boost/preprocessor/comparison/equal.hpp>
#include <boost/preprocessor/debug/assert.hpp>


BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_VA_CAT(0), 0))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_VA_CAT(1, 2), 12))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_VA_CAT(1, 2, 3), 123))
