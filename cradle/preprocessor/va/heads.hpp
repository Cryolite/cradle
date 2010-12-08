#if !defined(CRADLE_PREPROCESSOR_VA_HEADS_HPP_INCLUDE_GUARD)
#define CRADLE_PREPROCESSOR_VA_HEADS_HPP_INCLUDE_GUARD

#include <cradle/preprocessor/va/detail/assert_size_greater.hpp>
#include <cradle/preprocessor/va/detail/heads.hpp>


#define CRADLE_PP_VA_HEADS(...)                  \
CRADLE_PP_VA_ASSERT_SIZE_GREATER(1, __VA_ARGS__) \
CRADLE_PP_VA_HEADS_IMPL(__VA_ARGS__)             \
//////////////////////////////////////////////////


#endif // !defined(CRADLE_PREPROCESSOR_VA_HEADS_HPP_INCLUDE_GUARD)
