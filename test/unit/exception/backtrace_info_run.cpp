//  (C) Copyright Cryolite 2013. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cradle/exception/backtrace_info.hpp>
#include <boost/test/unit_test.hpp>
#include <boost/exception/get_error_info.hpp>
#include <boost/exception/enable_error_info.hpp>
#include <boost/exception/info.hpp>
#include <stdexcept>


BOOST_AUTO_TEST_SUITE(exception)

BOOST_AUTO_TEST_SUITE(backtrace_info)

namespace{

void f()
{
  throw boost::enable_error_info(std::runtime_error(""))
    << cradle::throw_backtrace();
}

} // namespace `unnnamed'

BOOST_AUTO_TEST_CASE(main)
{
  try {
    f();
  }
  catch (boost::exception const &e) {
    cradle::backtrace const *p
      = boost::get_error_info<cradle::backtrace_info>(e);
    BOOST_REQUIRE(p != nullptr);
    BOOST_CHECK_GT(p->end() - p->begin(), 0);
  }
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
