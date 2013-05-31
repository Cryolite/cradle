//  (C) Copyright Cryolite 2012. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cradle/scope_guard/scope_guard.hpp>

#include <boost/test/unit_test.hpp>


BOOST_AUTO_TEST_SUITE(scope_guard)

BOOST_AUTO_TEST_SUITE(scope_guard)

BOOST_AUTO_TEST_CASE(normal_scope_exit)
{
  int i = 1;
  {
    CRADLE_SCOPE_GUARD{
      --i;
    };
    BOOST_CHECK_EQUAL(i, 1);
  }
  BOOST_CHECK_EQUAL(i, 0);
}

BOOST_AUTO_TEST_CASE(exceptional_scope_exit)
{
  int i = 1;
  try {
    CRADLE_SCOPE_GUARD{
      --i;
    };
    BOOST_CHECK_EQUAL(i, 1);
    throw 0;
  }
  catch (...) {
    BOOST_CHECK_EQUAL(i, 0);
  }
  BOOST_CHECK_EQUAL(i, 0);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
