#include "main.h"

/**
 * flags - calls or turns on flags for _printf
 * @s: char that holds the flag specifier
 * @g: pointer to the struct flag
 *
 * Return: 1 if the flag is called, 0 otherwise
*/

int flags(char s, flag_t *g)
{
	int i = 1;

	switch (s)
	{
		case '+':
			g->plus = 1;
			break;
		case '-':
			g->minus = 1;
			break;
		case '0':
			g->zero = 1;
			break;
		case '#':
			g->hash = 1;
			break;
		case ' ':
			g->space = 1;
			break;
        default:
            i = 0;
            break;
	}
	return (i);
}
