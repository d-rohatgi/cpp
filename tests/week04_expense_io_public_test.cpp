#include "course/week04_expense_io.hpp"

#include <gtest/gtest.h>
#include <vector>

TEST(Week04ExpenseIO, ParsesValidExpenseLine) {
    auto parsed = course::parse_expense_line("food,12.50");
    ASSERT_TRUE(parsed.has_value());
    EXPECT_EQ(parsed->category, "food");
    EXPECT_DOUBLE_EQ(parsed->amount, 12.50);
}

TEST(Week04ExpenseIO, RejectsMalformedLineNoDelimiter) {
    auto parsed = course::parse_expense_line("food-only");
    EXPECT_FALSE(parsed.has_value());
}

TEST(Week04ExpenseIO, RejectsTooManyFields) {
    auto parsed = course::parse_expense_line("food,12.50,extra");
    EXPECT_FALSE(parsed.has_value());
}

TEST(Week04ExpenseIO, RejectsEmptyCategory) {
    auto parsed = course::parse_expense_line(",12.50");
    EXPECT_FALSE(parsed.has_value());
}

TEST(Week04ExpenseIO, RejectsMissingAmount) {
    auto parsed = course::parse_expense_line("food,");
    EXPECT_FALSE(parsed.has_value());
}

TEST(Week04ExpenseIO, RejectsInvalidNumericAmount) {
    auto parsed = course::parse_expense_line("food,abc");
    EXPECT_FALSE(parsed.has_value());
}

TEST(Week04ExpenseIO, RejectsNumericWithTrailingGarbage) {
    auto parsed = course::parse_expense_line("food,12.50abc");
    EXPECT_FALSE(parsed.has_value());
}

TEST(Week04ExpenseIO, TotalsAmounts) {
    std::vector<course::Expense> expenses{
        {"food", 10.0},
        {"rent", 100.0},
        {"coffee", 5.5},
    };
    EXPECT_DOUBLE_EQ(course::total_amount(expenses), 115.5);
}

TEST(Week04ExpenseIO, EmptyExpenseListTotalsToZero) {
    std::vector<course::Expense> expenses;
    EXPECT_DOUBLE_EQ(course::total_amount(expenses), 0.0);
}

TEST(Week04ExpenseIO, SingleExpenseTotalsCorrectly) {
    std::vector<course::Expense> expenses{
        {"food", 7.25},
    };
    EXPECT_DOUBLE_EQ(course::total_amount(expenses), 7.25);
}
