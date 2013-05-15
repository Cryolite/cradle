//  (C) Copyright Cryolite 2012. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_MAIN
#include <cradle/scope_guard/exception_guard.hpp>
#include <boost/test/unit_test.hpp>


BOOST_AUTO_TEST_CASE(testNormalScopeExit)
{
  int i = 1;
  {
    CRADLE_EXCEPTION_GUARD{
      --i;
    };
    BOOST_CHECK_EQUAL(i, 1);
  }
  BOOST_CHECK_EQUAL(i, 1);
}

BOOST_AUTO_TEST_CASE(testExceptionalScopeExit)
{
  int i = 1;
  try {
    CRADLE_EXCEPTION_GUARD{
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

namespace {

struct S
{
  ~S() noexcept
  {
    int i = 1;
    {
      CRADLE_EXCEPTION_GUARD{
        --i;
      };
      BOOST_CHECK_EQUAL(i, 1);
    }
    BOOST_CHECK_EQUAL(i, 1);
    try {
      CRADLE_EXCEPTION_GUARD{
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
}; // struct S

} // namespace `unnmaed'

BOOST_AUTO_TEST_CASE(testUnwind)
{
  int i = 1;
  {
    CRADLE_EXCEPTION_GUARD{
      --i;
    };
    BOOST_CHECK_EQUAL(i, 1);
    S s;
  }
  BOOST_CHECK_EQUAL(i, 1);
  try {
    CRADLE_EXCEPTION_GUARD{
      --i;
    };
    BOOST_CHECK_EQUAL(i, 1);
    S s;
    throw 0;
  }
  catch (...) {
    BOOST_CHECK_EQUAL(i, 0);
  }
  BOOST_CHECK_EQUAL(i, 0);
}
