#include "main.h"

/**
 * start_printf - formats a string
 * @format: string to be printed
 * @args: argument list
 * @storage: buffer
 * Return: number of bytes on success or -1 on error
*/

int start_printf(const char *format, va_list args, t_buff *storage)
{
	int o, tot_num = 0;
<<<<<<< HEAD
	unsigned int (*hand)(va_list, t_buff *, const char *, unsigned char);
=======
	char strindex;
>>>>>>> origin/bez
	unsigned char flag;
	unsigned int (*hand)(va_list, t_buff *, unsigned char);

	for (o = 0; *(format + o) != '\0'; o++)			/* iterate through string */
	{
<<<<<<< HEAD

		if (format[o] == '%')			/* beginning of format specifier */
=======
		if (*(format + o) == '%')			/* beginning of format specifier */
>>>>>>> origin/bez
		{
			flag = flags(format + o + 1);
<<<<<<< HEAD
			if (flag != 0)
				o++;

			hand = hand_spec(format + o + 1);
			if (hand != NULL)
			{
				o++;
				tot_num += hand(args, storage, (format + o), flag);
				continue;
			}
			else
			{
				tot_num = -1;
				break;
			}
		}
		tot_num += update_storage(storage, (format + o), 1);

	}
	tot_num += write(1, storage->buffer, storage->length);
=======
			o++;
			while (format[o] == '-' || format[o] == '+' || format[o] == ' '
			|| format[o] == '0' || format[o] == '#')
			{
				strindex++;
				o++;
			}
			hand = hand_spec(format + o + strindex);
			if (*(format + o + strindex + 1) == '\0')
			{
				tot_num = -1;
				break;
			}
			if (hand)
			{
				o += strindex + 1;
				tot_num += hand(args, storage, flag);
			}
		}
		else
		{
			_putchar(storage, format[o]);
			tot_num++;
		}
	}
>>>>>>> origin/bez
	return (tot_num);
}


/**
 * _printf - prints to standard output
 * @format: string to be printed
 * Return: number of bytes on success or -1 on error
*/

int _printf(const char *format, ...)
{
	t_buff *storage;			/* declare a buffer to store the string */
	va_list args;
	int num;

	if (!format)
		return (-1);

	storage = start_buff();				/* initialize the buffer */

	if (!storage)
		return (-1);

	va_start(args, format);

	num = start_printf(format, args, storage);		/* begin operation on format */

	va_end(args);

	return (num);
}
