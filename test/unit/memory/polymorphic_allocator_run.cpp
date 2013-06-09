//  (C) Copyright Cryolite 2013. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cradle/memory/polymorphic_allocator.hpp>

#include <boost/test/unit_test.hpp>
#include <boost/numeric/conversion/cast.hpp>
#include <type_traits>
#include <memory>
#include <utility>
#include <cstddef>


BOOST_AUTO_TEST_SUITE(memory)

BOOST_AUTO_TEST_SUITE(polymorphic_allocator)

#define ASSERT_SAME(T, U) static_assert(std::is_same< T , U >::value, "")

namespace{

constexpr std::size_t test_size = 1024u;

} // namespace `unnamed'

BOOST_AUTO_TEST_CASE(default_value)
{
  typedef cradle::polymorphic_allocator<int> A;
  ASSERT_SAME(A::value_type, int);
  ASSERT_SAME(A::pointer, int *);
  ASSERT_SAME(A::const_pointer, int const *);
  ASSERT_SAME(A::void_pointer, void *);
  ASSERT_SAME(A::const_void_pointer, void const *);
  ASSERT_SAME(A::difference_type, std::ptrdiff_t);
  ASSERT_SAME(A::size_type, std::size_t);
  static_assert(!A::propagate_on_container_copy_assignment::value, "");
  static_assert(A::propagate_on_container_move_assignment::value, "");
  static_assert(A::propagate_on_container_swap::value, "");
  ASSERT_SAME(A::rebind<double>::other, cradle::polymorphic_allocator<double>);

  static_assert(std::is_nothrow_default_constructible<A>::value, "");
  static_assert(std::is_nothrow_copy_constructible<A>::value, "");
  static_assert(std::is_nothrow_move_constructible<A>::value, "");
  static_assert(!std::is_copy_assignable<A>::value, "");
  static_assert(!std::is_move_assignable<A>::value, "");

  A a;
  {
    bool result = true;
    for (std::size_t i = 1u; i <= test_size; ++i) {
      int *p = a.allocate(i);
      for (std::size_t j = 0u; j < i; ++j) {
        a.construct(p + j, j * 3 + 1);
      }
      for (std::size_t j = 0u; j < i; ++j) {
        result = result && (p[j] == boost::numeric_cast<int>(j * 3 + 1));
      }
      for (std::size_t j = 0u; j < i; ++j) {
        a.destroy(p + j);
      }
      a.deallocate(p, i);
    }
    BOOST_CHECK(result);
  }
  BOOST_CHECK_GE(a.max_size(), test_size);
  BOOST_CHECK(a.select_on_container_copy_construction() == a);
  BOOST_CHECK(a == a);
  BOOST_CHECK(!(a != a));
}

BOOST_AUTO_TEST_CASE(default_copy_interoperability)
{
  cradle::polymorphic_allocator<int> a0;
  cradle::polymorphic_allocator<int> a1 = a0;
  {
    bool result = true;
    for (std::size_t i = 1u; i <= test_size; ++i) {
      int *p = a0.allocate(i);
      for (std::size_t j = 0u; j < i; ++j) {
        a0.construct(p + j, j * 3 + 1);
      }
      for (std::size_t j = 0u; j < i; ++j) {
        result = result && (p[j] == boost::numeric_cast<int>(j * 3 + 1));
      }
      for (std::size_t j = 0u; j < i; ++j) {
        a1.destroy(p + j);
      }
      a1.deallocate(p, i);
    }
    for (std::size_t i = 1u; i <= test_size; ++i) {
      int *p = a1.allocate(i);
      for (std::size_t j = 0u; j < i; ++j) {
        a1.construct(p + j, j * 3 + 1);
      }
      for (std::size_t j = 0u; j < i; ++j) {
        result = result && (p[j] == boost::numeric_cast<int>(j * 3 + 1));
      }
      for (std::size_t j = 0u; j < i; ++j) {
        a0.destroy(p + j);
      }
      a0.deallocate(p, i);
    }
    BOOST_CHECK(result);
  }
  BOOST_CHECK(a1 == a0);
  BOOST_CHECK(a0 == a1);
  BOOST_CHECK(!(a1 != a0));
  BOOST_CHECK(!(a0 != a1));
}

BOOST_AUTO_TEST_CASE(default_move_interoperability)
{
  cradle::polymorphic_allocator<int> a0;
  cradle::polymorphic_allocator<int> a1 = std::move(a0);
  {
    bool result = true;
    for (std::size_t i = 1u; i <= test_size; ++i) {
      int *p = a0.allocate(i);
      for (std::size_t j = 0u; j < i; ++j) {
        a0.construct(p + j, j * 3 + 1);
      }
      for (std::size_t j = 0u; j < i; ++j) {
        result = result && (p[j] == boost::numeric_cast<int>(j * 3 + 1));
      }
      for (std::size_t j = 0u; j < i; ++j) {
        a1.destroy(p + j);
      }
      a1.deallocate(p, i);
    }
    for (std::size_t i = 1u; i <= test_size; ++i) {
      int *p = a1.allocate(i);
      for (std::size_t j = 0u; j < i; ++j) {
        a1.construct(p + j, j * 3 + 1);
      }
      for (std::size_t j = 0u; j < i; ++j) {
        result = result && (p[j] == boost::numeric_cast<int>(j * 3 + 1));
      }
      for (std::size_t j = 0u; j < i; ++j) {
        a0.destroy(p + j);
      }
      a0.deallocate(p, i);
    }
    BOOST_CHECK(result);
  }
  BOOST_CHECK(a1 == a0);
  BOOST_CHECK(a0 == a1);
  BOOST_CHECK(!(a1 != a0));
  BOOST_CHECK(!(a0 != a1));
}

BOOST_AUTO_TEST_CASE(default_copy_conversion_interoperability)
{
  cradle::polymorphic_allocator<int> a;
  cradle::polymorphic_allocator<double> b(a);
  {
    bool result = true;
    for (std::size_t i = 1u; i <= test_size; ++i) {
      int *p = a.allocate(i);
      for (std::size_t j = 0u; j < i; ++j) {
        a.construct(p + j, j * 3 + 1);
      }
      for (std::size_t j = 0u; j < i; ++j) {
        result = result && (p[j] == boost::numeric_cast<int>(j * 3 + 1));
      }
      for (std::size_t j = 0u; j < i; ++j) {
        a.destroy(p + j);
      }
      a.deallocate(p, i);
    }
    for (std::size_t i = 1u; i <= test_size; ++i) {
      double *p = b.allocate(i);
      for (std::size_t j = 0u; j < i; ++j) {
        b.construct(p + j, j * 3 + 1);
      }
      for (std::size_t j = 0u; j < i; ++j) {
        result = result && (p[j] == j * 3 + 1);
      }
      for (std::size_t j = 0u; j < i; ++j) {
        b.destroy(p + j);
      }
      b.deallocate(p, i);
    }
    BOOST_CHECK(result);
  }
  BOOST_CHECK(a == b);
  BOOST_CHECK(b == a);
  BOOST_CHECK(!(a != b));
  BOOST_CHECK(!(b != a));
}

BOOST_AUTO_TEST_CASE(default_move_conversion_interoperability)
{
  cradle::polymorphic_allocator<int> a;
  cradle::polymorphic_allocator<double> b(std::move(a));
  {
    bool result = true;
    for (std::size_t i = 1u; i <= test_size; ++i) {
      int *p = a.allocate(i);
      for (std::size_t j = 0u; j < i; ++j) {
        a.construct(p + j, j * 3 + 1);
      }
      for (std::size_t j = 0u; j < i; ++j) {
        result = result && (p[j] == boost::numeric_cast<int>(j * 3 + 1));
      }
      for (std::size_t j = 0u; j < i; ++j) {
        a.destroy(p + j);
      }
      a.deallocate(p, i);
    }
    for (std::size_t i = 1u; i <= test_size; ++i) {
      double *p = b.allocate(i);
      for (std::size_t j = 0u; j < i; ++j) {
        b.construct(p + j, j * 3 + 1);
      }
      for (std::size_t j = 0u; j < i; ++j) {
        result = result && (p[j] == j * 3 + 1);
      }
      for (std::size_t j = 0u; j < i; ++j) {
        b.destroy(p + j);
      }
      b.deallocate(p, i);
    }
    BOOST_CHECK(result);
  }
  BOOST_CHECK(a == b);
  BOOST_CHECK(b == a);
  BOOST_CHECK(!(a != b));
  BOOST_CHECK(!(b != a));
}

BOOST_AUTO_TEST_CASE(default_statelessness)
{
  cradle::polymorphic_allocator<int> a0;
  cradle::polymorphic_allocator<int> a1;
  {
    bool result = true;
    for (std::size_t i = 1u; i <= test_size; ++i) {
      int *p = a0.allocate(i);
      for (std::size_t j = 0u; j < i; ++j) {
        a0.construct(p + j, j * 3 + 1);
      }
      for (std::size_t j = 0u; j < i; ++j) {
        result = result && (p[j] == boost::numeric_cast<int>(j * 3 + 1));
      }
      for (std::size_t j = 0u; j < i; ++j) {
        a1.destroy(p + j);
      }
      a1.deallocate(p, i);
    }
    for (std::size_t i = 1u; i <= test_size; ++i) {
      int *p = a1.allocate(i);
      for (std::size_t j = 0u; j < i; ++j) {
        a1.construct(p + j, j * 3 + 1);
      }
      for (std::size_t j = 0u; j < i; ++j) {
        result = result && (p[j] == boost::numeric_cast<int>(j * 3 + 1));
      }
      for (std::size_t j = 0u; j < i; ++j) {
        a0.destroy(p + j);
      }
      a0.deallocate(p, i);
    }
    BOOST_CHECK(result);
  }
  BOOST_CHECK(a1 == a0);
  BOOST_CHECK(a0 == a1);
  BOOST_CHECK(!(a1 != a0));
  BOOST_CHECK(!(a0 != a1));
}

BOOST_AUTO_TEST_CASE(allocator_traits)
{
  typedef cradle::polymorphic_allocator<int> A;
  typedef std::allocator_traits<A> T;
  ASSERT_SAME(T::value_type, int);
  ASSERT_SAME(T::pointer, int *);
  ASSERT_SAME(T::const_pointer, int const *);
  ASSERT_SAME(T::void_pointer, void *);
  ASSERT_SAME(T::const_void_pointer, void const *);
  ASSERT_SAME(T::difference_type, std::ptrdiff_t);
  ASSERT_SAME(T::size_type, std::size_t);
  static_assert(!T::propagate_on_container_copy_assignment::value, "");
  static_assert(T::propagate_on_container_move_assignment::value, "");
  static_assert(T::propagate_on_container_swap::value, "");
  ASSERT_SAME(T::rebind_alloc<double>,
              cradle::polymorphic_allocator<double>);
  ASSERT_SAME(T::rebind_traits<double>,
              std::allocator_traits<cradle::polymorphic_allocator<double> >);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
