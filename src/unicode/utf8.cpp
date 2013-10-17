//  (C) Copyright Cryolite 2013. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cradle/exception/throw_exception.hpp>
#include <cstddef>
#include <cstdint>
#include <stdexcept>
#include <unicode/utf8.h>


namespace cradle{ namespace unicode{ namespace detail_{

std::size_t copy_uchar_as_utf8_(char32_t const c, std::uint8_t (&buf)[4u])
{
  std::int32_t i = 0;
  constexpr std::int32_t capacity = sizeof(buf) / sizeof(buf[0u]);
  static_assert(capacity == 4u, "");
  UBool is_error = FALSE;
  U8_APPEND(buf, i, capacity, c, is_error);
  if (is_error != FALSE) {
    CRADLE_THROW_EXCEPTION((std::invalid_argument("")));
  }
  return i;
}

}}} // namespace cradle::unicode::detail_
