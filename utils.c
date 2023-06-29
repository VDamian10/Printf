#include "main.h"

/**
 * start_buff - initializes a struct for buffer storage
 * Return: pointer to a buffer
*/

t_buff *start_buff(void)
{
	t_buff *storage;

	storage = malloc(sizeof(t_buff));

	if (!storage)
		return (NULL);

	storage->buffer = malloc(sizeof(char) * 1024);

	if (!storage->buffer)
	{
		free(storage);
		return (NULL);
	}

	storage->start = storage->buffer;
	storage->length = 0;

	return (storage);
}

/**
 * update_storage - copies string to storage buffer
 * @storage: buffer
 * @str: string
 * @x: number of bytes to be copied
 * Return: number of bytes copied
*/

unsigned int update_storage(t_buff *storage, const char *str, unsigned int x)
{
	unsigned int o;

	for (o = 0; o < x && str[o] != '\0'; o++)
	{
		*(storage->buffer) = str[o];
		storage->length += 1;

		if (storage->length == 1024)
		{
			write(1, storage->start, storage->length);
			storage->buffer = storage->start;
			storage->length = 0;
		}
		else
			(storage->buffer)++;
	}

	if (storage->length < 1024)
	{
		write(1, storage->start, storage->length);
		storage->buffer = storage->start;
		storage->length = 0;
	}

	return (x);
}

/**
 * _putchar - writes a character to stdout
 * @storage: pointer to buffer struct
 * @c: the character to be written
 * Return: On success, returns the character written as an unsigned char
 *         cast to an int. On error, returns -1.
 */
int _putchar(t_buff *storage, char c)
{
	if (!storage)
	{
		storage = start_buff();
		if (!storage)
			return (-1);
	}

	if (storage->length == 1024 - 1)
	{
		write(1, storage->start, storage->length);
		storage->buffer = storage->start;
		storage->length = 0;
	}

	*(storage->buffer) = c;
	(storage->buffer)++;
	(storage->length)++;

	return ((unsigned char)c);
}
