//  (C) Copyright Cryolite 2014. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cradle/utility/integer_sequence.hpp>

#include <boost/test/unit_test.hpp>
#include <type_traits>
#include <cstddef>


BOOST_AUTO_TEST_SUITE(utility)

BOOST_AUTO_TEST_SUITE(integer_sequence)

namespace{

template<typename T, typename U>
void assertSame() noexcept
{
  static_assert(std::is_same<T, U>::value, "");
}

}

BOOST_AUTO_TEST_CASE(main)
{
  typedef cradle::make_integer_sequence<int, 0> SI0;
  assertSame<SI0, cradle::integer_sequence<int> >();
  typedef cradle::make_integer_sequence<int, 1> SI1;
  assertSame<SI1, cradle::integer_sequence<int, 0> >();
  typedef cradle::make_integer_sequence<int, 2> SI2;
  assertSame<SI2, cradle::integer_sequence<int, 0, 1> >();
  typedef cradle::make_integer_sequence<int, 3> SI3;
  assertSame<SI3, cradle::integer_sequence<int, 0, 1, 2> >();
  typedef cradle::make_integer_sequence<int, 4> SI4;
  assertSame<SI4, cradle::integer_sequence<int, 0, 1, 2, 3> >();
  typedef cradle::make_integer_sequence<int, 5> SI5;
  assertSame<SI5, cradle::integer_sequence<int, 0, 1, 2, 3, 4> >();
  typedef cradle::make_integer_sequence<int, 6> SI6;
  assertSame<SI6, cradle::integer_sequence<int, 0, 1, 2, 3, 4, 5> >();
  typedef cradle::make_integer_sequence<int, 7> SI7;
  assertSame<SI7, cradle::integer_sequence<int, 0, 1, 2, 3, 4, 5, 6> >();
  typedef cradle::make_integer_sequence<int, 8> SI8;
  assertSame<SI8, cradle::integer_sequence<int, 0, 1, 2, 3, 4, 5, 6, 7> >();
  typedef cradle::make_integer_sequence<int, 9> SI9;
  assertSame<SI9, cradle::integer_sequence<int, 0, 1, 2, 3, 4, 5, 6, 7, 8> >();
  typedef cradle::make_integer_sequence<int, 10> SI10;
  assertSame<SI10, cradle::integer_sequence<int, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9> >();
  typedef cradle::make_integer_sequence<int, 11> SI11;
  assertSame<SI11, cradle::integer_sequence<int, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10> >();
  typedef cradle::make_integer_sequence<int, 12> SI12;
  assertSame<SI12, cradle::integer_sequence<int, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11> >();
  typedef cradle::make_integer_sequence<int, 13> SI13;
  assertSame<SI13, cradle::integer_sequence<int, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12> >();
  typedef cradle::make_integer_sequence<int, 14> SI14;
  assertSame<SI14, cradle::integer_sequence<int, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13> >();
  typedef cradle::make_integer_sequence<int, 15> SI15;
  assertSame<SI15, cradle::integer_sequence<int, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14> >();
  typedef cradle::make_integer_sequence<int, 16> SI16;
  assertSame<SI16, cradle::integer_sequence<int, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15> >();
  typedef cradle::make_integer_sequence<int, 17> SI17;
  assertSame<SI17, cradle::integer_sequence<int, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16> >();
  typedef cradle::make_integer_sequence<int, 18> SI18;
  assertSame<SI18, cradle::integer_sequence<int, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17> >();
  typedef cradle::make_integer_sequence<int, 19> SI19;
  assertSame<SI19, cradle::integer_sequence<int, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18> >();
  typedef cradle::make_integer_sequence<int, 20> SI20;
  assertSame<SI20, cradle::integer_sequence<int, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19> >();
  typedef cradle::make_integer_sequence<std::size_t, 0> SS0;
  assertSame<SS0, cradle::integer_sequence<std::size_t> >();
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
