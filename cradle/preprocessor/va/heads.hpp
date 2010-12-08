#if !defined(CRADLE_PREPROCESSOR_VA_HEADS_HPP_INCLUDE_GUARD)
#define CRADLE_PREPROCESSOR_VA_HEADS_HPP_INCLUDE_GUARD

//#include <cradle/preprocessor/va/detail/assert_size_greater.hpp>
#include <cradle/preprocessor/va/detail/heads.hpp>

#include <boost/preprocessor/cat.hpp>


#define CRADLE_PP_VA_HEADS(N)                      \
/*CRADLE_PP_VA_ASSERT_SIZE_GREATER(1, __VA_ARGS__)*/   \
BOOST_PP_CAT(CRADLE_PP_VA_DETAIL_HEADS_IMPL_A_, N) \
////////////////////////////////////////////////////


#endif // !defined(CRADLE_PREPROCESSOR_VA_HEADS_HPP_INCLUDE_GUARD)
