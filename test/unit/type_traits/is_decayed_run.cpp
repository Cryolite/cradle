//  (C) Copyright Cryolite 2012. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cradle/type_traits/is_decayed.hpp>

#include <boost/test/unit_test.hpp>


BOOST_AUTO_TEST_SUITE(type_traits)

BOOST_AUTO_TEST_SUITE(is_decayed)

BOOST_AUTO_TEST_CASE(main)
{
  static_assert(cradle::is_decayed<int>::value, "");
  static_assert(!cradle::is_decayed<int const>::value, "");
  static_assert(!cradle::is_decayed<int volatile>::value, "");
  static_assert(!cradle::is_decayed<int const volatile>::value, "");
  static_assert(!cradle::is_decayed<int &>::value, "");
  static_assert(!cradle::is_decayed<int const &>::value, "");
  static_assert(!cradle::is_decayed<int volatile &>::value, "");
  static_assert(!cradle::is_decayed<int const volatile &>::value, "");
  static_assert(!cradle::is_decayed<int &&>::value, "");
  static_assert(!cradle::is_decayed<int const &&>::value, "");
  static_assert(!cradle::is_decayed<int volatile &&>::value, "");
  static_assert(!cradle::is_decayed<int const volatile &&>::value, "");
  static_assert(cradle::is_decayed<int *>::value, "");
  static_assert(cradle::is_decayed<int const *>::value, "");
  static_assert(cradle::is_decayed<int volatile *>::value, "");
  static_assert(cradle::is_decayed<int const volatile *>::value, "");
  static_assert(!cradle::is_decayed<int * const>::value, "");
  static_assert(!cradle::is_decayed<int const * const>::value, "");
  static_assert(!cradle::is_decayed<int volatile * const>::value, "");
  static_assert(!cradle::is_decayed<int const volatile * const>::value, "");
  static_assert(!cradle::is_decayed<int * volatile>::value, "");
  static_assert(!cradle::is_decayed<int const * volatile>::value, "");
  static_assert(!cradle::is_decayed<int volatile * volatile>::value, "");
  static_assert(
    !cradle::is_decayed<int const volatile * volatile>::value, "");
  static_assert(!cradle::is_decayed<int * const volatile>::value, "");
  static_assert(!cradle::is_decayed<int const * const volatile>::value, "");
  static_assert(
    !cradle::is_decayed<int volatile * const volatile>::value, "");
  static_assert(
    !cradle::is_decayed<int const volatile * const volatile>::value, "");
  static_assert(!cradle::is_decayed<int[1]>::value, "");
  static_assert(!cradle::is_decayed<int const [1]>::value, "");
  static_assert(!cradle::is_decayed<int volatile [1]>::value, "");
  static_assert(!cradle::is_decayed<int const volatile [1]>::value, "");
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
