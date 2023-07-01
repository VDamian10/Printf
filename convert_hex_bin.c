#include "main.h"

/**
 * replace_x - replaces convert_specs character with string
 * @args: list of arguments
 * @storage: buffer
 * @format: string to be formatted
 * @flag: flag formatter
 * Return: byte number stored
*/

unsigned int replace_x(va_list args, t_buff *storage, const char *format, unsigned char flag)
{
	unsigned int num = va_arg(args, unsigned int);
	int res = count_digit_base(num, 16);

	(void)format;

	if (flag & FLAG_HASH && num != 0)
		res += update_storage(storage, "0x", 2);

	print_hex_to_storage(num, storage, FLAG_LOWER);

	return (res);
}

/**
 * replace_X - replaces convert_specs character with string
 * @args: list of arguments
 * @storage: buffer
 * @format: string to be formatted
 * @flag: flag formatter
 * Return: byte number stored
*/

unsigned int replace_X(va_list args, t_buff *storage, const char *format, unsigned char flag)
{
	unsigned int num = va_arg(args, unsigned int);
	int res = count_digit_base(num, 16);

	(void)format;

	if (flag & FLAG_HASH && num != 0)
		res += update_storage(storage, "0X", 2);

	print_hex_to_storage(num, storage, FLAG_UPPER);

	return (res);
}

/**
 * print_hex_to_storage - prints hex int to storage buffer
 * @num: the number
 * @storage: pointer to buffer struct
 * @flags: flag specifier
*/
void print_hex_to_storage(unsigned int num, t_buff *storage, unsigned char flags)
{
	unsigned int num_digits = count_digit_base(num, 16);
	char *hex_str = malloc(num_digits + 1);

	const char *hex_digits_upper;
	const char *hex_digits_lower;
	const char *hex_digits;
	unsigned int i;

	if (hex_str == NULL)
		return;
	hex_digits_upper = "0123456789ABCDEF";
	hex_digits_lower = "0123456789abcdef";
	hex_digits = (flags & FLAG_UPPER) ? hex_digits_upper : hex_digits_lower;

	for (i = num_digits - 1; i < num_digits; i--)
	{
		hex_str[i] = hex_digits[num & 0xF];
		num >>= 4;
	}
	hex_str[num_digits] = '\0';

	update_storage(storage, hex_str, num_digits);

	free(hex_str);
}
