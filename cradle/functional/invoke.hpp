//  (C) Copyright Cryolite 2013. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CRADLE_FUNCTIONAL_INVOKE_HPP_INCLUDE_GUARD)
#define CRADLE_FUNCTIONAL_INVOKE_HPP_INCLUDE_GUARD

#include <cradle/type_traits/identity.hpp>
#include <cradle/utility/simple_auto_forward_return.hpp>
#include <utility>
#include <type_traits>

namespace cradle{

namespace detail_{

struct invoke_inference_;

/////////////////////////////////////////////////////////////////////////////
// Precondition: `f(args...)` is a valid expression, and the return type is
// explicitly specified but other than possibly cv-qualified void.
//
// Any specializations of the following function template shall not
// participate in overload resolution unless the type of the delegated
// expression is convertible to the specified return type.

template<typename R, typename F, typename... Args>
constexpr bool test_invoke_5f_() noexcept
{
  typedef decltype(std::declval<F>()(std::declval<Args>()...)) x;
  return std::is_convertible<x, R>::value
    && (std::is_reference<x>::value || !std::is_reference<R>::value);
}

template<typename R, typename F, typename... Args>
using enable_if_test_invoke_5f_
  = typename std::enable_if<test_invoke_5f_<R, F, Args...>()>::type;

template<typename R, typename F, typename... Args,
         typename = enable_if_test_invoke_5f_<R, F, Args...> >
R invoke_5f_(int, cradle::identity<R>, F &&f, Args &&... args)
  noexcept(
    noexcept(
      std::forward<F>(f)(std::forward<Args>(args)...))
    && std::is_nothrow_constructible<
         R,
         decltype(
           (std::forward<F>(f)(std::forward<Args>(args)...)))>::value)
{
  return std::forward<F>(f)(std::forward<Args>(args)...);
}

/////////////////////////////////////////////////////////////////////////////
// Precondition: `f(args...)` is a valid expression, and the return type is
// explicitly specified as possibly cv-qualified void.

template<typename F, typename... Args>
void invoke_5e_(F &&f, Args &&... args)
  noexcept(noexcept(std::declval<F>()(std::declval<Args>()...)))
{
  std::forward<F>(f)(std::forward<Args>(args)...);
}

/////////////////////////////////////////////////////////////////////////////
// Precondition: `f(args...)` is a valid expression, and the return type is
// explicitly specified.
//
// Overloads depending on whether the specified return type is possibly
// cv-qualified void.

template<typename R>
using enable_if_invoke_5d_
  = typename std::enable_if<std::is_void<R>::value>::type;

template<typename R, typename F, typename... Args,
         typename = enable_if_invoke_5d_<R> >
auto invoke_5d_(int, cradle::identity<R>, F &&f, Args &&... args)
CRADLE_SIMPLE_AUTO_FORWARD_RETURN(
  (invoke_5e_)(std::forward<F>(f), std::forward<Args>(args)...))

template<typename R, typename F, typename... Args>
auto invoke_5d_(bool, cradle::identity<R>, F &&f, Args &&... args)
CRADLE_SIMPLE_AUTO_FORWARD_RETURN(
  (invoke_5f_)(0, cradle::identity<R>(),
               std::forward<F>(f), std::forward<Args>(args)...))

/////////////////////////////////////////////////////////////////////////////
// Precondition: `f(args...)` is a valid expression and the return type is
// requested to be deduced.
//
// Any specializations of the following function template shall not
// participate overload resolution unless the type of the delegated
// expression is convertible to the deduced return type.

template<typename F, typename... Args>
constexpr bool test_invoke_5c_() noexcept
{
  typedef decltype(std::declval<F>()(std::declval<Args>()...)) x;
  return std::is_convertible<x, x>::value;
}

template<typename F, typename... Args>
using enable_if_invoke_5c_
  = typename std::enable_if<test_invoke_5c_<F, Args...>()>::type;

template<typename F, typename... Args,
         typename = enable_if_invoke_5c_<F, Args...> >
auto invoke_5c_(int, F &&f, Args &&... args)
CRADLE_SIMPLE_AUTO_FORWARD_RETURN(
  std::forward<F>(f)(std::forward<Args>(args)...))

/////////////////////////////////////////////////////////////////////////////
// Precondition: `f(args...)` is a valid expression.
//
// Overloads depending on whether the return type is explicitly specified or
// to be deduced from the delegated expression.

template<typename F, typename... Args>
auto invoke_5b_(
  int, cradle::identity<invoke_inference_>, F &&f, Args &&... args)
  CRADLE_SIMPLE_AUTO_FORWARD_RETURN(
    (invoke_5c_)(0, std::forward<F>(f), std::forward<Args>(args)...))

template<typename R, typename F, typename... Args>
auto invoke_5b_(bool, cradle::identity<R>, F &&f, Args &&... args)
CRADLE_SIMPLE_AUTO_FORWARD_RETURN(
  (invoke_5d_)(0, cradle::identity<R>(),
               std::forward<F>(f), std::forward<Args>(args)...))

/////////////////////////////////////////////////////////////////////////////
// Any specializations of the following function template shall not
// participate in overload resolution unless `f(args...)` is a valid
// expression.

template<typename R, typename F, typename... Args,
         typename = decltype(std::declval<F>()(std::declval<Args>()...))>
auto invoke_5a_(int, cradle::identity<R>, F &&f, Args &&... args)
CRADLE_SIMPLE_AUTO_FORWARD_RETURN(
  (invoke_5b_)(0, cradle::identity<R>(),
               std::forward<F>(f), std::forward<Args>(args)...))

/////////////////////////////////////////////////////////////////////////////
// Precondition: the number of arguments is equal to one, `(*a).*f` is a
// valid expression, and the return type is explicitly specified but other
// than possibly cv-qualified void, where `a` indicates the only argument.
//
// Checks convertibility from the type of the delegated expression to the
// specified return type. From the second precondition, the other form
// (`f(a)`) cannot become a valid expression. Therefore, no fallback is
// available if the type of the delegated expression is not convertible to
// the specified return type.

template<typename R, typename F, typename A>
constexpr bool test_invoke_4f_() noexcept
{
  typedef decltype((*std::declval<A>()).*std::declval<F>()) x;
  static_assert(std::is_reference<x>::value, "");
  return std::is_convertible<x, R>::value;
}

template<typename R, typename F, typename A>
using enable_if_invoke_4f_
  = typename std::enable_if<test_invoke_4f_<R, F, A>()>::type;

template<typename R, typename F, typename A,
         typename = enable_if_invoke_4f_<R, F, A> >
R invoke_4f_(int, cradle::identity<R>, F &&f, A &&a)
  noexcept(
    noexcept((*std::forward<A>(a)).*std::forward<F>(f))
    && std::is_nothrow_constructible<
         R, decltype(((*std::forward<A>(a)).*std::forward<F>(f)))>::value)
{
  return (*std::forward<A>(a)).*std::forward<F>(f);
}

/////////////////////////////////////////////////////////////////////////////
// Precondition: the number of arguments is equal to one, `(*a).*f` is a
// valid expression, and the return type is explicitly specified as possibly
// cv-qualified void, where `a` indicates the only argument.

template<typename F, typename A>
void invoke_4e_(F &&f, A &&a)
  noexcept(noexcept((*std::declval<A>()).*std::declval<F>()))
{
  static_cast<void>((*std::forward<A>(a)).*std::forward<F>(f));
}

/////////////////////////////////////////////////////////////////////////////
// Precondition: the number of arguments is equal to one, `(*a).*f` is a
// valid expression, and the return type is explicitly specified, where `a`
// indicates the only argument.
//
// Overloads depending on whether the specified return type is possibly
// cv-qualified void.

template<typename R>
using enable_if_invoke_4d_
  = typename std::enable_if<std::is_void<R>::value>::type;

template<typename R, typename F, typename A,
         typename = enable_if_invoke_4d_<R> >
auto invoke_4d_(int, cradle::identity<R>, F &&f, A &&a)
CRADLE_SIMPLE_AUTO_FORWARD_RETURN(
  (invoke_4e_)(std::forward<F>(f), std::forward<A>(a)))

template<typename R, typename F, typename A>
auto invoke_4d_(bool, cradle::identity<R>, F &&f, A &&a)
CRADLE_SIMPLE_AUTO_FORWARD_RETURN(
  (invoke_4f_)(0, cradle::identity<R>(),
               std::forward<F>(f), std::forward<A>(a)))

/////////////////////////////////////////////////////////////////////////////
// Precondition: the number of arguments is equal to one, `(*a).*f` is a
// valid expression, and the return type is requested to be deduced, where
// `a` indicates the only argument.
//
// Checks convertibility from the type of the delegated expression to the
// deduced return type. From the second precondition, the other form
// (`f(a)`) cannot become a valid expression. Therefore, no fallback is
// available if the type of the delegated expression is not convertible to
// the deduced return type.

template<typename F, typename A>
constexpr bool test_invoke_4c_() noexcept
{
  typedef decltype((*std::declval<A>()).*std::declval<F>()) x;
  return std::is_convertible<x, x>::value;
}

template<typename F, typename A>
using enable_if_invoke_4c_
  = typename std::enable_if<test_invoke_4c_<F, A>()>::type;

template<typename F, typename A, typename = enable_if_invoke_4c_<F, A> >
auto invoke_4c_(int, F &&f, A &&a)
CRADLE_SIMPLE_AUTO_FORWARD_RETURN(
  (*std::forward<A>(a)).*std::forward<F>(f))

/////////////////////////////////////////////////////////////////////////////
// Precondition: the number of arguments is equal to one, and `(*a).*f` is a
// valid expression, where `a` indicates the only argument.
//
// Overloads depending on whether the return type is explicitly specified or
// to be deduced from the delegated expression.

template<typename F, typename A>
auto invoke_4b_(int, cradle::identity<invoke_inference_>, F &&f, A &&a)
CRADLE_SIMPLE_AUTO_FORWARD_RETURN(
  (invoke_4c_)(0, std::forward<F>(f), std::forward<A>(a)))

template<typename R, typename F, typename A>
auto invoke_4b_(bool, cradle::identity<R>, F &&f, A &&a)
CRADLE_SIMPLE_AUTO_FORWARD_RETURN(
  (invoke_4d_)(0, cradle::identity<R>(),
               std::forward<F>(f), std::forward<A>(a)))

/////////////////////////////////////////////////////////////////////////////
// Precondition: the number of arguments is more than zero.
//
// Overloads depending on whether the number of the arguments is equal to
// one and `(*a).*f` is a valid expression, where `a` indicates the only
// argument.

template<typename R, typename F, typename A,
         typename = decltype((*std::declval<A>()).*std::declval<F>())>
auto invoke_4a_(int, cradle::identity<R>, F &&f, A &&a)
CRADLE_SIMPLE_AUTO_FORWARD_RETURN(
  (invoke_4b_)(0, cradle::identity<R>(),
               std::forward<F>(f), std::forward<A>(a)))

template<typename R, typename F, typename A, typename... Args>
auto invoke_4a_(bool, cradle::identity<R>, F &&f, A &&a, Args &&... args)
CRADLE_SIMPLE_AUTO_FORWARD_RETURN(
  (invoke_5a_)(0, cradle::identity<R>(), std::forward<F>(f),
               std::forward<A>(a), std::forward<Args>(args)...))

/////////////////////////////////////////////////////////////////////////////
// Precondition: the number of arguments is equal to one, `a.*f` is a valid
// expression, and the return type is explicitly specified but other than
// possibly cv-qualified void, where `a` indicates the only argument.
//
// Checks convertibility from the type of the delegated expression to the
// specified return type. From the second precondition, the other forms
// (`a.*f` and `f(a)`) cannot become valid expressions. Therefore, no
// fallback is available if the type of the delegated expression is not
// convertible to the specified return type.

template<typename R, typename F, typename A>
constexpr bool test_invoke_3f_() noexcept
{
  typedef decltype(std::declval<A>().*std::declval<F>()) x;
  static_assert(std::is_reference<x>::value, "");
  return std::is_convertible<x, R>::value;
}

template<typename R, typename F, typename A>
using enable_if_invoke_3f_
  = typename std::enable_if<test_invoke_3f_<R, F, A>()>::type;

template<typename R, typename F, typename A,
         typename = enable_if_invoke_3f_<R, F, A> >
R invoke_3f_(int, cradle::identity<R>, F &&f, A &&a)
  noexcept(
    noexcept(std::forward<A>(a).*std::forward<F>(f))
    && std::is_nothrow_constructible<
         R, decltype((std::forward<A>(a).*std::forward<F>(f)))>::value)
{
  return std::forward<A>(a).*std::forward<F>(f);
}

/////////////////////////////////////////////////////////////////////////////
// Precondition: the number of arguments is equal to one, `a.*f` is a valid
// expression, and the return type is explicitly specified as possibly
// cv-qualified void, where `a` indicates the only argument.

template<typename F, typename A>
void invoke_3e_(F &&f, A &&a)
  noexcept(noexcept(std::declval<A>().*std::declval<F>()))
{
  static_cast<void>(std::forward<A>(a).*std::forward<F>(f));
}

/////////////////////////////////////////////////////////////////////////////
// Precondition: the number of arguments is equal to one, `a.*f` is a valid
// expression, and the return type is explicitly specified, where `a`
// indicates the only argument.
//
// Overloads depending on whether the specified return type is possibly
// cv-qualified void.

template<typename R>
using enable_if_invoke_3d_
  = typename std::enable_if<std::is_void<R>::value>::type;

template<typename R, typename F, typename A,
         typename = enable_if_invoke_3d_<R> >
auto invoke_3d_(int, cradle::identity<R>, F &&f, A &&a)
CRADLE_SIMPLE_AUTO_FORWARD_RETURN(
  (invoke_3e_)(std::forward<F>(f), std::forward<A>(a)))

template<typename R, typename F, typename A>
auto invoke_3d_(bool, cradle::identity<R>, F &&f, A &&a)
CRADLE_SIMPLE_AUTO_FORWARD_RETURN(
  (invoke_3f_)(0, cradle::identity<R>(),
               std::forward<F>(f), std::forward<A>(a)))

/////////////////////////////////////////////////////////////////////////////
// Precondition: the number of arguments is equal to one, `a.*f` is a valid
// expression, and the return type is requested to be deduced, where `a`
// indicates the only argument.
//
// Checks convertibility from the type of the delegated expression to the
// deduced return type. From the second precondition, the other forms
// (`(*a).*f` and `f(a)`) cannot become valid expressions. Therefore, no
// fallback is available if the type of the delegated expression is not
// convertible to the deduced return type.

template<typename F, typename A>
constexpr bool test_invoke_3c_() noexcept
{
  typedef decltype(std::declval<A>().*std::declval<F>()) x;
  return std::is_convertible<x, x>::value;
}

template<typename F, typename A>
using enable_if_invoke_3c_
  = typename std::enable_if<test_invoke_3c_<F, A>()>::type;

template<typename F, typename A, typename = enable_if_invoke_3c_<F, A> >
auto invoke_3c_(int, F &&f, A &&a)
CRADLE_SIMPLE_AUTO_FORWARD_RETURN(std::forward<A>(a).*std::forward<F>(f))

/////////////////////////////////////////////////////////////////////////////
// Precondition: the number of arguments is equal to one, and `a.*f` is a
// valid expression, where `a` indicates the only argument.
//
// Overloads depending on whether the return type is explicitly specified or
// to be deduced from the delegated expression.

template<typename F, typename A>
auto invoke_3b_(int, cradle::identity<invoke_inference_>, F &&f, A &&a)
CRADLE_SIMPLE_AUTO_FORWARD_RETURN(
  (invoke_3c_)(0, std::forward<F>(f), std::forward<A>(a)))

template<typename R, typename F, typename A>
auto invoke_3b_(bool, cradle::identity<R>, F &&f, A &&a)
CRADLE_SIMPLE_AUTO_FORWARD_RETURN(
  (invoke_3d_)(0, cradle::identity<R>(),
               std::forward<F>(f), std::forward<A>(a)))

/////////////////////////////////////////////////////////////////////////////
// Precondition: the number of arguments is more than zero.
//
// Overloads depending on whether the number of the arguments is equal to
// one and `a.*f` is a valid expression, where `a` indicates the only
// argument.

template<typename R, typename F, typename A,
         typename = decltype(std::declval<A>().*std::declval<F>())>
auto invoke_3a_(int, cradle::identity<R>, F &&f, A &&a)
CRADLE_SIMPLE_AUTO_FORWARD_RETURN(
  (invoke_3b_)(
    0, cradle::identity<R>(), std::forward<F>(f), std::forward<A>(a)))

template<typename R, typename F, typename A, typename... Args>
auto invoke_3a_(bool, cradle::identity<R>, F &&f, A &&a, Args &&... args)
CRADLE_SIMPLE_AUTO_FORWARD_RETURN(
  (invoke_4a_)(0, cradle::identity<R>(), std::forward<F>(f),
               std::forward<A>(a), std::forward<Args>(args)...))

/////////////////////////////////////////////////////////////////////////////
// Precondition: the number of arguments is more than zero,
// `((*a).*f)(tail...)` is a valid expression, and the return type is
// explicitly specified but other than possibly cv-qualified void, where `a`
// indicates the first element in the arguments and `tail` indicates an
// invented function parameter pack representing the remaining arguments.
//
// Checks convertibility from the type of the delegated expression to the
// specified return type. From the second precondition, the other forms
// (`a.*f`, `(*a).*f` and `f(args...)`) cannot become valid expressions.
// Therefore, no fallback is available if the type of the delegated
// expression is not convertible to the specified return type.

template<typename R, typename F, typename A, typename... Args>
constexpr bool test_invoke_2f_() noexcept
{
  typedef decltype(
    ((*std::declval<A>()).*std::declval<F>())(std::declval<Args>()...)) x;
  return std::is_convertible<x, R>::value
    && (std::is_reference<x>::value || !std::is_reference<R>::value);
}

template<typename R, typename F, typename... Args>
using enable_if_invoke_2f_
  = typename std::enable_if<test_invoke_2f_<R, F, Args...>()>::type;

template<typename R, typename F, typename A, typename... Args,
         typename = enable_if_invoke_2f_<R, F, A, Args...> >
R invoke_2f_(int, cradle::identity<R>, F &&f, A &&a, Args &&... args)
  noexcept(
    noexcept(
      ((*std::forward<A>(a)).*std::forward<F>(f))(
        std::forward<Args>(args)...))
    && std::is_nothrow_constructible<
         R,
         decltype(
           (((*std::forward<A>(a)).*std::forward<F>(f))(
             std::forward<Args>(args)...)))>::value)
{
  return ((*std::forward<A>(a)).*std::forward<F>(f))(
    std::forward<Args>(args)...);
}

/////////////////////////////////////////////////////////////////////////////
// Precondition: the number of arguments is more than zero,
// `((*a).*f)(tail...)` is a valid expression, and the return type is
// explicitly specified as possibly cv-qualified void, where `a` indicates
// the first element in the arguments and `tail` indicates an invented
// function parameter pack representing the remaining arguments.

template<typename F, typename A, typename... Args>
void invoke_2e_(F &&f, A &&a, Args &&... args)
  noexcept(
    noexcept(
      ((*std::declval<A>()).*std::declval<F>())(std::declval<Args>()...)))
{
  ((*std::forward<A>(a)).*std::forward<F>(f))(std::forward<Args>(args)...);
}

/////////////////////////////////////////////////////////////////////////////
// Precondition: the number of arguments is more than zero,
// `((*a).*f)(tail...)` is a valid expression, and the return type is
// explicitly specified, where `a` indicates the first element in the
// arguments and `tail` indicates an invented function parameter pack
// representing the remaining arguments.
//
// Overloads depending on whether the specified return type is possibly
// cv-qualified void.

template<typename R>
using enable_if_invoke_2d_
  = typename std::enable_if<std::is_void<R>::value>::type;

template<typename R, typename F, typename... Args,
         typename = enable_if_invoke_2d_<R> >
auto invoke_2d_(int, cradle::identity<R>, F &&f, Args &&... args)
CRADLE_SIMPLE_AUTO_FORWARD_RETURN(
  (invoke_2e_)(std::forward<F>(f), std::forward<Args>(args)...))

template<typename R, typename F, typename... Args>
auto invoke_2d_(bool, cradle::identity<R>, F &&f, Args &&... args)
CRADLE_SIMPLE_AUTO_FORWARD_RETURN(
  (invoke_2f_)(0, cradle::identity<R>(),
               std::forward<F>(f), std::forward<Args>(args)...))

/////////////////////////////////////////////////////////////////////////////
// Precondition: the number of arguments is more than zero,
// `((*a).*f)(tail...)` is a valid expression, and the return type is
// requested to be deduced, where `a` indicates the first element in the
// arguments and `tail` indicates an invented function parameter pack
// representing the remaining arguments.
//
// Checks convertibility from the type of the delegated expression to the
// deduced return type. From the second precondition, the other forms
// (`a.*f`, `(*a).*f` and `f(args...)`) cannot become valid expressions.
// Therefore, no fallback is available if the type of the delegated
// expression is not convertible to the deduced return type.

template<typename F, typename A, typename... Args>
constexpr bool test_invoke_2c_() noexcept
{
  typedef decltype(
    ((*std::declval<A>()).*std::declval<F>())(std::declval<Args>()...)) x;
  return std::is_convertible<x, x>::value;
}

template<typename F, typename... Args>
using enable_if_invoke_2c_
  = typename std::enable_if<test_invoke_2c_<F, Args...>()>::type;

template<typename F, typename A, typename... Args,
         typename = enable_if_invoke_2c_<F, A, Args...> >
auto invoke_2c_(int, F &&f, A &&a, Args &&... args)
CRADLE_SIMPLE_AUTO_FORWARD_RETURN(
  ((*std::forward<A>(a)).*std::forward<F>(f))(std::forward<Args>(args)...))

/////////////////////////////////////////////////////////////////////////////
// Precondition: the number of arguments is more than zero, and
// `((*a).*f)(tail...)` is a valid expression, where `a` indicates the first
// element in the arguments and `tail` indicates an invented function
// parameter pack representing the remaining arguments.
//
// Overloads depending on whether the return type is explicitly specified or
// to be deduced from the delegated expression.

template<typename F, typename... Args>
auto invoke_2b_(
  int, cradle::identity<invoke_inference_>, F &&f, Args &&... args)
CRADLE_SIMPLE_AUTO_FORWARD_RETURN(
  (invoke_2c_)(0, std::forward<F>(f), std::forward<Args>(args)...))

template<typename R, typename F, typename... Args>
auto invoke_2b_(bool, cradle::identity<R>, F &&f, Args &&... args)
CRADLE_SIMPLE_AUTO_FORWARD_RETURN(
  (invoke_2d_)(0, cradle::identity<R>(),
               std::forward<F>(f), std::forward<Args>(args)...))

/////////////////////////////////////////////////////////////////////////////
// Precondition: the number of arguments is more than zero.
//
// Overloads depending on whether `((*a).*f)(tail...)` is a valid expression
// or not, where `a` indicates the first element in the arguments and `tail`
// indicates an invented function parameter pack representing the remaining
// arguments.

template<
  typename R, typename F, typename A, typename... Args,
  typename = decltype(
    ((*std::declval<A>()).*std::declval<F>())(std::declval<Args>()...))>
auto invoke_2a_(int, cradle::identity<R>, F &&f, A &&a, Args &&... args)
CRADLE_SIMPLE_AUTO_FORWARD_RETURN(
  (invoke_2b_)(0, cradle::identity<R>(), std::forward<F>(f),
               std::forward<A>(a), std::forward<Args>(args)...))

template<typename R, typename F, typename A, typename... Args>
auto invoke_2a_(bool, cradle::identity<R>, F &&f, A &&a, Args &&... args)
CRADLE_SIMPLE_AUTO_FORWARD_RETURN(
  (invoke_3a_)(0, cradle::identity<R>(), std::forward<F>(f),
               std::forward<A>(a), std::forward<Args>(args)...))

/////////////////////////////////////////////////////////////////////////////
// Precondition: the number of arguments is more than zero,
// `(a.*f)(tail...)` is a valid expression, and the return type is
// explicitly specified but other than possibly cv-qualified void, where `a`
// indicates the first element in the arguments and `tail` indicates an
// invented function parameter pack representing the remaining arguments.
//
// Checks convertibility from the type of the delegated expression to the
// specified return type. From the second precondition, the other forms
// (`((*a).*f)(tail...)`, `a.*f`, `(*a).*f` and `f(args...)`) cannot become
// valid expressions. Therefore, no fallback is available if the type of the
// delegated expression is not convertible to the specified return type.

template<typename R, typename F, typename A, typename... Args>
constexpr bool test_invoke_1f_() noexcept
{
  typedef decltype(
    ((std::declval<A>().*std::declval<F>())(std::declval<Args>()...))) x;
  return std::is_convertible<x, R>::value
    && (std::is_reference<x>::value || !std::is_reference<R>::value);
}

template<typename R, typename F, typename... Args>
using enable_if_invoke_1f_
  = typename std::enable_if<test_invoke_1f_<R, F, Args...>()>::type;

template<typename R, typename F, typename A, typename... Args,
         typename = enable_if_invoke_1f_<R, F, A, Args...> >
R invoke_1f_(int, cradle::identity<R>, F &&f, A &&a, Args &&... args)
  noexcept(
    noexcept(
      (std::forward<A>(a).*std::forward<F>(f))(std::forward<Args>(args)...))
    && std::is_nothrow_constructible<
         R,
         decltype(
           ((std::forward<A>(a).*std::forward<F>(f))(
             std::forward<Args>(args)...)))>::value)
{
  return (std::forward<A>(a).*std::forward<F>(f))(
    std::forward<Args>(args)...);
}

/////////////////////////////////////////////////////////////////////////////
// Precondition: the number of arguments is more than zero,
// `(a.*f)(tail...)` is a valid expression, and the return type is
// explicitly specified as possibly cv-qualified void, where `a` indicates
// the first element in the arguments and `tail` indicates an invented
// function parameter pack representing the remaining arguments.

template<typename F, typename A, typename... Args>
void invoke_1e_(F &&f, A &&a, Args &&... args)
  noexcept(
    noexcept(
      (std::declval<A>().*std::declval<F>())(std::declval<Args>()...)))
{
  (std::forward<A>(a).*std::forward<F>(f))(std::forward<Args>(args)...);
}

/////////////////////////////////////////////////////////////////////////////
// Precondition: the number of arguments is more than zero,
// `(a.*f)(tail...)` is a valid expression, and the return type is
// explicitly specified, where `a` indicates the first element in the
// arguments and `tail` indicates an invented function parameter pack
// representing the remaining arguments.
//
// Overloads depending on whether the specified return type is possibly
// cv-qualified void.

template<typename R>
using enable_if_invoke_1d_
  = typename std::enable_if<std::is_void<R>::value>::type;

template<typename R, typename F,
         typename... Args, typename = enable_if_invoke_1d_<R> >
auto invoke_1d_(int, cradle::identity<R>, F &&f, Args &&... args)
CRADLE_SIMPLE_AUTO_FORWARD_RETURN(
  (invoke_1e_)(std::forward<F>(f), std::forward<Args>(args)...))

template<typename R, typename F, typename... Args>
auto invoke_1d_(bool, cradle::identity<R>, F &&f, Args &&... args)
CRADLE_SIMPLE_AUTO_FORWARD_RETURN(
  (invoke_1f_)(0, cradle::identity<R>(),
               std::forward<F>(f), std::forward<Args>(args)...))

/////////////////////////////////////////////////////////////////////////////
// Precondition: the number of arguments is more than zero,
// `(a.*f)(tail...)` is a valid expression, and the return type is requested
// to be deduced, where `a` indicates the first element in the arguments and
// `tail` indicates an invented function parameter pack representing the
// remaining arguments.
//
// Checks convertibility from the type of the delegated expression to the
// deduced return type. From the second precondition, the other forms
// (`((*a).*f)(tail...)`, `a.*f`, `(*a).*f` and `f(args...)`) cannot become
// valid expressions. Therefore, no fallback is available if the type of the
// delegated expression is not convertible to the deduced return type.

template<typename F, typename A, typename... Args>
constexpr bool test_invoke_1c_() noexcept
{
  typedef decltype(
    (std::declval<A>().*std::declval<F>())(std::declval<Args>()...)) x;
  return std::is_convertible<x, x>::value;
}

template<typename F, typename... Args>
using enable_if_invoke_1c_
  = typename std::enable_if<test_invoke_1c_<F, Args...>()>::type;

template<typename F, typename A, typename... Args,
         typename = enable_if_invoke_1c_<F, A, Args...> >
auto invoke_1c_(int, F &&f, A &&a, Args &&... args)
CRADLE_SIMPLE_AUTO_FORWARD_RETURN(
  (std::forward<A>(a).*std::forward<F>(f))(std::forward<Args>(args)...))

/////////////////////////////////////////////////////////////////////////////
// Precondition: the number of arguments is more than zero, and
// `(a.*f)(tail...)` is a valid expression, where `a` indicates the first
// element in the arguments and `tail` indicates an invented function
// parameter pack representing the remaining arguments.
//
// Overloads depending on whether the return type is explicitly specified or
// to be deduced from the delegated expression.

template<typename F, typename... Args>
auto invoke_1b_(
  int, cradle::identity<invoke_inference_>, F &&f, Args &&... args)
CRADLE_SIMPLE_AUTO_FORWARD_RETURN(
  (invoke_1c_)(0, std::forward<F>(f), std::forward<Args>(args)...))

template<typename R, typename F, typename... Args>
auto invoke_1b_(bool, cradle::identity<R>, F &&f, Args &&... args)
CRADLE_SIMPLE_AUTO_FORWARD_RETURN(
  (invoke_1d_)(0, cradle::identity<R>(),
               std::forward<F>(f), std::forward<Args>(args)...))

/////////////////////////////////////////////////////////////////////////////
// Precondition: the number of arguments is more than zero.
//
// Overloads depending on whether `(a.*f)(tail...)` is a valid expression or
// not, where `a` indicates the first element in the arguments and `tail`
// indicates an invented function parameter pack representing the remaining
// arguments.

template<typename R, typename F, typename A, typename... Args,
         typename = decltype(
           (std::declval<A>().*std::declval<F>())(std::declval<Args>()...))>
auto invoke_1a_(int, cradle::identity<R>, F &&f, A &&a, Args &&... args)
CRADLE_SIMPLE_AUTO_FORWARD_RETURN(
  (invoke_1b_)(0, cradle::identity<R>(), std::forward<F>(f),
               std::forward<A>(a), std::forward<Args>(args)...))

template<typename R, typename F, typename A, typename... Args>
auto invoke_1a_(bool, cradle::identity<R>, F &&f, A &&a, Args &&... args)
CRADLE_SIMPLE_AUTO_FORWARD_RETURN(
  (invoke_2a_)(0, cradle::identity<R>(), std::forward<F>(f),
               std::forward<A>(a), std::forward<Args>(args)...))

/////////////////////////////////////////////////////////////////////////////
// Overloads depending on whether the number of arguments is more than zero.
// If the number of the arguments is equal to zero, `invoke_1x_`,
// `invoke_2x_`, `invoke_3x_` and `invoke_4x_` are skipped.

template<typename R, typename F>
auto invoke_0a_(cradle::identity<R>, F &&f)
CRADLE_SIMPLE_AUTO_FORWARD_RETURN(
  (invoke_5a_)(0, cradle::identity<R>(), std::forward<F>(f)))

template<typename R, typename F, typename... Args>
auto invoke_0a_(cradle::identity<R>, F &&f, Args &&... args)
CRADLE_SIMPLE_AUTO_FORWARD_RETURN(
  (invoke_1a_)(0, cradle::identity<R>(),
               std::forward<F>(f),  std::forward<Args>(args)...))

} // namespace detail_

/////////////////////////////////////////////////////////////////////////////
// If `invoke` is called with the form `invoke<R>(...)`, the return type is
// explicitly specified as `R`. Otherwise, the return type will be deduced
// from the delegated expression. The latter case is indicated by a special
// dummy type `detail_::invoke_inference_` .

template<
  typename R = detail_::invoke_inference_, typename F, typename... Args>
auto invoke(F &&f, Args &&... args)
CRADLE_SIMPLE_AUTO_FORWARD_RETURN(
  detail_::invoke_0a_(cradle::identity<R>(),
                      std::forward<F>(f), std::forward<Args>(args)...))

} // namespace cradle

#endif // !defined(CRADLE_FUNCTIONAL_INVOKE_HPP_INCLUDE_GUARD)
