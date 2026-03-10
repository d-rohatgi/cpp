cmake_minimum_required(VERSION 3.20)
project(cs290_elite_cpp_professor_v3 LANGUAGES CXX)

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
  src/week01_calculator.cpp
  src/week02_text_analyzer.cpp
  src/week03_bank_account.cpp
  src/week04_expense_io.cpp
  src/week05_frequency_counter.cpp
  src/week06_linked_list.cpp
  src/week08_shared_ptr_dummy.cpp
)
target_include_directories(course_core PUBLIC include)

if(ENABLE_TESTS)
  add_executable(public_tests
    tests/week01_calculator_public_test.cpp
    tests/week02_text_analyzer_public_test.cpp
    tests/week03_bank_account_public_test.cpp
    tests/week04_expense_io_public_test.cpp
    tests/week05_frequency_counter_public_test.cpp
    tests/week06_linked_list_public_test.cpp
    tests/week07_vector_public_test.cpp
    tests/week08_smart_pointers_public_test.cpp
  )
  target_link_libraries(public_tests PRIVATE course_core GTest::gtest_main)
  include(GoogleTest)
  gtest_discover_tests(public_tests)
endif()

if(ENABLE_BENCHMARKS)
  add_executable(week05_frequency_counter_bench benchmarks/week05_frequency_counter_bench.cpp)
  target_link_libraries(week05_frequency_counter_bench PRIVATE course_core benchmark::benchmark)

  add_executable(week07_vector_bench benchmarks/week07_vector_bench.cpp)
  target_link_libraries(week07_vector_bench PRIVATE course_core benchmark::benchmark)
endif()
