#include "main.h"

/**
 * replace_c - replaces a 'c' convert_specs with appropriate value
 * @args: list of srguments
 * @storage: buffer
 * @format: string to be formatted
 * @flag: flag formatter
 * Return: byte number stored in storage
*/

unsigned int replace_c(va_list args, t_buff *storage, const char *format, unsigned char flag)
{
	char x;

	(void)flag;
	(void)format;

	x = va_arg(args, int);
	return (update_storage(storage, &x, 1));
}

/**
 * replace_percentage - replcaes % convert_sepcs with appropriate value
 * @args: list of arguments
 * @storage: buffer
 * @format: string to be formatted
 * @flag: flag formatter
 * Return: byte number stored in storage
*/

unsigned int replace_percentage(va_list args, t_buff *storage, const char *format, unsigned char flag)
{
	const char percentage = '%';

	(void)flag;
	(void)args;
	(void)format;

	return (update_storage(storage, &percentage, 1));
}

/**
 * replace_p - replaces 'p' specifier with mem address value
 * @args: list of arguments
 * @storage: buffer
 * @format: string to be formatted
 * @flag: flag formatter
 * Return: number of bytes stored
*/

/*unsigned int replace_p(va_list args, t_buff *storage, const char *format, unsigned char flag)
{

}
*/
