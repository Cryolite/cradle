#if !defined(CRADLE_PREPROCESSOR_VA_REFUSE_EMPTY_HPP_INCLUDE_GUARD)
#define CRADLE_PREPROCESSOR_VA_REFUSE_EMPTY_HPP_INCLUDE_GUARD

#include <boost/preprocessor/facilities/expand.hpp>
#include <boost/preprocessor/debug/assert.hpp>


#define CRADLE_PP_VA_REFUSE_EMPTY_IMPL_E BOOST_PP_ASSERT(0)

#define CRADLE_PP_VA_REFUSE_EMPTY_IMPL_D(...)

#define CRADLE_PP_VA_REFUSE_EMPTY_IMPL_C(...)    \
(__VA_ARGS__ ## E)                               \
//////////////////////////////////////////////////

#define CRADLE_PP_VA_REFUSE_EMPTY_IMPL_B(...)    \
(CRADLE_PP_VA_REFUSE_EMPTY_IMPL_ ## __VA_ARGS__) \
//////////////////////////////////////////////////

#define CRADLE_PP_VA_REFUSE_EMPTY_IMPL_A(VA_TUPLE) \
CRADLE_PP_VA_REFUSE_EMPTY_IMPL_D                   \
  BOOST_PP_EXPAND(                                 \
    CRADLE_PP_VA_REFUSE_EMPTY_IMPL_C               \
      CRADLE_PP_VA_REFUSE_EMPTY_IMPL_B VA_TUPLE)   \
////////////////////////////////////////////////////

#define CRADLE_PP_VA_REFUSE_EMPTY(...)          \
CRADLE_PP_VA_REFUSE_EMPTY_IMPL_A((__VA_ARGS__)) \
/////////////////////////////////////////////////


#endif // !defined(CRADLE_PREPROCESSOR_VA_REFUSE_EMPTY_HPP_INCLUDE_GUARD)
