// error.h
// Řešení IJC-DU1, příklad b), 9.3.2022
// Autor: Filip Haužvic, FIT
// Přeloženo: gcc 9.3.0

#ifndef ERROR_H
#define ERROR_H 1

void warning_msg(const char *fmt, ...);
void error_exit(const char *fmt, ...);

#endif