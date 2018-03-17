cmake_minimum_required(VERSION 3.2)

project(ip_filter VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

add_executable(ip_filter_cli ip_filter.h main.cpp)

add_executable(test_ip_filter_cli ip_filter.h ip_filter_test.cpp)

set_target_properties(ip_filter_cli test_ip_filter_cli PROPERTIES
	CXX_STANDARD 14
	CXX_STANDARD_REQUIRED ON
	COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)

set_target_properties(test_ip_filter_cli PROPERTIES
	COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
	INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

target_link_libraries(test_ip_filter_cli
	${Boost_LIBRARIES}
)

install(TARGETS ip_filter_cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT lex9612@gmail.com)

include(CPack)

enable_testing()

add_test(test_split test_ip_filter_cli)

add_test(test_getIP test_ip_filter_cli)

