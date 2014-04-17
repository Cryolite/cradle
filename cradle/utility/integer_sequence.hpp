//  (C) Copyright Cryolite 2014. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CRADLE_UTILITY_INTEGER_SEQUENCE_HPP_INCLUDE_GUARD)
#define CRADLE_UTILITY_INTEGER_SEQUENCE_HPP_INCLUDE_GUARD

#include <boost/mpl/empty_base.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/identity.hpp>
#include <type_traits>
#include <cstddef>


namespace cradle{

template<typename T, T... Is>
struct integer_sequence{
  static_assert(std::is_integral<T>::value, "");

  typedef T type;

  static constexpr std::size_t size() noexcept
  {
    return sizeof...(Is);
  }
};

namespace detail_{

template<typename IntegerSequence, typename JntegerSequence>
struct concat_integer_sequence_;

template<typename T, T... Is, T... Js>
struct concat_integer_sequence_<integer_sequence<T, Is...>,
                                integer_sequence<T, Js...> >
  : boost::mpl::identity<
      integer_sequence<T, Is..., Js + sizeof...(Is)...> >
{};

template<typename T, T N>
struct make_integer_sequence_;

template<typename T, T N>
struct make_integer_sequence_eval_
  : concat_integer_sequence_<
      typename make_integer_sequence_<T, (N + 1) / 2>::type,
      typename make_integer_sequence_<T, N / 2>::type>
{};

template<typename T, T N>
struct make_integer_sequence_
  : boost::mpl::eval_if_c<
      (N > 1),
      make_integer_sequence_eval_<T, N>,
      boost::mpl::eval_if_c<
        N == 1,
        boost::mpl::identity<integer_sequence<T, 0> >,
        boost::mpl::eval_if_c<
          N == 0,
          boost::mpl::identity<integer_sequence<T> >,
          boost::mpl::empty_base> > >
{};

}

template<typename T, T N>
using make_integer_sequence
  = typename detail_::make_integer_sequence_<T, N>::type;

} // namespace cradle


#endif // !defined(CRADLE_UTILITY_INTEGER_SEQUENCE_HPP_INCLUDE_GUARD)
