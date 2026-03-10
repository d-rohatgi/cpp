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

TEST(Week02TextAnalyzer, LongestWordTracksSimplePunctuationScenario) {
    const auto result = course::analyze_text("hi there");
    EXPECT_EQ(result.longest_word, "there");
}
