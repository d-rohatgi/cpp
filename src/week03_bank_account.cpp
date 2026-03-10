#include "course/week03_bank_account.hpp"

#include <stdexcept>
#include <utility>

namespace course {

BankAccount::BankAccount(std::string owner, double initial_balance)
    : owner_(std::move(owner)), balance_(initial_balance) {
}

const std::string& BankAccount::owner() const noexcept {
    return owner_;
}

double BankAccount::balance() const noexcept {
    return balance_;
}

bool BankAccount::deposit(double amount) {
    (void)amount;
    throw std::logic_error("Week 03 deposit() not implemented");
}

bool BankAccount::withdraw(double amount) {
    (void)amount;
    throw std::logic_error("Week 03 withdraw() not implemented");
}

}  // namespace course
