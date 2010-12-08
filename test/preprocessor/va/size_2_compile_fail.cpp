#include <cradle/preprocessor/va/size.hpp>

#include <boost/preprocessor/comparison/equal.hpp>
#include <boost/preprocessor/tuple/eat.hpp>
#include <boost/preprocessor/facilities/expand.hpp>
#include <boost/preprocessor/debug/assert.hpp>


#define MACRO(...) int i = CRADLE_PP_VA_SIZE(__VA_ARGS__);

MACRO()
