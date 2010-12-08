#if !defined(CRADLE_PREPROCESSOR_VA_SIZE_HPP_INCLUDE_GUARD)
#define CRADLE_PREPROCESSOR_VA_SIZE_HPP_INCLUDE_GUARD

#include <cradle/preprocessor/va/detail/size.hpp>

#include <boost/preprocessor/tuple/eat.hpp>
#include <boost/preprocessor/facilities/expand.hpp>


#define CRADLE_PP_VA_SIZE_IMPL_A(SIZE, VA_TUPLE)        \
BOOST_PP_EXPAND(BOOST_PP_TUPLE_EAT(SIZE) VA_TUPLE SIZE) \
/////////////////////////////////////////////////////////

#define CRADLE_PP_VA_SIZE(...)                                  \
CRADLE_PP_VA_SIZE_IMPL_A(CRADLE_PP_VA_DETAIL_SIZE(__VA_ARGS__), \
                         (__VA_ARGS__))                         \
/////////////////////////////////////////////////////////////////


#endif // !defined(CRADLE_PREPROCESSOR_VA_SIZE_HPP_INCLUDE_GUARD)
