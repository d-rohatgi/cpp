#include "course/bank_account.hpp"

#include <gtest/gtest.h>

TEST(BankAccountPublicTest, StartsWithOwnerAndBalance) {
    course::BankAccount account("Dhruv", 100.0);
    EXPECT_EQ(account.owner(), "Dhruv");
    EXPECT_DOUBLE_EQ(account.balance(), 100.0);
}

TEST(BankAccountPublicTest, DepositIncreasesBalance) {
    course::BankAccount account("Test", 10.0);
    EXPECT_TRUE(account.deposit(15.0));
    EXPECT_DOUBLE_EQ(account.balance(), 25.0);
}

TEST(BankAccountPublicTest, WithdrawFailsWhenTooLarge) {
    course::BankAccount account("Test", 20.0);
    EXPECT_FALSE(account.withdraw(25.0));
    EXPECT_DOUBLE_EQ(account.balance(), 20.0);
}
