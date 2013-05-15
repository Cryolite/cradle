#include <cradle/scope_guard/scope_guard.hpp>

class C
{
  CRADLE_SCOPE_GUARD{
    int i = 0;
  };
};
