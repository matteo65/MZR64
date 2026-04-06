/*
 * speed_mizar64.c
 *
 * Version: 1.0
 * Date: 2026-04-01
 * Author: Matteo Zapparoli
 *
 * Speed benchmark in Cycles Per Number of mizar64 PRNG
 *
 * Compile: gcc -O3 -I.. speed_mizar64.c ../mizar64.o -o speed_mizar64
 *
 */
#include <stdio.h>
#include <stdint.h>
#include <x86intrin.h> // Necessario per __rdtsc()

#include "mizar64.h"

// Macro per il benchmark veloce
#define BENCH_SAMPLES 100000000 // 100 milioni di iterazioni

int main(void) 
{
    mizar64_state_t state;
    uint64_t seed = 0x123456789ABCDEFULL;
    uint64_t start, end;
    uint64_t sink = 0; // Per evitare l'ottimizzazione del compilatore

    printf("--- Mizar64 Benchmark & Speed Test (v.%d) ---\n", MIZAR64_VERSION);

    // Inizializzazione
    state.c = MIZAR64_DEFAULT_SEED_C;
	state.x = MIZAR64_DEFAULT_SEED_X;

    // Warm-up della CPU (per svegliare i core dal risparmio energetico)
    for (int i = 0; i < 1000000; i++) 
		sink ^= mizar64(&state);

    // Inizio misurazione
    start = __rdtsc();
    for (int i = 0; i < BENCH_SAMPLES; i++)
        sink ^= mizar64(&state); 

    end = __rdtsc();

    // Calcolo risultati
    double total_cycles = (double)(end - start);
    double cpn = total_cycles / BENCH_SAMPLES;

    printf("Processed %d samples.\n", BENCH_SAMPLES);
    printf("Total cycles: %llu\n", (unsigned long long)total_cycles);
    printf("Average Cycles Per Number (CPN): %.2f\n", cpn);
    printf("Checksum (sink): %llX\n", (unsigned long long)sink);

    return 0;
}
