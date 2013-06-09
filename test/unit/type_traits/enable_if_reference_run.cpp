//  (C) Copyright Cryolite 2013. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cradle/type_traits/enable_if_reference.hpp>

#include <boost/test/unit_test.hpp>


BOOST_AUTO_TEST_SUITE(type_traits)

BOOST_AUTO_TEST_SUITE(enable_if_reference)

namespace{

template<typename T, typename = cradle::enable_if_reference<T> >
constexpr bool is_reference_test_(int)
{
  return true;
}

template<typename T>
constexpr bool is_reference_test_(...)
{
  return false;
}

} // namespace `unnamed'

BOOST_AUTO_TEST_CASE(enable_if_reference)
{
  static_assert(is_reference_test_<int &>(0), "");
  static_assert(is_reference_test_<int &&>(0), "");
  static_assert(!is_reference_test_<int>(0), "");
}

namespace{

template<typename T, typename = cradle::disable_if_reference<T> >
constexpr bool is_not_reference_test_(int)
{
  return true;
}

template<typename T>
constexpr bool is_not_reference_test_(...)
{
  return false;
}

} // namespace `unnamed'

BOOST_AUTO_TEST_CASE(disable_if_reference)
{
  static_assert(!is_not_reference_test_<int &>(0), "");
  static_assert(!is_not_reference_test_<int &&>(0), "");
  static_assert(is_not_reference_test_<int>(0), "");
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
