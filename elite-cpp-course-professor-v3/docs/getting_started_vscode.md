# Let's Get Started — VS Code Environment Setup (macOS)

## Goal

By the end of this setup, you should be able to:
- open the repo in VS Code
- configure and build with CMake
- run public tests with `ctest`
- debug C++ code
- run one test target quickly

## Step 1 — Install prerequisites

Install:
- Xcode Command Line Tools
- Visual Studio Code
- CMake

### Xcode Command Line Tools
In Terminal:

```bash
xcode-select --install
```

### Visual Studio Code
Install VS Code, then add the `code` command to your PATH:

1. Open VS Code
2. Press `Cmd+Shift+P`
3. Run: `Shell Command: Install 'code' command in PATH`

Now you can open the repo from Terminal:

```bash
code .
```

### CMake
If you use Homebrew:

```bash
brew install cmake
```

## Step 2 — Open the repo in VS Code

```bash
cd /path/to/your/repo
code .
```

## Step 3 — Install recommended extensions

This repo recommends:
- C/C++
- CMake Tools
- CodeLLDB
- Even Better TOML
- EditorConfig for VS Code
- GitLens (optional)

## Step 4 — First build

```bash
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

## Step 5 — Configure IntelliSense if needed

If IntelliSense is not configured:
- Press `Cmd+Shift+P`
- Run `C/C++: Select IntelliSense Configuration`
- Choose `Use clang++`

## Step 6 — Debugging on macOS

Use LLDB:
- open Run and Debug
- pick `Debug public_tests`
- set breakpoints
- start debugging

## Step 7 — Daily workflow

1. Read the handout
2. Open the `.hpp` / `.cpp` files for that week
3. Build
4. Run the relevant public tests
5. Fix failures
6. Add your own tests
7. Write one debugging-journal note

## Useful commands

Build:
```bash
cmake --build build
```

All tests:
```bash
ctest --test-dir build --output-on-failure
```

One week’s tests:
```bash
./build/public_tests --gtest_filter=Week07*
```

## Common mistakes

- not installing Xcode Command Line Tools
- forgetting to add `code` to PATH
- editing files without rebuilding
- treating public tests as sufficient
- spending too much time customizing the editor

## Professor advice

Get to a stable setup quickly and start writing code.
A boring, reliable environment beats a fancy one.
