add_executable(test)
target_sources(test PRIVATE test.cpp)
target_include_directories(test PUBLIC "${CMAKE_SOURCE_DIR}/include")
target_link_libraries(test PRIVATE Eigen3::Eigen nctorus_warnings)
