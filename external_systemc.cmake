include(ExternalProject)

ExternalProject_Add(systemc
    PREFIX systemc_dir
    GIT_REPOSITORY https://github.com/yoshijava/systemc-2.3.3
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_BINARY_DIR}/systemc_dir -DCMAKE_CXX_STANDARD=${CMAKE_CXX_STANDARD}
    BUILD_COMMAND make -j
    UPDATE_COMMAND ""
)

#ExternalProject_Add(systemc
#    PREFIX systemc_dir
#    GIT_REPOSITORY https://github.com/systemc/systemc-2.3
#    CONFIGURE_COMMAND ${CMAKE_CURRENT_BINARY_DIR}/systemc_dir/src/systemc/configure --prefix=${CMAKE_CURRENT_BINARY_DIR}/systemc_dir
#    BUILD_COMMAND make -j
#    INSTALL_COMMAND make install
#    UPDATE_COMMAND ""
#)
