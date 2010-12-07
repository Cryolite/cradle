#if !defined(CRADLE_PREPROCESSOR_VA_TO_LIST_HPP_INCLUDE_GUARD)
#define CRADLE_PREPROCESSOR_VA_TO_LIST_HPP_INCLUDE_GUARD

#include <cradle/preprocessor/va/size.hpp>

#include <boost/preprocessor/tuple/to_list.hpp>


#define CRADLE_PP_VA_TO_LIST_IMPL_1(SIZE, TUPLE) \
BOOST_PP_TUPLE_TO_LIST(SIZE, TUPLE)              \
  /**/

#define CRADLE_PP_VA_TO_LIST(...)                                          \
CRADLE_PP_VA_TO_LIST_IMPL_1(CRADLE_PP_VA_SIZE(__VA_ARGS__), (__VA_ARGS__)) \
  /**/


#endif // !defined(CRADLE_PREPROCESSOR_VA_TO_LIST_HPP_INCLUDE_GUARD)
