#if !defined(CRADLE_PREPROCESSOR_VA_FROM_SEQ_HPP_INCLUDE_GUARD)
#define CRADLE_PREPROCESSOR_VA_FROM_SEQ_HPP_INCLUDE_GUARD

#include <cradle/preprocessor/va/from_tuple.hpp>

#include <boost/preprocessor/seq/to_tuple.hpp>


#define CRADLE_PP_VA_FROM_SEQ(SEQ)                  \
CRADLE_PP_VA_FROM_TUPLE(BOOST_PP_SEQ_TO_TUPLE(SEQ)) \
/////////////////////////////////////////////////////


#endif // !defined(CRADLE_PREPROCESSOR_VA_FROM_SEQ_HPP_INCLUDE_GUARD)
