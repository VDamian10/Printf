#include "main.h"

/**
 * hand_spec - handles conversion specifiers in order to format a string
 * @letter: identified specifier from input string
 * Return: a pointer to a function or NULL
*/

unsigned int (*hand_spec(const char *letter)) (va_list, t_buff *)
{
	int o;

	spec_s convert_specs[] = {
		{"d", replace_di},
		{"i", replace_di},
		{"c", replace_c},
		{"s", replace_s},
		{"p", replace_p},
		{"f", replace_f},
		{"e", replace_e},
		{"E", replace_E},
		{"o", replace_o},
		{"x", replace_x},
		{"X", replace_X},
		{"%", replace_percentage},
		{"u", replace_u},
		{"r", replace_r},
		{"R", replace_R},
		{"b", replace_b},
		{0, NULL}
	};

	for (o = 0; convert_specs[o].replacer; o++)
	{
		if (*(convert_specs[o].specifiers) == *letter)
		{
			return (convert_specs[o].replacer);
		}
	}

	return (NULL);
}

