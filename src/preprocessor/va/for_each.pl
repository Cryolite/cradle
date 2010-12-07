$max_count = 256;

print << 'HEADER';
#if !defined(CRADLE_PP_VA_FOR_EACH_HPP_INCLUDE_GUARD)
#define CRADLE_PP_VA_FOR_EACH_HPP_INCLUDE_GUARD

#include <cradle/preprocessor/va/to_list.hpp>

#include <boost/preprocessor/list/for_each.hpp>


#define CRADLE_PP_VA_FOR_EACH(MACRO, DATA, ...)                        \
BOOST_PP_LIST_FOR_EACH(MACRO, DATA, CRADLE_PP_VA_TO_LIST(__VA_ARGS__)) \
  /**/

HEADER
for ($count = 0; $count <= $max_count; ++$count) {
  print << "DEFINITION_OF_FOR_EACH_R";
#define CRADLE_PP_VA_FOR_EACH_${count}(MACRO, DATA, ...)                        \\
BOOST_PP_LIST_FOR_EACH_${count}(MACRO, DATA, CRADLE_PP_VA_TO_LIST(__VA_ARGS__)) \\
  /**/

DEFINITION_OF_FOR_EACH_R
}
print << 'FOOTER';
#endif // !defined(CRADLE_PP_VA_FOR_EACH_HPP_INCLUDE_GUARD)
FOOTER
