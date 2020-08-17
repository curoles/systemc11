enable_testing()

include_directories(.)
include_directories(${SYSTEMC_INCLUDE_DIR})

set(CMAKE_CXX_FLAGS "-Werror -Wall -Wextra")

add_executable(test1 test/test1.cpp)
target_link_libraries(test1 ${SYSTEMC_LIB_DIR}/libsystemc.so)
add_test(NAME test1 COMMAND test1)

add_executable(test_nand test/test_nand.cpp)
target_link_libraries(test_nand ${SYSTEMC_LIB_DIR}/libsystemc.so)
add_test(NAME test_nand COMMAND test_nand)
