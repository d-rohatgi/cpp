# CS 290: Elite C++ Systems Engineering — Professor Edition

This repo is designed the way a strong systems course would be structured:
you get **specs, public interfaces, visible smoke tests, benchmark harnesses, rubrics, and CI** —
but you still do the hard implementation and debugging work yourself.

The goal is not just to finish projects.
The goal is to become the kind of engineer who can reason about:
- ownership and lifetime
- performance and cache locality
- invariants and failure modes
- concurrency and synchronization
- production-quality testing discipline

## Course philosophy

Strong programs usually avoid two bad extremes:

1. **No scaffolding**  
   You waste energy on tooling, not engineering.

2. **Too much scaffolding**  
   You complete assignments faster, but learn less.

This repo aims for the sweet spot:
- compileable starter code
- public APIs
- visible public tests
- hidden-test guidance
- benchmark expectations
- intentionally incomplete implementations

## What you get

- 24-week curriculum
- detailed handouts for Weeks 1–5
- concise specs for Weeks 6–24
- public smoke tests for early assignments
- benchmark scaffolding
- grading rubrics
- design note templates
- CI and sanitizers

## What you still must do

- design internals
- enforce invariants
- write additional tests beyond the public ones
- choose tradeoffs
- optimize based on measurement

## Quick start

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

## Recommended weekly workflow

1. Read the handout in `docs/assignments/`
2. Write down your invariants
3. Implement the simplest correct version
4. Run the public tests
5. Add your own tests
6. Run with sanitizers
7. Benchmark
8. Write a short design note

## Suggested push to GitHub

```bash
git init
git add .
git commit -m "Initial professor-edition elite C++ course repo"
git branch -M main
git remote add origin <your-repo-url>
git push -u origin main
```
