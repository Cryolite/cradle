#include <cradle/preprocessor/va/refuse_empty.hpp>


#define MACRO(...) CRADLE_PP_VA_REFUSE_EMPTY(__VA_ARGS__)

MACRO( )
