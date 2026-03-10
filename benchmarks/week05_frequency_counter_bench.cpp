#include "course/frequency_counter.hpp"

#include <benchmark/benchmark.h>
#include <string>

static std::string make_text(int repeats) {
    std::string text;
    text.reserve(static_cast<std::size_t>(repeats) * 20);
    for (int i = 0; i < repeats; ++i) {
        text += "apple banana apple orange banana apple ";
    }
    return text;
}

static void BM_FrequencyCounter(benchmark::State& state) {
    const std::string text = make_text(static_cast<int>(state.range(0)));
    for (auto _ : state) {
        auto result = course::count_words(text);
        benchmark::DoNotOptimize(result);
    }
}

BENCHMARK(BM_FrequencyCounter)->Arg(100)->Arg(1000);
BENCHMARK_MAIN();
