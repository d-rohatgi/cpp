#include <iostream>
#include <stdexcept>

double calculate(double lhs, double rhs, char op) {
    switch (op) {
        case '+': return lhs + rhs;
        case '-': return lhs - rhs;
        case '*': return lhs * rhs;
        case '/':
            if (rhs == 0.0) {
                throw std::runtime_error("division by zero");
            }
            return lhs / rhs;
        default:
            throw std::runtime_error("unsupported operator");
    }
}

int main() {
    double lhs = 0.0;
    double rhs = 0.0;
    char op = '+';

    std::cout << "Enter: <number> <operator> <number>\n";
    std::cin >> lhs >> op >> rhs;

    try {
        std::cout << "Result: " << calculate(lhs, rhs, op) << "\n";
    } catch (const std::exception& ex) {
        std::cout << "Error: " << ex.what() << "\n";
    }
}
