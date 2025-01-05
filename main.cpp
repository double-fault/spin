#include <benchmark/benchmark.h>
#include <bits/stdc++.h>
#include <x86intrin.h>

using namespace std;

extern "C" void spin(int);

#define ST 26
#define ED 1000

void BM(benchmark::State &state) {
        int v = state.range(0);
        for (auto _ : state) {
                spin(v);
        }
}

BENCHMARK(BM)->DenseRange(ST, ED, 26);
//BENCHMARK(BM)->RangeMultiplier(2)->Range(1<<ST,1LL<<ED);
//BENCHMARK(BM_RanIterPrefetchOnly<ele64>)->ArgsProduct({
//                benchmark::CreateRange(1<<ST,1LL<<ED,2),
//                benchmark::CreateDenseRange(DST, DED, DSTP)
//                });
//BENCHMARK(BM_RanIterPrefetchSub<ele64>)->RangeMultiplier(2)->Range(1<<ST,1LL<<ED);
//BENCHMARK(BM_RanIterPrefetch<ele64>)->RangeMultiplier(2)->Range(1<<ST,1LL<<ED);

BENCHMARK_MAIN();
