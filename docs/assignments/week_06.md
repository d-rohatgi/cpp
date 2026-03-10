# Homework 6 — Pointers, References, and Linked Structures

## Overview

This homework introduces manual memory concerns in the smallest useful setting. The goal is not to make you love raw pointers. The goal is to make you understand why ownership discipline matters.

A small linked structure is enough to expose several important ideas:

- heap vs stack
- pointer updates
- cleanup responsibility
- how a simple bug can cause a crash or leak

## Learning Objectives

By the end of this homework, you should be able to:

- explain stack vs heap in your own words
- trace pointer updates by hand
- implement a tiny linked structure
- reason about cleanup and ownership
- identify leak-prone and crash-prone patterns

## Problem Statement

Implement a tiny singly linked list with:

- `push_front`
- `contains`
- `size`
- `clear`

## Files

You are expected to understand the role of:

- `include/course/week06_linked_list.hpp`
- `src/week06_linked_list.cpp`
- `tests/week06_linked_list_public_test.cpp`

## Deliverables

Submit:

- a correct implementation
- a hand-drawn pointer sketch in your notes
- testing notes
- a short reflection answering:
  - What bug would cause a leak?
  - What bug would cause a crash?
  - Why is manual memory management risky?

## Required Testing

At minimum, test:

- empty list
- one-element list
- multiple `push_front` operations
- successful and unsuccessful `contains`
- clearing a populated list
- repeated `clear`

## Grading Emphasis

- 35% correctness
- 25% ownership understanding
- 20% testing
- 10% cleanup discipline
- 10% reflection

## Common Mistakes

- losing the rest of the list during insertion
- forgetting cleanup
- reading freed memory
- assuming repeated clear is harmless without testing it

## Optional Extension

Add `push_back` or `remove_first` and document the new invariants.
