# Mizar64 PRNG
Mizar64 is an ultra-fast, minimalist, robust pseudo-random number generator (PRNG) designed for high-performance applications, simulations, and games. 

## Period

## Features

## Algorithm Logic
Mizar64 uses a cross-coupled mixing technique. It evolves a linear counter (LCG), then applies a non-linear mixing phase involving 32-bit XOR-rotations and a final multiplication to ensure maximum bit diffusion.

## Performance Benchmark
Numerous tests were performed with different tools:
- **Dieharder v. 3.31.1**
- **RNG_test v. 0.96** (PractRand - SourceForge) (compiler: g++ (Ubuntu 13.3.0-6ubuntu2~24.04.1) 13.3.0)
- **SmokeRand v. 0.46** gcc-linux64

The tests are executed on
- Linux mzpc2023 6.6.87.2-microsoft-standard-WSL2 #1 SMP PREEMPT_DYNAMIC Thu Jun  5 18:30:46 UTC 2025 x86_64 x86_64 x86_64 GNU/Linux

## Language	Cycles/Num	Speed (approx)

## Usage

## Compilation

## Versioning
Current Version: 1.0.0 (MIZAR64_VERSION 100)

## License
This project is released under the **Apache 2.0 License** - see the LICENSE file for details.
