#if !defined(CRADLE_PREPROCESSOR_VA_REFUSE_EMPTY_HPP_INCLUDE_GUARD)
#define CRADLE_PREPROCESSOR_VA_REFUSE_EMPTY_HPP_INCLUDE_GUARD

#include <cradle/preprocessor/va/detail/size.hpp>

#include <boost/preprocessor/comparison/greater.hpp>
#include <boost/preprocessor/control/iif.hpp>
#include <boost/preprocessor/facilities/expand.hpp>
#include <boost/preprocessor/debug/assert.hpp>


#define CRADLE_PP_VA_REFUSE_EMPTY_IMPL_F BOOST_PP_ASSERT(0)

#define CRADLE_PP_VA_REFUSE_EMPTY_IMPL_E(...)

#define CRADLE_PP_VA_REFUSE_EMPTY_IMPL_D(...)    \
(__VA_ARGS__ ## F)                               \
//////////////////////////////////////////////////

#define CRADLE_PP_VA_REFUSE_EMPTY_IMPL_C(...)    \
(CRADLE_PP_VA_REFUSE_EMPTY_IMPL_ ## __VA_ARGS__) \
//////////////////////////////////////////////////

#define CRADLE_PP_VA_REFUSE_EMPTY_IMPL_B(VA_TUPLE)  \
BOOST_PP_EXPAND(                                    \
  CRADLE_PP_VA_REFUSE_EMPTY_IMPL_E                  \
    BOOST_PP_EXPAND(                                \
      CRADLE_PP_VA_REFUSE_EMPTY_IMPL_D              \
        CRADLE_PP_VA_REFUSE_EMPTY_IMPL_C VA_TUPLE)) \
/////////////////////////////////////////////////////

#define CRADLE_PP_VA_REFUSE_EMPTY_IMPL_A(SIZE, VA_TUPLE) \
BOOST_PP_IIF(BOOST_PP_GREATER(SIZE, 1),                  \
             CRADLE_PP_VA_REFUSE_EMPTY_IMPL_E,           \
             CRADLE_PP_VA_REFUSE_EMPTY_IMPL_B)(VA_TUPLE) \
//////////////////////////////////////////////////////////

#define CRADLE_PP_VA_REFUSE_EMPTY(...)                                \
CRADLE_PP_VA_REFUSE_EMPTY_IMPL_A(CRADLE_PP_VA_SIZE_IMPL(__VA_ARGS__), \
                                 (__VA_ARGS__))                       \
///////////////////////////////////////////////////////////////////////


#endif // !defined(CRADLE_PREPROCESSOR_VA_REFUSE_EMPTY_HPP_INCLUDE_GUARD)
