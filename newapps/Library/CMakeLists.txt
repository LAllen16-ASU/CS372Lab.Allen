cmake_minimum_required(VERSION 3.14)
project(Library LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add your source files here
add_executable(Library main.cpp)

# Enable testing
enable_testing()

# Download and link GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Add your test source files here
add_executable(MyProjectTests test_main.cpp VectorTest.cpp)

target_link_libraries(MyProjectTests
  PRIVATE
    gtest_main
)

add_test(NAME MyProjectTests COMMAND MyProjectTests)