#pragma once

#include <cstddef>
#include <string>
#include <utility>
#include <vector>

namespace course {

std::vector<std::pair<std::string, int>> count_words(const std::string& text);
std::vector<std::pair<std::string, int>> top_k_words(const std::string& text, std::size_t k);

}  // namespace course
