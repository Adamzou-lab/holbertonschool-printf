#include "main.h"
/**
 * handler_c - Prints a character.
 * @args: A list of arguments pointing to the character to be printed.
 *
 * Return: The number of characters printed (always 1).
 */
int handler_c(va_list args)
{
	int c;

	c = va_arg(args, int);
	write(1, &c, 1);

	return (1);
}
/**
 * handler_s - Prints a string.
 * @args: A list of arguments pointing to the string to be printed.
 *
 * Return: The number of characters printed.
 */
int handler_s(va_list args)
{
	char *str;
	int i;

	str = va_arg(args, char *);
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	for (i = 0; str[i] != '\0'; i++)
		write(1, &str[i], 1);
	return (i);
}
/**
 * handler_percent - Prints a percent sign.
 * @args: A list of arguments (unused).
 *
 * Return: The number of characters printed (always 1).
 */
int handler_percent(va_list args)
{
	char percent = '%';
	(void)args;

	write(1, &percent, 1);
	return (1);
}
/**
 * handler_di - Gère les spécificateurs de format %d et %i.
 * @args: Liste des arguments variadiques.
 *
 * Return: Le nombre de caractères imprimés.
 */
int handler_di(va_list args)
{
	char minus;
	int n;
	int count;

	n = va_arg(args, int);
	if (n == INT_MIN)
	{
		/* Pour éviter l'overflow on le print direct */
		write(1, "-2147483648", 11);
		return (11);
	}

	if (n < 0)
	{
		minus = '-';
		write(1, &minus, 1);
		/* On reverse n pour pas qu'il soit négatif n = -(-42) = 42 */
		n = -n;
		count = print_int(n) + 1;
	}
	else
		count = print_int(n);
	return (count);
}
