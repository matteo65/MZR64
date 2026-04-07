package org.mizar64.test;

import org.mizar64.Mizar64;

/**
 * Simple mizar64 generator.
 * Used to compare Miza64 java version vs Mizar64 C version
 * @author ZappMa1
 * 7 apr 2026
 */
public class SimpleGen {

    private static void usage() {
        System.out.println("SimpleGen - Print on stdout random number using miza64 PRNG");
        System.out.println("Usage: simplegen <seed c> <seed x> <n>");
    }
    
    public static void main(String[] args) {
        if(args == null || args.length == 0) {
            usage();
            System.exit(0);
        }
        
        if(args.length != 3) {
            System.err.println("*** Error: invalid number");
        }
        
        long checksum = 0L;
        long c = Long.parseLong(args[0]);
        long x = Long.parseLong(args[1]);
        int n = Integer.parseInt(args[2]);
        Mizar64 mizar64 = new Mizar64(c, x);
        while(n-- > 0) {
            long rand = mizar64.nextLong();
            System.out.printf("%016X\n", rand);
            checksum ^= rand;
        }
        System.out.printf("\nChecksum = %016X\n", checksum);
    }
}
