#define BOOST_TEST_MAIN
#include <cradle/scope_guard/scope_guard.hpp>

#include <boost/test/unit_test.hpp>

int gi = 42;

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
