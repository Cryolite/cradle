//  (C) Copyright Cryolite 2013. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cradle/memory/memory_resource_adaptor.hpp>
#include <cradle/memory/memory_resource.hpp>

#include <cradle/utility/assert_precondition.hpp>
#include <boost/detail/workaround.hpp>
#include <memory>
#include <cstddef>


namespace cradle{

memory_resource::memory_resource() = default;

memory_resource::~memory_resource() = default;

void *memory_resource::allocate(std::size_t n, std::size_t alignment)
{
  if (n == 0u) {
    return nullptr;
  }
  CRADLE_ASSERT_PRECONDITION(alignment > 0u);
  return this->do_allocate(n, alignment);
}

void memory_resource::deallocate(
  void *p, std::size_t n, std::size_t alignment) noexcept
{
  CRADLE_ASSERT_PRECONDITION(p != nullptr);
  CRADLE_ASSERT_PRECONDITION(n > 0u);
  CRADLE_ASSERT_PRECONDITION(alignment > 0u);
  return this->do_deallocate(p, n, alignment);
}

std::size_t memory_resource::max_size() const noexcept
{
  return this->do_max_size();
}

bool memory_resource::is_equal_to(memory_resource const &x) const noexcept
{
  return this == &x || this->do_is_equal_to(x);
}

std::shared_ptr<memory_resource>
memory_resource::share_inner_memory_resource()
{
  return this->do_share_inner_memory_resource();
}


// Once this function does not exit via an exception, the subsequent calls
// should succeed. In other words, if a call of the following function exits
// via an exception, then there should not be any successful call.
std::shared_ptr<memory_resource> get_default_memory_resource()
{
#if BOOST_WORKAROUND(__GLIBCXX__, < 20140000)
  typedef ::max_align_t max_align_type;
#else // BOOST_WORKAROUND(__GLIBCXX__, < 20140000)
  typedef std::max_align_t max_align_type;
#endif // BOOST_WORKAROUND(__GLIBCXX__, < 20140000)
  typedef std::allocator<max_align_type> allocator_type;
  typedef memory_resource_adaptor<allocator_type> adaptor_type;
  static std::shared_ptr<memory_resource> p
    = std::make_shared<adaptor_type>(allocator_type());
  return p;
}

} // namespace cradle
