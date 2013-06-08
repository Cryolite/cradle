//  (C) Copyright Cryolite 2013. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cradle/exception/throw_exception.hpp>
#include <boost/test/unit_test.hpp>
#include <boost/exception/get_error_info.hpp>
#include <boost/exception/exception.hpp>
#include <stdexcept>


BOOST_AUTO_TEST_SUITE(exception)

BOOST_AUTO_TEST_SUITE(throw_exception)

namespace{

void f()
{
  CRADLE_THROW_EXCEPTION(std::runtime_error("foo"));
}

} // namespace `unnnamed'

BOOST_AUTO_TEST_CASE(main)
{
  int i = 0;
  try {
    f();
  }
  catch (std::exception const &e) {
    BOOST_CHECK(dynamic_cast<boost::exception const *>(&e));
    BOOST_CHECK_EQUAL(e.what(), "foo");
    {
      char const * const *p = boost::get_error_info<boost::throw_function>(e);
      BOOST_CHECK(p != nullptr);
    }
    {
      char const * const *p = boost::get_error_info<boost::throw_file>(e);
      BOOST_CHECK(p != nullptr);
    }
    {
      int const *p = boost::get_error_info<boost::throw_line>(e);
      BOOST_REQUIRE(p != nullptr);
      BOOST_CHECK_EQUAL(*p, 20);
    }
    {
      cradle::backtrace const *p
        = boost::get_error_info<cradle::backtrace_info>(e);
      BOOST_REQUIRE(p != nullptr);
      BOOST_CHECK_GT(p->end() - p->begin(), 0);
    }
    i = 42;
  }
  BOOST_CHECK_EQUAL(i, 42);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
