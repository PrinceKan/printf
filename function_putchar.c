#include "main.h"

/**
 * funct_putchar - writes a character to stdout
 * @a: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately
 */

int funct_putchar(char a)
{
	return (write(1, &a, 1));
}
