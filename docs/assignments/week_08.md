# Homework 8 — Smart Pointers

## Overview

This homework is your first explicit ownership homework. It is easy to write code that looks plausible here and still misunderstand the real semantics.

Take the time to reason carefully. The purpose is not only to imitate syntax. The purpose is to internalize ownership models.

## Learning Objectives

By the end of this homework, you should be able to:

- explain exclusive ownership
- explain shared ownership
- describe what triggers destruction
- distinguish move-only behavior from shared behavior
- write tests focused on lifetime and ownership

## Problem Statement

Implement:

- `UniquePtr`
- `SharedPtr`

## Files

You are expected to understand the role of:

- `include/course/week08_unique_ptr.hpp`
- `include/course/week08_shared_ptr.hpp`
- `include/course/week08_shared_ptr.tpp`
- `tests/week08_smart_pointers_public_test.cpp`

## Design Expectations

Before coding, write down:

- who owns the object
- when destruction should happen
- what copying means
- what moving means
- what null behavior means

## Deliverables

Submit:

- implementation
- a short written explanation of ownership for each smart pointer
- tests focused on lifetime behavior
- reflection note answering:
  - What is the core semantic difference between `UniquePtr` and `SharedPtr`?
  - What behavior is easiest to fake incorrectly?
  - What kind of bug does shared ownership make easier to create?

## Required Testing

At minimum, test:

- raw pointer ownership
- release behavior
- reset behavior
- initial shared count
- copy shared count
- destruction behavior
- null behavior

## Grading Emphasis

- 35% correctness
- 25% ownership reasoning
- 20% testing
- 10% interface clarity
- 10% reflection

## Common Mistakes

- confusing copying with moving
- forgetting to update counts on copy
- leaking on reset
- deleting too early or too often

## Optional Extension

Write a short note explaining when raw pointers are still useful even in modern C++.
