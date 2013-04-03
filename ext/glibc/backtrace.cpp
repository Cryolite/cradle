#include <string>
#include <cstdlib>
#include <execinfo.h>


int main()
{
  int const backtrace_max_size = 256;
  void *p_backtrace[backtrace_max_size];
  int const backtrace_size = backtrace(p_backtrace, backtrace_max_size);
  char * * const symbols
    = backtrace_symbols(p_backtrace, backtrace_size);
  try {
    for (int i = 0; i < backtrace_size; ++i) {
      std::string symbol = symbols[i];
    }
  }
  catch (...) {
    std::free(symbols);
    return EXIT_FAILURE;
  }
  std::free(symbols);
  return EXIT_SUCCESS;
}
