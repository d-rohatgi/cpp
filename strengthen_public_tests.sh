#!/usr/bin/env bash
set -euo pipefail

REPO="/Users/dhruvrohatgi/Documents/cpp"
cd "$REPO"

mkdir -p tests

cat > tests/week01_calculator_public_test.cpp <<'EOT'
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
EOT

cat > tests/week02_text_analyzer_public_test.cpp <<'EOT'
#include "course/week02_text_analyzer.hpp"

#include <gtest/gtest.h>

TEST(Week02TextAnalyzer, CountsBasicProperties) {
    const auto result = course::analyze_text("hello world");
    EXPECT_EQ(result.character_count, 11u);
    EXPECT_EQ(result.word_count, 2u);
    EXPECT_EQ(result.vowel_count, 3u);
    EXPECT_EQ(result.longest_word, "hello");
}

TEST(Week02TextAnalyzer, HandlesEmptyInput) {
    const auto result = course::analyze_text("");
    EXPECT_EQ(result.character_count, 0u);
    EXPECT_EQ(result.word_count, 0u);
    EXPECT_EQ(result.vowel_count, 0u);
    EXPECT_TRUE(result.longest_word.empty());
}

TEST(Week02TextAnalyzer, HandlesRepeatedSpaces) {
    const auto result = course::analyze_text("a    b");
    EXPECT_EQ(result.word_count, 2u);
}

TEST(Week02TextAnalyzer, CountsUppercaseVowels) {
    const auto result = course::analyze_text("AEIOU");
    EXPECT_EQ(result.vowel_count, 5u);
}

TEST(Week02TextAnalyzer, LeadingAndTrailingSpacesDoNotCreateWords) {
    const auto result = course::analyze_text("  hello world  ");
    EXPECT_EQ(result.word_count, 2u);
    EXPECT_EQ(result.longest_word, "hello");
}

TEST(Week02TextAnalyzer, AllSpacesProduceZeroWords) {
    const auto result = course::analyze_text("     ");
    EXPECT_EQ(result.character_count, 5u);
    EXPECT_EQ(result.word_count, 0u);
    EXPECT_EQ(result.vowel_count, 0u);
    EXPECT_TRUE(result.longest_word.empty());
}

TEST(Week02TextAnalyzer, TieKeepsFirstLongestWord) {
    const auto result = course::analyze_text("cat dog");
    EXPECT_EQ(result.longest_word, "cat");
}

TEST(Week02TextAnalyzer, CountsCharactersIncludingSpaces) {
    const auto result = course::analyze_text("a b");
    EXPECT_EQ(result.character_count, 3u);
}

TEST(Week02TextAnalyzer, PunctuationRemainsPartOfWordUnderWhitespaceRule) {
    const auto result = course::analyze_text("hi, there!");
    EXPECT_EQ(result.word_count, 2u);
    EXPECT_EQ(result.longest_word, "there!");
}

TEST(Week02TextAnalyzer, MixedCaseVowelsCountCorrectly) {
    const auto result = course::analyze_text("AbCdEf");
    EXPECT_EQ(result.vowel_count, 2u);
}
EOT

cat > tests/week03_bank_account_public_test.cpp <<'EOT'
#include "course/week03_bank_account.hpp"

#include <gtest/gtest.h>

TEST(Week03BankAccount, StoresOwnerAndBalance) {
    course::BankAccount account("Dhruv", 100.0);
    EXPECT_EQ(account.owner(), "Dhruv");
    EXPECT_DOUBLE_EQ(account.balance(), 100.0);
}

TEST(Week03BankAccount, NegativeInitialBalanceClampsToZero) {
    course::BankAccount account("Test", -50.0);
    EXPECT_DOUBLE_EQ(account.balance(), 0.0);
}

TEST(Week03BankAccount, DepositIncreasesBalance) {
    course::BankAccount account("Test", 10.0);
    EXPECT_TRUE(account.deposit(15.0));
    EXPECT_DOUBLE_EQ(account.balance(), 25.0);
}

TEST(Week03BankAccount, RejectsNegativeDeposit) {
    course::BankAccount account("Test", 10.0);
    EXPECT_FALSE(account.deposit(-1.0));
    EXPECT_DOUBLE_EQ(account.balance(), 10.0);
}

TEST(Week03BankAccount, RejectsZeroDeposit) {
    course::BankAccount account("Test", 10.0);
    EXPECT_FALSE(account.deposit(0.0));
    EXPECT_DOUBLE_EQ(account.balance(), 10.0);
}

TEST(Week03BankAccount, WithdrawDecreasesBalanceWhenValid) {
    course::BankAccount account("Test", 20.0);
    EXPECT_TRUE(account.withdraw(5.0));
    EXPECT_DOUBLE_EQ(account.balance(), 15.0);
}

TEST(Week03BankAccount, WithdrawRejectsTooLargeAmount) {
    course::BankAccount account("Test", 20.0);
    EXPECT_FALSE(account.withdraw(25.0));
    EXPECT_DOUBLE_EQ(account.balance(), 20.0);
}

TEST(Week03BankAccount, WithdrawRejectsNegativeAmount) {
    course::BankAccount account("Test", 20.0);
    EXPECT_FALSE(account.withdraw(-2.0));
    EXPECT_DOUBLE_EQ(account.balance(), 20.0);
}

TEST(Week03BankAccount, WithdrawExactBalanceReachesZero) {
    course::BankAccount account("Test", 20.0);
    EXPECT_TRUE(account.withdraw(20.0));
    EXPECT_DOUBLE_EQ(account.balance(), 0.0);
}

TEST(Week03BankAccount, SequenceOfOperationsMaintainsBalance) {
    course::BankAccount account("Test", 10.0);
    EXPECT_TRUE(account.deposit(5.0));
    EXPECT_TRUE(account.withdraw(3.0));
    EXPECT_FALSE(account.withdraw(100.0));
    EXPECT_DOUBLE_EQ(account.balance(), 12.0);
}
EOT

cat > tests/week04_expense_io_public_test.cpp <<'EOT'
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
EOT

cat > tests/week05_frequency_counter_public_test.cpp <<'EOT'
#include "course/week05_frequency_counter.hpp"

#include <gtest/gtest.h>

TEST(Week05FrequencyCounter, CountsSimpleWords) {
    const auto result = course::count_words("apple banana apple");
    ASSERT_FALSE(result.empty());
    EXPECT_EQ(result[0].first, "apple");
    EXPECT_EQ(result[0].second, 2);
}

TEST(Week05FrequencyCounter, TopKRespectsLimit) {
    const auto result = course::top_k_words("a a b b c", 2);
    EXPECT_LE(result.size(), 2u);
}

TEST(Week05FrequencyCounter, NormalizesCaseAndPunctuation) {
    const auto result = course::count_words("Apple apple, APPLE!");
    ASSERT_FALSE(result.empty());
    EXPECT_EQ(result[0].first, "apple");
    EXPECT_EQ(result[0].second, 3);
}

TEST(Week05FrequencyCounter, EmptyInputReturnsEmptyResult) {
    const auto result = course::count_words("");
    EXPECT_TRUE(result.empty());
}

TEST(Week05FrequencyCounter, PunctuationOnlyInputReturnsEmptyResult) {
    const auto result = course::count_words("!!! ???");
    EXPECT_TRUE(result.empty());
}

TEST(Week05FrequencyCounter, TieBreaksLexicographically) {
    const auto result = course::count_words("b a");
    ASSERT_EQ(result.size(), 2u);
    EXPECT_EQ(result[0].first, "a");
    EXPECT_EQ(result[0].second, 1);
    EXPECT_EQ(result[1].first, "b");
    EXPECT_EQ(result[1].second, 1);
}

TEST(Week05FrequencyCounter, TopKZeroReturnsEmpty) {
    const auto result = course::top_k_words("apple banana apple", 0);
    EXPECT_TRUE(result.empty());
}

TEST(Week05FrequencyCounter, AlphanumericTokensArePreserved) {
    const auto result = course::count_words("a1 a1 b2");
    ASSERT_FALSE(result.empty());
    EXPECT_EQ(result[0].first, "a1");
    EXPECT_EQ(result[0].second, 2);
}

TEST(Week05FrequencyCounter, WhitespaceOnlyReturnsEmpty) {
    const auto result = course::count_words("     ");
    EXPECT_TRUE(result.empty());
}
EOT

cat > tests/week06_linked_list_public_test.cpp <<'EOT'
#include "course/week06_linked_list.hpp"

#include <gtest/gtest.h>

TEST(Week06LinkedList, StartsEmpty) {
    course::LinkedList list;
    EXPECT_EQ(list.size(), 0u);
    EXPECT_FALSE(list.contains(1));
}

TEST(Week06LinkedList, PushFrontAddsElements) {
    course::LinkedList list;
    list.push_front(10);
    list.push_front(20);

    EXPECT_EQ(list.size(), 2u);
    EXPECT_TRUE(list.contains(10));
    EXPECT_TRUE(list.contains(20));
}

TEST(Week06LinkedList, ContainsReturnsFalseForMissingValue) {
    course::LinkedList list;
    list.push_front(10);
    EXPECT_FALSE(list.contains(99));
}

TEST(Week06LinkedList, ClearRemovesAllElements) {
    course::LinkedList list;
    list.push_front(1);
    list.push_front(2);
    list.clear();

    EXPECT_EQ(list.size(), 0u);
    EXPECT_FALSE(list.contains(1));
}

TEST(Week06LinkedList, RepeatedClearIsSafe) {
    course::LinkedList list;
    list.clear();
    list.clear();
    EXPECT_EQ(list.size(), 0u);
}

TEST(Week06LinkedList, PushAfterClearWorks) {
    course::LinkedList list;
    list.push_front(1);
    list.clear();
    list.push_front(2);

    EXPECT_EQ(list.size(), 1u);
    EXPECT_TRUE(list.contains(2));
    EXPECT_FALSE(list.contains(1));
}

TEST(Week06LinkedList, SizeTracksMultipleInsertions) {
    course::LinkedList list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    EXPECT_EQ(list.size(), 3u);
}
EOT

cat > tests/week07_vector_public_test.cpp <<'EOT'
#include "course/week07_vector.hpp"

#include <gtest/gtest.h>
#include <string>

namespace {
struct CountingValue {
    static inline int live_count = 0;
    int value = 0;

    explicit CountingValue(int v = 0) : value(v) { ++live_count; }
    CountingValue(const CountingValue& other) : value(other.value) { ++live_count; }
    CountingValue(CountingValue&& other) noexcept : value(other.value) { ++live_count; }
    ~CountingValue() { --live_count; }
};
}  // namespace

TEST(Week07Vector, StartsEmpty) {
    course::Vector<int> v;
    EXPECT_TRUE(v.empty());
    EXPECT_EQ(v.size(), 0u);
}

TEST(Week07Vector, PushBackStoresElementsInOrder) {
    course::Vector<int> v;
    v.push_back(10);
    v.push_back(20);
    ASSERT_EQ(v.size(), 2u);
    EXPECT_EQ(v[0], 10);
    EXPECT_EQ(v[1], 20);
}

TEST(Week07Vector, ReserveDoesNotChangeSizeAndPreservesElements) {
    course::Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.reserve(32);
    EXPECT_EQ(v.size(), 2u);
    EXPECT_GE(v.capacity(), 32u);
    EXPECT_EQ(v[0], 1);
    EXPECT_EQ(v[1], 2);
}

TEST(Week07Vector, ReserveBelowCurrentCapacityDoesNotLoseElements) {
    course::Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    const auto old_capacity = v.capacity();
    v.reserve(1);
    EXPECT_EQ(v.size(), 2u);
    EXPECT_GE(v.capacity(), 2u);
    EXPECT_EQ(v[0], 1);
    EXPECT_EQ(v[1], 2);
    EXPECT_GE(v.capacity(), old_capacity == 0 ? 2u : 0u);
}

TEST(Week07Vector, PopBackShrinksSize) {
    course::Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.pop_back();
    EXPECT_EQ(v.size(), 1u);
    EXPECT_EQ(v[0], 1);
}

TEST(Week07Vector, AtThrowsOutOfRange) {
    course::Vector<int> v;
    v.push_back(1);
    EXPECT_THROW(v.at(1), std::out_of_range);
}

TEST(Week07Vector, ClearDestroysElementsAndContainerRemainsUsable) {
    {
        course::Vector<CountingValue> v;
        v.push_back(CountingValue{1});
        v.push_back(CountingValue{2});
        v.clear();
        EXPECT_EQ(v.size(), 0u);
        v.push_back(CountingValue{3});
        EXPECT_EQ(v.size(), 1u);
    }
    EXPECT_EQ(CountingValue::live_count, 0);
}

TEST(Week07Vector, CopyCreatesIndependentContainer) {
    course::Vector<std::string> a;
    a.push_back("alpha");
    a.push_back("beta");

    course::Vector<std::string> b(a);
    b[0] = "changed";

    EXPECT_EQ(a[0], "alpha");
    EXPECT_EQ(b[0], "changed");
}

TEST(Week07Vector, CopyAssignmentCreatesIndependentContainer) {
    course::Vector<std::string> a;
    a.push_back("x");
    a.push_back("y");

    course::Vector<std::string> b;
    b = a;
    b[1] = "changed";

    EXPECT_EQ(a[1], "y");
    EXPECT_EQ(b[1], "changed");
}

TEST(Week07Vector, MoveLeavesSourceValid) {
    course::Vector<std::string> a;
    a.push_back("x");
    a.push_back("y");

    course::Vector<std::string> b(std::move(a));

    EXPECT_EQ(b.size(), 2u);
    EXPECT_EQ(b[0], "x");
    EXPECT_EQ(b[1], "y");
    EXPECT_TRUE(a.empty() || a.size() == 0u);
}

TEST(Week07Vector, MoveAssignmentLeavesSourceValid) {
    course::Vector<std::string> a;
    a.push_back("left");
    a.push_back("right");

    course::Vector<std::string> b;
    b = std::move(a);

    EXPECT_EQ(b.size(), 2u);
    EXPECT_EQ(b[0], "left");
    EXPECT_EQ(b[1], "right");
    EXPECT_TRUE(a.empty() || a.size() == 0u);
}
EOT

cat > tests/week08_smart_pointers_public_test.cpp <<'EOT'
#include "course/week08_shared_ptr.hpp"
#include "course/week08_unique_ptr.hpp"

#include <gtest/gtest.h>

namespace {
struct Counter {
    static inline int destructions = 0;
    int value = 0;

    explicit Counter(int v = 0) : value(v) {}
    ~Counter() { ++destructions; }
};
}  // namespace

TEST(Week08UniquePtr, OwnsRawPointer) {
    auto* raw = new Counter(7);
    course::UniquePtr<Counter> ptr(raw);

    ASSERT_NE(ptr.get(), nullptr);
    EXPECT_EQ(ptr->value, 7);
}

TEST(Week08UniquePtr, ReleaseReturnsRawPointerAndNullsOwner) {
    course::UniquePtr<Counter> ptr(new Counter(3));
    Counter* raw = ptr.release();

    ASSERT_NE(raw, nullptr);
    EXPECT_EQ(ptr.get(), nullptr);
    delete raw;
}

TEST(Week08UniquePtr, ResetCanPointToNewObject) {
    course::UniquePtr<Counter> ptr;
    ptr.reset(new Counter(9));
    ASSERT_NE(ptr.get(), nullptr);
    EXPECT_EQ(ptr->value, 9);
}

TEST(Week08UniquePtr, MoveConstructorTransfersOwnership) {
    course::UniquePtr<Counter> a(new Counter(5));
    course::UniquePtr<Counter> b(std::move(a));

    EXPECT_EQ(a.get(), nullptr);
    ASSERT_NE(b.get(), nullptr);
    EXPECT_EQ(b->value, 5);
}

TEST(Week08UniquePtr, MoveAssignmentTransfersOwnership) {
    course::UniquePtr<Counter> a(new Counter(6));
    course::UniquePtr<Counter> b;
    b = std::move(a);

    EXPECT_EQ(a.get(), nullptr);
    ASSERT_NE(b.get(), nullptr);
    EXPECT_EQ(b->value, 6);
}

TEST(Week08UniquePtr, ResetDeletesOldObject) {
    Counter::destructions = 0;
    {
        course::UniquePtr<Counter> ptr(new Counter(1));
        ptr.reset(new Counter(2));
    }
    EXPECT_GE(Counter::destructions, 2);
}

TEST(Week08SharedPtr, DefaultConstructionIsNull) {
    course::SharedPtr<Counter> ptr;
    EXPECT_EQ(ptr.get(), nullptr);
    EXPECT_EQ(ptr.use_count(), 0u);
}

TEST(Week08SharedPtr, StartsWithUseCountOne) {
    course::SharedPtr<Counter> ptr(new Counter(11));
    EXPECT_EQ(ptr.use_count(), 1u);
    EXPECT_EQ(ptr->value, 11);
}

TEST(Week08SharedPtr, CopyIncrementsUseCount) {
    course::SharedPtr<Counter> a(new Counter(1));
    course::SharedPtr<Counter> b(a);

    EXPECT_EQ(a.use_count(), 2u);
    EXPECT_EQ(b.use_count(), 2u);
}

TEST(Week08SharedPtr, CopyAssignmentIncrementsUseCount) {
    course::SharedPtr<Counter> a(new Counter(3));
    course::SharedPtr<Counter> b;
    b = a;

    EXPECT_EQ(a.use_count(), 2u);
    EXPECT_EQ(b.use_count(), 2u);
}

TEST(Week08SharedPtr, NestedScopeDropsCountBackDown) {
    course::SharedPtr<Counter> a(new Counter(4));
    {
        course::SharedPtr<Counter> b(a);
        EXPECT_EQ(a.use_count(), 2u);
        EXPECT_EQ(b.use_count(), 2u);
    }
    EXPECT_EQ(a.use_count(), 1u);
}

TEST(Week08SharedPtr, MoveConstructorTransfersOwnership) {
    course::SharedPtr<Counter> a(new Counter(5));
    course::SharedPtr<Counter> b(std::move(a));

    EXPECT_EQ(a.get(), nullptr);
    EXPECT_EQ(a.use_count(), 0u);
    ASSERT_NE(b.get(), nullptr);
    EXPECT_EQ(b.use_count(), 1u);
}

TEST(Week08SharedPtr, ResetCanDropOwnership) {
    Counter::destructions = 0;
    {
        course::SharedPtr<Counter> ptr(new Counter(9));
        ptr.reset();
        EXPECT_EQ(ptr.get(), nullptr);
        EXPECT_EQ(ptr.use_count(), 0u);
    }
    EXPECT_GE(Counter::destructions, 1);
}
EOT

echo "Stronger public tests written."
echo "Now run:"
echo "  cd $REPO"
echo "  cmake --build build"
echo "  ctest --test-dir build --output-on-failure"
