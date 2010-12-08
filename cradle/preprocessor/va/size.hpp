#if !defined(CRADLE_PREPROCESSOR_VA_SIZE_HPP_INCLUDE_GUARD)
#define CRADLE_PREPROCESSOR_VA_SIZE_HPP_INCLUDE_GUARD

#include <cradle/preprocessor/va/refuse_empty.hpp>
#include <cradle/preprocessor/va/detail/size.hpp>


#define CRADLE_PP_VA_SIZE(...)         \
CRADLE_PP_VA_REFUSE_EMPTY(__VA_ARGS__) \
CRADLE_PP_VA_SIZE_IMPL(__VA_ARGS__)    \
////////////////////////////////////////


#endif // !defined(CRADLE_PREPROCESSOR_VA_SIZE_HPP_INCLUDE_GUARD)
