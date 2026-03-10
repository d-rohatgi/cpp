cmake_minimum_required(VERSION 3.20)
project(cs290_elite_cpp_systems_professor_edition LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(ENABLE_TESTS "Build tests" ON)
option(ENABLE_BENCHMARKS "Build benchmarks" ON)
option(ENABLE_SANITIZERS "Enable ASan/UBSan" OFF)

include(cmake/Sanitizers.cmake)

if(ENABLE_SANITIZERS)
  enable_sanitizers()
endif()

include(FetchContent)

if(ENABLE_TESTS)
  FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
  )
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
  FetchContent_MakeAvailable(googletest)
  enable_testing()
endif()

if(ENABLE_BENCHMARKS)
  FetchContent_Declare(
    googlebenchmark
    URL https://github.com/google/benchmark/archive/refs/tags/v1.8.3.zip
  )
  set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "" FORCE)
  FetchContent_MakeAvailable(googlebenchmark)
endif()

add_library(course_core
  src/graph.cpp
)
target_include_directories(course_core PUBLIC include)

if(ENABLE_TESTS)
  add_executable(public_tests
    tests/vector_public_test.cpp
    tests/smart_pointers_public_test.cpp
    tests/algorithms_public_test.cpp
    tests/hashmap_public_test.cpp
    tests/lru_cache_public_test.cpp
    tests/graph_public_test.cpp
  )
  target_link_libraries(public_tests PRIVATE course_core GTest::gtest_main)
  include(GoogleTest)
  gtest_discover_tests(public_tests)
endif()

if(ENABLE_BENCHMARKS)
  add_executable(vector_bench benchmarks/vector_bench.cpp)
  target_link_libraries(vector_bench PRIVATE course_core benchmark::benchmark)

  add_executable(hashmap_bench benchmarks/hashmap_bench.cpp)
  target_link_libraries(hashmap_bench PRIVATE course_core benchmark::benchmark)
endif()
