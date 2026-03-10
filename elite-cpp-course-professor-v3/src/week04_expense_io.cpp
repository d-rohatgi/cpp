#include "course/week04_expense_io.hpp"

namespace course {

std::optional<Expense> parse_expense_line(const std::string& line) {
    (void)line;
    return std::nullopt;
}

double total_amount(const std::vector<Expense>& expenses) {
    (void)expenses;
    return 0.0;
}

}  // namespace course
