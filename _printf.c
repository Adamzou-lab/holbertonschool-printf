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

	char c;

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
			if (format[i] == 'c')
				count += handler_c(args);
			else if (format[i] == 's')
				count += handler_s(args);
			else if (format[i] == '%')
				count += handler_percent(args);
			else
			{
				c = '%';
				write(1, &c, 1);
				write(1, &format[i], 1);
				count += 2;
			}
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}

	va_end(args);
	return (count);
}
