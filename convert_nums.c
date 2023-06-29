#include "main.h"

/**
 * print_unsigned_to_storage - Prints an unsigned integer to the storage buffer
 * @num: The unsigned integer to print
 * @storage: The storage buffer
 *
 * Return: void
 */

void print_unsigned_to_storage(unsigned int num, t_buff *storage)
{
	char buffer[21];
	int len = 0, i;

	if (num == 0)
	{
		buffer[len++] = '0';
	}
	else
	{
		while (num != 0)
		{
			buffer[len++] = (num % 10) + '0';
			num /= 10;
		}
	}

	for (i = len - 1; i >= 0; i--)
		update_storage(storage, &buffer[i], 1);
}


/**
 * print_number_to_storage - Helper function that
 * prints an integer to the storage.
 * @n: The integer to be printed.
 * @storage: Pointer to the buffer structure for storing the result.
 */
void print_number_to_storage(int n, t_buff *storage)
{
	unsigned int n1;
	char digit;

	if (n < 0)
	{
		update_storage(storage, "-", 1);
		n1 = -n;
	}
	else
		n1 = n;

	if (n1 / 10)
		print_number_to_storage(n1 / 10, storage);

	digit = (n1 % 10) + '0';
	update_storage(storage, &digit, 1);
}

/**
 * count_digit - Returns the number of digits in an integer.
 * @i: The integer to evaluate.
 *
 * Return: The number of digits.
 */
int count_digit(int i)
{
	unsigned int d = 0;
	unsigned int u;

	if (i < 0)
		u = -i;
	else
		u = i;

	while (u != 0)
	{
		u /= 10;
		d++;
	}

	return (d);
}

/**
 * replace_di - replaces 'd' or 'i' specifier with integer value
 * @args: list of arguments
 * @storage: buffer
 * @flag: flag formatter
 * Return: number of bytes stored
*/

unsigned int replace_di(va_list args, t_buff *storage, unsigned char flag)
{
	int num = va_arg(args, int);
	int res = count_digit(num);

	if ((flag & FLAG_SPACE) && !(flag & FLAG_PLUS) && num >= 0)
		res += update_storage(storage, " ", 1);
	if (flag & FLAG_PLUS && num >= 0)
		res += update_storage(storage, "+", 1);
	if (num <= 0)
		res++;

	print_number_to_storage(num, storage);

	return (res);
}

/**
 * replace_u - replaces 'u' specifier with unsigned integer value
 * @args: list of arguments
 * @storage: buffer
 * @flag: flag formatter
 * Return: number of bytes stored
*/

unsigned int replace_u(va_list args, t_buff *storage, unsigned char flag)
{
	unsigned int num = va_arg(args, int);
	int res = count_digit_base(num, 10);

	(void)flag;

	if (num == 0)
		res++;

	print_unsigned_to_storage(num, storage);

	return (res);
}
