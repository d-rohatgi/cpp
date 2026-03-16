#include "course/week02_text_analyzer.hpp"
#include <cctype>

namespace course {

bool is_vowel(char text_char){
    char char_lower = static_cast<char>(std::tolower(static_cast<unsigned char>(text_char))); 
    if ( char_lower == 'a' || char_lower == 'e' || char_lower == 'i'|| char_lower == 'o' || char_lower == 'u'){
        return true;
    }
    else{
        return false;
    }
}

bool is_space(char text_char){
    return text_char == ' ';
}

TextAnalysis analyze_text(const std::string& text) {
    TextAnalysis result;
    std::size_t longest_word_length = 0;
    std::size_t curr_word_length = 0 ;
    std::string curr_word = "";
    for(char c: text){
        ++result.character_count;
        if (is_space(c)){
            if (curr_word_length > longest_word_length){
                longest_word_length = curr_word_length;
                result.longest_word = curr_word;
            }
            if (curr_word_length > 0){
                ++result.word_count;
            }
            curr_word_length = 0;
            curr_word = "";
            continue;
        }
        ++curr_word_length;
        curr_word += c;
        if (is_vowel(c)){
            ++result.vowel_count;
        }
        
    }
    if (curr_word_length > longest_word_length){
        longest_word_length = curr_word_length;
        result.longest_word = curr_word;
    }
    if (curr_word_length > 0){
        ++result.word_count;
    }
    return result;
}

}  // namespace course
