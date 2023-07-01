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

unsigned int replace_p(va_list args, t_buff *storage, const char *format, unsigned char flag)
{
    void *ptr = va_arg(args, void *);
    unsigned int res = 0;
    (void)format;
    (void)flag;

    res += update_storage(storage, "0x", 2);
    res += print_address_to_storage(ptr, storage);

    return (res);
}

/**
 * print_address_to_storage - Prints a memory address to the storage buffer
 * @ptr: Pointer to the memory address to be printed
 * @storage: Buffer
 * Return: Number of bytes stored
 */
unsigned int print_address_to_storage(void *ptr, t_buff *storage)
{
    unsigned long int address = (unsigned long int)ptr;
    unsigned int digits = 2 * sizeof(address) + 3;
    unsigned int res = 0;

    char *buffer;
    char hex_digit;
    int i, j, remainder;

    if (!ptr)
        return (update_storage(storage, "(nil)", 5));


    buffer = (char *)malloc(digits * sizeof(char));
    if (!buffer)
        return (0);

    for (i = 0; address > 0; i++)
    {
        remainder = address % 16;
        hex_digit = (remainder < 10) ? remainder + '0' : remainder - 10 + 'a';
        buffer[i] = hex_digit;
        address /= 16;
    }

    for (j = i - 1; j >= 0; j--)
        buffer[j] = update_storage(storage, &buffer[j], 1);

    free(buffer);

    return (res);
}
