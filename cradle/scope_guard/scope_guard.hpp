//  (C) Copyright Cryolite 2012. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CRADLE_SCOPE_GUARD_SCOPE_GUARD_HPP_INCLUDE_GUARD)
#define CRADLE_SCOPE_GUARD_SCOPE_GUARD_HPP_INCLUDE_GUARD

#include <cradle/type_traits/is_decayed.hpp>
#include <boost/preprocessor/cat.hpp>
#include <utility>
#include <type_traits>
#include <tuple>


namespace cradle{ namespace detail_{

template<typename F>
class scope_guard_ final
  : private std::tuple<F>
{
private:
  static_assert(cradle::is_decayed<F>::value, "");
  static_assert(std::is_same<decltype(std::declval<F>()()), void>::value, "");
  typedef std::tuple<F> base_type_;

public:
  explicit scope_guard_(F &&f) noexcept
    : base_type_(std::move(f)),
      owns_(true)
  {}

  scope_guard_(scope_guard_ const &) = delete;

  scope_guard_(scope_guard_ &&x) noexcept
    : base_type_(static_cast<base_type_ &&>(x)),
      owns_(x.owns_)
  {
    x.owns_ = false;
  }

  ~scope_guard_() noexcept
  {
    if (owns_) {
      std::get<0u>(static_cast<base_type_ &&>(*this))();
    }
  }

  scope_guard_ &operator=(scope_guard_ const &) = delete;

private:
  bool owns_;
}; // struct scope_guard_

struct scope_guard_precursor_ final
{
  template<typename F>
  cradle::detail_::scope_guard_<F> operator->*(F &&f) const noexcept
  {
    static_assert(cradle::is_decayed<F>::value, "");
    static_assert(std::is_same<decltype(std::move(f)()), void>::value, "");
    return cradle::detail_::scope_guard_<F>(std::move(f));
  }
}; // struct scope_guard_precursor_

}} // cradle::detail_

#define CRADLE_SCOPE_GUARD                                                 \
auto const BOOST_PP_CAT(CRADLE_SCOPE_GUARD_, __LINE__)                     \
  = ::cradle::detail_::scope_guard_precursor_() ->* [&]() noexcept -> void \
/**/


#endif // !defined(CRADLE_SCOPE_GUARD_SCOPE_GUARD_HPP_INCLUDE_GUARD)
