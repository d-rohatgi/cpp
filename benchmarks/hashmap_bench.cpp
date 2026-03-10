#include "course/hashmap.hpp"

#include <benchmark/benchmark.h>
#include <unordered_map>

static void BM_CourseHashMapInsert(benchmark::State& state) {
    for (auto _ : state) {
        course::HashMap<int, int> map;
        for (int i = 0; i < state.range(0); ++i) {
            map.insert(i, i);
        }
        benchmark::ClobberMemory();
    }
}

static void BM_StdUnorderedMapInsert(benchmark::State& state) {
    for (auto _ : state) {
        std::unordered_map<int, int> map;
        for (int i = 0; i < state.range(0); ++i) {
            map.insert({i, i});
        }
        benchmark::ClobberMemory();
    }
}

BENCHMARK(BM_CourseHashMapInsert)->Arg(1 << 10)->Arg(1 << 15);
BENCHMARK(BM_StdUnorderedMapInsert)->Arg(1 << 10)->Arg(1 << 15);

BENCHMARK_MAIN();
