//  (C) Copyright Cryolite 2014. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cradle/utility/index_sequence.hpp>

#include <boost/test/unit_test.hpp>
#include <type_traits>
#include <cstddef>


BOOST_AUTO_TEST_SUITE(utility)

BOOST_AUTO_TEST_SUITE(index_sequence)

namespace{

template<typename T, typename U>
void assertSame() noexcept
{
  static_assert(std::is_same<T, U>::value, "");
}

}

BOOST_AUTO_TEST_CASE(main)
{
  typedef cradle::make_index_sequence<0> S0;
  assertSame<S0, cradle::index_sequence<> >();
  assertSame<S0, cradle::integer_sequence<std::size_t> >();
  typedef cradle::make_index_sequence<1> S1;
  assertSame<S1, cradle::index_sequence<0> >();
  assertSame<S1, cradle::integer_sequence<std::size_t, 0> >();
  typedef cradle::make_index_sequence<2> S2;
  assertSame<S2, cradle::index_sequence<0, 1> >();
  assertSame<S2, cradle::integer_sequence<std::size_t, 0, 1> >();
  typedef cradle::make_index_sequence<3> S3;
  assertSame<S3, cradle::index_sequence<0, 1, 2> >();
  assertSame<S3, cradle::integer_sequence<std::size_t, 0, 1, 2> >();
  typedef cradle::make_index_sequence<4> S4;
  assertSame<S4, cradle::index_sequence<0, 1, 2, 3> >();
  assertSame<S4, cradle::integer_sequence<std::size_t, 0, 1, 2, 3> >();
  typedef cradle::make_index_sequence<5> S5;
  assertSame<S5, cradle::index_sequence<0, 1, 2, 3, 4> >();
  assertSame<S5, cradle::integer_sequence<std::size_t, 0, 1, 2, 3, 4> >();
  typedef cradle::make_index_sequence<6> S6;
  assertSame<S6, cradle::index_sequence<0, 1, 2, 3, 4, 5> >();
  assertSame<S6, cradle::integer_sequence<std::size_t, 0, 1, 2, 3, 4, 5> >();
  typedef cradle::make_index_sequence<7> S7;
  assertSame<S7, cradle::index_sequence<0, 1, 2, 3, 4, 5, 6> >();
  assertSame<S7, cradle::integer_sequence<std::size_t, 0, 1, 2, 3, 4, 5, 6> >();
  typedef cradle::make_index_sequence<8> S8;
  assertSame<S8, cradle::index_sequence<0, 1, 2, 3, 4, 5, 6, 7> >();
  assertSame<S8, cradle::integer_sequence<std::size_t, 0, 1, 2, 3, 4, 5, 6, 7> >();
  typedef cradle::make_index_sequence<9> S9;
  assertSame<S9, cradle::index_sequence<0, 1, 2, 3, 4, 5, 6, 7, 8> >();
  assertSame<S9, cradle::integer_sequence<std::size_t, 0, 1, 2, 3, 4, 5, 6, 7, 8> >();
  typedef cradle::make_index_sequence<10> S10;
  assertSame<S10, cradle::index_sequence<0, 1, 2, 3, 4, 5, 6, 7, 8, 9> >();
  assertSame<S10, cradle::integer_sequence<std::size_t, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9> >();
  typedef cradle::make_index_sequence<11> S11;
  assertSame<S11, cradle::index_sequence<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10> >();
  assertSame<S11, cradle::integer_sequence<std::size_t, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10> >();
  typedef cradle::make_index_sequence<12> S12;
  assertSame<S12, cradle::index_sequence<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11> >();
  assertSame<S12, cradle::integer_sequence<std::size_t, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11> >();
  typedef cradle::make_index_sequence<13> S13;
  assertSame<S13, cradle::index_sequence<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12> >();
  assertSame<S13, cradle::integer_sequence<std::size_t, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12> >();
  typedef cradle::make_index_sequence<14> S14;
  assertSame<S14, cradle::index_sequence<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13> >();
  assertSame<S14, cradle::integer_sequence<std::size_t, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13> >();
  typedef cradle::make_index_sequence<15> S15;
  assertSame<S15, cradle::index_sequence<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14> >();
  assertSame<S15, cradle::integer_sequence<std::size_t, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14> >();
  typedef cradle::make_index_sequence<16> S16;
  assertSame<S16, cradle::index_sequence<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15> >();
  assertSame<S16, cradle::integer_sequence<std::size_t, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15> >();
  typedef cradle::make_index_sequence<17> S17;
  assertSame<S17, cradle::index_sequence<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16> >();
  assertSame<S17, cradle::integer_sequence<std::size_t, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16> >();
  typedef cradle::make_index_sequence<18> S18;
  assertSame<S18, cradle::index_sequence<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17> >();
  assertSame<S18, cradle::integer_sequence<std::size_t, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17> >();
  typedef cradle::make_index_sequence<19> S19;
  assertSame<S19, cradle::index_sequence<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18> >();
  assertSame<S19, cradle::integer_sequence<std::size_t, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18> >();
  typedef cradle::make_index_sequence<20> S20;
  assertSame<S20, cradle::index_sequence<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19> >();
  assertSame<S20, cradle::integer_sequence<std::size_t, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19> >();
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
