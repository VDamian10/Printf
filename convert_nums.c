#include "main.h"

/**
 * convert_to_base - converts an unsigned int to
 * a base and stores it
 * @num: the unsigned int
 * @base: the base
 * @result: the char where it is stored
*/

void convert_to_base(unsigned int num, int base, char *result)
{
	const char *digits = "0123456789ABCDEF";
	int index = 0;

	if (num == 0)
	{
		result[index++] = '0';
		result[index] = '\0';
		return;
	}

	while (num != 0)
	{
		int digit = num % base;
		result[index++] = digits[digit];
		num /= base;
	}

	result[index] = '\0';
}

/**
 * count_digit_base - counts the number of digits in and
 * unsigned int when repreented in a base
 * @num: the unsigned int
 * @base: the base
 *
 * Return: the number of digits
*/

unsigned int count_digit_base(unsigned int num, int base)
{
	unsigned int count = 0;
	while (num != 0)
	{
		num /= base;
		count++;
	}
	return count;
}

/**
 * print_number_to_storage - Helper function that prints an integer to the storage.
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
 * @format: format specifier for flags
 * Return: number of bytes stored
*/

unsigned int replace_di(va_list args, t_buff *storage, const char *format)
{
	int num = va_arg(args, int);
	unsigned char flag = flags(format);
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
 * replace_b - replaces 'b' specifier with binary value
 * @args: list of arguments
 * @storage: buffer
 * Return: number of bytes stored
*/

unsigned int replace_b(va_list args, t_buff *storage)
{
	unsigned int num = va_arg(args, unsigned int);
	char binary[MAX_BINARY_DIGITS + 1];
	char temp;
	int i = 0, j, k;

	if (num == 0) {
		binary[i++] = '0';
	} else {
		while (num != 0) {
			binary[i++] = (num % 2) + '0';
			num /= 2;
		}
	}

	binary[i] = '\0';

	j = 0;
	k = i - 1;
	while (j < k) {
		temp = binary[j];
		binary[j] = binary[k];
		binary[k] = temp;
		j++;
		k--;
	}

	return (update_storage(storage, binary, i));
}

/**
 * replace_u - replaces 'u' specifier with unsigned integer value
 * @args: list of arguments
 * @storage: buffer
 * Return: number of bytes stored
*/

unsigned int replace_u(va_list args, t_buff *storage, const char *format)
{
	unsigned int num = va_arg(args, int);
	int res = count_digit(num);

	if (num == 0)
		res++;

	print_number_to_storage(num, storage);

	return (res);
}

/**
 * replace_o - replaces 'o' specifier with octal value
 * @args: list of arguments
 * @storage: buffer
 * Return: number of bytes stored
*/

unsigned int replace_o(va_list args, t_buff *storage)
{
	unsigned int num = va_arg(args, unsigned int);
	char octal[MAX_OCTAL_DIGITS + 1];
	char temp;
	int i = 0, j, k;

	if (num == 0) {
		octal[i++] = '0';
	} else {
		while (num != 0) {
			octal[i++] = (num % 8) + '0';
			num /= 8;
		}
	}

	octal[i] = '\0';

	j = 0;
	k = i - 1;
	while (j < k) {
		temp = octal[j];
		octal[j] = octal[k];
		octal[k] = temp;
		j++;
		k--;
	}

	return update_storage(storage, octal, i);
}
