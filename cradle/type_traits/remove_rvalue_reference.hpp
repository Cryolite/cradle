//  (C) Copyright Cryolite 2013. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CRADLE_TYPE_TRAITS_REMOVE_RVALUE_REFERENCE_HPP_INCLUDE_GUARD)
#define CRADLE_TYPE_TRAITS_REMOVE_RVALUE_REFERENCE_HPP_INCLUDE_GUARD

#include <cradle/type_traits/identity.hpp>

namespace cradle{

template<typename T>
struct remove_rvalue_reference
  : cradle::identity<T>
{};

template<typename T>
struct remove_rvalue_reference<T &&>
  : cradle::identity<T>
{};

} // namespace cradle

#endif // !defined(CRADLE_TYPE_TRAITS_REMOVE_RVALUE_REFERENCE_HPP_INCLUDE_GUARD)
