# CS 290: Elite C++ Engineer Track — Professor Edition v3

This version is designed to feel much closer to a strong elite-college course:

- **no solution implementations**
- **real runnable public tests**
- **CMake + ctest**
- **public interfaces and contracts**
- **pseudocode, not code**
- **office-hours hints**
- **rubrics, reflection prompts, and debugging journals**
- **increasing rigor across the course**

## The course design

### Stage 1 — Foundations Bootcamp (Weeks 1–6)
You learn to use C++ fluently.

### Stage 2 — Data Structures and Algorithms in C++ (Weeks 7–14)
You learn to build and test core abstractions.

### Stage 3 — Elite Systems C++ (Weeks 15–24)
You learn performance, memory layout, concurrency, and systems architecture.

## Core philosophy

You should type the real code yourself.

This repo gives you:
- interfaces
- tests
- specs
- pseudocode
- hints
- rubrics

This repo does **not** give you:
- worked implementations
- starter logic that quietly solves the assignment
- hidden hand-holding that removes the important thinking

## Build and run tests

```bash
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

## Run a single week's tests

```bash
./build/public_tests --gtest_filter=Week01*
./build/public_tests --gtest_filter=Week07*
```

## With sanitizers

```bash
cmake -S . -B build -DENABLE_SANITIZERS=ON
cmake --build build
ctest --test-dir build --output-on-failure
```

## Important note

The repo **compiles**, but many tests are expected to fail until you implement the assignment.

That is intentional.


## New in v4

This version adds two important upgrades:

1. **Senior Interview Track**
   - timed coding practice
   - system design preparation
   - behavioral/story preparation
   - debugging and communication drills
   - mock interview checklists

2. **Let's Get Started with VS Code**
   - macOS + VS Code environment setup
   - recommended extensions
   - CMake + test workflow
   - launch points for debugging and test runs

See:
- `docs/getting_started_vscode.md`
- `docs/interview_track/README.md`
- `.vscode/extensions.json`
- `.vscode/settings.json`
- `.vscode/tasks.json`
- `.vscode/launch.json`
