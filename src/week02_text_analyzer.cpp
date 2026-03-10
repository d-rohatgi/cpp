#include <algorithm>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int count_vowels(const std::string& text) {
    int count = 0;
    for (char ch : text) {
        char lower = static_cast<char>(std::tolower(static_cast<unsigned char>(ch)));
        if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u') {
            ++count;
        }
    }
    return count;
}

std::vector<std::string> split_words(const std::string& text) {
    std::istringstream in(text);
    std::vector<std::string> words;
    std::string word;
    while (in >> word) {
        words.push_back(word);
    }
    return words;
}

int main() {
    std::string line;
    std::cout << "Enter text: ";
    std::getline(std::cin, line);

    const auto words = split_words(line);
    std::string longest;
    for (const auto& word : words) {
        if (word.size() > longest.size()) {
            longest = word;
        }
    }

    std::cout << "Characters: " << line.size() << "\n";
    std::cout << "Words: " << words.size() << "\n";
    std::cout << "Vowels: " << count_vowels(line) << "\n";
    std::cout << "Longest word: " << longest << "\n";
}
