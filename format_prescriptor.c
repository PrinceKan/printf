#include "main.h"
/**
 * funct_char - Prints character
 * @list: list of arguments
 * Return: Will return the amount of characters printed.
 */
int funct_char(va_list list)
{
	funct_putchar(va_arg(list, int));
	return (1);
}

/**
 * funct_string - Prints a string
 * @list: list of arguments
 * Return: Will return the amount of characters printed.
 */
int funct_string(va_list list)
{
	int i;
	char *str;

	str = va_arg(list, char *);
	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i] != '\0'; i++)
		funct_putchar(str[i]);
	return (i);
}

/**
 * funct_percent - Prints a percent symbol
 * @list: list of arguments
 * Return: Will return the amount of characters printed.
 */
int funct_percent(__attribute__((unused))va_list list)
{
	funct_putchar('%');
	return (1);
}

/**
 * funct_intg - Prints an integer
 * @list: list of arguments
 * Return: Will return the amount of characters printed.
 */
int funct_intg(va_list list)
{
	int num_length;

	num_length = funct_num(list);
	return (num_length);
}

/**
* unsign_intg - Prints Unsigned integers
* @list: List of all of the argumets
* Return: a count of the numbers
*/
int unsign_intg(va_list list)
{
	unsigned int num;

	num = va_arg(list, unsigned int);

	if (num == 0)
		return (unsignedNumberPrinter(num));

	if (num < 1)
		return (-1);
	return (unsignedNumberPrinter(num)); /*From function helper*/
}
