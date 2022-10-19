#include "main.h"

/**
 * parser - Receives the main string and all the necessary parameters to
 * print a formated string.
 * @format: A string containing all the desired characters.
 * @f_list: A list of all the posible functions.
 * @arg_list: A list containing all the argumentents passed to the program.
 * Return: A total count of the characters printed.
 */
int descrambler(const char *format, form_stor f_list[], va_list arg_list)
{
	int i, j, rtrn_val_stored, chars_to_print;

	chars_to_print = 0;
	for (i = 0; format[i] != '\0'; i++)/* Iterates through the main str*/
	{
		if (format[i] == '%') /*Checks for format specifiers*/
		{
			/*Iterates through struct to find the right function*/
			for (j = 0; f_list[j].form != NULL; j++)
			{
				if (format[i + 1] == f_list[j].form[0])
				{
					rtrn_val_stored = f_list[j].funct(arg_list);
					if (rtrn_val_stored == -1)
						return (-1);
					chars_to_print += rtrn_val_stored;
					break;
				}
			}
			if (f_list[j].form == NULL && format[i + 1] != ' ')
			{
				if (format[i + 1] != '\0')
				{
					funct_putchar(format[i]);
					funct_putchar(format[i + 1]);
					chars_to_print = chars_to_print + 2;
				}
				else
					return (-1);
			}
			i = i + 1; /*Updating i to skip format symbols*/
		}
		else
		{
			funct_putchar(format[i]); /*call the fuction wich will write*/
			chars_to_print++;
		}
	}
	return (chars_to_print);
}

