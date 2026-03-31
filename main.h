#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

/* Main function */
int _printf(const char *format, ...);

/* Handler specifier */
int get_handler(char s, va_list args);

/* Handlers functions */
int handler_c(va_list args);
int handler_s(va_list args);
int handler_percent(va_list args);
int handler_di(va_list args);

/* Print number functions */
int print_int(int n);

#endif
