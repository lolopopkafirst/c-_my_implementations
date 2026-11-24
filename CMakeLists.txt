
cmake_minimum_required(VERSION 3.20)

project(LRUCache LANGUAGES CXX)

# C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# LRU Cache library
add_library(lru_cache STATIC
    src/LRU.cpp
)

target_include_directories(lru_cache
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# GoogleTest
include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.17.0
)

FetchContent_MakeAvailable(googletest)

# Unit tests
enable_testing()

add_executable(lru_tests
    tests/LRUCacheTest.cpp
)

target_link_libraries(lru_tests
    PRIVATE
        lru_cache
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(lru_tests)
