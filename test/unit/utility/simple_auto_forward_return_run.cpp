//  (C) Copyright Cryolite 2013. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cradle/utility/simple_auto_forward_return.hpp>

#include <cradle/utility/as_const.hpp>
#include <boost/test/unit_test.hpp>


BOOST_AUTO_TEST_SUITE(utility)

BOOST_AUTO_TEST_SUITE(simple_auto_forward_return)

namespace{

int gi = 42;

auto variable()
CRADLE_SIMPLE_AUTO_FORWARD_RETURN(gi)

} // namespace `unnamed'

#define ASSERT_SAME(EXPRESSION, TYPE_ID)                               \
static_assert(std::is_same<decltype(EXPRESSION), TYPE_ID >::value, "") \
/**/

#define ASSERT_NOEXCEPT(EXPRESSION) static_assert(noexcept(EXPRESSION), "")

BOOST_AUTO_TEST_CASE(testVariable)
{
  ASSERT_SAME(variable(), int &);
  ASSERT_NOEXCEPT(variable());
  BOOST_CHECK_EQUAL(&variable(), &gi);
}

namespace{

auto literal()
CRADLE_SIMPLE_AUTO_FORWARD_RETURN(42)

}

BOOST_AUTO_TEST_CASE(testLiteral)
{
  ASSERT_SAME(literal(), int);
  ASSERT_NOEXCEPT(literal());
  BOOST_CHECK_EQUAL(literal(), 42);
}

namespace{

void f()
{}

auto identifier_to_function()
CRADLE_SIMPLE_AUTO_FORWARD_RETURN(f)

}

BOOST_AUTO_TEST_CASE(testIdentifierToFunction)
{
  ASSERT_SAME(identifier_to_function(), void (&)());
  ASSERT_NOEXCEPT(identifier_to_function());
  BOOST_CHECK_EQUAL(&identifier_to_function(), &f);
}

namespace{

auto void_()
CRADLE_SIMPLE_AUTO_FORWARD_RETURN(static_cast<void>(++gi))

}

BOOST_AUTO_TEST_CASE(testVoid)
{
  ASSERT_SAME(void_(), void);
  ASSERT_NOEXCEPT(void_());
  gi = 1;
  void_();
  BOOST_CHECK_EQUAL(gi, 2);
}

namespace{

struct S
{
  int mv;
};

S s;

auto member_access()
CRADLE_SIMPLE_AUTO_FORWARD_RETURN(s.mv)

}

BOOST_AUTO_TEST_CASE(testMemberAccess)
{
  ASSERT_SAME(member_access(), int &);
  ASSERT_NOEXCEPT(member_access());
  BOOST_CHECK_EQUAL(&member_access(), &s.mv);
}

namespace{

template<typename T>
auto forward(T &&x)
CRADLE_SIMPLE_AUTO_FORWARD_RETURN(std::forward<T>(x))

}

BOOST_AUTO_TEST_CASE(testForward)
{
  ASSERT_SAME(forward(42), int &&);
  ASSERT_NOEXCEPT(forward(42));
  BOOST_CHECK_EQUAL(forward(42), 42);

  {
    int i = 42;

    ASSERT_SAME(forward(i), int &);
    ASSERT_NOEXCEPT(forward(i));
    BOOST_CHECK_EQUAL(&forward(i), &i);

    ASSERT_SAME(forward(cradle::as_const(i)), int const &);
    ASSERT_NOEXCEPT(forward(cradle::as_const(i)));
    BOOST_CHECK_EQUAL(&forward(cradle::as_const(i)), &i);

    ASSERT_SAME(forward(std::move(i)), int &&);
    ASSERT_NOEXCEPT(forward(std::move(i)));
    BOOST_CHECK_EQUAL(&static_cast<int const &>(forward(std::move(i))), &i);
  }
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
