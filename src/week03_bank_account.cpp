#include "course/week03_bank_account.hpp"

#include <stdexcept>
#include <utility>

namespace course {

BankAccount::BankAccount(std::string owner, double initial_balance)
    : owner_(std::move(owner)), balance_(initial_balance <= 0.0 ? 0.0 : initial_balance) {
}

const std::string& BankAccount::owner() const noexcept {
    return owner_;
}

double BankAccount::balance() const noexcept {
    return balance_;
}

bool BankAccount::deposit(double amount) {
    if (amount <= 0){
        return false;
    }
    balance_ += amount;
    return true;
}

bool BankAccount::withdraw(double amount) {
    if (amount <= 0){
        return false;
    }
    if (amount > balance_){
        return false;
    }
    balance_-= amount;
    return true;
}

}  // namespace course
