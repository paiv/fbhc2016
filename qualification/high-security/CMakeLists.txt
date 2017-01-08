cmake_minimum_required(VERSION 3.2)
project(high_security)

add_executable(highsec main.cpp)

set_property(TARGET highsec PROPERTY CXX_STANDARD 11)

set(TESTS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/tests")
set(TESTS_COMMAND "${CMAKE_CURRENT_BINARY_DIR}/highsec")
configure_file(tests/runner.py.in tests_runner.py @ONLY)
