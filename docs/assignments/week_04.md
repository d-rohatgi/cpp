# Homework 4 — File I/O and Parsing

## Overview

Many real programs fail not because the “main algorithm” is difficult, but because input handling is sloppy. This homework focuses on disciplined parsing and aggregation.

You are not being asked to build a full expense tracker yet. You are being asked to build the core helpers cleanly enough that a larger program could depend on them.

## Learning Objectives

By the end of this homework, you should be able to:

- separate parsing from aggregation
- define and enforce a line format
- handle malformed input intentionally
- test parsing logic independently from file logic
- write small helper functions with clear responsibilities

## Problem Statement

Implement helpers for:

- parsing one expense line
- computing the total amount across expenses

These helpers will later serve as the foundation for a larger expense-tracking tool.

## Files

You are expected to understand the role of:

- `include/course/week04_expense_io.hpp`
- `src/week04_expense_io.cpp`
- `tests/week04_expense_io_public_test.cpp`

## Data Format

You must define the expected line format and enforce it consistently. A strong solution makes malformed input a first-class case rather than an afterthought.

## Deliverables

Submit:

- a correct implementation
- a written description of your expected line format
- at least three malformed-input examples
- a short reflection answering:
  - What makes parsing brittle?
  - What malformed case was easiest to overlook?
  - Why is it useful to separate parsing from aggregation?

## Required Testing

At minimum, test:

- valid line
- malformed line
- invalid numeric field
- empty expense list
- multiple valid expenses

## Grading Emphasis

- 35% correctness
- 25% parsing discipline
- 20% tests
- 10% error-policy clarity
- 10% reflection

## Common Mistakes

- assuming every line is valid
- mixing file reading, parsing, and totaling in one function
- not defining a format before coding
- treating malformed input as impossible

## Optional Extension

Support whitespace trimming or multiple valid delimiter formats.
