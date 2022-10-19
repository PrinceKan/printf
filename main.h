#ifndef ALXPRINTF_H
#define ALXPRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>

/*
 * The purpose of this structure is to store the format specifier
 * and its corresponding function. This way, we can call a function
 * depending on what format specifier was passed as an argument
 */

struct format_store
{
	char *form;
	int (*funct)(va_list);
};
typedef struct format_store form_stor;/*
				       * works by creating an alias
				       * for the data type struct convert
				       */

/*protypes*/

int _printf(const char *format, ...);

int descrambler(const char *format, form_stor Flist[] va_list arg_list);/*
									 * function uses to identenfy
									 * the type of argumument symbol
									 * passed to a strimg into a function
									 */

int funct_putchar(char);/*printing a character*/

int funct_char(va_list);/*Function prints a character.*/

int funct_string(va_list);/*
			   * takes a string as an argument and
			   * prints each character of the string
			   */

int funct_percent(va_list);/*
			    * takes in a list of arguments
			    * and returns an integer
			    */

int funct_intg(va_list);/*
			 * function that takes in the list of
			 * arguments, then calling print_number
			 * to print the number
			 */

int funct_num(va_list);/* int funct_num(va_list);
			* kes an integer as argument and prints it
			* It uses the _write_char function to print
			* each digit of the number
			*/

int funct_bin(va_list);/*
			* function takes an int as a
			* parameter and prints it in
			* binary
			*/

int funct_reverter(va_list arg); /*This function prints a string in reverse*/

int rot13(va_list);/*
		    * The function returns the
		    * numbers of characters printed
		    */

int unsign_intg(va_list);/*
			  * function that takes a list of arguments and
			  * assigning the next argument in that list to
			  * an unsigned int variable
			  */

int unsign_intg(va_list);/*
			  * function that takes a list of arguments and
			  * assigning the next argument in that list to
			  * an unsigned int variable
			  */


int funct_oct(va_list list);/*
			     * converting the number to octal and then
			     * printing that representation
			     */

int funct_hex(va_list list);/*
			     * prints a number in
			     * uppercaae hexadecimal format
			     */

int funct_HEX(va_list list);/*
			     * prints a number in lowercase
			     * hexadecimal format
			     */

#endif
