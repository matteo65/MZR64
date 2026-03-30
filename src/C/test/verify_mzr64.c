#include <stdio.h>
#include <stdint.h>
#include "mzr64.h"

int main() {
    uint64_t seed = 42;
    uint64_t v1, v2;
    mzr64_state_t state;

    printf("--- MZR64 Verification Test (v.%d) ---\n", MZR64_VERSION);

    // 1. Inizializzazione di entrambi i generatori con lo stesso seed
    mzr64_seed(seed);
    mzr64_seed_r(&state, seed);

    printf("Generating 5 numbers to verify consistency:\n\n");

    int match = 1;
    for (int i = 0; i < 5; i++) {
        v1 = mzr64();        // Versione semplice
        v2 = mzr64_r(&state); // Versione struct

        printf("[%d] Simple: %016lX | Struct: %016lX\n", i + 1, v1, v2);

        if (v1 != v2) {
            match = 0;
        }
    }

    // 2. Verdetto finale
    if (match) {
        printf("\n[SUCCESS] Both versions produce identical sequences.\n");
    } else {
        printf("\n[FAILED] Sequence mismatch detected!\n");
    }

    return (match ? 0 : 1);
}
