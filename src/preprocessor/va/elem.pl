$max_count = 24;

print << 'HEADER';
#if !defined(CRADLE_PREPROCESSOR_VA_ELEM_HPP_INCLUDE_GUARD)
#define CRADLE_PREPROCESSOR_VA_ELEM_HPP_INCLUDE_GUARD

#include <cradle/preprocessor/config.hpp>
#include <cradle/preprocessor/va/size.hpp>

#include <boost/preprocessor/config/limits.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/comparison/less_equal.hpp>
#include <boost/preprocessor/tuple/elem.hpp>
#include <boost/preprocessor/facilities/expand.hpp>
#include <boost/preprocessor/debug/assert.hpp>


BOOST_PP_ASSERT(BOOST_PP_LESS_EQUAL(CRADLE_PP_LIMIT_VA, BOOST_PP_LIMIT_TUPLE))

HEADER
for ($count = 0; $count <= $max_count; ++$count) {
  print << "DEFINITION_OF_VA_ELEM_IMPL";
#define CRADLE_PP_VA_ELEM_IMPL_C_${count}(VA_TUPLE)               \\
(BOOST_PP_EXPAND(CRADLE_PP_VA_SIZE VA_TUPLE), ${count}, VA_TUPLE) \\
////////////////////////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_B_${count}(VA_TUPLE)                              \\
BOOST_PP_EXPAND(BOOST_PP_TUPLE_ELEM CRADLE_PP_VA_ELEM_IMPL_C_${count}(VA_TUPLE)) \\
///////////////////////////////////////////////////////////////////////////

#define CRADLE_PP_VA_ELEM_IMPL_A_${count}(...)   \\
CRADLE_PP_VA_ELEM_IMPL_B_${count}((__VA_ARGS__)) \\
///////////////////////////////////////////

DEFINITION_OF_VA_ELEM_IMPL
}
print << 'FOOTER';
#define CRADLE_PP_VA_ELEM(I) BOOST_PP_CAT(CRADLE_PP_VA_ELEM_IMPL_A_, I)


#endif // !defined(CRADLE_PREPROCESSOR_VA_ELEM_HPP_INCLUDE_GUARD)
FOOTER
