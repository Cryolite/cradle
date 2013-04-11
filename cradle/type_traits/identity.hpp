//  (C) Copyright Cryolite 2013. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CRADLE_TYPE_TRAITS_IDENTITY_HPP_INCLUDE_GUARD)
#define CRADLE_TYPE_TRAITS_IDENTITY_HPP_INCLUDE_GUARD

namespace cradle{

template<typename T>
struct identity
{
  typedef T type;
};

} // namespace cradle

#endif // !defined(CRADLE_TYPE_TRAITS_IDENTITY_HPP_INCLUDE_GUARD)
