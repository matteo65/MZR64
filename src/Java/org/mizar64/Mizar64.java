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

    public static final long MIZAR64_DEFAULT_SEED = 0L;
    
    /**
     * Internal counter state
     */
    private long state_c;
    
    /**
     * Mixing state
     */
    private long state_x;
    
    public Mizar64(long seed) {
        this.state_c = 1;
        this.state_x = seed;
    }
    
    public Mizar64() {
        this(MIZAR64_DEFAULT_SEED);
    }
    
    public long nextLong() {
        // 1. Linear step: update counter
        state_c *= 0x9e3779b97f4a7c15L;

        // 2. Mixing step: cross-coupled XOR-rotation and multiplication
        return state_x = 0x9e3779b97f4a7c15L * ((state_c << 32) ^ (state_c >>> 32) ^
                                                (state_x << 32) ^ (state_x >>> 32));
    }

}
