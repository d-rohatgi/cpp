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
