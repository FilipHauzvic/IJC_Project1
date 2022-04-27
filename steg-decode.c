// ppm.c
// Řešení IJC-DU1, příklad b), 13.3.2022
// Autor: Filip Haužvic, FIT
// Přeloženo: gcc 9.3.0
#include "error.h"
#include "eratosthenes.h"
#include "ppm.h"
#include "bitset.h"
#include <stdio.h>

int main(int argc, char* argv[])
{
    if(argc != 2){
        error_exit("Špatný počet argumentů\n");
    }

    struct ppm *picture_data = ppm_read(argv[1]);
    if(!picture_data){
        error_exit("Chyba při načítání obrázku\n");
    }
    
    unsigned long data_size = picture_data->xsize * picture_data->ysize * 3;
    bitset_alloc(prime_array, data_size);
    eratosthenes(prime_array);
    
    char current_byte[1] = {0};
    unsigned long bit_count = 0;
    for(unsigned long i = 29; i < data_size; i++){
        if(bitset_getbit(prime_array, i) != 0){
            continue;
        }

        char current_bit = bitset_getbit_unrestricted((&(picture_data->data[i])), 0);
        bitset_setbit_unrestricted(current_byte, bit_count, current_bit);
        bit_count++;

        if(bit_count >= 8){
            if(current_byte[0] == '\0'){
                bitset_free(prime_array);
                ppm_free(picture_data);
                putchar('\n');
                return 0;
            }
            putchar(current_byte[0]);
            current_byte[0] = 0;
            bit_count = 0;
        }
    }

    bitset_free(prime_array);
    ppm_free(picture_data);
    error_exit("Zpráva nebyla korektně ukončena\n");
}