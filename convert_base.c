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
	int index = 0, digit;

	if (num == 0)
	{
		result[index++] = '0';
		result[index] = '\0';
		return;
	}
	while (num != 0)
	{
		digit = num % base;
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
	return (count);
}

/**
 * replace_b - replaces 'b' specifier with binary value
 * @args: list of arguments
 * @storage: buffer
 * @flag: flag formatter
 * Return: number of bytes stored
*/

unsigned int replace_b(va_list args, t_buff *storage, unsigned char flag)
{
	unsigned int count, num = va_arg(args, unsigned int);
	char *binary;
	char temp;
	int i = 0, j, k;


	(void)flag;

	if (num == 0)
	{
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> origin/bez
		binary = malloc(sizeof(char) * 2);

		if (!binary)
			return (0);

		binary[0] = '0';
		binary[1] = '\0';

	}
	else
	{
		count = count_digit_base(num, 2);

		binary = malloc(sizeof(char) * (count + 1));

		if (!binary)
			return (0);

		while (num != 0) 
		{
			binary[i++] = (num % 2) + '0';
			num /= 2;
		}

		binary[i] = '\0';
	}

	j = 0;
	k = i - 1;
	while (j < k)
	{
		temp = binary[j];
		binary[j] = binary[k];
		binary[k] = temp;
		j++;
		k--;
	}

	return (update_storage(storage, binary, i));
}

/**
 * replace_o - replaces 'o' specifier with octal value
 * @args: list of arguments
 * @storage: buffer
 * @flag: flag formatter
 * Return: number of bytes stored
*/

unsigned int replace_o(va_list args, t_buff *storage, unsigned char flag)
{
	unsigned int num = va_arg(args, unsigned int);
	char octal[MAX_OCTAL_DIGITS + 1];
	char temp;
	int i = 0, j, k;

	(void)flag;

	if (num == 0)
	{
		octal[i++] = '0';
	}
	else
	{
		while (num != 0)
		{
			octal[i++] = (num % 8) + '0';
			num /= 8;
		}
	}

	octal[i] = '\0';

	j = 0;
	k = i - 1;
	while (j < k)
	{
		temp = octal[j];
		octal[j] = octal[k];
		octal[k] = temp;
		j++;
		k--;
	}
	return (update_storage(storage, octal, i));
}
