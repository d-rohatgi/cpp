#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::cout << "Expense tracker starter.\n";
    std::cout << "TODO(student): parse file lines, compute totals, and write output.\n";

    std::ifstream in("expenses.txt");
    if (!in) {
        std::cout << "No expenses.txt found yet. Create one as part of the assignment.\n";
        return 0;
    }

    std::string line;
    while (std::getline(in, line)) {
        std::cout << line << "\n";
    }
}
