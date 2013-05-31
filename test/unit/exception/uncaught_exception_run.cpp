//  (C) Copyright Cryolite 2012, 2013. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_MAIN
#include <cradle/exception/uncaught_exception.hpp>

#include <boost/test/unit_test.hpp>

#include <cstddef>
#include <stdexcept>
#include <memory>
#include <string>
#include <iostream>
#include <fstream>

class GlobalFixture
{
public:
  GlobalFixture()
    : p_log_stream_()
  {
    std::size_t const argc = boost::unit_test::framework::master_test_suite().argc;
    char const * const * const argv = boost::unit_test::framework::master_test_suite().argv;
    if (argc != 2u) {
      throw std::runtime_error("");
    }
    if (argv[1u] == std::string("--xunit-log-format=hrf")) {
      // Do nothing.
    }
    else if (argv[1u] == std::string("--xunit-log-format=xml")) {
      std::string log_file_path(argv[0u]);
      log_file_path += ".xml" ;
      p_log_stream_.reset(new std::ofstream(log_file_path.c_str()));
      boost::unit_test::unit_test_log.set_stream(*p_log_stream_);
    }
    else {
      throw std::runtime_error("");
    }
  }

  ~GlobalFixture()
  {
    if (p_log_stream_) {
      *p_log_stream_ << "</TestLog>" << std::flush;
      boost::unit_test::unit_test_log.set_stream(std::cout);
    }
  }

private:
  std::shared_ptr<std::ostream> p_log_stream_;
};

BOOST_GLOBAL_FIXTURE(GlobalFixture)

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
