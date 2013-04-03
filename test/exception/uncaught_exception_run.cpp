//  (C) Copyright Cryolite 2012, 2013. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_MAIN
#include <cradle/exception/uncaught_exception.hpp>
#include <boost/test/unit_test.hpp>
#include <cstddef>


BOOST_AUTO_TEST_CASE(testZero)
{
  BOOST_CHECK_EQUAL(cradle::exceptions::get_num_uncaught_exceptions(), 0u);
}

BOOST_AUTO_TEST_CASE(testCatch)
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

}

BOOST_AUTO_TEST_CASE(testUnwind)
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
