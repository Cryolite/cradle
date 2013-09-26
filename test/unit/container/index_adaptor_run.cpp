#include <cradle/container/index_adaptor.hpp>

#include <cradle/utility/as_const.hpp>

#include <boost/test/unit_test.hpp>

#include <cstddef>
#include <limits>


BOOST_AUTO_TEST_SUITE(container)

BOOST_AUTO_TEST_SUITE(index_adaptor)

namespace {

class integer_index
  : public cradle::index_adaptor<integer_index, std::size_t>
{
private:
  friend class cradle::index_core_access;

public:
  constexpr integer_index() noexcept
    : index_adaptor_(std::numeric_limits<std::size_t>::max())
  {}

  constexpr explicit integer_index(std::size_t i) noexcept
    : index_adaptor_(i)
  {}
}; // class integer_index

} // namespace *unnamed

BOOST_AUTO_TEST_CASE(null)
{
  {
    integer_index i;
    BOOST_CHECK((noexcept(i.is_null())));
    BOOST_CHECK((i.is_null()));
    BOOST_CHECK((noexcept(cradle::as_const(i).is_null())));
    BOOST_CHECK((cradle::as_const(i).is_null()));
  }
  BOOST_CHECK((noexcept(integer_index().is_null())));
  BOOST_CHECK((integer_index().is_null()));
  static_assert(integer_index().is_null(), "");
  {
    integer_index i(0);
    BOOST_CHECK((!i.is_null()));
    BOOST_CHECK((!cradle::as_const(i).is_null()));
  }
  BOOST_CHECK((!integer_index(0).is_null()));
  static_assert(!integer_index(0).is_null(), "");
}

BOOST_AUTO_TEST_CASE(equality_comparison)
{
  integer_index i;

  BOOST_CHECK((noexcept(i == i)));
  BOOST_CHECK((i == i));
  BOOST_CHECK((noexcept(i == cradle::as_const(i))));
  BOOST_CHECK((i == cradle::as_const(i)));
  BOOST_CHECK((noexcept(i == integer_index())));
  BOOST_CHECK((i == integer_index()));
  BOOST_CHECK((noexcept(cradle::as_const(i) == i)));
  BOOST_CHECK((cradle::as_const(i) == i));
  BOOST_CHECK((noexcept(cradle::as_const(i) == cradle::as_const(i))));
  BOOST_CHECK((cradle::as_const(i) == cradle::as_const(i)));
  BOOST_CHECK((noexcept(cradle::as_const(i) == integer_index())));
  BOOST_CHECK((cradle::as_const(i) == integer_index()));
  BOOST_CHECK((noexcept(integer_index() == i)));
  BOOST_CHECK((integer_index() == i));
  BOOST_CHECK((noexcept(integer_index() == cradle::as_const(i))));
  BOOST_CHECK((integer_index() == cradle::as_const(i)));
  BOOST_CHECK((noexcept(integer_index() == integer_index())));
  BOOST_CHECK((integer_index() == integer_index()));
  static_assert(integer_index() == integer_index(), "");

  BOOST_CHECK((noexcept(i != i)));
  BOOST_CHECK((!(i != i)));
  BOOST_CHECK((noexcept(i != cradle::as_const(i))));
  BOOST_CHECK((!(i != cradle::as_const(i))));
  BOOST_CHECK((noexcept(i != integer_index())));
  BOOST_CHECK((!(i != integer_index())));
  BOOST_CHECK((noexcept(cradle::as_const(i) != i)));
  BOOST_CHECK((!(cradle::as_const(i) != i)));
  BOOST_CHECK((noexcept(cradle::as_const(i) != cradle::as_const(i))));
  BOOST_CHECK((!(cradle::as_const(i) != cradle::as_const(i))));
  BOOST_CHECK((noexcept(cradle::as_const(i) != integer_index())));
  BOOST_CHECK((!(cradle::as_const(i) != integer_index())));
  BOOST_CHECK((noexcept(integer_index() != i)));
  BOOST_CHECK((!(integer_index() != i)));
  BOOST_CHECK((noexcept(integer_index() != cradle::as_const(i))));
  BOOST_CHECK((!(integer_index() != cradle::as_const(i))));
  BOOST_CHECK((noexcept(integer_index() != integer_index())));
  BOOST_CHECK((!(integer_index() != integer_index())));
  static_assert(!(integer_index() != integer_index()), "");
}

BOOST_AUTO_TEST_CASE(total_order)
{
  integer_index i;

  BOOST_CHECK((noexcept(i < i)));
  BOOST_CHECK((!(i < i)));
  BOOST_CHECK((noexcept(i < cradle::as_const(i))));
  BOOST_CHECK((!(i < cradle::as_const(i))));
  BOOST_CHECK((noexcept(i < integer_index())));
  BOOST_CHECK((!(i < integer_index())));
  BOOST_CHECK((noexcept(cradle::as_const(i) < i)));
  BOOST_CHECK((!(cradle::as_const(i) < i)));
  BOOST_CHECK((noexcept(cradle::as_const(i) < cradle::as_const(i))));
  BOOST_CHECK((!(cradle::as_const(i) < cradle::as_const(i))));
  BOOST_CHECK((noexcept(cradle::as_const(i) < integer_index())));
  BOOST_CHECK((!(cradle::as_const(i) < integer_index())));
  BOOST_CHECK((noexcept(integer_index() < i)));
  BOOST_CHECK((!(integer_index() < i)));
  BOOST_CHECK((noexcept(integer_index() < cradle::as_const(i))));
  BOOST_CHECK((!(integer_index() < cradle::as_const(i))));
  BOOST_CHECK((noexcept(integer_index() < integer_index())));
  BOOST_CHECK((!(integer_index() < integer_index())));
  static_assert(!(integer_index() < integer_index()), "");

  BOOST_CHECK((noexcept(i > i)));
  BOOST_CHECK((!(i > i)));
  BOOST_CHECK((noexcept(i > cradle::as_const(i))));
  BOOST_CHECK((!(i > cradle::as_const(i))));
  BOOST_CHECK((noexcept(i > integer_index())));
  BOOST_CHECK((!(i > integer_index())));
  BOOST_CHECK((noexcept(cradle::as_const(i) > i)));
  BOOST_CHECK((!(cradle::as_const(i) > i)));
  BOOST_CHECK((noexcept(cradle::as_const(i) > cradle::as_const(i))));
  BOOST_CHECK((!(cradle::as_const(i) > cradle::as_const(i))));
  BOOST_CHECK((noexcept(cradle::as_const(i) > integer_index())));
  BOOST_CHECK((!(cradle::as_const(i) > integer_index())));
  BOOST_CHECK((noexcept(integer_index() > i)));
  BOOST_CHECK((!(integer_index() > i)));
  BOOST_CHECK((noexcept(integer_index() > cradle::as_const(i))));
  BOOST_CHECK((!(integer_index() > cradle::as_const(i))));
  BOOST_CHECK((noexcept(integer_index() > integer_index())));
  BOOST_CHECK((!(integer_index() > integer_index())));
  static_assert(!(integer_index() > integer_index()), "");

  BOOST_CHECK((noexcept(i <= i)));
  BOOST_CHECK((i <= i));
  BOOST_CHECK((noexcept(i <= cradle::as_const(i))));
  BOOST_CHECK((i <= cradle::as_const(i)));
  BOOST_CHECK((noexcept(i <= integer_index())));
  BOOST_CHECK((i <= integer_index()));
  BOOST_CHECK((noexcept(cradle::as_const(i) <= i)));
  BOOST_CHECK((cradle::as_const(i) <= i));
  BOOST_CHECK((noexcept(cradle::as_const(i) <= cradle::as_const(i))));
  BOOST_CHECK((cradle::as_const(i) <= cradle::as_const(i)));
  BOOST_CHECK((noexcept(cradle::as_const(i) <= integer_index())));
  BOOST_CHECK((cradle::as_const(i) <= integer_index()));
  BOOST_CHECK((noexcept(integer_index() <= i)));
  BOOST_CHECK((integer_index() <= i));
  BOOST_CHECK((noexcept(integer_index() <= cradle::as_const(i))));
  BOOST_CHECK((integer_index() <= cradle::as_const(i)));
  BOOST_CHECK((noexcept(integer_index() <= integer_index())));
  BOOST_CHECK((integer_index() <= integer_index()));
  static_assert(integer_index() <= integer_index(), "");

  BOOST_CHECK((noexcept(i >= i)));
  BOOST_CHECK((i >= i));
  BOOST_CHECK((noexcept(i >= cradle::as_const(i))));
  BOOST_CHECK((i >= cradle::as_const(i)));
  BOOST_CHECK((noexcept(i >= integer_index())));
  BOOST_CHECK((i >= integer_index()));
  BOOST_CHECK((noexcept(cradle::as_const(i) >= i)));
  BOOST_CHECK((cradle::as_const(i) >= i));
  BOOST_CHECK((noexcept(cradle::as_const(i) >= cradle::as_const(i))));
  BOOST_CHECK((cradle::as_const(i) >= cradle::as_const(i)));
  BOOST_CHECK((noexcept(cradle::as_const(i) >= integer_index())));
  BOOST_CHECK((cradle::as_const(i) >= integer_index()));
  BOOST_CHECK((noexcept(integer_index() >= i)));
  BOOST_CHECK((integer_index() >= i));
  BOOST_CHECK((noexcept(integer_index() >= cradle::as_const(i))));
  BOOST_CHECK((integer_index() >= cradle::as_const(i)));
  BOOST_CHECK((noexcept(integer_index() >= integer_index())));
  BOOST_CHECK((integer_index() >= integer_index()));
  static_assert(integer_index() >= integer_index(), "");

  BOOST_CHECK((!(integer_index(0) < integer_index(0))));
  BOOST_CHECK((integer_index(0) < integer_index(1)));
  BOOST_CHECK((!(integer_index(1) < integer_index(0))));
  BOOST_CHECK((integer_index(0) < integer_index()));
  BOOST_CHECK((!(integer_index() < integer_index(0))));

  BOOST_CHECK((!(integer_index(0) > integer_index(0))));
  BOOST_CHECK((!(integer_index(0) > integer_index(1))));
  BOOST_CHECK((integer_index(1) > integer_index(0)));
  BOOST_CHECK((!(integer_index(0) > integer_index())));
  BOOST_CHECK((integer_index() > integer_index(0)));

  BOOST_CHECK((integer_index(0) <= integer_index(0)));
  BOOST_CHECK((integer_index(0) <= integer_index(1)));
  BOOST_CHECK((!(integer_index(1) <= integer_index(0))));
  BOOST_CHECK((integer_index(0) <= integer_index()));
  BOOST_CHECK((!(integer_index() <= integer_index(0))));

  BOOST_CHECK((integer_index(0) >= integer_index(0)));
  BOOST_CHECK((!(integer_index(0) >= integer_index(1))));
  BOOST_CHECK((integer_index(1) >= integer_index(0)));
  BOOST_CHECK((!(integer_index(0) >= integer_index())));
  BOOST_CHECK((integer_index() >= integer_index(0)));
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
