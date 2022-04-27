CFLAGS = -g -std=c11 -pedantic -Wall -Wextra
LDFLAGS = -lm
OFLAG = -O2

all : primes primes-i steg-decode

run : all
	./primes
	./primes-i

primes : primes.c error.c eratosthenes.c bitset.h
	gcc $(CFLAGS) $(OFLAG) primes.c error.c eratosthenes.c -o primes $(LDFLAGS)

primes-i : primes.c error.c eratosthenes.c bitset.h bitset.c
	gcc $(CFLAGS) $(OFLAG) -DUSE_INLINE primes.c error.c eratosthenes.c bitset.c -o primes-i $(LDFLAGS)

steg-decode : steg-decode.c error.c eratosthenes.c ppm.c bitset.h
	gcc $(CFLAGS) $(OFLAG) steg-decode.c error.c eratosthenes.c ppm.c -o steg-decode $(LDFLAGS)

clean : 
	rm -f *.o primes primes-i steg-decode *.zip