# Hidden Tests Guidance

Strong systems courses often use hidden tests to prevent students from overfitting to the visible suite.

This repo does not include actual hidden tests, but it does include **hidden-test themes** in every early assignment handout.

## What hidden tests usually target
- API corner cases
- lifetime / ownership bugs
- copy / move mistakes
- invariant drift after long operation sequences
- collision-heavy or adversarial inputs
- complexity regressions
- exception safety or resource leaks

## How to prepare
Ask yourself:
- What would break after 100,000 operations?
- What if the input is empty?
- What if elements collide heavily?
- What if move/copy operations interleave in odd ways?
- What if the same key is inserted repeatedly?
