//  (C) Copyright Cryolite 2013. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CRADLE_TYPE_TRAITS_ENABLE_IF_VOLATILE_HPP_INCLUDE_GUARD)
#define CRADLE_TYPE_TRAITS_ENABLE_IF_VOLATILE_HPP_INCLUDE_GUARD

#include <type_traits>


namespace cradle{

template<typename T, typename R = void>
using enable_if_volatile
  = typename std::enable_if<std::is_volatile<T>::value, R>::type;

template<typename T, typename R = void>
using disable_if_volatile
  = typename std::enable_if<!std::is_volatile<T>::value, R>::type;

} // namespace cradle


#endif // !defined(CRADLE_TYPE_TRAITS_ENABLE_IF_VOLATILE_HPP_INCLUDE_GUARD)
