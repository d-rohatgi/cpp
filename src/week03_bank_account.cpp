#include "course/bank_account.hpp"
#include <utility>

namespace course {

BankAccount::BankAccount(std::string owner, double initial_balance)
    : owner_(std::move(owner)), balance_(initial_balance < 0.0 ? 0.0 : initial_balance) {}

const std::string& BankAccount::owner() const noexcept {
    return owner_;
}

double BankAccount::balance() const noexcept {
    return balance_;
}

bool BankAccount::deposit(double amount) {
    if (amount <= 0.0) {
        return false;
    }
    balance_ += amount;
    return true;
}

bool BankAccount::withdraw(double amount) {
    if (amount <= 0.0 || amount > balance_) {
        return false;
    }
    balance_ -= amount;
    return true;
}

}  // namespace course
