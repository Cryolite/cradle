#include <cradle/preprocessor/arity.hpp>

#include <boost/preprocessor/comparison/equal.hpp>
#include <boost/preprocessor/debug/assert.hpp>


BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_ARITY(), 0))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_ARITY( ), 0))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_ARITY(0), 1))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_ARITY(0 ), 1))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_ARITY( 0), 1))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_ARITY( 0 ), 1))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_ARITY(0,1), 2))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_ARITY(0,1 ), 2))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_ARITY(0, 1), 2))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_ARITY( 0,1), 2))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_ARITY(0, 1 ), 2))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_ARITY( 0,1 ), 2))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_ARITY( 0, 1), 2))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_ARITY( 0, 1 ), 2))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_ARITY(0,1,2), 3))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_ARITY(0,1,2,3), 4))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_ARITY(0,1,2,3,4), 5))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_ARITY(0,1,2,3,4,5), 6))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_ARITY(0,1,2,3,4,5,6), 7))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_ARITY(0,1,2,3,4,5,6,7), 8))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_ARITY(0,1,2,3,4,5,6,7,8), 9))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_ARITY(0,1,2,3,4,5,6,7,8,9), 10))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_ARITY(0,1,2,3,4,5,6,7,8,9,10), 11))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(CRADLE_PP_ARITY(0,1,2,3,4,5,6,7,8,9,10,11), 12))
BOOST_PP_ASSERT(
  BOOST_PP_EQUAL(CRADLE_PP_ARITY(0,1,2,3,4,5,6,7,8,9,10,11,12), 13))
BOOST_PP_ASSERT(
  BOOST_PP_EQUAL(CRADLE_PP_ARITY(0,1,2,3,4,5,6,7,8,9,10,11,12,13), 14))
BOOST_PP_ASSERT(
  BOOST_PP_EQUAL(CRADLE_PP_ARITY(0,1,2,3,4,5,6,7,8,9,10,11,12,13,14), 15))
BOOST_PP_ASSERT(
  BOOST_PP_EQUAL(CRADLE_PP_ARITY(0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15), 16))
BOOST_PP_ASSERT(
  BOOST_PP_EQUAL(
    CRADLE_PP_ARITY(0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16), 17))
BOOST_PP_ASSERT(
  BOOST_PP_EQUAL(
    CRADLE_PP_ARITY(0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17), 18))
BOOST_PP_ASSERT(
  BOOST_PP_EQUAL(
    CRADLE_PP_ARITY(0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18), 19))
BOOST_PP_ASSERT(
  BOOST_PP_EQUAL(
    CRADLE_PP_ARITY(0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19), 20))
BOOST_PP_ASSERT(
  BOOST_PP_EQUAL(
    CRADLE_PP_ARITY(0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20), 21))
BOOST_PP_ASSERT(
  BOOST_PP_EQUAL(
    CRADLE_PP_ARITY(0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21),
    22))
BOOST_PP_ASSERT(
  BOOST_PP_EQUAL(
    CRADLE_PP_ARITY(0,1,2,3,4,5,6,7,8,9,
                    10,11,12,13,14,15,16,17,18,19,
                    20,21,22),
    23))
BOOST_PP_ASSERT(
  BOOST_PP_EQUAL(
    CRADLE_PP_ARITY(0,1,2,3,4,5,6,7,8,9,
                    10,11,12,13,14,15,16,17,18,19,
                    20,21,22,23),
    24))
BOOST_PP_ASSERT(
  BOOST_PP_EQUAL(
    CRADLE_PP_ARITY(0,1,2,3,4,5,6,7,8,9,
                    10,11,12,13,14,15,16,17,18,19,
                    20,21,22,23,24),
    25))
BOOST_PP_ASSERT(
  BOOST_PP_EQUAL(
    CRADLE_PP_ARITY(0,1,2,3,4,5,6,7,8,9,
                    10,11,12,13,14,15,16,17,18,19,
                    20,21,22,23,24,25),
    26))
BOOST_PP_ASSERT(
  BOOST_PP_EQUAL(
    CRADLE_PP_ARITY(0,1,2,3,4,5,6,7,8,9,
                    10,11,12,13,14,15,16,17,18,19,
                    20,21,22,23,24,25,26),
    27))
BOOST_PP_ASSERT(
  BOOST_PP_EQUAL(
    CRADLE_PP_ARITY(0,1,2,3,4,5,6,7,8,9,
                    10,11,12,13,14,15,16,17,18,19,
                    20,21,22,23,24,25,26,27),
    28))
BOOST_PP_ASSERT(
  BOOST_PP_EQUAL(
    CRADLE_PP_ARITY(0,1,2,3,4,5,6,7,8,9,
                    10,11,12,13,14,15,16,17,18,19,
                    20,21,22,23,24,25,26,27,28),
    29))
BOOST_PP_ASSERT(
  BOOST_PP_EQUAL(
    CRADLE_PP_ARITY(0,1,2,3,4,5,6,7,8,9,
                    10,11,12,13,14,15,16,17,18,19,
                    20,21,22,23,24,25,26,27,28,29),
    30))
BOOST_PP_ASSERT(
  BOOST_PP_EQUAL(
    CRADLE_PP_ARITY(0,1,2,3,4,5,6,7,8,9,
                    10,11,12,13,14,15,16,17,18,19,
                    20,21,22,23,24,25,26,27,28,29,
                    30),
    31))
/*
static_assert(
  BOOST_PP_EQUAL(
    CRADLE_PP_ARITY(0,1,2,3,4,5,6,7,8,9,
                    10,11,12,13,14,15,16,17,18,19,
                    20,21,22,23,24,25,26,27,28,29,
                    30,31),
    32) == 1,
  "");
static_assert(
  BOOST_PP_EQUAL(
    CRADLE_PP_ARITY(0,1,2,3,4,5,6,7,8,9,
                    10,11,12,13,14,15,16,17,18,19,
                    20,21,22,23,24,25,26,27,28,29,
                    30,31,32),
    33) == 1,
  "");
static_assert(
  BOOST_PP_EQUAL(
    CRADLE_PP_ARITY(0,1,2,3,4,5,6,7,8,9,
                    10,11,12,13,14,15,16,17,18,19,
                    20,21,22,23,24,25,26,27,28,29,
                    30,31,32,33),
    34) == 1,
  "");
static_assert(
  BOOST_PP_EQUAL(
    CRADLE_PP_ARITY(0,1,2,3,4,5,6,7,8,9,
                    10,11,12,13,14,15,16,17,18,19,
                    20,21,22,23,24,25,26,27,28,29,
                    30,31,32,33,34),
    35) == 1,
  "");
static_assert(
  BOOST_PP_EQUAL(
    CRADLE_PP_ARITY(0,1,2,3,4,5,6,7,8,9,
                    10,11,12,13,14,15,16,17,18,19,
                    20,21,22,23,24,25,26,27,28,29,
                    30,31,32,33,34,35),
    36) == 1,
  "");
static_assert(
  BOOST_PP_EQUAL(
    CRADLE_PP_ARITY(0,1,2,3,4,5,6,7,8,9,
                    10,11,12,13,14,15,16,17,18,19,
                    20,21,22,23,24,25,26,27,28,29,
                    30,31,32,33,34,35,36),
    37) == 1,
  "");
static_assert(
  BOOST_PP_EQUAL(
    CRADLE_PP_ARITY(0,1,2,3,4,5,6,7,8,9,
                    10,11,12,13,14,15,16,17,18,19,
                    20,21,22,23,24,25,26,27,28,29,
                    30,31,32,33,34,35,36,37),
    38) == 1,
  "");
static_assert(
  BOOST_PP_EQUAL(
    CRADLE_PP_ARITY(0,1,2,3,4,5,6,7,8,9,
                    10,11,12,13,14,15,16,17,18,19,
                    20,21,22,23,24,25,26,27,28,29,
                    30,31,32,33,34,35,36,37,38),
    39) == 1,
  "");
static_assert(
  BOOST_PP_EQUAL(
    CRADLE_PP_ARITY(0,1,2,3,4,5,6,7,8,9,
                    10,11,12,13,14,15,16,17,18,19,
                    20,21,22,23,24,25,26,27,28,29,
                    30,31,32,33,34,35,36,37,38,39,
                    40,41,42,43,44,45,46,47,48,49,
                    50,51,52,53,54,55,56,57,58,59,
                    60,61,62,63,64,65,66,67,68,69,
                    70,71,72,73,74,75,76,77,78,79,
                    80,81,82,83,84,85,86,87,88,89,
                    90,91,92,93,94,95,96,97,98,99),
    100) == 1,
  "");
static_assert(
  BOOST_PP_EQUAL(
    CRADLE_PP_ARITY(0,1,2,3,4,5,6,7,8,9,
                    10,11,12,13,14,15,16,17,18,19,
                    20,21,22,23,24,25,26,27,28,29,
                    30,31,32,33,34,35,36,37,38,39,
                    40,41,42,43,44,45,46,47,48,49,
                    50,51,52,53,54,55,56,57,58,59,
                    60,61,62,63,64,65,66,67,68,69,
                    70,71,72,73,74,75,76,77,78,79,
                    80,81,82,83,84,85,86,87,88,89,
                    90,91,92,93,94,95,96,97,98,99,
                    100,101,102,103,104,105,106,107,108,109,
                    110,111,112,113,114,115,116,117,118,119,
                    120,121,122,123,124,125,126),
    127) == 1,
  "");
*/
