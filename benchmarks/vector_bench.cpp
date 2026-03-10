#include "course/vector.hpp"

#include <benchmark/benchmark.h>
#include <vector>
#include <exception>

static void BM_CourseVectorPushBack(benchmark::State& state) {
    for (auto _ : state) {
        try {
            course::Vector<int> v;
            for (int i = 0; i < state.range(0); ++i) {
                v.push_back(i);
            }
            benchmark::DoNotOptimize(v.size());
        } catch (const std::exception& ex) {
            state.SkipWithError(ex.what());
            break;
        }
    }
}

static void BM_StdVectorPushBack(benchmark::State& state) {
    for (auto _ : state) {
        std::vector<int> v;
        for (int i = 0; i < state.range(0); ++i) {
            v.push_back(i);
        }
        benchmark::DoNotOptimize(v.size());
    }
}

BENCHMARK(BM_CourseVectorPushBack)->Arg(1 << 10)->Arg(1 << 15);
BENCHMARK(BM_StdVectorPushBack)->Arg(1 << 10)->Arg(1 << 15);

BENCHMARK_MAIN();
