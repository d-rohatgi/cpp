# Homework 1 — Calculator and Basic Control Flow

## Overview

This assignment is intentionally small in scope. The goal is not cleverness. The goal is disciplined control over program behavior, decomposition, and failure handling.

Professional software is not judged only by whether it “works on the happy path.” It is judged by whether it behaves clearly, predictably, and correctly when the input is wrong, incomplete, or unexpected. This homework begins training those habits in the smallest useful setting.

## Learning Objectives

By the end of this homework, you should be able to:

- separate computation from input/output
- implement a function from a precise contract
- define and enforce a failure policy
- reason about normal and corner cases
- validate behavior using both manual and automated tests

## Problem Statement

Implement a function with the following interface:

`double calculate(double lhs, double rhs, char op);`

The function must support the operators:

- `+`
- `-`
- `*`
- `/`

The function must reject:

- unsupported operators
- division by zero

Use the public tests as part of the contract.

## Files

You are expected to understand the role of:

- `include/course/week01_calculator.hpp`
- `src/week01_calculator.cpp`
- `tests/week01_calculator_public_test.cpp`

## Required Behavior

Your implementation must satisfy the following:

1. Addition, subtraction, multiplication, and division return correct arithmetic results.
2. Division by zero signals failure.
3. Unsupported operators signal failure.
4. Negative values are handled correctly.
5. Decimal values are handled correctly.

## Deliverables

Submit:

- a correct implementation
- eight manual test cases in your notes
- a short written reflection answering:
  - What bug would be easiest to make here?
  - What policy did you choose for invalid input?
  - What would make this calculator easier to extend?

## Testing Requirements

At minimum, verify:

- one valid test for each supported operator
- division by zero
- invalid operator
- negative input values
- decimal input values

Passing the public tests is required but not sufficient.

## Grading Emphasis

- 40% correctness
- 20% decomposition and readability
- 20% testing discipline
- 10% edge-case handling
- 10% reflection quality

## Common Mistakes

- putting all logic in `main`
- mixing user interaction with computation
- handling invalid operators inconsistently
- failing to think about division by zero before writing code

## Optional Extension

Add a loop-based CLI that allows repeated calculations without restarting the program.
