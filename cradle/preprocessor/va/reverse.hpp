#if !defined(CRADLE_PREPROCESSOR_VA_REVERSE_HPP_INCLUDE_GUARD)
#define CRADLE_PREPROCESSOR_VA_REVERSE_HPP_INCLUDE_GUARD

#include <cradle/preprocessor/va/size.hpp>

#include <boost/preprocessor/tuple/reverse.hpp>
#include <boost/preprocessor/tuple/rem.hpp>


#define CRADLE_PP_VA_REVERSE_IMPL(SIZE, TUPLE)                     \
BOOST_PP_TUPLE_REM_CTOR(SIZE, BOOST_PP_TUPLE_REVERSE(SIZE, TUPLE)) \
  /**/

#define CRADLE_PP_VA_REVERSE(...)                                        \
CRADLE_PP_VA_REVERSE_IMPL(CRADLE_PP_VA_SIZE(__VA_ARGS__), (__VA_ARGS__)) \
  /**/


#endif // !defined(CRADLE_PREPROCESSOR_VA_REVERSE_HPP_INCLUDE_GUARD)
