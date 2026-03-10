#pragma once

#include <optional>
#include <string>
#include <vector>

namespace course {

struct Expense {
    std::string category;
    double amount = 0.0;
};

std::optional<Expense> parse_expense_line(const std::string& line);
double total_amount(const std::vector<Expense>& expenses);

}  // namespace course
