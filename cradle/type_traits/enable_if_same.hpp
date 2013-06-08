//  (C) Copyright Cryolite 2013. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CRADLE_TYPE_TRAITS_ENABLE_IF_SAME_HPP_INCLUDE_GUARD)
#define CRADLE_TYPE_TRAITS_ENABLE_IF_SAME_HPP_INCLUDE_GUARD

#include <type_traits>


namespace cradle{

template<typename T, typename U, typename R = void>
using enable_if_same
  = typename std::enable_if<std::is_same<T, U>::value, R>::type;

} // namespace cradle


#endif // !defined(CRADLE_TYPE_TRAITS_ENABLE_IF_SAME_HPP_INCLUDE_GUARD)
