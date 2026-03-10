#include "course/week01_calculator.hpp"

#include <stdexcept>

namespace course {

double calculate(double lhs, double rhs, char op) {
    switch(op){
        case '+':
            return lhs + rhs;
        case '-':
            return lhs - rhs;
        case '/':
            if (rhs == 0){
                throw std::runtime_error("cannot divide by zero");
            }
            return lhs/rhs;
        case '*':
            return lhs*rhs;
        default:
            throw std::runtime_error("operator is not valid");
    }
}

}  // namespace course
