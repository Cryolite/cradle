//  (C) Copyright Cryolite 2012. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CRADLE_TYPE_TRAITS_IS_PLAIN_HPP_INCLUDE_GUARD)
#define CRADLE_TYPE_TRAITS_IS_PLAIN_HPP_INCLUDE_GUARD

#include <type_traits>


namespace cradle{

template<typename T>
struct is_plain
  : std::integral_constant<
      bool,
      !std::is_reference<T>::value
      && !std::is_const<T>::value
      && !std::is_volatile<T>::value>
{};

} // namespace cradle

#endif // !defined(CRADLE_TYPE_TRAITS_IS_PLAIN_HPP_INCLUDE_GUARD)
