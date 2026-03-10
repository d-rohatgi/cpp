#include "course/week02_text_analyzer.hpp"

#include <gtest/gtest.h>
#include <string>

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
