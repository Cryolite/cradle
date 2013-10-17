//  (C) Copyright Cryolite 2013. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CRADLE_UNICODE_UTF8_HPP_INCLUDE_GUARD)
#define CRADLE_UNICODE_UTF8_HPP_INCLUDE_GUARD

#include <cradle/unicode/config.hpp>
#include <cstddef>
#include <cstdint>
#include <utility>
#include <algorithm>


namespace cradle{ namespace unicode{

namespace detail_{

std::size_t copy_uchar_as_utf8_(char32_t c, std::uint8_t (&buf)[4u]);

} // namespace detail_

template<typename OutputIterator>
void copy_uchar_as_utf8(char32_t const c, OutputIterator iter)
{
  std::uint8_t buf[4u];
  std::size_t const n = detail_::copy_uchar_as_utf8_(c, buf);
  std::copy(&buf[0u], &buf[0u] + n, std::move(iter));
}

}} // namespace cradle::unicode

#endif // !defined(CRADLE_UNICODE_UTF8_HPP_INCLUDE_GUARD)
