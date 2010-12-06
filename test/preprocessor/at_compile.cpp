#include <cradle/preprocessor/at.hpp>

#include <boost/preprocessor/comparison/equal.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>
#include <boost/preprocessor/debug/assert.hpp>

BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_AT(0,0), 0))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_AT(0,0 ), 0))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_AT(0, 0), 0))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_AT(0 ,0), 0))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_AT( 0,0), 0))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_AT(0, 0 ), 0))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_AT(0 ,0 ), 0))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_AT( 0,0 ), 0))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_AT(0 , 0), 0))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_AT( 0, 0), 0))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_AT( 0 ,0), 0))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_AT(0 , 0 ), 0))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_AT( 0, 0 ), 0))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_AT( 0 ,0 ), 0))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_AT( 0 , 0), 0))

BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_AT(0, 0, 1), 0))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_AT(1, 0, 1), 1))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_AT(0, 0, 1, 2), 0))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_AT(1, 0, 1, 2), 1))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_AT(2, 0, 1, 2), 2))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_AT(0, 0, 1, 2, 3), 0))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_AT(1, 0, 1, 2, 3), 1))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_AT(2, 0, 1, 2, 3), 2))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_AT(3, 0, 1, 2, 3), 3))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_AT(0, 0, 1, 2, 3, 4), 0))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_AT(1, 0, 1, 2, 3, 4), 1))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_AT(2, 0, 1, 2, 3, 4), 2))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_AT(3, 0, 1, 2, 3, 4), 3))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_AT(4, 0, 1, 2, 3, 4), 4))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_AT(0, 0, 1, 2, 3, 4, 5), 0))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_AT(1, 0, 1, 2, 3, 4, 5), 1))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_AT(2, 0, 1, 2, 3, 4, 5), 2))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_AT(3, 0, 1, 2, 3, 4, 5), 3))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_AT(4, 0, 1, 2, 3, 4, 5), 4))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_AT(5, 0, 1, 2, 3, 4, 5), 5))

#define MACRO_126(Z, INDEX, DATA)                                  \
BOOST_PP_ASSERT(                                                   \
  BOOST_PP_EQUAL(                                                  \
    CRADLE_PP_AT(INDEX,                                            \
                 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,                     \
                 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,           \
                 20, 21, 22, 23, 24, 25, 26, 27, 28, 29,           \
                 30, 31, 32, 33, 34, 35, 36, 37, 38, 39,           \
                 40, 41, 42, 43, 44, 45, 46, 47, 48, 49,           \
                 50, 51, 52, 53, 54, 55, 56, 57, 58, 59,           \
                 60, 61, 62, 63, 64, 65, 66, 67, 68, 69,           \
                 70, 71, 72, 73, 74, 75, 76, 77, 78, 79,           \
                 80, 81, 82, 83, 84, 85, 86, 87, 88, 89,           \
                 90, 91, 92, 93, 94, 95, 96, 97, 98, 99,           \
                 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, \
                 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, \
                 120, 121, 122, 123, 124, 125), INDEX))            \
  /**/

BOOST_PP_REPEAT(126, MACRO_126, _)

#define MACRO_127(Z, INDEX, DATA)                                  \
BOOST_PP_ASSERT(                                                   \
  BOOST_PP_EQUAL(                                                  \
    CRADLE_PP_AT(INDEX,                                            \
                 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,                     \
                 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,           \
                 20, 21, 22, 23, 24, 25, 26, 27, 28, 29,           \
                 30, 31, 32, 33, 34, 35, 36, 37, 38, 39,           \
                 40, 41, 42, 43, 44, 45, 46, 47, 48, 49,           \
                 50, 51, 52, 53, 54, 55, 56, 57, 58, 59,           \
                 60, 61, 62, 63, 64, 65, 66, 67, 68, 69,           \
                 70, 71, 72, 73, 74, 75, 76, 77, 78, 79,           \
                 80, 81, 82, 83, 84, 85, 86, 87, 88, 89,           \
                 90, 91, 92, 93, 94, 95, 96, 97, 98, 99,           \
                 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, \
                 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, \
                 120, 121, 122, 123, 124, 125, 126), INDEX))       \
  /**/

BOOST_PP_REPEAT(127, MACRO_127, _)
