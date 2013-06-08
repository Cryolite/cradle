//  (C) Copyright Cryolite 2013. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CRADLE_EXCEPTION_BACKTRACE_INFO_HPP_INCLUDE_GUARD)
#define CRADLE_EXCEPTION_BACKTRACE_INFO_HPP_INCLUDE_GUARD

#include <boost/exception/info.hpp>

#include <string>
#include <memory>


namespace cradle{

class backtrace
{
public:
  backtrace();

  backtrace(backtrace const &) = default;

  backtrace &operator=(backtrace const &) = default;

  typedef std::string const *iterator;
  typedef iterator const_iterator;

  const_iterator begin() const noexcept;

  const_iterator end() const noexcept;

private:
  class impl_;
  std::shared_ptr<impl_> p_;
}; // class backtrace

struct backtrace_info_;

typedef boost::error_info<backtrace_info_, cradle::backtrace> backtrace_info;

backtrace_info throw_backtrace();

} // namespace cradle


#endif // !defined(CRADLE_EXCEPTION_BACKTRACE_INFO_HPP_INCLUDE_GUARD)
