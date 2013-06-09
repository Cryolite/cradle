//  (C) Copyright Cryolite 2013. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CRADLE_MEMORY_POLYMORPHIC_ALLOCATOR_HPP_INCLUDE_GUARD)
#define CRADLE_MEMORY_POLYMORPHIC_ALLOCATOR_HPP_INCLUDE_GUARD

#include <cradle/memory/memory_resource_adaptor.hpp>
#include <cradle/memory/memory_resource.hpp>
#include <cradle/exception/throw_with_nested.hpp>
#include <cradle/type_traits/enable_if_same.hpp>
#include <cradle/type_traits/enable_if_reference.hpp>
#include <cradle/type_traits/enable_if_volatile.hpp>
#include <type_traits>
#include <memory>
#include <utility>
#include <stdexcept>
#include <new>
#include <cstddef>


namespace cradle{

template<typename T>
class polymorphic_allocator;


template<typename T>
struct is_polymorphic_allocator
  : std::false_type
{};

template<typename T>
struct is_polymorphic_allocator<polymorphic_allocator<T> >
  : std::true_type
{};

template<typename T>
struct is_polymorphic_allocator<polymorphic_allocator<T> const>
  : std::true_type
{};

template<typename T>
struct is_polymorphic_allocator<polymorphic_allocator<T> volatile>
  : std::true_type
{};

template<typename T>
struct is_polymorphic_allocator<polymorphic_allocator<T> const volatile>
  : std::true_type
{};


template<typename T, typename R = void>
using enable_if_polymorphic_allocator
  = typename std::enable_if<is_polymorphic_allocator<T>::value, R>::type;

template<typename T, typename R = void>
using disable_if_polymorphic_allocator
  = typename std::enable_if<!is_polymorphic_allocator<T>::value, R>::type;


template<typename T, typename U>
bool operator==(polymorphic_allocator<T> const &x,
                polymorphic_allocator<U> const &y) noexcept;


template<>
class polymorphic_allocator<void>
{
public:
  typedef void value_type;
  typedef void *pointer;
  typedef void const *const_pointer;
  typedef void *void_pointer;
  typedef void const *const_void_pointer;
  typedef std::ptrdiff_t difference_type;
  typedef std::size_t size_type;
  static_assert(
    std::is_same<
      std::make_unsigned<difference_type>::type, size_type>::value,
    "");

  typedef std::false_type propagate_on_container_copy_assignment;
  typedef std::true_type propagate_on_container_move_assignment;
  typedef std::true_type propagate_on_container_swap;

  template<typename U>
  struct rebind
  {
    typedef polymorphic_allocator<U> other;
  };
};


template<typename T>
class polymorphic_allocator
{
private:
  template<typename U>
  friend class polymorphic_allocator;

private:
  static_assert(std::is_object<T>::value, "");
  static_assert(!std::is_const<T>::value, "");
  static_assert(!std::is_volatile<T>::value, "");

public:
  typedef T value_type;
  typedef T *pointer;
  typedef T const *const_pointer;
  typedef void *void_pointer;
  typedef void const *const_void_pointer;
  typedef std::ptrdiff_t difference_type;
  typedef std::size_t size_type;

  typedef std::false_type propagate_on_container_copy_assignment;
  typedef std::true_type propagate_on_container_move_assignment;
  typedef std::true_type propagate_on_container_swap;

  template<typename U>
  struct rebind
  {
    typedef polymorphic_allocator<U> other;
  };

public:
  polymorphic_allocator() = default;

private:
  explicit polymorphic_allocator(
    std::shared_ptr<cradle::memory_resource> const &p)
    : p_(p)
  {}

  explicit polymorphic_allocator(
    std::shared_ptr<cradle::memory_resource> &&p)
    : p_(std::move(p))
  {}

public:
  template<typename U>
  polymorphic_allocator(std::allocator<U> &a)
    : p_(cradle::get_default_memory_resource())
  {}

  template<typename U>
  polymorphic_allocator(std::allocator<U> const &a)
    : p_(cradle::get_default_memory_resource())
  {}

  template<typename U>
  polymorphic_allocator(std::allocator<U> &&a)
    : p_(cradle::get_default_memory_resource())
  {}

  template<typename U>
  polymorphic_allocator(std::allocator<U> const &&a)
    : p_(cradle::get_default_memory_resource())
  {}

  template<typename Allocator,
           typename = cradle::disable_if_volatile<Allocator> >
  polymorphic_allocator(Allocator const &a)
    : p_(std::make_shared<cradle::memory_resource_adaptor<Allocator> >(a))
  {}

  template<
    typename Allocator,
    typename = cradle::disable_if_volatile<Allocator>,
    typename = cradle::disable_if_reference<Allocator>,
    typename = disable_if_polymorphic_allocator<Allocator>,
    typename = cradle::disable_if_same<
      Allocator, std::shared_ptr<cradle::memory_resource> const> >
  polymorphic_allocator(Allocator &&a)
    : p_(std::make_shared<
           cradle::memory_resource_adaptor<Allocator> >(std::move(a)))
  {}

  polymorphic_allocator(polymorphic_allocator const &) = default;

  polymorphic_allocator(polymorphic_allocator &&) = default;

  template<typename U>
  explicit polymorphic_allocator(polymorphic_allocator<U> const &x) noexcept
    : p_(x.p_)
  {}

  template<typename U>
  explicit polymorphic_allocator(polymorphic_allocator<U> &&x) noexcept
    : p_(std::move(x.p_))
  {}

  polymorphic_allocator &operator=(polymorphic_allocator const &) = delete;

  T *allocate(std::size_t const n)
  {
    if (!p_) {
      typedef std::allocator<T> allocator_type;
      typedef std::allocator_traits<allocator_type> traits_type;
      allocator_type a;
      return traits_type::allocate(a, n);
    }
    void * const p = p_->allocate(n * sizeof(T), alignof(T));
    return static_cast<T *>(p);
  }

  void deallocate(T * const p, std::size_t const n) noexcept
  {
    if (!p_) {
      typedef std::allocator<T> allocator_type;
      typedef std::allocator_traits<allocator_type> traits_type;
      allocator_type a;
      traits_type::deallocate(a, p, n);
      return;
    }
    p_->deallocate(p, n * sizeof(T), alignof(T));
  }

  std::size_t max_size() const noexcept
  {
    if (!p_) {
      typedef std::allocator<T> allocator_type;
      typedef std::allocator_traits<allocator_type> traits_type;
      allocator_type a;
      return traits_type::max_size(a);
    }
    return p_->max_size() / sizeof(T);
  }

private:
  template<typename U, typename... Args>
  void construct_impl1_(std::false_type, U * const p, Args &&... args)
  {
    static_assert(
      std::is_constructible<U, Args &&..., polymorphic_allocator>::value,
      "");
    ::new (static_cast<void *>(p)) U(
      std::forward<Args>(args)..., this->get_inner_allocator());
  }

  template<typename U, typename... Args>
  void construct_impl1_(std::true_type, U * const p, Args &&... args)
  {
    ::new (static_cast<void *>(p)) U(
      std::allocator_arg,
      this->get_inner_allocator(), std::forward<Args>(args)...);
  }

  template<typename U, typename... Args>
  void construct_impl0_(std::false_type, U * const p, Args &&... args)
  {
    static_assert(std::is_constructible<U, Args &&...>::value, "");
    ::new (static_cast<void *>(p)) U(std::forward<Args>(args)...);
  }

  template<typename U, typename... Args>
  void construct_impl0_(std::true_type, U * const p, Args &&... args)
  {
    typedef typename std::is_constructible<
      U, std::allocator_arg_t,
      polymorphic_allocator, Args &&...>::type is_constructible;
    this->construct_impl1_(
      is_constructible(), p, std::forward<Args>(args)...);
  }

public:
  template<typename U, typename... Args>
  void construct(U * const p, Args &&... args)
  {
    static_assert(std::is_object<U>::value, "");
    static_assert(!std::is_const<U>::value, "");
    static_assert(!std::is_volatile<U>::value, "");
    if (!p_) {
      typedef std::allocator<T> allocator_type;
      typedef std::allocator_traits<allocator_type> traits_type;
      allocator_type a;
      traits_type::construct(a, p, std::forward<Args>(args)...);
      return;
    }
    typedef std::uses_allocator<U, polymorphic_allocator> uses_allocator;
    this->construct_impl0_(
      uses_allocator(), p, std::forward<Args>(args)...);
  }

  template<typename U>
  void destroy(U * const p)
  {
    static_assert(std::is_object<U>::value, "");
    static_assert(!std::is_volatile<U>::value, "");
    if (!p_) {
      typedef std::allocator<T> allocator_type;
      typedef std::allocator_traits<allocator_type> traits_type;
      allocator_type a;
      traits_type::destroy(a, p);
      return;
    }
    p->~U();
  }

  polymorphic_allocator
  select_on_container_copy_construction() const noexcept
  {
    return polymorphic_allocator();
  }

  polymorphic_allocator get_inner_allocator()
  {
    if (!p_) {
      return polymorphic_allocator();
    }
    std::shared_ptr<cradle::memory_resource> p
      = p_->share_inner_memory_resource();
    return p ? polymorphic_allocator(std::move(p)) : *this;
  }

  template<typename L, typename R>
  friend bool cradle::operator==(
    polymorphic_allocator<L> const &x,
    polymorphic_allocator<R> const &y) noexcept;

private:
  std::shared_ptr<cradle::memory_resource> p_;
}; // class polymorphic_allocator

template<typename T, typename U>
bool operator==(polymorphic_allocator<T> const &x,
                polymorphic_allocator<U> const &y) noexcept
{
  if (!x.p_) {
    // `x` represents the default allocator (`std::allocator<T>`).
    if (!y.p_) {
      // `y` also represents the default allocator, and the default
      // allocator is stateless.
      return true;
    }
    try {
      // When `y` represents the default allocator but its member variable
      // `p_` is not NULL, it is guaranteed that `y.p_` is created by a call
      // of `cradle::get_default_memory_resource` (see the overloads of the
      // constructor of `cradle::polymorphic_allocator`). And it is
      // guaranteed that only the first call of
      // `cradle::get_default_memory_resource` might throw an exception, and
      // the second and subsequent calls of it never exit via an exception.
      // Thus, if the following call of
      // `cradle::get_default_memory_resource` exists via an exception, then
      // the call is the first one and `y.p_` is not created by
      // `cradle::get_default_memory_resource`. Therefore, it can be
      // concluded that `y` does not represent the default allocator.
      return y.p_ == cradle::get_default_memory_resource();
    }
    catch (std::bad_alloc const &) {
    }
    catch (...) {
      CRADLE_THROW_WITH_NESTED(std::logic_error("an unexpected exception"));
    }
    return false;
  }
  if (!y.p_) {
    try {
      return x.p_ == cradle::get_default_memory_resource();
    }
    catch (std::bad_alloc const &) {
    }
    catch (...) {
      CRADLE_THROW_WITH_NESTED(std::logic_error("an unexpected exception"));
    }
    return false;
  }
  return x.p_->is_equal_to(*y.p_);
}

template<typename T, typename U>
bool operator!=(polymorphic_allocator<T> const &x,
                polymorphic_allocator<U> const &y) noexcept
{
  return !(x == y);
}

} // namespace cradle


#endif // !defined(CRADLE_MEMORY_POLYMORPHIC_ALLOCATOR_HPP_INCLUDE_GUARD)
