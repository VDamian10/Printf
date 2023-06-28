#include "main.h"

/**
 * replace_c - replaces a 'c' convert_specs with appropriate value
 * @args: list of srguments
 * @storage: buffer
 * @flag: flag formatter
 * Return: byte number stored in storage
*/

unsigned int replace_c(va_list args, t_buff *storage, unsigned char flag)
{
	char x;
	unsigned int byte_num = 0;

	(void)flag;

	x = va_arg(args, int);
	byte_num += update_storage(storage, &x, 1);
	return (byte_num);
}

/**
 * replace_percentage - replcaes % convert_sepcs with appropriate value
 * @args: list of arguments
 * @storage: buffer
 * @flag: flag formatter
 * Return: byte number stored in storage
*/

unsigned int replace_percentage(va_list args, t_buff *storage, unsigned char flag)
{
	const char percentage = '%';
	unsigned int byte_num = 0;

	(void)flag;
	(void)args;

	byte_num += update_storage(storage, &percentage, 1);
	return (byte_num);
}

/**
 * replace_p - replaces 'p' specifier with mem address value
 * @args: list of arguments
 * @storage: buffer
 * @flag: flag formatter
 * Return: number of bytes stored
*/

/*unsigned int replace_p(va_list args, t_buff *storage, unsigned char flag)
{

}
*/