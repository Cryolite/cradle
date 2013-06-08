//  (C) Copyright Cryolite 2013. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CRADLE_MEMORY_POLYMORPHIC_ALLOCATOR_HPP_INCLUDE_GUARD)
#define CRADLE_MEMORY_POLYMORPHIC_ALLOCATOR_HPP_INCLUDE_GUARD

#include <cradle/utility/assert_precondition.hpp>
#include <cradle/exception/throw_with_nested.hpp>
#include <cradle/exception/throw_exception.hpp>
#include <cradle/type_traits/enable_if_same.hpp>
#include <cradle/type_traits/enable_if_reference.hpp>
#include <boost/detail/workaround.hpp>
#include <type_traits>
#include <memory>
#include <utility>
#include <stdexcept>
#include <new>
#include <cstddef>


namespace cradle{

class memory_resource
{
public:
  memory_resource();

  memory_resource(memory_resource const &) = delete;

  virtual ~memory_resource();

  memory_resource &operator=(memory_resource const &) = delete;

  void *allocate(std::size_t n, std::size_t alignment);

  void deallocate(void *p, std::size_t n, std::size_t alignment) noexcept;

  std::size_t max_size() const noexcept;

  bool is_equal_to(memory_resource const &x) const noexcept;

  std::shared_ptr<memory_resource> share_inner_memory_resource();

private:
  virtual void *do_allocate(std::size_t n, std::size_t alignment) = 0;

  virtual void do_deallocate(
    void *p, std::size_t n, std::size_t alignment) noexcept = 0;

  virtual std::size_t do_max_size() const noexcept = 0;

  virtual bool do_is_equal_to(memory_resource const &x) const noexcept = 0;

  virtual std::shared_ptr<memory_resource>
  do_share_inner_memory_resource() = 0;
}; // class memory_resource


namespace detail_{

template<typename AlignedAllocator>
class memory_resource_adaptor_impl_ final
  : public memory_resource
{
private:
#if BOOST_WORKAROUND(__GLIBCXX__, < 20140000)
  // A workaround for http://gcc.gnu.org/bugzilla/show_bug.cgi?id=56019
  typedef ::max_align_t max_align_type_;
#else // BOOST_WORKAROUND(__GLIBCXX__, < 20140000)
  typedef std::max_align_t max_align_type_
#endif // BOOST_WORKAROUND(__GLIBCXX__, < 20140000)

private:
  typedef AlignedAllocator aligned_allocator_type_;
  typedef std::allocator_traits<aligned_allocator_type_> traits_type_;
  static_assert(
    std::is_same<
      typename traits_type_::value_type, max_align_type_>::value,
    "");
  static_assert(
    std::is_same<typename traits_type_::pointer, max_align_type_ *>::value,
    "");
  static_assert(
    std::is_same<
      typename traits_type_::const_pointer,
      max_align_type_ const *>::value,
    "");
  static_assert(
    std::is_same<typename traits_type_::void_pointer, void *>::value, "");
  static_assert(
    std::is_same<
      typename traits_type_::const_void_pointer, void const *>::value,
    "");
  static_assert(
    std::is_same<
      typename traits_type_::difference_type, std::ptrdiff_t>::value,
    "");
  static_assert(
    std::is_same<typename traits_type_::size_type, std::size_t>::value,
    "");

public:
  memory_resource_adaptor_impl_()
  noexcept(
    std::is_nothrow_default_constructible<aligned_allocator_type_>::value)
    : a_()
  {}

  template<
    typename Allocator,
    typename = cradle::enable_if_same<
      typename std::allocator_traits<Allocator>
        ::template rebind_alloc<max_align_type_>,
      aligned_allocator_type_> >
  explicit memory_resource_adaptor_impl_(Allocator const &a)
  noexcept(
    std::is_nothrow_copy_constructible<aligned_allocator_type_>::value)
    : a_(a)
  {}

  template<
    typename Allocator,
    typename = cradle::enable_if_same<
      typename std::allocator_traits<Allocator>
        ::template rebind_alloc<max_align_type_>,
      aligned_allocator_type_> >
  explicit memory_resource_adaptor_impl_(Allocator &&a)
  noexcept(
    std::is_nothrow_move_constructible<aligned_allocator_type_>::value)
    : a_(std::move(a))
  {}

  memory_resource_adaptor_impl_(
    memory_resource_adaptor_impl_ const &) = delete;

  ~memory_resource_adaptor_impl_() override
  {}

  memory_resource_adaptor_impl_ &
  operator=(memory_resource_adaptor_impl_ const &) = delete;

private:
  void *do_allocate(
    std::size_t const n, std::size_t const alignment) override
  {
    CRADLE_ASSERT_PRECONDITION(n > 0u);
    CRADLE_ASSERT_PRECONDITION(alignment > 0u);
    max_align_type_ *p
      = traits_type_::allocate(a_, (n - 1) / sizeof(max_align_type_) + 1);
#if BOOST_WORKAROUND(__GLIBCXX__, < 20140000)
    // `std::align' is not implemented.
#else // BOOST_WORKAROUND(__GLIBCXX__, < 20140000)
    {
      max_align_type_ *q = p;
      std::size_t space = n;
      if (std::align(alignment, n, q, space) == nullptr) {
        CRADLE_THROW_EXCEPTION(
          std::bad_alloc("requested alignment could not be satisfied"));
      }
      if (q != p || space != n) {
        CRADLE_THROW_EXCEPTION(
          std::bad_alloc("requested alignment could not be satisfied"));
      }
    }
#endif // BOOST_WORKAROUND(__GLIBCXX__, < 20140000)
    return static_cast<void *>(p);
  }

  void do_deallocate(
    void *p, std::size_t n, std::size_t /*alignment*/) noexcept override
  {
    CRADLE_ASSERT_PRECONDITION(p != nullptr);
    CRADLE_ASSERT_PRECONDITION(n > 0u);
    traits_type_::deallocate(a_, static_cast<max_align_type_ *>(p), n);
  }

  std::size_t do_max_size() const noexcept override
  {
    return traits_type_::max_size(a_) * sizeof(max_align_type_);
  }

  bool do_is_equal_to(memory_resource const &x) const noexcept override
  {
    memory_resource_adaptor_impl_ const *p
      = dynamic_cast<memory_resource_adaptor_impl_ const *>(&x);
    return p != nullptr && a_ == p->a_;
  }

  std::shared_ptr<memory_resource> do_share_inner_memory_resource() override
  {
    return std::shared_ptr<memory_resource>(nullptr);
  }

private:
  aligned_allocator_type_ a_;
}; // class memory_resource_adaptor_impl_

} // namespace detail_


#if BOOST_WORKAROUND(__GLIBCXX__, < 20140000)
// A workaround for http://gcc.gnu.org/bugzilla/show_bug.cgi?id=56019
template<typename Allocator>
using memory_resource_adaptor
  = cradle::detail_::memory_resource_adaptor_impl_<
      std::allocator_traits<Allocator>::rebind_alloc< ::max_align_t> >;
#else // BOOST_WORKAROUND(__GLIBCXX__, < 20140000)
template<typename Allocator>
using memory_resource_adaptor
  = cradle::detail_::memory_resource_adaptor_impl_<
      std::allocator_traits<Allocator>::rebind_alloc<std::max_align_t> >;
#endif // BOOST_WORKAROUND(__GLIBCXX__, < 20140000)


std::shared_ptr<cradle::memory_resource> get_default_memory_resource();


template<typename T>
class polymorphic_allocator;


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
  template<typename Allocator>
  polymorphic_allocator(Allocator const &a)
    : p_(std::make_shared<memory_resource_adaptor<Allocator> >(a))
  {}

  template<
    typename Allocator,
    typename = cradle::disable_if_reference<Allocator>,
    typename = cradle::disable_if_same<Allocator, polymorphic_allocator>,
    typename = cradle::disable_if_same<
      Allocator, polymorphic_allocator const>,
    typename = cradle::disable_if_same<
      Allocator, std::shared_ptr<cradle::memory_resource> >,
    typename = cradle::disable_if_same<
      Allocator, std::shared_ptr<cradle::memory_resource> const> >
  polymorphic_allocator(Allocator &&a)
    : p_(std::make_shared<memory_resource_adaptor<Allocator> >(std::move(a)))
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
      p_ = cradle::get_default_memory_resource();
    }
    void * const p = p_->allocate(n * sizeof(T), alignof(T));
    return static_cast<T *>(p);
  }

  void deallocate(T * const p, std::size_t const n) noexcept
  {
    if (!p_) {
      std::allocator<T> a;
      typedef std::allocator_traits<std::allocator<T> > traits_type;
      traits_type::deallocate(a, p, n);
      return;
    }
    p_->deallocate(p, n * sizeof(T), alignof(T));
  }

  std::size_t max_size() const noexcept
  {
    if (!p_) {
      return std::allocator_traits<
        std::allocator<T> >::max_size(std::allocator<T>());
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
      std::allocator<U> a;
      typedef std::allocator_traits<std::allocator<U> > traits_type;
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
    p->~U();
  }

  polymorphic_allocator select_on_container_copy_construction() const
  {
    return polymorphic_allocator();
  }

  polymorphic_allocator get_inner_allocator()
  {
    if (!p_) {
      return polymorphic_allocator();
    }
    auto p = p_->share_inner_memory_resource();
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
    if (!y.p_) {
      return true;
    }
    try {
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
