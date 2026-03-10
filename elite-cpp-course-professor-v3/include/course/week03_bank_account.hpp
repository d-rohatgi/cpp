#pragma once

#include <string>

namespace course {

class BankAccount {
public:
    explicit BankAccount(std::string owner, double initial_balance = 0.0);

    const std::string& owner() const noexcept;
    double balance() const noexcept;

    bool deposit(double amount);
    bool withdraw(double amount);

private:
    std::string owner_;
    double balance_;
};

}  // namespace course
