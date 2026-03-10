#pragma once

#include <string>

namespace course {

struct TextAnalysis {
    std::size_t character_count = 0;
    std::size_t word_count = 0;
    std::size_t vowel_count = 0;
    std::string longest_word;
};

TextAnalysis analyze_text(const std::string& text);

}  // namespace course
