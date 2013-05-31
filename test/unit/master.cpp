//  (C) Copyright Cryolite 2012, 2013. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_MODULE master
#include <boost/test/unit_test.hpp>

#include <fstream>
#include <iostream>
#include <string>
#include <memory>
#include <stdexcept>
#include <cstddef>

namespace{

class GlobalFixture
{
public:
  GlobalFixture()
    : p_log_stream_()
  {
    std::size_t const argc
      = boost::unit_test::framework::master_test_suite().argc;
    char const * const * const argv
      = boost::unit_test::framework::master_test_suite().argv;
    if (argc != 2u) {
      throw std::runtime_error(
        "an invalid number of arguments passed to the unit test module");
    }
    if (argv[1u] == std::string("--xunit-log-format=hrf")) {
      // Do nothing.
    }
    else if (argv[1u] == std::string("--xunit-log-format=xml")) {
      std::string log_file_path(argv[0u]);
      log_file_path += ".xml" ;
      p_log_stream_.reset(new std::ofstream(log_file_path.c_str()));
      boost::unit_test::unit_test_log.set_stream(*p_log_stream_);
    }
    else {
      throw std::runtime_error("an unknown command-line option");
    }
  }

  ~GlobalFixture()
  {
    if (p_log_stream_) {
      *p_log_stream_ << "</TestLog>" << std::flush;
      boost::unit_test::unit_test_log.set_stream(std::cout);
    }
  }

private:
  std::shared_ptr<std::ostream> p_log_stream_;
};

} // namespace `unnamed'

BOOST_GLOBAL_FIXTURE(GlobalFixture)
