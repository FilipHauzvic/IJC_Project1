## C language project #1

**Primes** prints out the last N prime numbers from X numbers using Eratosthenes sieve.
N and X are constants defined in primes.c.
**Primes-i** does the same thing, but uses inline functions instead of macros.
Usage:  ./primes
        ./primes-i

**Steg-decode** reads a secret message from a picture of ppm format.
The message is a string of chars. Reads the color data of the picture.
Every byte which has a prime index (starting at 29) contains 1 bit from the char (LSB).
The decoding is ended when 0 is read.
Usage:  ./steg-decode picture.ppm

Use ***make*** to compile, ***make run*** to compile and run primes and primes-i, ***make clean*** to delete binaries.