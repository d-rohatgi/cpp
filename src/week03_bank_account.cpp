#include "course/week03_bank_account.hpp"

namespace course {

BankAccount::BankAccount(std::string owner, double initial_balance)
    : owner_(std::move(owner)), balance_(initial_balance) {}

const std::string& BankAccount::owner() const noexcept {
    return owner_;
}

double BankAccount::balance() const noexcept {
    return balance_;
}

bool BankAccount::deposit(double amount) {
    (void)amount;
    return false;
}

bool BankAccount::withdraw(double amount) {
    (void)amount;
    return false;
}

}  // namespace course
