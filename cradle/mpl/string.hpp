//  (C) Copyright Cryolite 2013. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CRADLE_MPL_STRING_HPP_INCLUDE_GUARD)
#define CRADLE_MPL_STRING_HPP_INCLUDE_GUARD

#include <boost/preprocessor/config/limits.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/facilities/intercept.hpp>
#include <boost/preprocessor/tuple/elem.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>
#include <boost/preprocessor/repetition/enum_trailing.hpp>
#include <boost/preprocessor/repetition/enum_trailing_params.hpp>
#include <boost/preprocessor/repetition/enum_trailing_binary_params.hpp>

#include <cstddef>
#include <type_traits>
#include <array>


// For the sake of simplicity, `CRADLE_MPL_STRING_DETAIL_` prefix of macro
// names and `::cradle::mpl::detail::` scope qualification of identifiers
// are omitted in the following comments.

// The following macros are NOT intended to be modified by users.
// The following conditions should be guaranteed when the values of these
// macros are changed;
//
// * `UNROLLING_LENGTH_` is a positive integer,
// * `MAX_SIZE_ / UNROLLING_LENGTH_ + 2` is not greater than the
//   implementation quantity of recursively nested template instantiations
//   (the recommended quality is 1024, described in ISO/IEC 14882:2011 Annex
//   B [implimits]),
// * `EXPANSION_SIZE_` is equal to `MAX_SIZE_ + UNROLLING_LENGTH_`,
// * `EXPANSION_SIZE_ + 2` is not greater than the implementation quantity
//   of template arguments in a template declaration (the recommended
//   quality is 1024, described in ISO/IEC 14882:2011 Annex B [implimits]),
// * `EXPANSION_SIZE_INNER_` is not greater than `BOOST_PP_LIMIT_REPEAT`,
// * `EXPANSION_SIZE_OUTER_` is not greater than `BOOST_PP_LIMIT_REPEAT`,
// * `EXPANSION_SIZE_OUTER_` is equal to
//   `EXPANSION_SIZE_ / EXPANSION_SIZE_INNER_`, and
// * `EXPANSION_SIZE_TRAILING_` is equal to
//   `EXPANSION_SIZE_ % EXPANSION_SIZE_INNER_`.
#define CRADLE_MPL_STRING_DETAIL_MAX_SIZE_ 256
#define CRADLE_MPL_STRING_DETAIL_UNROLLING_LENGTH_ 8
#define CRADLE_MPL_STRING_DETAIL_EXPANSION_SIZE_ 264
#define CRADLE_MPL_STRING_DETAIL_EXPANSION_SIZE_INNER_ 256
#define CRADLE_MPL_STRING_DETAIL_EXPANSION_SIZE_OUTER_ 1
#define CRADLE_MPL_STRING_DETAIL_EXPANSION_SIZE_TRAILING_ \
        CRADLE_MPL_STRING_DETAIL_UNROLLING_LENGTH_
/**/

namespace cradle{ namespace mpl{

constexpr std::size_t string_max_size = CRADLE_MPL_STRING_DETAIL_MAX_SIZE_;

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
constexpr T string_at_(T const (&str)[N], std::size_t i)
{
  // `str` is a reference to a string literal, and `N` is equal to the
  // length of the string literal. Thus, `str` has a null character at its
  // end, and `N` is one greater than the net length of the string.
  static_assert(
    std::is_same<T, char>::value
    || std::is_same<T, char16_t>::value
    || std::is_same<T, char32_t>::value
    || std::is_same<T, wchar_t>::value, "");
  static_assert(N > 0u, "");
  static_assert(N <= string_max_size + 1, "");
  return i < CRADLE_MPL_STRING_DETAIL_EXPANSION_SIZE_
    ? (str[N - 1] == '\0'
         ? (i < N ? str[i] : static_cast<T>(0))
         : throw "")
    : throw "";
}

template<typename T, typename String, std::size_t I, T... Chars>
struct get_string__;

template<
  typename T,
  T... HeadChars,
  std::size_t I
  BOOST_PP_ENUM_TRAILING_BINARY_PARAMS(
    CRADLE_MPL_STRING_DETAIL_UNROLLING_LENGTH_, T BOOST_PP_INTERCEPT, C),
  T... TailChars>
struct get_string__<
  T,
  cradle::mpl::string<T, HeadChars...>,
  I
  BOOST_PP_ENUM_TRAILING_PARAMS(
    CRADLE_MPL_STRING_DETAIL_UNROLLING_LENGTH_, C),
  TailChars...>
  : public get_string__<
      T,
      cradle::mpl::string<
        T,
        HeadChars...
        BOOST_PP_ENUM_TRAILING_PARAMS(
          CRADLE_MPL_STRING_DETAIL_UNROLLING_LENGTH_, C)>,
      I - CRADLE_MPL_STRING_DETAIL_UNROLLING_LENGTH_,
      TailChars...>
{};

#define CRADLE_MPL_STRING_DETAIL_TERMINATOR_(Z, I, DATA)                  \
template<                                                                 \
  typename T,                                                             \
  T... HeadChars                                                          \
  BOOST_PP_ENUM_TRAILING_BINARY_PARAMS_Z(                                 \
    Z,                                                                    \
    CRADLE_MPL_STRING_DETAIL_UNROLLING_LENGTH_,                           \
    T BOOST_PP_INTERCEPT,                                                 \
    C),                                                                   \
  T... TailChars>                                                         \
struct get_string__<                                                      \
  T,                                                                      \
  cradle::mpl::string<T, HeadChars...>,                                   \
  I                                                                       \
  BOOST_PP_ENUM_TRAILING_PARAMS_Z(                                        \
    Z, CRADLE_MPL_STRING_DETAIL_UNROLLING_LENGTH_, C),                    \
  TailChars...>                                                           \
{                                                                         \
  static_assert(                                                          \
    std::is_same<T, char>::value                                          \
    || std::is_same<T, char16_t>::value                                   \
    || std::is_same<T, char32_t>::value                                   \
    || std::is_same<T, wchar_t>::value, "");                              \
  static_assert(sizeof...(HeadChars) + I <= string_max_size, "");         \
  static_assert(                                                          \
    sizeof...(HeadChars)                                                  \
      + CRADLE_MPL_STRING_DETAIL_UNROLLING_LENGTH_                        \
      + sizeof...(TailChars)                                              \
      == CRADLE_MPL_STRING_DETAIL_EXPANSION_SIZE_, "");                   \
  typedef cradle::mpl::string<                                            \
    T,                                                                    \
    HeadChars...                                                          \
    BOOST_PP_ENUM_TRAILING_PARAMS_Z(Z, I, C)> type;                       \
};                                                                        \
/**/

BOOST_PP_REPEAT(CRADLE_MPL_STRING_DETAIL_UNROLLING_LENGTH_,
                CRADLE_MPL_STRING_DETAIL_TERMINATOR_,
                DATA)

template<typename T, std::size_t N, T... Chars>
struct get_string_
  : public get_string__<T, cradle::mpl::string<T>, N, Chars...>
{};

} // namespace detail_

}} // namespace cradle::mpl

#define CRADLE_MPL_STRING_DETAIL_EXPANSION_INNER__(STRING_LITERAL, I, J)  \
::cradle::mpl::detail_::string_at_(                                       \
  STRING_LITERAL, I * CRADLE_MPL_STRING_DETAIL_EXPANSION_SIZE_INNER_ + J) \
/**/

#define CRADLE_MPL_STRING_DETAIL_EXPANSION_INNER_(Z, J, DATA)          \
CRADLE_MPL_STRING_DETAIL_EXPANSION_INNER__(                            \
  BOOST_PP_TUPLE_ELEM(2, 0, DATA), BOOST_PP_TUPLE_ELEM(2, 1, DATA), J) \
/**/

#define CRADLE_MPL_STRING_DETAIL_EXPANSION_OUTER_(Z, I, STRING_LITERAL) \
BOOST_PP_CAT(BOOST_PP_ENUM_TRAILING_, Z)(                               \
  CRADLE_MPL_STRING_DETAIL_EXPANSION_SIZE_INNER_,                       \
  CRADLE_MPL_STRING_DETAIL_EXPANSION_INNER_,                            \
  (STRING_LITERAL, I))                                                  \
/**/

// Expands to
//   get_string_<
//     T, N,
//     string_at_(STRING_LITERAL, 0),
//     string_at_(STRING_LITERAL, 1),
//     ...,
//     string_at_(STRING_LITERAL, EXPANSION_SIZE_)>::type
#define CRADLE_MPL_STRING(STRING_LITERAL)                                    \
::cradle::mpl::detail_::get_string_<                                         \
  ::std::remove_const<                                                       \
    ::std::remove_reference<decltype(STRING_LITERAL[0])>::type>::type,       \
  sizeof(STRING_LITERAL) / sizeof(STRING_LITERAL[0]) - 1                     \
  BOOST_PP_REPEAT(                                                           \
    CRADLE_MPL_STRING_DETAIL_EXPANSION_SIZE_OUTER_,                          \
    CRADLE_MPL_STRING_DETAIL_EXPANSION_OUTER_,                               \
    STRING_LITERAL)                                                          \
  BOOST_PP_ENUM_TRAILING(                                                    \
    CRADLE_MPL_STRING_DETAIL_EXPANSION_SIZE_TRAILING_,                       \
    CRADLE_MPL_STRING_DETAIL_EXPANSION_INNER_,                               \
    (STRING_LITERAL, CRADLE_MPL_STRING_DETAIL_EXPANSION_SIZE_OUTER_))>::type \
/**/

#endif // !defined(CRADLE_MPL_STRING_HPP_INCLUDE_GUARD)
