// ppm.c
// Řešení IJC-DU1, příklad b), 13.3.2022
// Autor: Filip Haužvic, FIT
// Přeloženo: gcc 9.3.0
#include "ppm.h"
#include "error.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ppm *ppm_read(const char *filename){
    FILE *ppm_file = fopen(filename, "rw");
    if(!ppm_file){
        warning_msg("ppm_read: Chyba při otevírání %s\n", filename);
        return NULL;
    }

    char format[3];
    unsigned int width;
    unsigned int height;
    unsigned char color;

    int read_arguments = fscanf(ppm_file, "%2s %u %u %hhu", format, &width, &height, &color);
    if(read_arguments < 4){
        warning_msg("ppm_read: Chyba při čtení vlastností ze souboru %s\n", filename);
        fclose(ppm_file);
        return NULL;
    }

    if(strcmp(format, "P6") != 0){
        warning_msg("ppm_read: Špatný formát\n");
        fclose(ppm_file);
        return NULL;
    }

    unsigned long data_size = width * height * 3;
    if(data_size > PPM_MAX_SIZE){
        warning_msg("ppm_read: Velikost obrázku přesáhla daný limit\n");
        fclose(ppm_file);
        return NULL;
    }

    struct ppm *result = malloc(sizeof(struct ppm) + data_size);
    if(!result){
        warning_msg("ppm_read: Chyba při alokaci paměti\n");
        fclose(ppm_file);
        return NULL;
    }

    result->xsize = width;
    result->ysize = height;

    unsigned long read_values = fread(result->data, sizeof(char), data_size, ppm_file);
    if(read_values != data_size){
        warning_msg("ppm_read: Chyba při čtení dat ze souboru %s\n", filename);
        fclose(ppm_file);
        free(result);
        return NULL;
    }

    fclose(ppm_file);
    return result;
}

void ppm_free(struct ppm *p){
    free(p);
}