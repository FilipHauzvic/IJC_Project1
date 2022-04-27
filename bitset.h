// bitset.h
// Řešení IJC-DU1, příklad a), 9.3.2022
// Autor: Filip Haužvic, FIT
// Přeloženo: gcc 9.3.0

#ifndef BITSET_H
#define BITSET_H 1

#include "error.h"
#include <assert.h>
#include <stdlib.h>

typedef unsigned long bitset_t;
typedef unsigned long bitset_index_t;

#define UL_SIZE (sizeof(bitset_t) * 8)

// vypocita pocet unsigned long potrebnych pro reprezentaci daneho poctu bitu
// pricitani v citateli (+ sizeof(bitset_t - 1)) pro zaokrouhleni nahoru
#define bit_to_ul(velikost)\
    (((velikost) + UL_SIZE - 1) / (UL_SIZE))

#define bitset_create(jmeno_pole, velikost)\
    static_assert(velikost >= 0, "Velikost musí být kladné číslo!\n");\
    bitset_t jmeno_pole[bit_to_ul(velikost) + 1] = {velikost, 0}

#define bitset_alloc(jmeno_pole, velikost)\
    bitset_t *jmeno_pole = calloc(bit_to_ul(velikost) + 1, sizeof(bitset_t));\
    if(!jmeno_pole){\
        error_exit("bitset_alloc: Chyba alokace paměti\n");\
    }\
    jmeno_pole[0] = velikost

#ifndef USE_INLINE

#define bitset_free(jmeno_pole)\
    free(jmeno_pole)

#define bitset_size(jmeno_pole)\
    jmeno_pole[0]

#define bitset_setbit(jmeno_pole, index, vyraz)\
    do{\
        if(index >= bitset_size(jmeno_pole)){\
            error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu\n",\
                (unsigned long)index, (unsigned long)bitset_size(jmeno_pole));\
        }\
        if(vyraz){\
            jmeno_pole[1 + bit_to_ul(index)] |= (1ul << ( (index) % UL_SIZE));\
        }else{\
            jmeno_pole[1 + bit_to_ul(index)] &= (~(1ul << ( (index) % UL_SIZE)));\
        }\
    }while(0)

#define bitset_setbit_unrestricted(jmeno_pole, index, vyraz)\
    do{\
        if(vyraz){\
            jmeno_pole[1 + bit_to_ul(index)] |= (1ul << ( (index) % UL_SIZE));\
        }else{\
            jmeno_pole[1 + bit_to_ul(index)] &= (~(1ul << ( (index) % UL_SIZE)));\
        }\
    }while(0)

#define bitset_getbit(jmeno_pole, index)\
    ((index) >= bitset_size(jmeno_pole)) ? (\
        error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu\n",\
        (unsigned long)index, (unsigned long)bitset_size(jmeno_pole)), 0 \
    ) : (\
    (jmeno_pole[1 + bit_to_ul(index)] & (1ul << ( (index) % UL_SIZE))) ? 1 : 0\
    )

#define bitset_getbit_unrestricted(jmeno_pole, index)\
    (jmeno_pole[1 + bit_to_ul(index)] & (1ul << ( (index) % UL_SIZE))) ? 1 : 0
#else

inline void bitset_free(bitset_t jmeno_pole[]){
    free(jmeno_pole);
}

inline bitset_index_t bitset_size(bitset_t jmeno_pole[]){
    return jmeno_pole[0];
}

inline void bitset_setbit(bitset_t jmeno_pole[], bitset_index_t index, int vyraz){
    if(index >= bitset_size(jmeno_pole)){
        error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu\n",
            (long long)index, (long long)bitset_size(jmeno_pole));
    }
    
    if(vyraz){
        jmeno_pole[1 + bit_to_ul(index)] |= (1ul << ( (index) % UL_SIZE));
    }else{
        jmeno_pole[1 + bit_to_ul(index)] &= (~(1ul << ( (index) % UL_SIZE)));\
    }
}

inline int bitset_getbit(bitset_t jmeno_pole[], bitset_index_t index){
    if(index >= bitset_size(jmeno_pole)){
        error_exit("bitset_setbit: Index %lli mimo rozsah 0..%lli\n",
        (long long)index, (long long)bitset_size(jmeno_pole));
    }

    return (jmeno_pole[1 + bit_to_ul(index)] & (1ul << ( (index) % UL_SIZE))) ? 1 : 0;
}

#endif
#endif