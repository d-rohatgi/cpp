#include "course/week01_calculator.hpp"

#include <gtest/gtest.h>
#include <stdexcept>

TEST(Week01Calculator, AddsNumbers) {
    EXPECT_DOUBLE_EQ(course::calculate(2.0, 3.0, '+'), 5.0);
}

TEST(Week01Calculator, SubtractsNumbers) {
    EXPECT_DOUBLE_EQ(course::calculate(10.0, 4.0, '-'), 6.0);
}

TEST(Week01Calculator, MultipliesNumbers) {
    EXPECT_DOUBLE_EQ(course::calculate(4.0, 5.0, '*'), 20.0);
}

TEST(Week01Calculator, DividesNumbers) {
    EXPECT_DOUBLE_EQ(course::calculate(8.0, 2.0, '/'), 4.0);
}

TEST(Week01Calculator, DivisionByZeroThrows) {
    EXPECT_THROW(course::calculate(8.0, 0.0, '/'), std::runtime_error);
}

TEST(Week01Calculator, InvalidOperatorThrows) {
    EXPECT_THROW(course::calculate(8.0, 2.0, '?'), std::runtime_error);
}

TEST(Week01Calculator, SupportsNegativeInputs) {
    EXPECT_DOUBLE_EQ(course::calculate(-3.0, 2.0, '+'), -1.0);
}

TEST(Week01Calculator, SupportsDecimalInputs) {
    EXPECT_DOUBLE_EQ(course::calculate(2.5, 4.0, '*'), 10.0);
}

TEST(Week01Calculator, ZeroNumeratorDivisionReturnsZero) {
    EXPECT_DOUBLE_EQ(course::calculate(0.0, 5.0, '/'), 0.0);
}

TEST(Week01Calculator, DoubleNegativeSubtractionWorks) {
    EXPECT_DOUBLE_EQ(course::calculate(-2.0, -3.0, '-'), 1.0);
}
