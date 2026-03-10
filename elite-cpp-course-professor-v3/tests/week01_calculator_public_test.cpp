#include "course/week01_calculator.hpp"

#include <gtest/gtest.h>
#include <stdexcept>

TEST(Week01Calculator, AddsNumbers) {
    EXPECT_DOUBLE_EQ(course::calculate(2.0, 3.0, '+'), 5.0);
}

TEST(Week01Calculator, MultipliesNumbers) {
    EXPECT_DOUBLE_EQ(course::calculate(4.0, 5.0, '*'), 20.0);
}

TEST(Week01Calculator, DivisionByZeroThrows) {
    EXPECT_THROW(course::calculate(8.0, 0.0, '/'), std::runtime_error);
}

TEST(Week01Calculator, InvalidOperatorThrows) {
    EXPECT_THROW(course::calculate(8.0, 2.0, '?'), std::runtime_error);
}
