# Homework 3 — Classes, Invariants, and Methods

## Overview

This homework is not just about defining a class. It is about protecting an invariant.

A class is valuable because it constrains behavior and makes invalid states harder to reach. This assignment introduces that mindset in a small, stateful setting.

## Learning Objectives

By the end of this homework, you should be able to:

- distinguish interface from implementation
- identify and state a class invariant
- protect state against invalid transitions
- write tests for stateful behavior
- explain why members should or should not be public

## Problem Statement

Implement a `BankAccount` class with:

- owner
- balance
- deposit
- withdraw

You must choose and enforce a reasonable policy for invalid operations.

## Files

You are expected to understand the role of:

- `include/course/week03_bank_account.hpp`
- `src/week03_bank_account.cpp`
- `tests/week03_bank_account_public_test.cpp`

## Invariant

Your class should maintain a clear invariant regarding balance validity. You must write this invariant down explicitly in your notes before implementing the methods.

## Deliverables

Submit:

- a correct implementation
- a written statement of the class invariant
- a test plan
- a short reflection answering:
  - What operations can fail?
  - How did you protect the invariant?
  - What would you change if overdraft were allowed?

## Required Testing

At minimum, test:

- constructor behavior
- successful deposit
- unsuccessful deposit
- successful withdraw
- oversized withdraw
- zero and negative amounts

## Grading Emphasis

- 35% correctness
- 25% invariant protection
- 20% tests
- 10% API clarity
- 10% reflection

## Common Mistakes

- allowing invalid balances
- making all members public
- forgetting that negative or zero amounts need a policy
- writing tests only for success cases

## Optional Extension

Add a transaction history or transfer operation between two accounts.
