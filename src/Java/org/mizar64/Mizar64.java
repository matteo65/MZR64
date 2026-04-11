package org.mizar64;

/**
 * Mizar64 PRNG java minimalist implementation
 * @author Matteo Zapparoli
 * @date 2026-04-07
 * @version 1.0
 * 
 * SPDX-FileCopyrightText: 2026 Matteo Zapparoli
 * SPDX-License-Identifier: Apache-2.0
 * See LICENSE file in project root.
 * 
 */
public class Mizar64 {
    
    public static final long MIZAR64_DEFAULT_SEED_C = 0L;
    public static final long MIZAR64_DEFAULT_SEED_X = 0L;
    
    /**
     * Internal counter state
     */
    private long state_c;
    
    /**
     * Mixing state
     */
    private long state_x;
    
    public Mizar64(long seed_c, long seed_x) {
        this.state_c = seed_c;
        this.state_x = seed_x;
    }
    
    public Mizar64(long seed) {
        this(seed, ~seed);
    }
    
    public Mizar64() {
        this(MIZAR64_DEFAULT_SEED_C, MIZAR64_DEFAULT_SEED_X);
    }
    
    public long nextLong() {
        // 1. Linear step: update counter
        state_c = state_c * 0x5851f42d4c957f2dL + 0x14057b7ef767814fL;

        // 2. Mixing step: cross-coupled XOR-rotation and multiplication
        return state_x = 0x9e3779b97f4a7c15L * ((state_c << 32) ^ (state_c >>> 32) ^
                                                (state_x << 32) ^ (state_x >>> 32));
    }

}
