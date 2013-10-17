//  (C) Copyright Cryolite 2013. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CRADLE_UNICODE_CONFIG_HPP_INCLUDE_GUARD)
#define CRADLE_UNICODE_CONFIG_HPP_INCLUDE_GUARD

#include <cstdint>
#include <limits>


namespace cradle{ namespace unicode{ namespace detail_{

template<std::uint8_t c>
void assert_bijection_between_char_and_uint8_t_impl_()
{
  assert_bijection_between_char_and_uint8_t_impl_<c - 1>();
  static_assert(static_cast<std::uint8_t>(static_cast<char>(c)) == c, "");
}

template<>
void assert_bijection_between_char_and_uint8_t_impl_<0u>()
{
  constexpr std::uint8_t c = 0u;
  static_assert(static_cast<std::uint8_t>(static_cast<char>(c)) == c, "");
}

inline void assert_bijection_between_char_and_uint8_t_()
{
  assert_bijection_between_char_and_uint8_t_impl_<std::numeric_limits<std::uint8_t>::max()>();
}

}}} // namespace cradle::unicode::detail_


#endif // !defined(CRADLE_UNICODE_CONFIG_HPP_INCLUDE_GUARD)
