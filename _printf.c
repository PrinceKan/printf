#include "main.h"

/**
 * _printf - Receives the main string and all the necessary parameters to
 * print a formated string
 * @format: A string containing all the desired characters
 * Return: A total count of the characters printed
 */
int _printf(const char *format, ...)
{
	int printed_chars;
	form_stor f_list[] = {
		{"c", funct_char},
		{"s", funct_string},
		{"%", funct_percent},
		{NULL, NULL}
	};

	va_list arg_list;

	if (format == NULL)
		return (-1);

	va_start(arg_list, format);
	/*Calling descrambler function*/
	chars_to_print = descrambler(format, f_list, arg_list);
	va_end(arg_list);
	return (chars_to_print);
}
