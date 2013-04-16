//  (C) Copyright Cryolite 2013. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CRADLE_UTILITY_SIMPLE_AUTO_FORWARD_RETURN_HPP_INCLUDE_GUARD)
#define CRADLE_UTILITY_SIMPLE_AUTO_FORWARD_RETURN_HPP_INCLUDE_GUARD

#include <type_traits>

#define CRADLE_SIMPLE_AUTO_FORWARD_RETURN(EXPRESSION)               \
noexcept(                                                           \
  noexcept(EXPRESSION)                                              \
  && (::std::is_void<decltype((EXPRESSION))>::value                 \
      || ::std::is_nothrow_constructible<                           \
           decltype((EXPRESSION)), decltype((EXPRESSION))>::value)) \
-> decltype((EXPRESSION))                                           \
{                                                                   \
  return EXPRESSION;                                                \
}                                                                   \
/**/

#endif // !defined(CRADLE_UTILITY_SIMPLE_AUTO_FORWARD_RETURN_HPP_INCLUDE_GUARD)
