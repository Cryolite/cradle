//  (C) Copyright Cryolite 2013. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CRADLE_CONTAINER_INDEX_FACADE_HPP_INCLUDE_GUARD)
#define CRADLE_CONTAINER_INDEX_FACADE_HPP_INCLUDE_GUARD

#include <utility>
#include <type_traits>


namespace cradle{

template<typename Derived>
class index_facade;

class index_core_access
{
private:
  template<typename Derived> friend class index_facade;

public:
  template<typename Derived>
  static constexpr bool is_derived_() noexcept
  {
    return !std::is_const<Derived>::value && !std::is_volatile<Derived>::value
      && !std::is_same<Derived, index_facade<Derived> >::value
      && std::is_base_of<index_facade<Derived>, Derived>::value;
  }

  template<typename Derived, typename OtherDerived,
           typename = decltype(std::declval<Derived const &>().is_equal_to_(std::declval<OtherDerived const &>()))>
  static constexpr bool has_is_equal_to_(int) noexcept
  {
    return true;
  }

  template<typename Derived, typename OtherDerived>
  static constexpr bool has_is_equal_to_(bool) noexcept
  {
    return false;
  }

  template<typename Derived, typename OtherDerived>
  static constexpr bool is_equality_comparable_() noexcept
  {
    return is_derived_<Derived>() && is_derived_<OtherDerived>() && has_is_equal_to_<Derived, OtherDerived>(0);
  }

  template<typename Derived, typename OtherDerived,
           typename = decltype(std::declval<Derived const &>().is_less_than_(std::declval<OtherDerived const &>()))>
  static constexpr bool has_is_less_than_(int) noexcept
  {
    return true;
  }

  template<typename Derived, typename OtherDerived>
  static constexpr bool has_is_less_than_(bool) noexcept
  {
    return false;
  }

  template<typename Derived, typename OtherDerived>
  static constexpr bool is_totally_orderable_() noexcept
  {
    return is_derived_<Derived>() && is_derived_<OtherDerived>()
      && has_is_equal_to_<Derived, OtherDerived>(0) && has_is_less_than_<Derived, OtherDerived>(0);
  }

  template<typename Derived>
  static constexpr bool is_nullable_() noexcept
  {
    return is_derived_<Derived>() && std::is_default_constructible<Derived>()
      && is_equality_comparable_<Derived, Derived>();
  }

public:
  index_core_access() = delete;

private:
  template<typename Derived, typename OtherDerived>
  static constexpr typename std::enable_if<is_equality_comparable_<Derived, OtherDerived>(), bool>::type
  is_equal_to_(Derived const &x, OtherDerived const &y) noexcept(noexcept(x.is_equal_to_(y)))
  {
    return x.is_equal_to_(y);
  }

  template<typename Derived, typename OtherDerived>
  static constexpr typename std::enable_if<is_totally_orderable_<Derived, OtherDerived>(), bool>::type
  is_less_than_(Derived const &x, OtherDerived const &y) noexcept(noexcept(x.is_less_than_(y)))
  {
    return x.is_less_than_(y);
  }
}; // class index_core_access

template<typename Derived>
class index_facade
{
private:
  constexpr Derived const &as_derived_() const noexcept
  {
    static_assert(index_core_access::is_derived_<Derived>(), "");
    return static_cast<Derived const &>(*this);
  }

public:
  template<typename OtherDerived>
  constexpr typename std::enable_if<index_core_access::is_equality_comparable_<Derived, OtherDerived>(), bool>::type
  operator==(index_facade<OtherDerived> const &x) const
  noexcept(noexcept(index_core_access::is_equal_to_(
                      std::declval<index_facade const &>().as_derived_(), static_cast<OtherDerived const &>(x))))
  {
    static_assert(index_core_access::is_derived_<OtherDerived>(), "");
    return index_core_access::is_equal_to_(this->as_derived_(), static_cast<OtherDerived const &>(x));
  }

  template<typename OtherDerived>
  constexpr typename std::enable_if<index_core_access::is_equality_comparable_<Derived, OtherDerived>(), bool>::type
  operator!=(index_facade<OtherDerived> const &x) const
  noexcept(noexcept(!(std::declval<index_facade const &>() == x)))
  {
    return !(*this == x);
  }

  template<typename OtherDerived>
  constexpr typename std::enable_if<index_core_access::is_totally_orderable_<Derived, OtherDerived>(), bool>::type
  operator<(index_facade<OtherDerived> const &x) const
  noexcept(noexcept(index_core_access::is_less_than_(
                      std::declval<index_facade const &>().as_derived_(), static_cast<OtherDerived const &>(x))))
  {
    static_assert(index_core_access::is_derived_<OtherDerived>(), "");
    return index_core_access::is_less_than_(this->as_derived_(), static_cast<OtherDerived const &>(x));
  }

  template<typename OtherDerived>
  constexpr typename std::enable_if<index_core_access::is_totally_orderable_<Derived, OtherDerived>(), bool>::type
  operator>(index_facade<OtherDerived> const &x) const
  noexcept(noexcept(x < std::declval<index_facade const &>()))
  {
    return x < *this;
  }

  template<typename OtherDerived>
  constexpr typename std::enable_if<index_core_access::is_totally_orderable_<Derived, OtherDerived>(), bool>::type
  operator<=(index_facade<OtherDerived> const &x) const
  noexcept(noexcept(!(std::declval<index_facade const &>() > x)))
  {
    return !(*this > x);
  }

  template<typename OtherDerived>
  constexpr typename std::enable_if<index_core_access::is_totally_orderable_<Derived, OtherDerived>(), bool>::type
  operator>=(index_facade<OtherDerived> const &x) const
  noexcept(noexcept(x <= std::declval<index_facade const &>()))
  {
    return x <= *this;
  }

  template<typename T = void *>
  constexpr typename std::enable_if<sizeof(T) != 0u && index_core_access::is_nullable_<Derived>(), bool>::type
  is_null() const noexcept(noexcept(std::declval<index_facade const &>().as_derived_() == Derived()))
  {
    return this->as_derived_() == Derived();
  }
}; // class index_facade

} // namespace cradle


#endif // !defined(CRADLE_CONTAINER_INDEX_FACADE_HPP_INCLUDE_GUARD)
