#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/* Main function */
int _printf(const char *format, ...);

/* Handler specifier*/
int handle_specifier(char s, va_list args);

/* Handlers functions */
int handler_c(va_list args);
int handler_s(va_list args);
int handler_percent(va_list args);

#endif /* MAIN_H */
