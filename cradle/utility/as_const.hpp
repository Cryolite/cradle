//  (C) Copyright Cryolite 2013. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CRADLE_UTILITY_AS_CONST_HPP_INCLUDE_GUARD)
#define CRADLE_UTILITY_AS_CONST_HPP_INCLUDE_GUARD

#include <utility>

namespace cradle{

template<typename T>
T const &as_const(T const &x) noexcept
{
  return x;
}

template<typename T>
T const &&as_const(T const &&x) noexcept
{
  return std::move(x);
}

} // namespace cradle

#endif // !defined(CRADLE_UTILITY_AS_CONST_HPP_INCLUDE_GUARD)
