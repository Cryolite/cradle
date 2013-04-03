#include <cxxabi.h>
#include <cstdlib>


namespace __cxxabiv1{

struct __cxa_exception;

struct __cxa_eh_globals
{
  __cxa_exception *caughtExceptions;
  unsigned int uncaughtExceptions;
};

} // namespace __cxxabiv1

namespace {

class C
{
public:
  explicit C(unsigned int n)
    : n_(n)
  {}

  ~C()
  {
    unsigned int n = __cxxabiv1::__cxa_get_globals()->uncaughtExceptions;
    if (n != n_) {
      std::abort();
    }
    if (n >= 10u) {
      return;
    }
    try {
      C c(n_ + 1);
      throw 0;
    }
    catch (...) {
      n = __cxxabiv1::__cxa_get_globals()->uncaughtExceptions;
      if (n != n_) {
        std::abort();
      }
    }
    n = __cxxabiv1::__cxa_get_globals()->uncaughtExceptions;
    if (n != n_) {
      std::abort();
    }
  }

private:
  unsigned int n_;
}; // class C

} // namespace `unnamed'

int main()
{
  unsigned int n = __cxxabiv1::__cxa_get_globals()->uncaughtExceptions;
  if (n != 0u) {
    std::abort();
  }
  try {
    C c(1u);
    throw 0;
  }
  catch (...) {
    n = __cxxabiv1::__cxa_get_globals()->uncaughtExceptions;
    if (n != 0u) {
      std::abort();
    }
  }
  n = __cxxabiv1::__cxa_get_globals()->uncaughtExceptions;
  if (n != 0u) {
    std::abort();
  }
  return EXIT_SUCCESS;
}
