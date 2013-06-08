//  (C) Copyright Cryolite 2013. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CRADLE_UTILITY_ASSERT_PRECONDITION_HPP_INCLUDE_GUARD)
#define CRADLE_UTILITY_ASSERT_PRECONDITION_HPP_INCLUDE_GUARD

#include <cradle/exception/throw_exception.hpp>
#include <boost/preprocessor/stringize.hpp>
#include <stdexcept>


#if defined(CRADLE_CHECKING)

#define CRADLE_ASSERT_PRECONDITION(EXPRESSION)                     \
(EXPRESSION)                                                       \
  ? static_cast<void>(0)                                           \
  : CRADLE_THROW_EXCEPTION(                                        \
      std::logic_error(                                            \
        "precondition violated: " BOOST_PP_STRINGIZE(EXPRESSION))) \
/**/

#else // defined(CRADLE_CHECKING)

#define CRADLE_ASSERT_PRECONDITION(EXPRESSION) \
static_cast<void>(EXPRESSION)                  \
/**/

#endif // defined(CRADLE_CHECKING)


#endif // !defined(CRADLE_UTILITY_ASSERT_PRECONDITION_HPP_INCLUDE_GUARD)
