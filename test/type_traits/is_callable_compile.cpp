#include <cradle/type_traits/is_callable.hpp>

#include <memory>

namespace{

struct S
{};

}

static_assert(!cradle::is_callable<void (S::*)()>::value, "");
static_assert(cradle::is_callable<void (S::*)(), S &>::value, "");
static_assert(!cradle::is_callable<void (S::*)(), S const &>::value, "");
static_assert(cradle::is_callable<void (S::*)(), S &&>::value, "");
static_assert(cradle::is_callable<void (S::*)(), S *>::value, "");
static_assert(!cradle::is_callable<void (S::*)(), S const *>::value, "");
static_assert(cradle::is_callable<void (S::*)(), std::unique_ptr<S> >::value, "");
static_assert(!cradle::is_callable<void (S::*)(), std::unique_ptr<S const> >::value, "");
static_assert(!cradle::is_callable<void (S::*)(), S &, int>::value, "");

static_assert(!cradle::is_callable<void (S::*)() const>::value, "");
static_assert(cradle::is_callable<void (S::*)() const, S &>::value, "");
static_assert(cradle::is_callable<void (S::*)() const, S const &>::value, "");
static_assert(cradle::is_callable<void (S::*)() const, S &&>::value, "");
static_assert(cradle::is_callable<void (S::*)() const, S *>::value, "");
static_assert(cradle::is_callable<void (S::*)() const, S const *>::value, "");
static_assert(cradle::is_callable<void (S::*)() const, std::unique_ptr<S> >::value, "");
static_assert(cradle::is_callable<void (S::*)() const, std::unique_ptr<S const> >::value, "");
static_assert(!cradle::is_callable<void (S::*)() const, S &, int>::value, "");

static_assert(cradle::is_callable<int (S::*)(), S &>::value, "");
static_assert(cradle::is_callable<int &(S::*)(), S &>::value, "");
static_assert(cradle::is_callable<int const &(S::*)(), S &>::value, "");
static_assert(cradle::is_callable<int &&(S::*)(), S &>::value, "");

namespace{

struct NonCopyConstructible
{
  NonCopyConstructible(NonCopyConstructible const &) = delete;
};

}

static_assert(!cradle::is_callable<NonCopyConstructible (S::*)(), S &>::value, "");
static_assert(cradle::is_callable<NonCopyConstructible &(S::*)(), S &>::value, "");
static_assert(cradle::is_callable<NonCopyConstructible const &(S::*)(), S &>::value, "");
static_assert(cradle::is_callable<NonCopyConstructible &&(S::*)(), S &>::value, "");

static_assert(cradle::is_callable<std::unique_ptr<int> (S::*)(), S &>::value, "");
static_assert(cradle::is_callable<std::unique_ptr<int> &(S::*)(), S &>::value, "");
static_assert(cradle::is_callable<std::unique_ptr<int> const &(S::*)(), S &>::value, "");
static_assert(cradle::is_callable<std::unique_ptr<int> &&(S::*)(), S &>::value, "");

static_assert(cradle::is_callable<void (S::*)(int), S &, int &>::value, "");
static_assert(cradle::is_callable<void (S::*)(int), S &, int const &>::value, "");
static_assert(cradle::is_callable<void (S::*)(int), S &, int &&>::value, "");

static_assert(cradle::is_callable<void (S::*)(int &), S &, int &>::value, "");
static_assert(!cradle::is_callable<void (S::*)(int &), S &, int const &>::value, "");
static_assert(!cradle::is_callable<void (S::*)(int &), S &, int &&>::value, "");

static_assert(cradle::is_callable<void (S::*)(int const &), S &, int &>::value, "");
static_assert(cradle::is_callable<void (S::*)(int const &), S &, int const &>::value, "");
static_assert(cradle::is_callable<void (S::*)(int const &), S &, int &&>::value, "");

static_assert(!cradle::is_callable<void (S::*)(int &&), S &, int &>::value, "");
static_assert(!cradle::is_callable<void (S::*)(int &&), S &, int const &>::value, "");
static_assert(cradle::is_callable<void (S::*)(int &&), S &, int &&>::value, "");

static_assert(!cradle::is_callable<void (S::*)(std::unique_ptr<int>), S &, std::unique_ptr<int> &>::value, "");
static_assert(!cradle::is_callable<void (S::*)(std::unique_ptr<int>), S &, std::unique_ptr<int> const &>::value, "");
static_assert(cradle::is_callable<void (S::*)(std::unique_ptr<int>), S &, std::unique_ptr<int> &&>::value, "");

static_assert(cradle::is_callable<void (S::*)(std::unique_ptr<int> &), S &, std::unique_ptr<int> &>::value, "");
static_assert(!cradle::is_callable<void (S::*)(std::unique_ptr<int> &), S &, std::unique_ptr<int> const &>::value, "");
static_assert(!cradle::is_callable<void (S::*)(std::unique_ptr<int> &), S &, std::unique_ptr<int> &&>::value, "");

static_assert(cradle::is_callable<void (S::*)(std::unique_ptr<int> const &), S &, std::unique_ptr<int> &>::value, "");
static_assert(cradle::is_callable<void (S::*)(std::unique_ptr<int> const &), S &, std::unique_ptr<int> const &>::value, "");
static_assert(cradle::is_callable<void (S::*)(std::unique_ptr<int> const &), S &, std::unique_ptr<int> &&>::value, "");

static_assert(!cradle::is_callable<void (S::*)(std::unique_ptr<int> &&), S &, std::unique_ptr<int> &>::value, "");
static_assert(!cradle::is_callable<void (S::*)(std::unique_ptr<int> &&), S &, std::unique_ptr<int> const &>::value, "");
static_assert(cradle::is_callable<void (S::*)(std::unique_ptr<int> &&), S &, std::unique_ptr<int> &&>::value, "");


static_assert(cradle::is_callable<int S::*, S &>::value, "");
static_assert(cradle::is_callable<int S::*, S const &>::value, "");
static_assert(cradle::is_callable<int S::*, S &&>::value, "");
static_assert(cradle::is_callable<int S::*, S *>::value, "");
static_assert(cradle::is_callable<int S::*, S const *>::value, "");
static_assert(cradle::is_callable<int S::*, std::unique_ptr<S> >::value, "");
static_assert(cradle::is_callable<int S::*, std::unique_ptr<S const> >::value, "");

static_assert(cradle::is_callable<std::unique_ptr<int> S::*, S &>::value, "");
static_assert(cradle::is_callable<std::unique_ptr<int> S::*, S const &>::value, "");

static_assert(cradle::is_callable<NonCopyConstructible S::*, S &>::value, "");
static_assert(cradle::is_callable<NonCopyConstructible S::*, S const &>::value, "");


static_assert(cradle::is_callable<void (*)()>::value, "");
static_assert(cradle::is_callable<void (&)()>::value, "");
