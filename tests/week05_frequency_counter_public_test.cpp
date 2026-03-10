#include "course/frequency_counter.hpp"

#include <gtest/gtest.h>

TEST(FrequencyCounterPublicTest, CountsSimpleWords) {
    const auto result = course::count_words("apple banana apple");
    ASSERT_FALSE(result.empty());
    EXPECT_EQ(result[0].first, "apple");
    EXPECT_EQ(result[0].second, 2);
}

TEST(FrequencyCounterPublicTest, TopKRespectsLimit) {
    const auto result = course::top_k_words("a a b b c", 2);
    EXPECT_LE(result.size(), 2u);
}
