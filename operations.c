#include "main.h"

/**
 * hand_spec - handles conversion specifiers in order to format a string
 * @f: identified specifier from input string
 * Return: a pointer to a function or NULL
*/

unsigned int (*hand_spec(const char *f))(va_list, t_buff *, const char *, unsigned char)
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
		{"x", replace_x},
		{"X", replace_X},
		{"e", replace_e},
		{"E", replace_E},
		{"s", replace_s},
		{"p", replace_p},
		{"r", replace_r},
		{"R", replace_R},
		{0, NULL}
	};

	for (o = 0; convert_specs[o].specifiers; o++)
	{
		if (*(convert_specs[o].specifiers) == *f)
		{
			return (convert_specs[o].replacer);
		}
	}

	return (NULL);
}
