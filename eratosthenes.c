// eratosthenes.c
// Řešení IJC-DU1, příklad a), 9.3.2022
// Autor: Filip Haužvic, FIT
// Přeloženo: gcc 9.3.0

#include "bitset.h"
#include "eratosthenes.h"
#include <math.h>

void eratosthenes(bitset_t pole[]){
    // cisla 1 a 2 nejsou prvocisla
    bitset_setbit(pole, 0, 1);
    bitset_setbit(pole, 1, 1);

    bitset_index_t max = sqrt(bitset_size(pole));

    for(bitset_index_t i = 2; i <= max; i++){
        if(bitset_getbit(pole, i) == 0){
            for(bitset_index_t nasobek = i * i; nasobek < bitset_size(pole); nasobek += i){
                bitset_setbit(pole, nasobek, 1);
            }
        }
    }
}