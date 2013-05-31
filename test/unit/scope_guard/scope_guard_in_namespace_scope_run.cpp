#include <cradle/scope_guard/scope_guard.hpp>

#include <boost/test/unit_test.hpp>


BOOST_AUTO_TEST_SUITE(scope_guard)

BOOST_AUTO_TEST_SUITE(scope_guard_in_namespace_scope)

int gi = 42;

namespace{

class C
{
public:
  explicit C(int expected) noexcept
    : expected_(expected)
  {}

  ~C()
  {
    assert(gi == expected_);
  }

private:
  int expected_;
};

} // namespace `unnamed'

C c1(41);

CRADLE_SCOPE_GUARD{
  ++gi;
};

C c2(40);

CRADLE_SCOPE_GUARD{
  gi -= 2;
};

C c3(42);

BOOST_AUTO_TEST_CASE(dummy)
{
  BOOST_CHECK_EQUAL(gi, 42);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
