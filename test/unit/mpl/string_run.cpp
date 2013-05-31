#include <cradle/mpl/string.hpp>

#include <boost/test/unit_test.hpp>
#include <array>
#include <type_traits>

BOOST_AUTO_TEST_SUITE(mpl)

BOOST_AUTO_TEST_SUITE(string)

BOOST_AUTO_TEST_CASE(narrow_0)
{
  typedef CRADLE_MPL_STRING("") str;
  static_assert(std::is_same<str, cradle::mpl::string<char> >::value, "");
  typedef str::value_type value_type;
  static_assert(std::is_same<value_type, std::array<char, 0> >::value, "");
  constexpr value_type value = str::value;
  static_assert(value.size() == 0u, "");
  static_assert(value.empty(), "");
  typedef str::type type;
  static_assert(std::is_same<type, str>::value, "");
}

BOOST_AUTO_TEST_CASE(narrow_1)
{
  typedef CRADLE_MPL_STRING("a") str;
  static_assert(
    std::is_same<str, cradle::mpl::string<char, 'a'> >::value, "");
  typedef str::value_type value_type;
  static_assert(std::is_same<value_type, std::array<char, 1> >::value, "");
  constexpr value_type value = str::value;
  static_assert(value[0] == 'a', "");
  static_assert(value.size() == 1u, "");
  static_assert(!value.empty(), "");
  typedef str::type type;
  static_assert(std::is_same<type, str>::value, "");
}

BOOST_AUTO_TEST_CASE(narrow_2)
{
  typedef CRADLE_MPL_STRING("ab") str;
  static_assert(
    std::is_same<str, cradle::mpl::string<char, 'a', 'b'> >::value, "");
  typedef str::value_type value_type;
  static_assert(std::is_same<value_type, std::array<char, 2> >::value, "");
  constexpr value_type value = str::value;
  static_assert(value[0] == 'a', "");
  static_assert(value[1] == 'b', "");
  static_assert(value.size() == 2u, "");
  static_assert(!value.empty(), "");
  typedef str::type type;
  static_assert(std::is_same<type, str>::value, "");
}

BOOST_AUTO_TEST_CASE(narrow_3)
{
  typedef CRADLE_MPL_STRING("abc") str;
  static_assert(
    std::is_same<str, cradle::mpl::string<char, 'a', 'b', 'c'> >::value,
    "");
  typedef str::value_type value_type;
  static_assert(std::is_same<value_type, std::array<char, 3> >::value, "");
  constexpr value_type value = str::value;
  static_assert(value[0] == 'a', "");
  static_assert(value[1] == 'b', "");
  static_assert(value[2] == 'c', "");
  static_assert(value.size() == 3u, "");
  static_assert(!value.empty(), "");
  typedef str::type type;
  static_assert(std::is_same<type, str>::value, "");
}

BOOST_AUTO_TEST_CASE(narrow_4)
{
  typedef CRADLE_MPL_STRING("abcd") str;
  static_assert(
    std::is_same<
      str,
      cradle::mpl::string<char, 'a', 'b', 'c', 'd'> >::value,
    "");
  typedef str::value_type value_type;
  static_assert(std::is_same<value_type, std::array<char, 4> >::value, "");
  constexpr value_type value = str::value;
  static_assert(value[0] == 'a', "");
  static_assert(value[1] == 'b', "");
  static_assert(value[2] == 'c', "");
  static_assert(value[3] == 'd', "");
  static_assert(value.size() == 4u, "");
  static_assert(!value.empty(), "");
  typedef str::type type;
  static_assert(std::is_same<type, str>::value, "");
}

BOOST_AUTO_TEST_CASE(narrow_5)
{
  typedef CRADLE_MPL_STRING("abcde") str;
  static_assert(
    std::is_same<
      str,
      cradle::mpl::string<char, 'a', 'b', 'c', 'd', 'e'> >::value,
    "");
  typedef str::value_type value_type;
  static_assert(std::is_same<value_type, std::array<char, 5> >::value, "");
  constexpr value_type value = str::value;
  static_assert(value[0] == 'a', "");
  static_assert(value[1] == 'b', "");
  static_assert(value[2] == 'c', "");
  static_assert(value[3] == 'd', "");
  static_assert(value[4] == 'e', "");
  static_assert(value.size() == 5u, "");
  static_assert(!value.empty(), "");
  typedef str::type type;
  static_assert(std::is_same<type, str>::value, "");
}

BOOST_AUTO_TEST_CASE(narrow_6)
{
  typedef CRADLE_MPL_STRING("abcdef") str;
  static_assert(
    std::is_same<
      str,
      cradle::mpl::string<char, 'a', 'b', 'c', 'd', 'e', 'f'> >::value,
    "");
  typedef str::value_type value_type;
  static_assert(std::is_same<value_type, std::array<char, 6> >::value, "");
  constexpr value_type value = str::value;
  static_assert(value[0] == 'a', "");
  static_assert(value[1] == 'b', "");
  static_assert(value[2] == 'c', "");
  static_assert(value[3] == 'd', "");
  static_assert(value[4] == 'e', "");
  static_assert(value[5] == 'f', "");
  static_assert(value.size() == 6u, "");
  static_assert(!value.empty(), "");
  typedef str::type type;
  static_assert(std::is_same<type, str>::value, "");
}

BOOST_AUTO_TEST_CASE(narrow_7)
{
  typedef CRADLE_MPL_STRING("abcdefg") str;
  static_assert(
    std::is_same<
      str,
      cradle::mpl::string<char, 'a', 'b', 'c', 'd', 'e', 'f', 'g'> >::value,
    "");
  typedef str::value_type value_type;
  static_assert(std::is_same<value_type, std::array<char, 7> >::value, "");
  constexpr value_type value = str::value;
  static_assert(value[0] == 'a', "");
  static_assert(value[1] == 'b', "");
  static_assert(value[2] == 'c', "");
  static_assert(value[3] == 'd', "");
  static_assert(value[4] == 'e', "");
  static_assert(value[5] == 'f', "");
  static_assert(value[6] == 'g', "");
  static_assert(value.size() == 7u, "");
  static_assert(!value.empty(), "");
  typedef str::type type;
  static_assert(std::is_same<type, str>::value, "");
}

BOOST_AUTO_TEST_CASE(narrow_8)
{
  typedef CRADLE_MPL_STRING("abcdefgh") str;
  static_assert(
    std::is_same<
      str,
      cradle::mpl::string<
        char, 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'> >::value,
    "");
  typedef str::value_type value_type;
  static_assert(std::is_same<value_type, std::array<char, 8> >::value, "");
  constexpr value_type value = str::value;
  static_assert(value[0] == 'a', "");
  static_assert(value[1] == 'b', "");
  static_assert(value[2] == 'c', "");
  static_assert(value[3] == 'd', "");
  static_assert(value[4] == 'e', "");
  static_assert(value[5] == 'f', "");
  static_assert(value[6] == 'g', "");
  static_assert(value[7] == 'h', "");
  static_assert(value.size() == 8u, "");
  static_assert(!value.empty(), "");
  typedef str::type type;
  static_assert(std::is_same<type, str>::value, "");
}

BOOST_AUTO_TEST_CASE(narrow_9)
{
  typedef CRADLE_MPL_STRING("abcdefghi") str;
  static_assert(
    std::is_same<
      str,
      cradle::mpl::string<
        char, 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'> >::value,
    "");
  typedef str::value_type value_type;
  static_assert(std::is_same<value_type, std::array<char, 9> >::value, "");
  constexpr value_type value = str::value;
  static_assert(value[0] == 'a', "");
  static_assert(value[1] == 'b', "");
  static_assert(value[2] == 'c', "");
  static_assert(value[3] == 'd', "");
  static_assert(value[4] == 'e', "");
  static_assert(value[5] == 'f', "");
  static_assert(value[6] == 'g', "");
  static_assert(value[7] == 'h', "");
  static_assert(value[8] == 'i', "");
  static_assert(value.size() == 9u, "");
  static_assert(!value.empty(), "");
  typedef str::type type;
  static_assert(std::is_same<type, str>::value, "");
}

BOOST_AUTO_TEST_CASE(narrow_limit)
{
  typedef CRADLE_MPL_STRING("abcdefghiaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabcdefghi") str;
  typedef str::value_type value_type;
  static_assert(std::is_same<value_type, std::array<char, 256> >::value, "");
  constexpr value_type value = str::value;
  static_assert(value[0] == 'a', "");
  static_assert(value[1] == 'b', "");
  static_assert(value[2] == 'c', "");
  static_assert(value[3] == 'd', "");
  static_assert(value[4] == 'e', "");
  static_assert(value[5] == 'f', "");
  static_assert(value[6] == 'g', "");
  static_assert(value[7] == 'h', "");
  static_assert(value[8] == 'i', "");
  static_assert(value[247] == 'a', "");
  static_assert(value[248] == 'b', "");
  static_assert(value[249] == 'c', "");
  static_assert(value[250] == 'd', "");
  static_assert(value[251] == 'e', "");
  static_assert(value[252] == 'f', "");
  static_assert(value[253] == 'g', "");
  static_assert(value[254] == 'h', "");
  static_assert(value[255] == 'i', "");
  static_assert(value.size() == 256u, "");
  static_assert(!value.empty(), "");
  typedef str::type type;
  static_assert(std::is_same<type, str>::value, "");
}

BOOST_AUTO_TEST_CASE(u8_0)
{
  typedef CRADLE_MPL_STRING(u8"") str;
  static_assert(std::is_same<str, cradle::mpl::string<char> >::value, "");
  typedef str::value_type value_type;
  static_assert(std::is_same<value_type, std::array<char, 0> >::value, "");
  constexpr value_type value = str::value;
  static_assert(value.size() == 0u, "");
  static_assert(value.empty(), "");
  typedef str::type type;
  static_assert(std::is_same<type, str>::value, "");
}

BOOST_AUTO_TEST_CASE(u8_3)
{
  typedef CRADLE_MPL_STRING(u8"bar") str;
  static_assert(std::is_same<str, cradle::mpl::string<char, 'b', 'a', 'r'> >::value, "");
  typedef str::value_type value_type;
  static_assert(std::is_same<value_type, std::array<char, 3> >::value, "");
  constexpr value_type value = str::value;
  static_assert(value[0] == 'b', "");
  static_assert(value[1] == 'a', "");
  static_assert(value[2] == 'r', "");
  static_assert(value.size() == 3u, "");
  static_assert(!value.empty(), "");
  typedef str::type type;
  static_assert(std::is_same<type, str>::value, "");
}

BOOST_AUTO_TEST_CASE(u8_limit)
{
  typedef CRADLE_MPL_STRING(u8"abcdefghiaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabcdefghi") str;
  typedef str::value_type value_type;
  static_assert(std::is_same<value_type, std::array<char, 256> >::value, "");
  constexpr value_type value = str::value;
  static_assert(value[0] == 'a', "");
  static_assert(value[1] == 'b', "");
  static_assert(value[2] == 'c', "");
  static_assert(value[3] == 'd', "");
  static_assert(value[4] == 'e', "");
  static_assert(value[5] == 'f', "");
  static_assert(value[6] == 'g', "");
  static_assert(value[7] == 'h', "");
  static_assert(value[8] == 'i', "");
  static_assert(value[247] == 'a', "");
  static_assert(value[248] == 'b', "");
  static_assert(value[249] == 'c', "");
  static_assert(value[250] == 'd', "");
  static_assert(value[251] == 'e', "");
  static_assert(value[252] == 'f', "");
  static_assert(value[253] == 'g', "");
  static_assert(value[254] == 'h', "");
  static_assert(value[255] == 'i', "");
  static_assert(value.size() == 256u, "");
  static_assert(!value.empty(), "");
  typedef str::type type;
  static_assert(std::is_same<type, str>::value, "");
}

BOOST_AUTO_TEST_CASE(u16_0)
{
  typedef CRADLE_MPL_STRING(u"") str;
  static_assert(std::is_same<str, cradle::mpl::string<char16_t> >::value, "");
  typedef str::value_type value_type;
  static_assert(std::is_same<value_type, std::array<char16_t, 0> >::value, "");
  constexpr value_type value = str::value;
  static_assert(value.size() == 0u, "");
  static_assert(value.empty(), "");
  typedef str::type type;
  static_assert(std::is_same<type, str>::value, "");
}

BOOST_AUTO_TEST_CASE(u16_3)
{
  typedef CRADLE_MPL_STRING(u"bar") str;
  static_assert(std::is_same<str, cradle::mpl::string<char16_t, u'b', u'a', u'r'> >::value, "");
  typedef str::value_type value_type;
  static_assert(std::is_same<value_type, std::array<char16_t, 3> >::value, "");
  constexpr value_type value = str::value;
  static_assert(value[0] == u'b', "");
  static_assert(value[1] == u'a', "");
  static_assert(value[2] == u'r', "");
  static_assert(value.size() == 3u, "");
  static_assert(!value.empty(), "");
  typedef str::type type;
  static_assert(std::is_same<type, str>::value, "");
}

BOOST_AUTO_TEST_CASE(u16_limit)
{
  typedef CRADLE_MPL_STRING(u"abcdefghiaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabcdefghi") str;
  typedef str::value_type value_type;
  static_assert(std::is_same<value_type, std::array<char16_t, 256> >::value, "");
  constexpr value_type value = str::value;
  static_assert(value[0] == u'a', "");
  static_assert(value[1] == u'b', "");
  static_assert(value[2] == u'c', "");
  static_assert(value[3] == u'd', "");
  static_assert(value[4] == u'e', "");
  static_assert(value[5] == u'f', "");
  static_assert(value[6] == u'g', "");
  static_assert(value[7] == u'h', "");
  static_assert(value[8] == u'i', "");
  static_assert(value[247] == u'a', "");
  static_assert(value[248] == u'b', "");
  static_assert(value[249] == u'c', "");
  static_assert(value[250] == u'd', "");
  static_assert(value[251] == u'e', "");
  static_assert(value[252] == u'f', "");
  static_assert(value[253] == u'g', "");
  static_assert(value[254] == u'h', "");
  static_assert(value[255] == u'i', "");
  static_assert(value.size() == 256u, "");
  static_assert(!value.empty(), "");
  typedef str::type type;
  static_assert(std::is_same<type, str>::value, "");
}

BOOST_AUTO_TEST_CASE(u32_0)
{
  typedef CRADLE_MPL_STRING(U"") str;
  static_assert(std::is_same<str, cradle::mpl::string<char32_t> >::value, "");
  typedef str::value_type value_type;
  static_assert(std::is_same<value_type, std::array<char32_t, 0> >::value, "");
  constexpr value_type value = str::value;
  static_assert(value.size() == 0u, "");
  static_assert(value.empty(), "");
  typedef str::type type;
  static_assert(std::is_same<type, str>::value, "");
}

BOOST_AUTO_TEST_CASE(u32_3)
{
  typedef CRADLE_MPL_STRING(U"bar") str;
  static_assert(std::is_same<str, cradle::mpl::string<char32_t, U'b', U'a', U'r'> >::value, "");
  typedef str::value_type value_type;
  static_assert(std::is_same<value_type, std::array<char32_t, 3> >::value, "");
  constexpr value_type value = str::value;
  static_assert(value[0] == U'b', "");
  static_assert(value[1] == U'a', "");
  static_assert(value[2] == U'r', "");
  static_assert(value.size() == 3u, "");
  static_assert(!value.empty(), "");
  typedef str::type type;
  static_assert(std::is_same<type, str>::value, "");
}

BOOST_AUTO_TEST_CASE(u32_limit)
{
  typedef CRADLE_MPL_STRING(U"abcdefghiaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabcdefghi") str;
  typedef str::value_type value_type;
  static_assert(std::is_same<value_type, std::array<char32_t, 256> >::value, "");
  constexpr value_type value = str::value;
  static_assert(value[0] == U'a', "");
  static_assert(value[1] == U'b', "");
  static_assert(value[2] == U'c', "");
  static_assert(value[3] == U'd', "");
  static_assert(value[4] == U'e', "");
  static_assert(value[5] == U'f', "");
  static_assert(value[6] == U'g', "");
  static_assert(value[7] == U'h', "");
  static_assert(value[8] == U'i', "");
  static_assert(value[247] == U'a', "");
  static_assert(value[248] == U'b', "");
  static_assert(value[249] == U'c', "");
  static_assert(value[250] == U'd', "");
  static_assert(value[251] == U'e', "");
  static_assert(value[252] == U'f', "");
  static_assert(value[253] == U'g', "");
  static_assert(value[254] == U'h', "");
  static_assert(value[255] == U'i', "");
  static_assert(value.size() == 256u, "");
  static_assert(!value.empty(), "");
  typedef str::type type;
  static_assert(std::is_same<type, str>::value, "");
}

BOOST_AUTO_TEST_CASE(wide_0)
{
  typedef CRADLE_MPL_STRING(L"") str;
  static_assert(std::is_same<str, cradle::mpl::string<wchar_t> >::value, "");
  typedef str::value_type value_type;
  static_assert(std::is_same<value_type, std::array<wchar_t, 0> >::value, "");
  constexpr value_type value = str::value;
  static_assert(value.size() == 0u, "");
  static_assert(value.empty(), "");
  typedef str::type type;
  static_assert(std::is_same<type, str>::value, "");
}

BOOST_AUTO_TEST_CASE(wide_3)
{
  typedef CRADLE_MPL_STRING(L"bar") str;
  static_assert(std::is_same<str, cradle::mpl::string<wchar_t, L'b', L'a', L'r'> >::value, "");
  typedef str::value_type value_type;
  static_assert(std::is_same<value_type, std::array<wchar_t, 3> >::value, "");
  constexpr value_type value = str::value;
  static_assert(value[0] == L'b', "");
  static_assert(value[1] == L'a', "");
  static_assert(value[2] == L'r', "");
  static_assert(value.size() == 3u, "");
  static_assert(!value.empty(), "");
  typedef str::type type;
  static_assert(std::is_same<type, str>::value, "");
}

BOOST_AUTO_TEST_CASE(wide_limit)
{
  typedef CRADLE_MPL_STRING(L"abcdefghiaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabcdefghi") str;
  typedef str::value_type value_type;
  static_assert(std::is_same<value_type, std::array<wchar_t, 256> >::value, "");
  constexpr value_type value = str::value;
  static_assert(value[0] == L'a', "");
  static_assert(value[1] == L'b', "");
  static_assert(value[2] == L'c', "");
  static_assert(value[3] == L'd', "");
  static_assert(value[4] == L'e', "");
  static_assert(value[5] == L'f', "");
  static_assert(value[6] == L'g', "");
  static_assert(value[7] == L'h', "");
  static_assert(value[8] == L'i', "");
  static_assert(value[247] == L'a', "");
  static_assert(value[248] == L'b', "");
  static_assert(value[249] == L'c', "");
  static_assert(value[250] == L'd', "");
  static_assert(value[251] == L'e', "");
  static_assert(value[252] == L'f', "");
  static_assert(value[253] == L'g', "");
  static_assert(value[254] == L'h', "");
  static_assert(value[255] == L'i', "");
  static_assert(value.size() == 256u, "");
  static_assert(!value.empty(), "");
  typedef str::type type;
  static_assert(std::is_same<type, str>::value, "");
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
