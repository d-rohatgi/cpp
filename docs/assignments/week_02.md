# Homework 2 — Strings, Vectors, and Decomposition

## Overview

This homework focuses on using the standard library as a working programmer would: by decomposing a problem into small helper functions and composing the results cleanly.

This is not a “write one long function” exercise. Your solution should show that you can break a text-processing task into simpler parts and reason about each part independently.

## Learning Objectives

By the end of this homework, you should be able to:

- use `std::string` and `std::vector` comfortably
- decompose a small problem into helper functions
- define and document a tokenization rule
- return structured results rather than printing everything directly
- test text-handling logic with representative inputs

## Problem Statement

Implement a text analyzer that computes:

- total character count
- total word count
- total vowel count
- longest word

You must define what counts as a “word” and apply that policy consistently.

## Files

You are expected to understand the role of:

- `include/course/week02_text_analyzer.hpp`
- `src/week02_text_analyzer.cpp`
- `tests/week02_text_analyzer_public_test.cpp`

## Design Guidance

A strong solution will likely separate the work into smaller conceptual steps such as:

- counting characters
- identifying words
- counting vowels
- tracking the longest word

Do not let `main` or one giant function absorb all of the logic.

## Deliverables

Submit:

- a correct implementation
- a short note explaining your word-splitting rule
- at least five hand-designed test inputs
- a brief reflection answering:
  - Which helper function was easiest to verify?
  - Where did your first design create confusion?
  - What input policy did you choose?

## Required Testing

At minimum, test:

- empty input
- simple two-word input
- repeated spaces
- uppercase vowels
- input that includes punctuation

## Grading Emphasis

- 35% correctness
- 25% decomposition into helper functions
- 20% testing
- 10% edge-case handling
- 10% reflection

## Common Mistakes

- burying all logic in one function
- changing tokenization rules halfway through the implementation
- forgetting that repeated spaces should not create fake words
- mixing analysis with output formatting too early

## Optional Extension

Return additional statistics such as shortest word, average word length, or consonant count.
