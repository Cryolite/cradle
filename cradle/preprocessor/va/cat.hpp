#if !defined(CRADLE_PREPROCESSOR_VA_CAT_HPP_INCLUDE_GUARD)
#define CRADLE_PREPROCESSOR_VA_CAT_HPP_INCLUDE_GUARD

#include <cradle/preprocessor/va/to_list.hpp>

#include <boost/preprocessor/list/cat.hpp>


#define CRADLE_PP_VA_CAT(...)                        \
BOOST_PP_LIST_CAT(CRADLE_PP_VA_TO_LIST(__VA_ARGS__)) \
  /**/


#endif // !defined(CRADLE_PREPROCESSOR_VA_CAT_HPP_INCLUDE_GUARD)
