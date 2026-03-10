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
