// bitset.c
// Řešení IJC-DU1, příklad a), 9.3.2022
// Autor: Filip Haužvic, FIT
// Přeloženo: gcc 9.3.0
#include "bitset.h"

extern inline void bitset_free(bitset_t jmeno_pole[]);
extern inline bitset_index_t bitset_size(bitset_t jmeno_pole[]);
extern inline void bitset_setbit(bitset_t jmeno_pole[], bitset_index_t index, int vyraz);
extern inline int bitset_getbit(bitset_t jmeno_pole[], bitset_index_t index);