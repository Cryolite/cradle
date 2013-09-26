//  (C) Copyright Cryolite 2013. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CRADLE_CONTAINER_INDEX_ADAPTOR_HPP_INCLUDE_GUARD)
#define CRADLE_CONTAINER_INDEX_ADAPTOR_HPP_INCLUDE_GUARD

#include <cradle/container/index_facade.hpp>

#include <utility>
#include <type_traits>


namespace cradle{

template<typename Derived, typename Base>
class index_adaptor
  : public cradle::index_facade<Derived>
{
private:
  friend class cradle::index_core_access;

  template<typename OtherDerived, typename OtherBase> friend class index_adaptor;

public:
  typedef Base base_type;

private:
  static constexpr bool is_base_nothrow_swappable_test_() noexcept
  {
    using std::swap;
    return noexcept(swap(std::declval<base_type &>(), std::declval<base_type &>()));
  }

  static constexpr bool is_base_nothrow_swappable_ = is_base_nothrow_swappable_test_();

protected:
  typedef index_adaptor index_adaptor_;

public:
  explicit constexpr index_adaptor(base_type const &x) noexcept(std::is_nothrow_copy_constructible<base_type>::value)
    : v_(x)
  {}

  explicit constexpr index_adaptor(base_type &&x) noexcept(std::is_nothrow_move_constructible<base_type>::value)
    : v_(std::move(x))
  {}

  index_adaptor(index_adaptor const &) = default;

  index_adaptor(index_adaptor &&) = default;

  void swap(index_adaptor &x) noexcept(is_base_nothrow_swappable_)
  {
    using std::swap;
    swap(v_, x.v_);
  }

  index_adaptor &operator=(index_adaptor const &x)
  noexcept(noexcept(index_adaptor(x).swap(std::declval<index_adaptor &>())))
  {
    index_adaptor(x).swap(*this);
    return *this;
  }

  index_adaptor &operator=(index_adaptor &&x)
  noexcept(noexcept(index_adaptor(std::move(x)).swap(std::declval<index_adaptor &>())))
  {
    index_adaptor(std::move(x)).swap(*this);
    return *this;
  }

protected:
  base_type &base_reference() noexcept
  {
    return v_;
  }

  base_type const &base_reference() const noexcept
  {
    return v_;
  }

private:
  template<typename OtherDerived, typename OtherBase,
           typename = decltype(std::declval<Base const &>() == std::declval<OtherBase const &>())>
  constexpr bool is_equal_to_(index_adaptor<OtherDerived, OtherBase> const &x) const
  noexcept(noexcept(std::declval<index_adaptor const &>().v_ == x.v_))
  {
    return v_ == x.v_;
  }

  template<typename OtherDerived, typename OtherBase,
           typename = decltype(std::declval<Base const &>() < std::declval<OtherBase const &>())>
  constexpr bool is_less_than_(index_adaptor<OtherDerived, OtherBase> const &x) const
  noexcept(noexcept(std::declval<index_adaptor const &>().v_ < x.v_))
  {
    return v_ < x.v_;
  }

private:
  base_type v_;
}; // class index_adaptor

template<typename Derived, typename Base>
void swap(index_adaptor<Derived, Base> &x, index_adaptor<Derived, Base> &y) noexcept(noexcept(x.swap(y)))
{
  x.swap(y);
}

} // namespace cradle


#endif // !defined(CRADLE_CONTAINER_INDEX_ADAPTOR_HPP_INCLUDE_GUARD)
