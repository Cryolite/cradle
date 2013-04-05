//  (C) Copyright Cryolite 2012. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CRADLE_TYPE_TRAITS_IS_DECAYED_HPP_INCLUDE_GUARD)
#define CRADLE_TYPE_TRAITS_IS_DECAYED_HPP_INCLUDE_GUARD

#include <boost/mpl/bool.hpp>
#include <type_traits>


namespace cradle{

namespace detail_{

template<bool b>
struct is_decayed__
  : boost::mpl::bool_<b>
{};

template<typename T, typename Decayed>
struct is_decayed_
  : cradle::detail_::is_decayed__<std::is_same<T, Decayed>::value>
{};

} // namespace detail_

template<typename T>
struct is_decayed
  : cradle::detail_::is_decayed_<T, typename std::decay<T>::type>
{
  typedef typename cradle::detail_::is_decayed_<T, typename std::decay<T>::type>::type type;

  static constexpr bool value = type::value;

  constexpr operator bool()
  {
    return value;
  }
};

} // namespace cradle

#endif // !defined(CRADLE_TYPE_TRAITS_IS_DECAYED_HPP_INCLUDE_GUARD)
