//  (C) Copyright Cryolite 2013. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/detail/workaround.hpp>

#if !defined(CRADLE_CONFIG_CONFIG_HPP_INCLUDE_GUARD)
#define CRADLE_CONFIG_CONFIG_HPP_INCLUDE_GUARD

#if defined(__GNUC__) && !defined(__clang__)
#  define CRADLE_GCC_FULL_VERSION ((__GNUC__ * 1000 + __GNUC_MINOR__) * 1000 + __GNUC_PATCHLEVEL__)
#endif

#if BOOST_WORKAROUND(CRADLE_GCC_FULL_VERSION, < 4010000)
#  define CRADLE_NO_NOEXCEPT_ON_FUNCTION_POINTERS
#endif

#endif // !defined(CRADLE_CONFIG_CONFIG_HPP_INCLUDE_GUARD)
