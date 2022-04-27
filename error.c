// error.c
// Řešení IJC-DU1, příklad b), 9.3.2022
// Autor: Filip Haužvic, FIT
// Přeloženo: gcc 9.3.0

#include "error.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void warning_msg(const char *fmt, ...){
    va_list argumenty;
    va_start(argumenty, fmt);

    fprintf(stderr, "Chyba: ");
    vfprintf(stderr, fmt, argumenty);

    va_end(argumenty);
}

void error_exit(const char *fmt, ...){
    va_list argumenty;
    va_start(argumenty, fmt);

    fprintf(stderr, "Chyba: ");
    vfprintf(stderr, fmt, argumenty);

    va_end(argumenty);
    exit(1);
}