#if !defined(CRADLE_PREPROCESSOR_VA_ELEM_HPP_INCLUDE_GUARD)
#define CRADLE_PREPROCESSOR_VA_ELEM_HPP_INCLUDE_GUARD

#include <cradle/preprocessor/config.hpp>
#include <cradle/preprocessor/va/size.hpp>

#include <boost/preprocessor/config/limits.hpp>
#include <boost/preprocessor/comparison/less_equal.hpp>
#include <boost/preprocessor/tuple/elem.hpp>
#include <boost/preprocessor/debug/assert.hpp>


BOOST_PP_ASSERT(BOOST_PP_LESS_EQUAL(CRADLE_PP_LIMIT_VA, BOOST_PP_LIMIT_TUPLE))

#define CRADLE_PP_VA_ELEM_IMPL_0(INDEX, SIZE, TUPLE) \
BOOST_PP_TUPLE_ELEM(SIZE, INDEX, TUPLE)              \
  /**/

#define CRADLE_PP_VA_ELEM(INDEX, ...)                     \
CRADLE_PP_VA_ELEM_IMPL_0(                                 \
  INDEX, CRADLE_PP_VA_SIZE(__VA_ARGS__), (__VA_ARGS__))   \
  /**/


#endif // !defined(CRADLE_PREPROCESSOR_VA_ELEM_HPP_INCLUDE_GUARD)
