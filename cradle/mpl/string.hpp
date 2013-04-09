//  (C) Copyright Cryolite 2013. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CRADLE_MPL_STRING_HPP_INCLUDE_GUARD)
#define CRADLE_MPL_STRING_HPP_INCLUDE_GUARD

#include <boost/preprocessor/config/limits.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/tuple/elem.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>
#include <boost/preprocessor/repetition/enum_trailing.hpp>

#include <cstddef>
#include <type_traits>
#include <array>


// The following macros are NOT intended to be modified by users.
// The following conditions should be guaranteed when the values of these
// macros are changed;
//
// * CRADLE_MPL_DETAIL_STRING_MAX_SIZE_ is less than the implementation
//   quantity of template arguments in a template declaration,
// * CRADLE_MPL_DETAIL_STRING_MAX_SIZE_ + 1 is less than the implementation
//   quantity of recursively nested template instantiations,
// * CRADLE_MPL_DETAIL_ENUM_STRING_LITERAL_ELEMS_INNER_SIZE_ is not greater
//   than BOOST_PP_LIMIT_REPEAT,
// * CRADLE_MPL_DETAIL_ENUM_STRING_LITERAL_ELEMS_OUTER_SIZE_ is equal to
//   CRADLE_MPL_DETAIL_STRING_MAX_SIZE_ / CRADLE_MPL_DETAIL_ENUM_STRING_LITERAL_ELEMS_INNER_SIZE_,
// * CRADLE_MPL_DETAIL_ENUM_STRING_LITERAL_ELEMS_OUTER_SIZE_ is not greater
//   than BOOST_PP_LIMIT_REPEAT, and
// * CRADLE_MPL_DETAIL_ENUM_STRING_LITERAL_ELEMS_INNER_TRAILING_SIZE_ is
//   equal to CRADLE_MPL_DETAIL_STRING_MAX_SIZE_ % CRADLE_MPL_DETAIL_ENUM_STRING_LITERAL_ELEMS_INNER_SIZE_.
#define CRADLE_MPL_DETAIL_STRING_MAX_SIZE_ 1022
#define CRADLE_MPL_DETAIL_ENUM_STRING_LITERAL_ELEMS_INNER_SIZE_ 256
#define CRADLE_MPL_DETAIL_ENUM_STRING_LITERAL_ELEMS_OUTER_SIZE_ 3
#define CRADLE_MPL_DETAIL_ENUM_STRING_LITERAL_ELEMS_INNER_TRAILING_SIZE_ 254

namespace cradle{ namespace mpl{

constexpr std::size_t string_max_size = CRADLE_MPL_DETAIL_STRING_MAX_SIZE_;

template<typename T, T... Chars>
struct string
{
  static_assert(
    std::is_same<T, char>::value
    || std::is_same<T, char16_t>::value
    || std::is_same<T, char32_t>::value
    || std::is_same<T, wchar_t>::value, "");
  static_assert(sizeof...(Chars) <= string_max_size, "");

  typedef std::array<T, sizeof...(Chars)> value_type;
  static constexpr value_type value = {{ Chars... }};
  typedef string type;

  constexpr operator value_type()
  {
    return value;
  }
};

namespace detail_{

template<typename T, std::size_t N>
constexpr T get_string_literal_elem_with_truncation_(T const (&str)[N], std::size_t i)
{
  static_assert(
    std::is_same<T, char>::value
    || std::is_same<T, char16_t>::value
    || std::is_same<T, char32_t>::value
    || std::is_same<T, wchar_t>::value, "");
  static_assert(N > 0u, "");
  static_assert(N <= string_max_size + 1, "");
  return i <= string_max_size ? (i < N - 1 ? str[i] : static_cast<T>(0)) : throw "";
}

template<typename T, typename String, std::size_t N, std::size_t I, T... Chars>
struct get_string__;

template<typename T, T... HeadChars, std::size_t N, std::size_t I, T C, T... TailChars>
struct get_string__<T, cradle::mpl::string<T, HeadChars...>, N, I, C, TailChars...>
  : public get_string__<T, cradle::mpl::string<T, HeadChars..., C>, N, I + 1, TailChars...>
{};

template<typename T, T... HeadChars, std::size_t N, T C, T... TailChars>
struct get_string__<T, cradle::mpl::string<T, HeadChars...>, N, N, C, TailChars...>
{
  static_assert(
    std::is_same<T, char>::value
    || std::is_same<T, char16_t>::value
    || std::is_same<T, char32_t>::value
    || std::is_same<T, wchar_t>::value, "");
  static_assert(sizeof...(HeadChars) <= string_max_size, "");
  static_assert(N == sizeof...(HeadChars), "");
  static_assert(C == static_cast<T>(0), "");
  static_assert(N + 1 + sizeof...(TailChars) == string_max_size, "");
  typedef cradle::mpl::string<T, HeadChars...> type;
};

template<typename T, T... HeadChars, std::size_t N, T... TailChars>
struct get_string__<T, cradle::mpl::string<T, HeadChars...>, N, N, TailChars...>
{
  static_assert(
    std::is_same<T, char>::value
    || std::is_same<T, char16_t>::value
    || std::is_same<T, char32_t>::value
    || std::is_same<T, wchar_t>::value, "");
  static_assert(sizeof...(HeadChars) <= string_max_size, "");
  static_assert(N == sizeof...(HeadChars), "");
  static_assert(N + sizeof...(TailChars) == string_max_size, "");
  typedef cradle::mpl::string<T, HeadChars...> type;
};

template<typename T, std::size_t N, T... Chars>
struct get_string_
  : public get_string__<T, cradle::mpl::string<T>, N, 0u, Chars...>
{};

} // namespace detail_

}} // namespace cradle::mpl

#define CRADLE_MPL_DETAIL_ENUM_STRING_LITERAL_ELEMS_INNER__(STRING_LITERAL, I, J) \
::cradle::mpl::detail_::get_string_literal_elem_with_truncation_(                 \
  STRING_LITERAL,                                                                 \
  I * CRADLE_MPL_DETAIL_ENUM_STRING_LITERAL_ELEMS_INNER_SIZE_ + J)                \
/**/

#define CRADLE_MPL_DETAIL_ENUM_STRING_LITERAL_ELEMS_INNER_(Z, J, DATA) \
CRADLE_MPL_DETAIL_ENUM_STRING_LITERAL_ELEMS_INNER__(                   \
  BOOST_PP_TUPLE_ELEM(2, 0, DATA), BOOST_PP_TUPLE_ELEM(2, 1, DATA), J) \
/**/

#define CRADLE_MPL_DETAIL_ENUM_STRING_LITERAL_ELEMS_OUTER_(Z, I, STRING_LITERAL) \
BOOST_PP_CAT(BOOST_PP_ENUM_TRAILING_, Z)(                                        \
  CRADLE_MPL_DETAIL_ENUM_STRING_LITERAL_ELEMS_INNER_SIZE_,                       \
  CRADLE_MPL_DETAIL_ENUM_STRING_LITERAL_ELEMS_INNER_,                            \
  (STRING_LITERAL, I))                                                           \
/**/

#define CRADLE_MPL_STRING(STRING_LITERAL)                                             \
::cradle::mpl::detail_::get_string_<                                                  \
  ::std::remove_const<                                                                \
    ::std::remove_reference<decltype(STRING_LITERAL[0])>::type>::type,                \
  sizeof(STRING_LITERAL) / sizeof(STRING_LITERAL[0]) - 1                              \
  BOOST_PP_REPEAT(                                                                    \
    CRADLE_MPL_DETAIL_ENUM_STRING_LITERAL_ELEMS_OUTER_SIZE_,                          \
    CRADLE_MPL_DETAIL_ENUM_STRING_LITERAL_ELEMS_OUTER_,                               \
    STRING_LITERAL)                                                                   \
  BOOST_PP_ENUM_TRAILING(                                                             \
    CRADLE_MPL_DETAIL_ENUM_STRING_LITERAL_ELEMS_INNER_TRAILING_SIZE_,                 \
    CRADLE_MPL_DETAIL_ENUM_STRING_LITERAL_ELEMS_INNER_,                               \
    (STRING_LITERAL, CRADLE_MPL_DETAIL_ENUM_STRING_LITERAL_ELEMS_OUTER_SIZE_))>::type \
/**/

#endif // !defined(CRADLE_MPL_STRING_HPP_INCLUDE_GUARD)
