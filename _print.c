#include "main.h"
/**
 * _print - prints group of characters to output
 * @str: string to print to output
 * Description: Loops through the different characters in str
 * and prints them to output. Ends with a new line.
 *
 */

void _print(char *str)
{
	size_t i = 0;

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
}
