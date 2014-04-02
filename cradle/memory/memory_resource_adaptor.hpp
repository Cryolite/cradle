//  (C) Copyright Cryolite 2013. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CRADLE_MEMORY_MEMORY_RESOURCE_ADAPTOR_HPP_INCLUDE_GUARD)
#define CRADLE_MEMORY_MEMORY_RESOURCE_ADAPTOR_HPP_INCLUDE_GUARD

#include <cradle/memory/memory_resource.hpp>
#include <cradle/utility/assert_precondition.hpp>
#include <cradle/exception/throw_exception.hpp>
#include <cradle/type_traits/enable_if_volatile.hpp>
#include <cradle/config/config.hpp>
#include <boost/detail/workaround.hpp>
#include <type_traits>
#include <memory>
#include <utility>
#include <new>
#include <cstddef>


namespace cradle{

namespace detail_{

template<typename AlignedAllocator>
class memory_resource_adaptor_impl_ final
  : public cradle::memory_resource
{
private:
#if BOOST_WORKAROUND(CRADLE_GCC_FULL_VERSION, < 4009000)
  // A workaround for http://gcc.gnu.org/bugzilla/show_bug.cgi?id=56019
  typedef ::max_align_t max_align_type_;
#else // BOOST_WORKAROUND(CRADLE_GCC_FULL_VERSION, < 4009000)
  typedef std::max_align_t max_align_type_;
#endif // BOOST_WORKAROUND(CRADLE_GCC_FULL_VERSION, < 4009000)

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
  template<typename Allocator,
           typename = cradle::disable_if_volatile<Allocator> >
  explicit memory_resource_adaptor_impl_(Allocator &&a)
  noexcept(
    std::is_nothrow_constructible<
      aligned_allocator_type_, Allocator &&>::value)
    : cradle::memory_resource(),
      a_(std::forward<Allocator>(a))
  {}

  memory_resource_adaptor_impl_(memory_resource_adaptor_impl_ &) = delete;

  memory_resource_adaptor_impl_(
    memory_resource_adaptor_impl_ const &) = delete;

  memory_resource_adaptor_impl_(memory_resource_adaptor_impl_ &&) = delete;

  memory_resource_adaptor_impl_(
    memory_resource_adaptor_impl_ const &&) = delete;

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
#if BOOST_WORKAROUND(CRADLE_GCC_FULL_VERSION, < 4010000)
    // `std::align' is not implemented.
#else // BOOST_WORKAROUND(CRADLE_GCC_FULL_VERSION, < 4010000)
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
#endif // BOOST_WORKAROUND(CRADLE_GCC_FULL_VERSION, < 4009000)
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

  bool do_is_equal_to(
    cradle::memory_resource const &x) const noexcept override
  {
    memory_resource_adaptor_impl_ const *p
      = dynamic_cast<memory_resource_adaptor_impl_ const *>(&x);
    return p != nullptr && a_ == p->a_;
  }

  std::shared_ptr<cradle::memory_resource>
  do_share_inner_memory_resource() override
  {
    return std::shared_ptr<cradle::memory_resource>(nullptr);
  }

private:
  aligned_allocator_type_ a_;
}; // class memory_resource_adaptor_impl_

} // namespace detail_

#if BOOST_WORKAROUND(CRADLE_GCC_FULL_VERSION, < 4009000)
// A workaround for http://gcc.gnu.org/bugzilla/show_bug.cgi?id=56019
template<typename Allocator>
using memory_resource_adaptor
  = cradle::detail_::memory_resource_adaptor_impl_<
      typename std::allocator_traits<Allocator>::template rebind_alloc< ::max_align_t> >;
#else // BOOST_WORKAROUND(CRADLE_GCC_FULL_VERSION, < 4009000)
template<typename Allocator>
using memory_resource_adaptor
  = cradle::detail_::memory_resource_adaptor_impl_<
      typename std::allocator_traits<Allocator>::template rebind_alloc<std::max_align_t> >;
#endif // BOOST_WORKAROUND(CRADLE_GCC_FULL_VERSION, < 4009000)

} // namespace cradle


#endif // !defined(CRADLE_MEMORY_MEMORY_RESOURCE_ADAPTOR_HPP_INCLUDE_GUARD)
