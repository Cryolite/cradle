//  (C) Copyright Cryolite 2012, 2013. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cradle/exception/uncaught_exception.hpp>
#include <cxxabi.h>
#include <cstddef>


#if defined(CRADLE_HAS_LIBSTDCXX_UNCAUGHT_EXCEPTIONS)

namespace __cxxabiv1{

struct __cxa_exception;

struct __cxa_eh_globals
{
  __cxa_exception *caughtExceptions;
  unsigned int uncaughtExceptions;
};

}

namespace cradle{ namespace exceptions{

std::size_t get_num_uncaught_exceptions() noexcept
{
  return __cxxabiv1::__cxa_get_globals()->uncaughtExceptions;
}

}}

#else // defined(CRADLE_HAS_LIBSTDCXX_UNCAUGHT_EXCEPTIONS)

#  error "sorry, unimplemented"

#endif
