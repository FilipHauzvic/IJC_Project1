// ppm.h
// Řešení IJC-DU1, příklad b), 13.3.2022
// Autor: Filip Haužvic, FIT
// Přeloženo: gcc 9.3.0

#ifndef PPM_H
#define PPM_H 1

#define PPM_MAX_SIZE (8000 * 8000 * 3)

struct ppm {
    unsigned xsize;
    unsigned ysize;
    char data[];    // RGB bajty, celkem 3*xsize*ysize
};

struct ppm *ppm_read(const char *filename);
void ppm_free(struct ppm *p);

#endif