//  (C) Copyright Cryolite 2012. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CRADLE_SCOPE_GUARD_EXCEPTION_GUARD_HPP_INCLUDE_GUARD)
#define CRADLE_SCOPE_GUARD_EXCEPTION_GUARD_HPP_INCLUDE_GUARD

#include <cradle/type_traits/is_decayed.hpp>
#include <cradle/exception/uncaught_exception.hpp>
#include <boost/preprocessor/cat.hpp>
#include <cstddef>
#include <limits>
#include <utility>
#include <type_traits>
#include <tuple>


namespace cradle{ namespace detail_{

template<typename F>
class exception_guard_ final
  : private std::tuple<F>
{
private:
  static_assert(cradle::is_decayed<F>::value, "");
  static_assert(std::is_same<decltype(std::declval<F>()()), void>::value, "");
  typedef std::tuple<F> base_type_;

public:
  explicit exception_guard_(F &&f) noexcept
    : base_type_(std::move(f)),
      num_uncaught_exceptions_(
        cradle::exceptions::get_num_uncaught_exceptions())
  {}

  exception_guard_(exception_guard_ const &) = delete;

  exception_guard_(exception_guard_ &&x) noexcept
    : base_type_(static_cast<base_type_ &&>(x)),
      num_uncaught_exceptions_(x.num_uncaught_exceptions_)
  {
    x.num_uncaught_exceptions_ = std::numeric_limits<std::size_t>::max();
  }

  ~exception_guard_() noexcept
  {
    if (cradle::exceptions::get_num_uncaught_exceptions() > num_uncaught_exceptions_) {
      std::get<0u>(static_cast<base_type_ &&>(*this))();
    }
  }

  exception_guard_ &operator=(exception_guard_ const &) = delete;

private:
  std::size_t num_uncaught_exceptions_;
}; // struct exception_guard_

struct exception_guard_precursor_ final
{
  template<typename F>
  cradle::detail_::exception_guard_<F> operator->*(F &&f) const noexcept
  {
    static_assert(cradle::is_decayed<F>::value, "");
    static_assert(std::is_same<decltype(std::move(f)()), void>::value, "");
    return cradle::detail_::exception_guard_<F>(std::move(f));
  }
}; // struct exception_guard_precursor_

}} // cradle::detail_

#define CRADLE_EXCEPTION_GUARD                                                 \
auto const BOOST_PP_CAT(CRADLE_EXCEPTION_GUARD_, __LINE__)                     \
  = ::cradle::detail_::exception_guard_precursor_() ->* [&]() noexcept -> void \
/**/


#endif // !defined(CRADLE_SCOPE_GUARD_EXCEPTION_GUARD_HPP_INCLUDE_GUARD)
