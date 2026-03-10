# Week 01 — Dynamic Vector

## Objective
Implement a dynamic array that owns raw storage and grows amortized-constant time.

## Why this assignment matters
This is your first real exercise in:
- raw storage vs constructed objects
- destructor discipline
- copy vs move semantics
- growth policy tradeoffs
- writing tests for lifetime-sensitive code

## Required public API
See `include/course/vector.hpp`.

## Required behavior
- `push_back` appends an element
- `pop_back` removes the last element or throws if empty
- `reserve` increases capacity without changing size
- `clear` destroys elements but keeps capacity
- copy operations perform deep copies
- move operations transfer ownership and leave the source valid

## Milestones
### Milestone A
- constructors
- `size`
- `capacity`
- `empty`
- bounds-checked `at`

### Milestone B
- `push_back`
- growth policy
- `pop_back`

### Milestone C
- copy constructor / copy assignment
- move constructor / move assignment
- `clear`
- regression tests

## Public test focus
- starts empty
- size changes after append
- out-of-range access throws
- copy independence
- move leaves valid source

## Hidden-test themes
- repeated growth
- many push/pop cycles
- object types with nontrivial destructors
- self-assignment
- reserve smaller than current capacity
- clear followed by reuse

## Suggested custom tests
- track destructor calls with a counter type
- long random operation sequences
- compare against `std::vector` for model-based testing
- verify moved-from vector can still be assigned to

## Benchmark requirement
Compare append throughput and iteration throughput vs `std::vector`.

## Rubric emphasis
- correctness under copy/move: 40%
- tests beyond the visible suite: 25%
- memory/lifetime hygiene: 20%
- benchmark note: 15%

## Design questions
- Are you managing raw storage or object lifetime correctly?
- What exactly does `capacity` mean in your design?
- Which operations invalidate references or pointers?
