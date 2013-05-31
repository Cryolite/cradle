//  (C) Copyright Cryolite 2012, 2013. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cradle/exception/uncaught_exception.hpp>
#include <boost/test/unit_test.hpp>
#include <cstddef>


BOOST_AUTO_TEST_SUITE(exception)

BOOST_AUTO_TEST_SUITE(uncaught_exception)

BOOST_AUTO_TEST_CASE(zero)
{
  BOOST_CHECK_EQUAL(cradle::exceptions::get_num_uncaught_exceptions(), 0u);
}

BOOST_AUTO_TEST_CASE(catch_)
{
  try {
    throw 0;
  }
  catch (...) {
    BOOST_CHECK_EQUAL(cradle::exceptions::get_num_uncaught_exceptions(), 0u);
  }
  BOOST_CHECK_EQUAL(cradle::exceptions::get_num_uncaught_exceptions(), 0u);
}

namespace {

class S
{
public:
  explicit S(std::size_t n) noexcept
    : n_(n)
  {}

  ~S() noexcept
  {
    BOOST_CHECK_EQUAL(cradle::exceptions::get_num_uncaught_exceptions(), n_);
    if (n_ > 10u) {
      return;
    }
    try {
      BOOST_CHECK_EQUAL(cradle::exceptions::get_num_uncaught_exceptions(), n_);
      S s(n_ + 1);
      BOOST_CHECK_EQUAL(cradle::exceptions::get_num_uncaught_exceptions(), n_);
      throw 0;
    }
    catch (...) {
      BOOST_CHECK_EQUAL(cradle::exceptions::get_num_uncaught_exceptions(), n_);
    }
    BOOST_CHECK_EQUAL(cradle::exceptions::get_num_uncaught_exceptions(), n_);
  }

private:
  std::size_t n_;
};

} // namespace `unnamed'

BOOST_AUTO_TEST_CASE(unwind)
{
  BOOST_CHECK_EQUAL(cradle::exceptions::get_num_uncaught_exceptions(), 0u);
  try {
    BOOST_CHECK_EQUAL(cradle::exceptions::get_num_uncaught_exceptions(), 0u);
    S s(1u);
    BOOST_CHECK_EQUAL(cradle::exceptions::get_num_uncaught_exceptions(), 0u);
    throw 0;
  }
  catch (...) {
    BOOST_CHECK_EQUAL(cradle::exceptions::get_num_uncaught_exceptions(), 0u);
  }
  BOOST_CHECK_EQUAL(cradle::exceptions::get_num_uncaught_exceptions(), 0u);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
