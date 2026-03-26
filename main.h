#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/* Main function */
int _printf(const char *format, ...);

/* Helper functions */
int _putchar(char c);
int print_string(char *str);
int handle_format(char format, va_list args);

#endif /* MAIN_H */