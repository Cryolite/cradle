//  (C) Copyright Cryolite 2012, 2013. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CRADLE_EXCEPTION_UNCAUGHT_EXCEPTION_HPP_INCLUDE_GUARD)
#define CRADLE_EXCEPTION_UNCAUGHT_EXCEPTION_HPP_INCLUDE_GUARD

#include <cstddef>


namespace cradle{ namespace exceptions{

std::size_t get_num_uncaught_exceptions() noexcept;

}}


#endif // !defined(CRADLE_EXCEPTION_UNCAUGHT_EXCEPTION_HPP_INCLUDE_GUARD)
