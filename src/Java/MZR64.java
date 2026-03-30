package org.mzr;

/**
 * MZR64 PRNG - Minimalist Zap-Rand 64-bit
 * Java implementation (Thread-safe)
 */
public class MZR64 {

    private static final long MZR_GOLDEN = 0x9E3779B97F4A7C15L;
    private static final long MZR_WEYL   = 0x14057B7EF767814FL;

    private long s; // Internal counter
    private long v; // Mixing state

    public MZR64(long seed) {
        seed(seed);
    }

    public void seed(long seed) {
        this.s = seed;
        this.v = ~seed;
    }

    public long nextLong() {
        // Linear step
        s = s * MZR_GOLDEN + MZR_WEYL;
        
        // Mixing step: Java's >>> is the logical (unsigned) right shift
        v = MZR_GOLDEN * ((s << 32) ^ (s >>> 32) ^ (v << 32) ^ (v >>> 32));
        return v;
    }
}