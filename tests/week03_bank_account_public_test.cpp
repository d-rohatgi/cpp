#include "course/week03_bank_account.hpp"

#include <gtest/gtest.h>

TEST(Week03BankAccount, StoresOwnerAndBalance) {
    course::BankAccount account("Dhruv", 100.0);
    EXPECT_EQ(account.owner(), "Dhruv");
    EXPECT_DOUBLE_EQ(account.balance(), 100.0);
}

TEST(Week03BankAccount, NegativeInitialBalanceClampsToZero) {
    course::BankAccount account("Test", -50.0);
    EXPECT_DOUBLE_EQ(account.balance(), 0.0);
}

TEST(Week03BankAccount, DepositIncreasesBalance) {
    course::BankAccount account("Test", 10.0);
    EXPECT_TRUE(account.deposit(15.0));
    EXPECT_DOUBLE_EQ(account.balance(), 25.0);
}

TEST(Week03BankAccount, RejectsNegativeDeposit) {
    course::BankAccount account("Test", 10.0);
    EXPECT_FALSE(account.deposit(-1.0));
    EXPECT_DOUBLE_EQ(account.balance(), 10.0);
}

TEST(Week03BankAccount, RejectsZeroDeposit) {
    course::BankAccount account("Test", 10.0);
    EXPECT_FALSE(account.deposit(0.0));
    EXPECT_DOUBLE_EQ(account.balance(), 10.0);
}

TEST(Week03BankAccount, WithdrawDecreasesBalanceWhenValid) {
    course::BankAccount account("Test", 20.0);
    EXPECT_TRUE(account.withdraw(5.0));
    EXPECT_DOUBLE_EQ(account.balance(), 15.0);
}

TEST(Week03BankAccount, WithdrawRejectsTooLargeAmount) {
    course::BankAccount account("Test", 20.0);
    EXPECT_FALSE(account.withdraw(25.0));
    EXPECT_DOUBLE_EQ(account.balance(), 20.0);
}

TEST(Week03BankAccount, WithdrawRejectsNegativeAmount) {
    course::BankAccount account("Test", 20.0);
    EXPECT_FALSE(account.withdraw(-2.0));
    EXPECT_DOUBLE_EQ(account.balance(), 20.0);
}

TEST(Week03BankAccount, WithdrawExactBalanceReachesZero) {
    course::BankAccount account("Test", 20.0);
    EXPECT_TRUE(account.withdraw(20.0));
    EXPECT_DOUBLE_EQ(account.balance(), 0.0);
}

TEST(Week03BankAccount, SequenceOfOperationsMaintainsBalance) {
    course::BankAccount account("Test", 10.0);
    EXPECT_TRUE(account.deposit(5.0));
    EXPECT_TRUE(account.withdraw(3.0));
    EXPECT_FALSE(account.withdraw(100.0));
    EXPECT_DOUBLE_EQ(account.balance(), 12.0);
}
