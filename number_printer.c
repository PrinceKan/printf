#include "main.h"

/**
 * funct_num - prints a number send to this function
 * @args: List of arguments
 * Return: The number of arguments printed
 */
int funct_num(va_list args)
{
	int n;
	int div;
	int len;
	unsigned int num;

	n  = va_arg(args, int);
	div = 1;
	len = 0;

	if (n < 0)
	{
		len += funct_putchar('-');
		num = n * -1;
	}
	else
		num = n;

	for (; num / div > 9; )
		div *= 10;

	for (; div != 0; )
	{
		len += funct_putchar('0' + num / div);
		num %= div;
		div /= 10;
	}

	return (len);
}