#include "main.h"
/**
 * handle_specifier - Determines which handler function to use based on
 * the specifier character.
 * @s: The specifier character (e.g., 'c', 's', '%').
 * @args: The list of arguments to be processed.
 *
 * Return: The number of characters printed.
 */
int get_handler(char s, va_list args)
{
	char percent = '%';

	if (s == 's')
		return (handler_s(args));
	if (s == 'c')
		return (handler_c(args));
	if (s == '%')
		return (handler_percent(args));

	write(1, &percent, 1);
	write(1, &s, 1);
	return (2);
}
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
			{
				va_end(args);
				return (-1);
			}
			count += get_handler(format[i], args);
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
