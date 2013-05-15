#include <cradle/mpl/string.hpp>

void testOrdinary()
{
  typedef CRADLE_MPL_STRING("foo") foo;
  static_assert(std::is_same<foo, cradle::mpl::string<char, 'f', 'o', 'o'> >::value, "");
  typedef foo::value_type value_type;
  static_assert(std::is_same<value_type, std::array<char, 3> >::value, "");
  constexpr value_type value = foo::value;
  static_assert(value[0] == 'f', "");
  static_assert(value[1] == 'o', "");
  static_assert(value[2] == 'o', "");
  static_assert(value.size() == 3u, "");
  static_assert(!value.empty(), "");
  typedef foo::type type;
  static_assert(std::is_same<type, foo>::value, "");
}

void testOrdinaryEmpty()
{
  typedef CRADLE_MPL_STRING("") foo;
  static_assert(std::is_same<foo, cradle::mpl::string<char> >::value, "");
  typedef foo::value_type value_type;
  static_assert(std::is_same<value_type, std::array<char, 0> >::value, "");
  constexpr value_type value = foo::value;
  static_assert(value.size() == 0u, "");
  static_assert(value.empty(), "");
  typedef foo::type type;
  static_assert(std::is_same<type, foo>::value, "");
}

void testOrdinaryLimit()
{
  typedef CRADLE_MPL_STRING("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaayz") foo;
  typedef foo::value_type value_type;
  static_assert(std::is_same<value_type, std::array<char, 1022> >::value, "");
  constexpr value_type value = foo::value;
  static_assert(value[0] == 'a', "");
  static_assert(value[1] == 'a', "");
  static_assert(value[1019] == 'a', "");
  static_assert(value[1020] == 'y', "");
  static_assert(value[1021] == 'z', "");
  static_assert(value.size() == 1022u, "");
  static_assert(!value.empty(), "");
  typedef foo::type type;
  static_assert(std::is_same<type, foo>::value, "");
}

void testU8()
{
  typedef CRADLE_MPL_STRING(u8"foo") foo;
  static_assert(std::is_same<foo, cradle::mpl::string<char, 'f', 'o', 'o'> >::value, "");
  typedef foo::value_type value_type;
  static_assert(std::is_same<value_type, std::array<char, 3> >::value, "");
  constexpr value_type value = foo::value;
  static_assert(value[0] == 'f', "");
  static_assert(value[1] == 'o', "");
  static_assert(value[2] == 'o', "");
  static_assert(value.size() == 3u, "");
  static_assert(!value.empty(), "");
  typedef foo::type type;
  static_assert(std::is_same<type, foo>::value, "");
}

void testU8Empty()
{
  typedef CRADLE_MPL_STRING(u8"") foo;
  static_assert(std::is_same<foo, cradle::mpl::string<char> >::value, "");
  typedef foo::value_type value_type;
  static_assert(std::is_same<value_type, std::array<char, 0> >::value, "");
  constexpr value_type value = foo::value;
  static_assert(value.size() == 0u, "");
  static_assert(value.empty(), "");
  typedef foo::type type;
  static_assert(std::is_same<type, foo>::value, "");
}

void testU8Limit()
{
  typedef CRADLE_MPL_STRING(u8"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaayz") foo;
  typedef foo::value_type value_type;
  static_assert(std::is_same<value_type, std::array<char, 1022> >::value, "");
  constexpr value_type value = foo::value;
  static_assert(value[0] == 'a', "");
  static_assert(value[1] == 'a', "");
  static_assert(value[1019] == 'a', "");
  static_assert(value[1020] == 'y', "");
  static_assert(value[1021] == 'z', "");
  static_assert(value.size() == 1022u, "");
  static_assert(!value.empty(), "");
  typedef foo::type type;
  static_assert(std::is_same<type, foo>::value, "");
}

void testU16()
{
  typedef CRADLE_MPL_STRING(u"foo") foo;
  static_assert(std::is_same<foo, cradle::mpl::string<char16_t, u'f', u'o', u'o'> >::value, "");
  typedef foo::value_type value_type;
  static_assert(std::is_same<value_type, std::array<char16_t, 3> >::value, "");
  constexpr value_type value = foo::value;
  static_assert(value[0] == u'f', "");
  static_assert(value[1] == u'o', "");
  static_assert(value[2] == u'o', "");
  static_assert(value.size() == 3u, "");
  static_assert(!value.empty(), "");
  typedef foo::type type;
  static_assert(std::is_same<type, foo>::value, "");
}

void testU16Empty()
{
  typedef CRADLE_MPL_STRING(u"") foo;
  static_assert(std::is_same<foo, cradle::mpl::string<char16_t> >::value, "");
  typedef foo::value_type value_type;
  static_assert(std::is_same<value_type, std::array<char16_t, 0> >::value, "");
  constexpr value_type value = foo::value;
  static_assert(value.size() == 0u, "");
  static_assert(value.empty(), "");
  typedef foo::type type;
  static_assert(std::is_same<type, foo>::value, "");
}

void testU16Limit()
{
  typedef CRADLE_MPL_STRING(u"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaayz") foo;
  typedef foo::value_type value_type;
  static_assert(std::is_same<value_type, std::array<char16_t, 1022> >::value, "");
  constexpr value_type value = foo::value;
  static_assert(value[0] == u'a', "");
  static_assert(value[1] == u'a', "");
  static_assert(value[1019] == u'a', "");
  static_assert(value[1020] == u'y', "");
  static_assert(value[1021] == u'z', "");
  static_assert(value.size() == 1022u, "");
  static_assert(!value.empty(), "");
  typedef foo::type type;
  static_assert(std::is_same<type, foo>::value, "");
}

void testU32()
{
  typedef CRADLE_MPL_STRING(U"foo") foo;
  static_assert(std::is_same<foo, cradle::mpl::string<char32_t, U'f', U'o', U'o'> >::value, "");
  typedef foo::value_type value_type;
  static_assert(std::is_same<value_type, std::array<char32_t, 3> >::value, "");
  constexpr value_type value = foo::value;
  static_assert(value[0] == U'f', "");
  static_assert(value[1] == U'o', "");
  static_assert(value[2] == U'o', "");
  static_assert(value.size() == 3u, "");
  static_assert(!value.empty(), "");
  typedef foo::type type;
  static_assert(std::is_same<type, foo>::value, "");
}

void testU32Empty()
{
  typedef CRADLE_MPL_STRING(U"") foo;
  static_assert(std::is_same<foo, cradle::mpl::string<char32_t> >::value, "");
  typedef foo::value_type value_type;
  static_assert(std::is_same<value_type, std::array<char32_t, 0> >::value, "");
  constexpr value_type value = foo::value;
  static_assert(value.size() == 0u, "");
  static_assert(value.empty(), "");
  typedef foo::type type;
  static_assert(std::is_same<type, foo>::value, "");
}

void testU32Limit()
{
  typedef CRADLE_MPL_STRING(U"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaayz") foo;
  typedef foo::value_type value_type;
  static_assert(std::is_same<value_type, std::array<char32_t, 1022> >::value, "");
  constexpr value_type value = foo::value;
  static_assert(value[0] == U'a', "");
  static_assert(value[1] == U'a', "");
  static_assert(value[1019] == U'a', "");
  static_assert(value[1020] == U'y', "");
  static_assert(value[1021] == U'z', "");
  static_assert(value.size() == 1022u, "");
  static_assert(!value.empty(), "");
  typedef foo::type type;
  static_assert(std::is_same<type, foo>::value, "");
}

void testWide()
{
  typedef CRADLE_MPL_STRING(L"foo") foo;
  static_assert(std::is_same<foo, cradle::mpl::string<wchar_t, L'f', L'o', L'o'> >::value, "");
  typedef foo::value_type value_type;
  static_assert(std::is_same<value_type, std::array<wchar_t, 3> >::value, "");
  constexpr value_type value = foo::value;
  static_assert(value[0] == L'f', "");
  static_assert(value[1] == L'o', "");
  static_assert(value[2] == L'o', "");
  static_assert(value.size() == 3u, "");
  static_assert(!value.empty(), "");
  typedef foo::type type;
  static_assert(std::is_same<type, foo>::value, "");
}

void testWideEmpty()
{
  typedef CRADLE_MPL_STRING(L"") foo;
  static_assert(std::is_same<foo, cradle::mpl::string<wchar_t> >::value, "");
  typedef foo::value_type value_type;
  static_assert(std::is_same<value_type, std::array<wchar_t, 0> >::value, "");
  constexpr value_type value = foo::value;
  static_assert(value.size() == 0u, "");
  static_assert(value.empty(), "");
  typedef foo::type type;
  static_assert(std::is_same<type, foo>::value, "");
}

void testWideLimit()
{
  typedef CRADLE_MPL_STRING(L"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaayz") foo;
  typedef foo::value_type value_type;
  static_assert(std::is_same<value_type, std::array<wchar_t, 1022> >::value, "");
  constexpr value_type value = foo::value;
  static_assert(value[0] == L'a', "");
  static_assert(value[1] == L'a', "");
  static_assert(value[1019] == L'a', "");
  static_assert(value[1020] == L'y', "");
  static_assert(value[1021] == L'z', "");
  static_assert(value.size() == 1022u, "");
  static_assert(!value.empty(), "");
  typedef foo::type type;
  static_assert(std::is_same<type, foo>::value, "");
}
