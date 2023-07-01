#include "main.h"

/**
 * replace_s - replaces convert_specs character with string
 * @args: list of arguments
 * @storage: buffer
 * @format: string to be formatted
 * @flag: flag formatter
 * Return: byte number stored
*/

unsigned int replace_s(va_list args, t_buff *storage, const char *format, unsigned char flag)
{
	int i;
	const char *fstring;
	char *null = "null";
	unsigned int o = 0;

	(void)format;
	(void)flag;

	fstring = va_arg(args, char *);
	if (!fstring)
	{
		o += update_storage(storage, null, 4);
	}

	for (i = 0; fstring[i] != '\0'; i++)
	{
		o += update_storage(storage, (fstring + i), 1);
	}

	return (o);
}


/**
 * replace_r - replaces convert_specs character with string
 * @args: list of arguments
 * @storage: buffer
 * @format: string to be formatted
 * @flag: flag formatter
 * Return: byte number stored
*/

unsigned int replace_r(va_list args, t_buff *storage, const char *format, unsigned char flag)
{
	const char *revstr;
	int len = 0, i, j;
	unsigned int o = 0;
	char *null = "null";

	(void)format;
	(void)flag;

	revstr = va_arg(args, char *);
	if (!revstr)
		o += update_storage(storage, null, 4);

	for (i = 0; revstr[i] != '\0'; i++)
	{
		len++;
	}
	len++;

	for (j = len - 1; j > 0; j--)
	{
		o += update_storage(storage, (revstr + j), 1);
	}

	return (o);
}

/**
 * replace_R - replaces convert_specs character with string
 * @args: list of arguments
 * @storage: buffer
 * @format: string to be formatted
 * @flag: flag formatter
 * Return: byte number stored
*/

unsigned int replace_R(va_list args, t_buff *storage, const char *format, unsigned char flag)
{

	char *alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *rotstr = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *str, *null = "null";
	int i;
	unsigned int w = 0;

	(void)flags;
	(void)format;

	str = va_arg(args, char *);
	if (!str)
		return (update_storage(storage, null, 4));

	for (i = 0; *(str + i) != '\0'; i++)
	{
		if (*(str + i) == *(alphabet + i))
		{
			w += update_storage(storage, (rotstr + i), 1);
			break;
		}
	}
	return (w);
}

