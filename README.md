# CS 290: Elite C++ Engineer Track — Redesigned

This repo is intentionally redesigned to start easier and ramp much more intelligently.

## Stage 1 — C++ Foundations Bootcamp
Learn to use C++ comfortably.

## Stage 2 — Data Structures and Algorithms in C++
Learn to build core structures and reason about complexity.

## Stage 3 — Elite Systems C++
Learn to engineer high-performance, testable, production-style C++ systems.

That sequencing is much better if your long-term goal is to become an elite C++ programmer.

## Repo philosophy

Early weeks:
- smaller projects
- more concrete guidance
- lighter testing requirements
- focus on fluency and debugging

Middle weeks:
- stronger APIs
- more unit tests
- benchmarks start to matter more
- data structure invariants become central

Late weeks:
- systems thinking
- concurrency
- memory layout
- performance engineering
- design notes and profiling

## Important note

This repo is designed to compile cleanly, but many assignments include TODOs and
public tests that will fail until you implement the real logic.

## Build

```bash
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

## With sanitizers

```bash
cmake -S . -B build -DENABLE_SANITIZERS=ON
cmake --build build
ctest --test-dir build --output-on-failure
```
