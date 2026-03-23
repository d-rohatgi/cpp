#include "course/week04_expense_io.hpp"

#include <stdexcept>
#include <sstream>
#include <string>
#include <vector>

namespace course {

std::optional<Expense> parse_expense_line(const std::string& line) {
    Expense res;
    std::vector<std::string> fields;
    std::stringstream ss(line);
    std::string field;
    
    while (std::getline(ss, field, ',')){
        fields.push_back(field);
    }
    res.category =  fields[0];
    res.amount = std::stod(fields[1]);
    return res; 


}

double total_amount(const std::vector<Expense>& expenses) {
    (void)expenses;
    throw std::logic_error("Week 04 total_amount() not implemented");
}

}  // namespace course
