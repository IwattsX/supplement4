cmake_minimum_required(VERSION 3.14)
project(my_project)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directory for header files
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add your library
add_library(csvLib src/source.cpp)

# GoogleTest setup using FetchContent
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# Prevent Windows-specific overrides
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Enable testing
enable_testing()

# Add test executables
add_executable(file_test tests/test_csv_file.cc)
target_link_libraries(file_test csvLib GTest::gtest_main)

# Use gtest_discover_tests for each test executable
include(GoogleTest)
gtest_discover_tests(file_test)
