# Homework 5 — Using the STL Well

## Overview

Before you implement your own hash map later in the course, you should first demonstrate that you know how to use the standard library well.

This homework emphasizes good use of `std::unordered_map` or `std::map` for a realistic counting task. The goal is not only to get the right answer, but to think clearly about normalization, output ordering, and scaling.

## Learning Objectives

By the end of this homework, you should be able to:

- normalize tokens consistently
- use a map-like container for counting
- sort and rank aggregated results
- explain what your program does on empty or punctuation-heavy input
- reason at a basic level about performance

## Problem Statement

Implement a word-frequency counter that:

- tokenizes text
- normalizes words
- counts occurrences
- returns the top-k most frequent words

## Files

You are expected to understand the role of:

- `include/course/week05_frequency_counter.hpp`
- `src/week05_frequency_counter.cpp`
- `tests/week05_frequency_counter_public_test.cpp`

## Design Expectations

You must choose and document a normalization policy. Examples include:

- lowercase conversion
- punctuation stripping
- ignoring empty tokens

Your policy must be consistent and testable.

## Deliverables

Submit:

- a correct implementation
- a short normalization-policy note
- a simple benchmark plan
- a short reflection answering:
  - Why is it better to use the STL before implementing your own hash table?
  - What policy did you choose for punctuation?
  - What would change for very large inputs?

## Required Testing

At minimum, test:

- repeated words
- case normalization
- punctuation stripping
- empty text
- top-k size limit
- tie behavior

## Grading Emphasis

- 35% correctness
- 20% normalization clarity
- 20% testing
- 15% ordering correctness
- 10% reflection

## Common Mistakes

- sorting before counting
- failing to normalize consistently
- forgetting empty-input behavior
- not deciding how ties are ordered

## Optional Extension

Add stop-word filtering or support reading from a text file.
