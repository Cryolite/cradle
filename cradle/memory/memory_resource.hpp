//  (C) Copyright Cryolite 2013. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CRADLE_MEMORY_MEMORY_RESOURCE_HPP_INCLUDE_GUARD)
#define CRADLE_MEMORY_MEMORY_RESOURCE_HPP_INCLUDE_GUARD

#include <memory>
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

// Once this function does not exit via an exception, the subsequent calls
// should succeed. In other words, if a call of the following function exits
// via an exception, then there should not be any successful call.
std::shared_ptr<cradle::memory_resource> get_default_memory_resource();

} // namespace cradle


#endif // !defined(CRADLE_MEMORY_MEMORY_RESOURCE_HPP_INCLUDE_GUARD)
