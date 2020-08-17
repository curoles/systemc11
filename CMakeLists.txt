cmake_minimum_required(VERSION 3.3)

project(systemc11 CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(external_systemc.cmake)

ExternalProject_Get_property(systemc INSTALL_DIR)
set(SYSTEMC_LIB_DIR ${INSTALL_DIR}/lib)
set(SYSTEMC_INCLUDE_DIR ${INSTALL_DIR}/include)
message("SystemC install dir: ${INSTALL_DIR}")

include(test/test.cmake)

