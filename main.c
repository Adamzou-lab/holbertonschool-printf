#include <stdio.h>
#include "main.h"

int main(void)
{
	int len1, len2;

	len1 = _printf("Hello %s!\n", "World");
	len2 = printf("Hello %s!\n", "World");

	printf("_printf length: %d\n", len1);
	printf("printf length: %d\n", len2);

	return (0);
}
