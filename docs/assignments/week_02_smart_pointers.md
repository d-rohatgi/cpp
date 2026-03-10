# Week 02 — Smart Pointers

## Objective
Implement lightweight versions of `UniquePtr` and `SharedPtr`.

## Why this assignment matters
Elite C++ engineers are expected to reason clearly about:
- who owns what
- when destruction happens
- how aliasing changes the design
- why reference counting is convenient but not free

## Required public API
See:
- `include/course/unique_ptr.hpp`
- `include/course/shared_ptr.hpp`

## Required behavior
### UniquePtr
- move-only semantics
- `get`
- `release`
- `reset`
- dereference operators

### SharedPtr
- reference counting
- copy increments count
- destruction decrements count
- object destroyed exactly once

## Public test focus
- move-only behavior for `UniquePtr`
- reset/release semantics
- shared ownership count changes
- object destruction count

## Hidden-test themes
- self-reset edge cases
- repeated copies and moves
- destroying copies in different orders
- null-pointer behavior
- resource leaks

## Suggested custom tests
- counter-based object lifetime tests
- move chains
- reset after release
- nested scopes that exercise reference count transitions

## Benchmark requirement
Measure rough overhead of shared ownership vs direct stack allocation for a simple object.

## Rubric emphasis
- lifetime correctness: 45%
- test depth: 25%
- API clarity: 15%
- benchmark reasoning: 15%
