// primes.c
// Řešení IJC-DU1, příklad a), 9.3.2022
// Autor: Filip Haužvic, FIT
// Přeloženo: gcc 9.3.0

#include "eratosthenes.h"
#include "bitset.h"
#include <stdio.h>
#include <time.h>

#define VELIKOST_POLE 300000000
#define POCET_PRVOCISEL 10

int main(){
    clock_t start = clock();

    // bitset_create(pole, VELIKOST_POLE);
    bitset_alloc(pole, VELIKOST_POLE);
    eratosthenes(pole);

    int pocet = 0;
    bitset_t posledni[POCET_PRVOCISEL] = {0};
    for(bitset_index_t i = bitset_size(pole) - 1; pocet < POCET_PRVOCISEL; i--){
        if((bitset_getbit(pole, i)) == 0){
            posledni[pocet++] = i;
        }
        if(i == 1) break;
    }
    
    while(pocet != 0){
        printf("%lu\n", posledni[--pocet]);
    }

    bitset_free(pole);
    fprintf(stderr, "Time=%.3g\n", (double)(clock()-start)/CLOCKS_PER_SEC);
}