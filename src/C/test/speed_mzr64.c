#include <stdio.h>
#include <stdint.h>
#include <x86intrin.h> // Necessario per __rdtsc()

#include "mzr64.h"

// Macro per il benchmark veloce
#define BENCH_SAMPLES 100000000 // 100 milioni di iterazioni

int main() {
    mzr64_state_t state;
    uint64_t seed = 0x123456789ABCDEFULL;
    uint64_t start, end;
    uint64_t sink = 0; // Per evitare l'ottimizzazione del compilatore

    printf("--- MZR64 Benchmark & Speed Test (v.%d) ---\n", MZR64_VERSION);

    // Inizializzazione
    mzr64_seed_r(&state, seed);

    // Warm-up della CPU (per svegliare i core dal risparmio energetico)
    for (int i = 0; i < 1000000; i++) sink ^= mzr64_r(&state);

    // Inizio misurazione
    start = __rdtsc();
    for (int i = 0; i < BENCH_SAMPLES; i++) {
        sink ^= mzr64_r(&state); 
    }
    end = __rdtsc();

    // Calcolo risultati
    double total_cycles = (double)(end - start);
    double cpn = total_cycles / BENCH_SAMPLES;

    printf("Processed %d samples.\n", BENCH_SAMPLES);
    printf("Total cycles: %llu\n", (unsigned long long)total_cycles);
    printf("Average Cycles Per Number (CPN): %.2f\n", cpn);
    printf("Checksum (sink): %llX\n", (unsigned long long)sink);

    if (cpn < 5.0) {
        printf("\n[PERFORMANCE] Excellent: Top-tier speed.\n");
    } else {
        printf("\n[PERFORMANCE] Good: Standard PRNG speed.\n");
    }

    return 0;
}
