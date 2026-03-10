#include "course/frequency_counter.hpp"

#include <algorithm>
#include <cctype>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

namespace course {

namespace {
std::string normalize(std::string word) {
    std::string result;
    result.reserve(word.size());
    for (char ch : word) {
        if (std::isalnum(static_cast<unsigned char>(ch))) {
            result.push_back(static_cast<char>(std::tolower(static_cast<unsigned char>(ch))));
        }
    }
    return result;
}
}  // namespace

std::vector<std::pair<std::string, int>> count_words(const std::string& text) {
    std::unordered_map<std::string, int> freq;
    std::istringstream in(text);
    std::string word;

    while (in >> word) {
        word = normalize(word);
        if (!word.empty()) {
            ++freq[word];
        }
    }

    std::vector<std::pair<std::string, int>> items(freq.begin(), freq.end());
    std::sort(items.begin(), items.end(), [](const auto& a, const auto& b) {
        if (a.second != b.second) {
            return a.second > b.second;
        }
        return a.first < b.first;
    });
    return items;
}

std::vector<std::pair<std::string, int>> top_k_words(const std::string& text, std::size_t k) {
    auto items = count_words(text);
    if (items.size() > k) {
        items.resize(k);
    }
    return items;
}

}  // namespace course
