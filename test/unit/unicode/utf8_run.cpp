//  (C) Copyright Cryolite 2013. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cradle/unicode/utf8.hpp>
#include <boost/test/unit_test.hpp>
#include <string>
#include <iterator>


BOOST_AUTO_TEST_SUITE(unicode)

BOOST_AUTO_TEST_SUITE(utf8)

BOOST_AUTO_TEST_CASE(test1)
{
  std::string s;
  cradle::unicode::copy_uchar_as_utf8(U'\u0020', std::back_inserter(s));
  BOOST_REQUIRE_EQUAL(s.size(), 1u);
  BOOST_CHECK_EQUAL((s[0] + 256) % 256, 0x20);
}

BOOST_AUTO_TEST_CASE(test2)
{
  std::string s;
  cradle::unicode::copy_uchar_as_utf8(U'\u0393', std::back_inserter(s));
  BOOST_REQUIRE_EQUAL(s.size(), 2u);
  BOOST_CHECK_EQUAL((s[0] + 256) % 256, 0xCE);
  BOOST_CHECK_EQUAL((s[1] + 256) % 256, 0x93);
}

BOOST_AUTO_TEST_CASE(test3)
{
  std::string s;
  cradle::unicode::copy_uchar_as_utf8(U'\u3001', std::back_inserter(s));
  BOOST_REQUIRE_EQUAL(s.size(), 3u);
  BOOST_CHECK_EQUAL((s[0] + 256) % 256, 0xE3);
  BOOST_CHECK_EQUAL((s[1] + 256) % 256, 0x80);
  BOOST_CHECK_EQUAL((s[2] + 256) % 256, 0x81);
}

BOOST_AUTO_TEST_CASE(test4)
{
  std::string s;
  cradle::unicode::copy_uchar_as_utf8(U'\U00020BB7', std::back_inserter(s));
  BOOST_REQUIRE_EQUAL(s.size(), 4u);
  BOOST_CHECK_EQUAL((s[0] + 256) % 256, 0xF0);
  BOOST_CHECK_EQUAL((s[1] + 256) % 256, 0xA0);
  BOOST_CHECK_EQUAL((s[2] + 256) % 256, 0xAE);
  BOOST_CHECK_EQUAL((s[3] + 256) % 256, 0xB7);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
