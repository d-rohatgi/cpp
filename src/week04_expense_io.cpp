#include "course/week04_expense_io.hpp"

#include <stdexcept>

namespace course {

std::optional<Expense> parse_expense_line(const std::string& line) {
    (void)line;
    throw std::logic_error("Week 04 parse_expense_line() not implemented");
}

double total_amount(const std::vector<Expense>& expenses) {
    (void)expenses;
    throw std::logic_error("Week 04 total_amount() not implemented");
}

}  // namespace course
