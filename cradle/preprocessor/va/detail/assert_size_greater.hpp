#if !defined(CRADLE_PREPROCESSOR_VA_DETAIL_ASSERT_SIZE_GREATER_HPP_INCLUDE_GUARD)
#define CRADLE_PREPROCESSOR_VA_DETAIL_ASSERT_SIZE_GREATER_HPP_INCLUDE_GUARD

#include <cradle/preprocessor/va/detail/tuple_head.hpp>
#include <cradle/preprocessor/va/refuse_empty.hpp>
#include <cradle/preprocessor/va/detail/size.hpp>

#include <boost/preprocessor/arithmetic/inc.hpp>
#include <boost/preprocessor/comparison/greater.hpp>
#include <boost/preprocessor/control/iif.hpp>
#include <boost/preprocessor/tuple/eat.hpp>
#include <boost/preprocessor/debug/assert.hpp>


#define CRADLE_PP_VA_ASSERT_SIZE_GREATER_IMPL_B(N, SIZE) \
BOOST_PP_IIF(BOOST_PP_GREATER(SIZE, BOOST_PP_INC(N)),    \
             BOOST_PP_TUPLE_EAT(1),                      \
             BOOST_PP_ASSERT)(0)                         \
//////////////////////////////////////////////////////////

#define CRADLE_PP_VA_ASSERT_SIZE_GREATER_IMPL_A(VA_TUPLE)                 \
CRADLE_PP_VA_ASSERT_SIZE_GREATER_IMPL_B(CRADLE_PP_VA_TUPLE_HEAD VA_TUPLE, \
                                        CRADLE_PP_VA_SIZE_IMPL VA_TUPLE)  \
///////////////////////////////////////////////////////////////////////////

#define CRADLE_PP_VA_ASSERT_SIZE_GREATER(...)          \
CRADLE_PP_VA_REFUSE_EMPTY(__VA_ARGS__)                 \
CRADLE_PP_VA_ASSERT_SIZE_GREATER_IMPL_A((__VA_ARGS__)) \
//////////////////////////////////////////////////////


#endif // !defined(CRADLE_PREPROCESSOR_VA_DETAIL_ASSERT_SIZE_GREATER_HPP_INCLUDE_GUARD)
