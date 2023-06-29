#include "main.h"

/**
 * flags - calls or turns on flags for _printf
 * @format: format specifier for a particular conversion flag
 *
 * Return: 1 if the flag is called, 0 otherwise
*/

unsigned char flags(const char *format)
{
	unsigned char flag = 0;

	while (*format)
	{
		if (*format == ' ')
			flag |= FLAG_SPACE;
		else if (*format == '+')
			flag |= FLAG_PLUS;
		else if (*format == '-')
			flag |= FLAG_MINUS;
		else if (*format == '0')
			flag |= FLAG_ZERO;
		else if (*format == '#')
			flag |= FLAG_HASH;
		else
			break;

		format++;
	}

	return flag;
}
