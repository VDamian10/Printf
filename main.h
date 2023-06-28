#ifndef MAIN_H
#define MAIN_H

#define FLAG_SPACE (1 << 0)
#define FLAG_PLUS (1 << 1)
#define FLAG_MINUS (1 << 2)
#define FLAG_ZERO (1 << 3)
#define FLAG_HASH (1 << 4)

#define MAX_BINARY_DIGITS 32
#define MAX_OCTAL_DIGITS 12

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

/**
 * struct buffsize - holds buffer prior to final print on stdout
 * @buffer: pointer to a character array
 * @start: pointer to the start of the buffer
 * @length: length of the string
*/

typedef struct buffsize
{
	char *buffer;
	char *start;
	unsigned int length;
} t_buff;

/**
 * struct flag - a struct containing flags
 * to be used in the _printf function
 * @plus: flag for '+'
 * @space: flag for ' '
 * @hash: flag for '#'
 * @zero: flag for '0'
 * @minus: flag for '-'
*/

/*
typedef struct flag
{
	int plus;
	int space;
	int hash;
	int zero;
	int minus;
} flag_t;
*/

/**
 * struct specifiers - holds format specifier letters and conversion formulas
 * @specifiers: an array of characters (holding the letter correspondants)
 * @convertor: pointer to a conversion formula matching the specifier
*/

typedef struct specifiers
{
	char *specifiers;
	unsigned int (*replacer)(va_list, t_buff *, unsigned char);
} spec_s;

int main(void);
int _printf(const char *format, ...);
int _strlen(const char *str);
int _putchar(t_buff *storage, char c);

/*
int flags(char s, flag_t *g);
*/

/* handle conversion specifications in format string */
unsigned int (*hand_spec(const char *format))(va_list, t_buff *, unsigned char);

unsigned int update_storage(t_buff *, const char *str, unsigned int x);
t_buff *start_buff(void);

/* conversion specification replacer functions */
unsigned int replace_di(va_list, t_buff *storage, unsigned char flag);
unsigned int replace_c(va_list, t_buff *storage, unsigned char flag);
unsigned int replace_s(va_list, t_buff *storage, unsigned char flag);
unsigned int replace_p(va_list, t_buff *storage, unsigned char flag);
unsigned int replace_f(va_list, t_buff *storage, unsigned char flag);
unsigned int replace_e(va_list, t_buff *storage, unsigned char flag);
unsigned int replace_E(va_list, t_buff *storage, unsigned char flag);
unsigned int replace_o(va_list, t_buff *storage, unsigned char flag);
unsigned int replace_x(va_list, t_buff *storage, unsigned char flag);
unsigned int replace_X(va_list, t_buff *storage, unsigned char flag);
unsigned int replace_percentage(va_list, t_buff *storage, unsigned char flag);
unsigned int replace_u(va_list, t_buff *storage, unsigned char flag);
unsigned int replace_r(va_list, t_buff *storage, unsigned char flag);
unsigned int replace_R(va_list, t_buff *storage, unsigned char flag);
unsigned int replace_b(va_list, t_buff *storage, unsigned char flag);
unsigned char flags(const char *format);

void print_number_to_storage(int n, t_buff *storage);
int count_digit(int i);
void convert_to_base(unsigned int num, int base, char *result);
unsigned int count_digit_base(unsigned int num, int base);

#endif
