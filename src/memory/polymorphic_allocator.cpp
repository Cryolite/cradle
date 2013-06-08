//  (C) Copyright Cryolite 2013. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cradle/memory/polymorphic_allocator.hpp>

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


std::shared_ptr<cradle::memory_resource> get_default_memory_resource()
{
#if BOOST_WORKAROUND(__GLIBCXX__, < 20140000)
  typedef cradle::memory_resource_adaptor<std::allocator< ::max_align_t> >
    default_memory_resource_adaptor;
#else // BOOST_WORKAROUND(__GLIBCXX__, < 20140000)
  typedef cradle::memory_resource_adaptor<std::allocator<std::max_align_t> >
    default_memory_resource_adaptor;
#endif // BOOST_WORKAROUND(__GLIBCXX__, < 20140000)
  static std::shared_ptr<cradle::memory_resource> p
    = std::make_shared<default_memory_resource_adaptor>();
  return p;
}

} // namespace cradle
