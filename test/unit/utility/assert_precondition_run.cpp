//  (C) Copyright Cryolite 2013. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cradle/utility/assert_precondition.hpp>

#include <cradle/exception/backtrace_info.hpp>
#include <boost/test/unit_test.hpp>
#include <boost/exception/get_error_info.hpp>
#include <boost/exception/exception.hpp>
#include <stdexcept>


BOOST_AUTO_TEST_SUITE(utility)

BOOST_AUTO_TEST_SUITE(assert_precondition)

BOOST_AUTO_TEST_CASE(main)
{
#if defined(CRADLE_CHECKING)
  int i = 0;
  try {
    CRADLE_ASSERT_PRECONDITION(false);
  }
  catch (std::logic_error const &e) {
    BOOST_CHECK(dynamic_cast<boost::exception const *>(&e));
    BOOST_CHECK_EQUAL(e.what(), "precondition violated: false");
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
      BOOST_CHECK_EQUAL(*p, 23);
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
#else // defined(CRADLE_CHECKING)
  int i = 42;
  try {
    CRADLE_ASSERT_PRECONDITION(false);
  }
  catch (...) {
    i = 0;
  }
  BOOST_CHECK_EQUAL(i, 42);
#endif // defined(CRADLE_CHECKING)
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
