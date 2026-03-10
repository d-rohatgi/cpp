# Week 03 — Generic Algorithms

## Objective
Write iterator-based templated algorithms and compare them to STL equivalents.

## Why this assignment matters
The point is not to outperform STL.
The point is to learn:
- iterator-based abstraction
- comparator-based generic design
- template ergonomics
- why algorithm interfaces matter

## Required public API
See `include/course/algorithms.hpp`.

## Required behavior
Implement:
- `find`
- `accumulate`
- `copy_if`
- `lower_bound`

## Public test focus
- empty ranges
- single-element ranges
- predicate behavior
- sorted-input requirement for `lower_bound`

## Hidden-test themes
- custom types
- non-random-access iterators
- off-by-one errors
- incorrect comparator assumptions
- accidental copies

## Suggested custom tests
- compare outputs to STL on random vectors
- use `std::list` or another non-random-access container
- test duplicates around lower_bound boundaries

## Benchmark requirement
Compare your `find` and `copy_if` against STL over large vectors.

## Rubric emphasis
- template correctness: 35%
- genericity / interface quality: 20%
- test depth: 25%
- benchmark note: 20%
