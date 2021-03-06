#define BOOST_TEST_MODULE test_main
#include <boost/test/included/unit_test.hpp>

#include "ip_filter.h"

BOOST_AUTO_TEST_SUITE(test_suite_main)

BOOST_AUTO_TEST_CASE(test_split) {
    BOOST_CHECK( split( "aaaa\taaa\taa\ta", '\t') == std::vector<std::string>({ "aaaa", "aaa", "aa", "a"}) );
    BOOST_CHECK( split(".." , '.') == std::vector<std::string>({"", "", "" }) );
    BOOST_CHECK( split("aa.aa." , '.') == std::vector<std::string>({"aa", "aa", "" }) );
    BOOST_CHECK( split(".aa.aa" , '.') == std::vector<std::string>({"", "aa", "aa" }) );
    BOOST_CHECK( split("aa..aa" , '.') == std::vector<std::string>({"aa", "", "aa" }) );
    BOOST_CHECK( split("aa" , '.') == std::vector<std::string>({"aa" }) );
    BOOST_CHECK( split("" , '.') == std::vector<std::string>({"" }) );
}

BOOST_AUTO_TEST_CASE(test_getIP) {
    BOOST_CHECK( getIP("221.22.45.31") == ip_adress({ 221, 22, 45, 31}) );

    BOOST_CHECK_THROW(getIP("121.322.45.71"),  std::invalid_argument);
    BOOST_CHECK_THROW(getIP("240.234.121.22.56.78"),  std::length_error);
    BOOST_CHECK_THROW(getIP("240.234"),  std::length_error);
}

BOOST_AUTO_TEST_SUITE_END()
