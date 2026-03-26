#include "main.h"

/**
* _printf - prints formatted output
* @format: format string
*
* Return: number of characters printed
*/
int _printf(const char *format, ...)
{
	int i = 0, count = 0;

	va_list args;

	if (!format)
		return (-1);

	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (!format[i])
				return (-1);
			/* handle_specifier returns the number of characters printed */
			count += handle_specifier(format[i], args);
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
		i++;
	}

	va_end(args);
	return (count);
}
