//  (C) Copyright Cryolite 2013. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CRADLE_EXCEPTION_THROW_EXCEPTION_HPP_INCLUDE_GUARD)
#define CRADLE_EXCEPTION_THROW_EXCEPTION_HPP_INCLUDE_GUARD

#include <cradle/exception/backtrace_info.hpp>

#include <boost/exception/enable_error_info.hpp>
#include <boost/exception/info.hpp>
#include <boost/exception/exception.hpp>
#include <boost/current_function.hpp>


#define CRADLE_THROW_EXCEPTION(EXPRESSION)           \
throw ::boost::enable_error_info(EXPRESSION)         \
  << ::boost::throw_function(BOOST_CURRENT_FUNCTION) \
  << ::boost::throw_file(__FILE__)                   \
  << ::boost::throw_line((int)__LINE__)              \
  << ::cradle::throw_backtrace()                     \
/**/


#endif // !defined(CRADLE_EXCEPTION_THROW_EXCEPTION_HPP_INCLUDE_GUARD)
