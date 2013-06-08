//  (C) Copyright Cryolite 2013. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cradle/exception/backtrace_info.hpp>

#include <vector>
#include <string>
#include <memory>
#include <new>
#include <cstdlib>
#include <cstddef>

#include <execinfo.h>


namespace cradle{

class backtrace::impl_
{
public:
  impl_()
    : symbols_()
  {
    constexpr std::size_t initial_size = 256u;
    std::vector<void *> buf(initial_size, nullptr);
    {
      std::size_t n = 0u;
      for ( ; ; buf.resize(buf.size() * 2u, nullptr)) {
        n = ::backtrace(buf.data(), buf.size());
        if (n < buf.size()) {
          break;
        }
      }
      buf.resize(n, nullptr);
    }
    char * * const p = backtrace_symbols(buf.data(), buf.size());
    if (p == NULL) {
      BOOST_THROW_EXCEPTION(std::bad_alloc());
    }
    try {
      symbols_.reserve(buf.size());
      for (std::size_t i = 0; i < buf.size(); ++i) {
        symbols_.push_back(p[i]);
      }
    }
    catch (...) {
      std::free(p);
      throw;
    }
    std::free(p);
  }

  impl_(impl_ const &) = delete;

  impl_ &operator=(impl_ const &) = delete;

  std::string const *begin() const noexcept
  {
    return symbols_.data();
  }

  std::string const *end() const noexcept
  {
    return symbols_.data() + symbols_.size();
  }

private:
  std::vector<std::string> symbols_;
}; // class backtrace::impl_;

backtrace::backtrace()
  : p_(std::make_shared<impl_>())
{}

std::string const *backtrace::begin() const noexcept
{
  return p_->begin();
}

std::string const *backtrace::end() const noexcept
{
  return p_->end();
}

backtrace_info throw_backtrace()
{
  return backtrace_info(backtrace());
}

} // namespace cradle
