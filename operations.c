#include "main.h"

/**
 * hand_spec - handles conversion specifiers in order to format a string
 * @f: identified specifier from input string
 * Return: a pointer to a function or NULL
*/

unsigned int (*hand_spec(const char *f))(va_list, t_buff *, unsigned char)
{
	int o;

	spec_s convert_specs[] = {
		{"d", replace_di},
		{"i", replace_di},
		{"c", replace_c},
		{"o", replace_o},
		{"%", replace_percentage},
		{"u", replace_u},
		{"b", replace_b},
		{0, NULL}
	};

	for (o = 0; convert_specs[o].replacer; o++)
	{
		if (*(convert_specs[o].specifiers) == *f)
		{
			return (convert_specs[o].replacer);
		}
	}

	return (NULL);
}
