#include "mzr64.h"

/* Professional constants for maximum bit diffusion */
#define MZR_GOLDEN 0x9E3779B97F4A7C15ULL // Golden Ratio (64-bit)
#define MZR_WEYL   0x14057B7EF767814FULL // Weyl sequence constant

/* Internal static state for the simple version */
static mzr64_state_t internal_state = {1, 1};

/* --- Reentrant Version (Core Logic) --- */

void mzr64_seed_r(mzr64_state_t *state, uint64_t seed) {
    if (state) {
        state->s = seed;
        state->v = ~seed;
    }
}

uint64_t mzr64_r(mzr64_state_t *state) {
    // 1. Linear step: update counter s
    state->s = state->s * MZR_GOLDEN + MZR_WEYL;
    
    // 2. Mixing step: cross-coupled XOR-rotation and multiplication
    return state->v = MZR_GOLDEN * ( (state->s << 32) ^ (state->s >> 32) ^ 
                                     (state->v << 32) ^ (state->v >> 32) );
}

/* --- Simple Version (Wrappers) --- */

void mzr64_seed(uint64_t seed) {
    mzr64_seed_r(&internal_state, seed);
}

uint64_t mzr64(void) {
    return mzr64_r(&internal_state);
}
