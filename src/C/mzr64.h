/**
 * mzr64
 * 
 * Ultra-fast, minimalist, robust pseudo-random number generator (PRNG)
 * 
 * Author: Matteo Zapparoli
 * Date: 2026-04
 * Version 1.0
 *
 * SPDX-FileCopyrightText: 2026 Matteo Zapparoli
 * SPDX-License-Identifier: Apache-2.0
 * See LICENSE file in project root.
 * 
 */

#ifndef MZR64_H
#define MZR64_H

#include <stdint.h>

#define MZR64_VERSION 100 // Version 1.0.0

#ifdef __cplusplus
extern "C" {
#endif

/* MZR64 State structure */
typedef struct {
    uint64_t s; // Internal counter
    uint64_t v; // Mixing state
} mzr64_state_t;

/* Reentrant version (Thread-safe, requires state struct) */
void     mzr64_seed_r(mzr64_state_t *state, uint64_t seed);
uint64_t mzr64_r(mzr64_state_t *state);

/* Simple version (Uses internal static state) */
void     mzr64_seed(uint64_t seed);
uint64_t mzr64(void);

#ifdef __cplusplus
}
#endif

#endif /* MZR64_H */
