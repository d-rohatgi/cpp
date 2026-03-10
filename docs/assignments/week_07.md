# Homework 7 — Dynamic Vector

## Overview

You have already used `std::vector`. Now you will implement a simplified vector yourself.

This is the first homework where your mental model must become sharper. Raw storage, live objects, logical size, and reserved capacity are not the same thing. You should not proceed by trial and error alone; you should proceed by stating invariants and checking them repeatedly.

## Learning Objectives

By the end of this homework, you should be able to:

- explain the difference between size and capacity
- reason about growth and reallocation
- think about copy and move behavior
- write tests for container invariants
- separate raw memory concerns from logical container behavior

## Problem Statement

Implement a simplified `Vector<T>` supporting:

- `push_back`
- `pop_back`
- `reserve`
- `clear`
- `size`
- `capacity`
- copy support
- move support

## Files

You are expected to understand the role of:

- `include/course/week07_vector.hpp`
- `include/course/week07_vector.tpp`
- `tests/week07_vector_public_test.cpp`

## Design Expectations

Before writing code, you should write down:

- what `size` means
- what `capacity` means
- what must be true after growth
- what copy should guarantee
- what move should guarantee

## Deliverables

Submit:

- a correct implementation
- an invariant list
- unit tests
- a design note
- a short reflection answering:
  - What exactly happens when the vector grows?
  - Which bug is easiest to make in copy behavior?
  - What does a valid moved-from vector mean in your design?

## Required Testing

At minimum, test:

- starts empty
- push order
- reserve behavior
- pop_back behavior
- clear behavior
- bounds checking
- copy independence
- move validity

## Grading Emphasis

- 35% correctness
- 20% invariant clarity
- 20% testing
- 15% copy/move reasoning
- 10% reflection

## Common Mistakes

- confusing size with capacity
- forgetting to preserve elements across growth
- copying storage metadata without copying logical contents correctly
- not thinking about moved-from validity

## Optional Extension

Add iterator support or a `reserve` growth policy analysis note.
