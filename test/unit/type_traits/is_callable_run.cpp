//  (C) Copyright Cryolite 2013. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cradle/type_traits/is_callable.hpp>

#include <cradle/config/config.hpp>

#include <boost/test/unit_test.hpp>
#include <boost/detail/workaround.hpp>
#include <memory>


namespace{

struct S
{};

} // namespace `unnamed'

BOOST_AUTO_TEST_SUITE(type_traits)

BOOST_AUTO_TEST_SUITE(is_callable)

BOOST_AUTO_TEST_CASE(main)
{
  static_assert(!cradle::is_callable<void (S::*)()>::value, "");
  static_assert(cradle::is_callable<void (S::*)(), S &>::value, "");
#if !BOOST_WORKAROUND(CRADLE_GCC_FULL_VERSION, < 4008000)
  static_assert(!cradle::is_callable<void (S::*)(), S const &>::value, "");
#endif // !BOOST_WORKAROUND(CRADLE_GCC_FULL_VERSION, < 4008000)
  static_assert(cradle::is_callable<void (S::*)(), S &&>::value, "");
#if !BOOST_WORKAROUND(CRADLE_GCC_FULL_VERSION, < 4008000)
  static_assert(cradle::is_callable<void (S::*)(), S *>::value, "");
  static_assert(!cradle::is_callable<void (S::*)(), S const *>::value, "");
  static_assert(
    cradle::is_callable<void (S::*)(), std::unique_ptr<S> >::value, "");
  static_assert(
    !cradle::is_callable<void (S::*)(), std::unique_ptr<S const> >::value,
    "");
  static_assert(!cradle::is_callable<void (S::*)(), S &, int>::value, "");
#endif // !BOOST_WORKAROUND(CRADLE_GCC_FULL_VERSION, < 4008000)
  static_assert(!cradle::is_callable<void (S::*)() const>::value, "");
  static_assert(cradle::is_callable<void (S::*)() const, S &>::value, "");
  static_assert(
    cradle::is_callable<void (S::*)() const, S const &>::value, "");
  static_assert(cradle::is_callable<void (S::*)() const, S &&>::value, "");
#if !BOOST_WORKAROUND(CRADLE_GCC_FULL_VERSION, < 4008000)
  static_assert(cradle::is_callable<void (S::*)() const, S *>::value, "");
  static_assert(
    cradle::is_callable<void (S::*)() const, S const *>::value, "");
  static_assert(
    cradle::is_callable<void (S::*)() const, std::unique_ptr<S> >::value,
    "");
  static_assert(
    cradle::is_callable<
      void (S::*)() const, std::unique_ptr<S const> >::value,
    "");
  static_assert(
    !cradle::is_callable<void (S::*)() const, S &, int>::value, "");
#endif // !BOOST_WORKAROUND(CRADLE_GCC_FULL_VERSION, < 4008000)

  static_assert(cradle::is_callable<int (S::*)(), S &>::value, "");
  static_assert(cradle::is_callable<int &(S::*)(), S &>::value, "");
  static_assert(cradle::is_callable<int const &(S::*)(), S &>::value, "");
  static_assert(cradle::is_callable<int &&(S::*)(), S &>::value, "");
}

namespace{

struct NonCopyConstructible
{
  NonCopyConstructible(NonCopyConstructible const &) = delete;
};

} // namespace `unnamed'

BOOST_AUTO_TEST_CASE(non_copy_constructive)
{
  static_assert(
    !cradle::is_callable<NonCopyConstructible (S::*)(), S &>::value, "");
  static_assert(
    cradle::is_callable<NonCopyConstructible &(S::*)(), S &>::value, "");
  static_assert(
    cradle::is_callable<NonCopyConstructible const &(S::*)(), S &>::value,
    "");
  static_assert(
    cradle::is_callable<NonCopyConstructible &&(S::*)(), S &>::value, "");

  static_assert(
    cradle::is_callable<std::unique_ptr<int> (S::*)(), S &>::value, "");
  static_assert(
    cradle::is_callable<std::unique_ptr<int> &(S::*)(), S &>::value, "");
  static_assert(
    cradle::is_callable<std::unique_ptr<int> const &(S::*)(), S &>::value,
    "");
  static_assert(
    cradle::is_callable<std::unique_ptr<int> &&(S::*)(), S &>::value, "");

  static_assert(
    cradle::is_callable<void (S::*)(int), S &, int &>::value, "");
  static_assert(
    cradle::is_callable<void (S::*)(int), S &, int const &>::value, "");
  static_assert(
    cradle::is_callable<void (S::*)(int), S &, int &&>::value, "");

  static_assert(
    cradle::is_callable<void (S::*)(int &), S &, int &>::value, "");
#if !BOOST_WORKAROUND(CRADLE_GCC_FULL_VERSION, < 4008000)
  static_assert(
    !cradle::is_callable<void (S::*)(int &), S &, int const &>::value, "");
  static_assert(
    !cradle::is_callable<void (S::*)(int &), S &, int &&>::value, "");
#endif // !BOOST_WORKAROUND(CRADLE_GCC_FULL_VERSION, < 4008000)

  static_assert(
    cradle::is_callable<void (S::*)(int const &), S &, int &>::value, "");
  static_assert(
    cradle::is_callable<void (S::*)(int const &), S &, int const &>::value,
    "");
  static_assert(
    cradle::is_callable<void (S::*)(int const &), S &, int &&>::value, "");

#if !BOOST_WORKAROUND(CRADLE_GCC_FULL_VERSION, < 4008000)
  static_assert(
    !cradle::is_callable<void (S::*)(int &&), S &, int &>::value, "");
  static_assert(
    !cradle::is_callable<void (S::*)(int &&), S &, int const &>::value, "");
#endif // !BOOST_WORKAROUND(CRADLE_GCC_FULL_VERSION, < 4008000)
  static_assert(
    cradle::is_callable<void (S::*)(int &&), S &, int &&>::value, "");

#if !BOOST_WORKAROUND(CRADLE_GCC_FULL_VERSION, < 4008000)
  static_assert(
    !cradle::is_callable<
      void (S::*)(std::unique_ptr<int>), S &, std::unique_ptr<int> &>::value,
    "");
  static_assert(
    !cradle::is_callable<
      void (S::*)(std::unique_ptr<int>), S &,
      std::unique_ptr<int> const &>::value,
    "");
#endif // !BOOST_WORKAROUND(CRADLE_GCC_FULL_VERSION, < 4008000)
  static_assert(
    cradle::is_callable<
      void (S::*)(std::unique_ptr<int>),
      S &, std::unique_ptr<int> &&>::value,
    "");

  static_assert(
    cradle::is_callable<
      void (S::*)(std::unique_ptr<int> &),
      S &, std::unique_ptr<int> &>::value,
    "");
#if !BOOST_WORKAROUND(CRADLE_GCC_FULL_VERSION, < 4008000)
  static_assert(
    !cradle::is_callable<
      void (S::*)(std::unique_ptr<int> &),
      S &, std::unique_ptr<int> const &>::value,
    "");
  static_assert(
    !cradle::is_callable<
      void (S::*)(std::unique_ptr<int> &),
      S &, std::unique_ptr<int> &&>::value,
    "");
#endif // !BOOST_WORKAROUND(CRADLE_GCC_FULL_VERSION, < 4008000)

  static_assert(
    cradle::is_callable<
      void (S::*)(std::unique_ptr<int> const &),
      S &, std::unique_ptr<int> &>::value,
    "");
  static_assert(
    cradle::is_callable<
      void (S::*)(std::unique_ptr<int> const &),
      S &, std::unique_ptr<int> const &>::value,
    "");
  static_assert(
    cradle::is_callable<
      void (S::*)(std::unique_ptr<int> const &),
      S &, std::unique_ptr<int> &&>::value,
    "");

#if !BOOST_WORKAROUND(CRADLE_GCC_FULL_VERSION, < 4008000)
  static_assert(
    !cradle::is_callable<
      void (S::*)(std::unique_ptr<int> &&),
      S &, std::unique_ptr<int> &>::value,
    "");
  static_assert(
    !cradle::is_callable<
      void (S::*)(std::unique_ptr<int> &&),
      S &, std::unique_ptr<int> const &>::value,
    "");
#endif // !BOOST_WORKAROUND(CRADLE_GCC_FULL_VERSION, < 4008000)
  static_assert(
    cradle::is_callable<
      void (S::*)(std::unique_ptr<int> &&),
      S &, std::unique_ptr<int> &&>::value,
    "");


  static_assert(cradle::is_callable<int S::*, S &>::value, "");
  static_assert(cradle::is_callable<int S::*, S const &>::value, "");
  static_assert(cradle::is_callable<int S::*, S &&>::value, "");
#if !BOOST_WORKAROUND(CRADLE_GCC_FULL_VERSION, < 4008000)
  static_assert(cradle::is_callable<int S::*, S *>::value, "");
  static_assert(cradle::is_callable<int S::*, S const *>::value, "");
  static_assert(
    cradle::is_callable<int S::*, std::unique_ptr<S> >::value, "");
  static_assert(
    cradle::is_callable<int S::*, std::unique_ptr<S const> >::value, "");
#endif // !BOOST_WORKAROUND(CRADLE_GCC_FULL_VERSION, < 4008000)

  static_assert(
    cradle::is_callable<std::unique_ptr<int> S::*, S &>::value, "");
  static_assert(
    cradle::is_callable<std::unique_ptr<int> S::*, S const &>::value, "");

  static_assert(
    cradle::is_callable<NonCopyConstructible S::*, S &>::value, "");
  static_assert(
    cradle::is_callable<NonCopyConstructible S::*, S const &>::value, "");


  static_assert(cradle::is_callable<void (*)()>::value, "");
  static_assert(cradle::is_callable<void (&)()>::value, "");
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
