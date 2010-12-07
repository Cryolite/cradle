#if !defined(CRADLE_PREPROCESSOR_VA_FROM_LIST_HPP_INCLUDE_GUARD)
#define CRADLE_PREPROCESSOR_VA_FROM_LIST_HPP_INCLUDE_GUARD

#include <cradle/preprocessor/va/from_tuple.hpp>

#include <boost/preprocessor/list/to_tuple.hpp>


#define CRADLE_PP_VA_FROM_LIST(LIST)                  \
CRADLE_PP_VA_FROM_TUPLE(BOOST_PP_LIST_TO_TUPLE(LIST)) \
  /**/


#endif // !defined(CRADLE_PREPROCESSOR_VA_FROM_LIST_HPP_INCLUDE_GUARD)
