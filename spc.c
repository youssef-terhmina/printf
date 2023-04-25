#include "main.h"

/**
 * get_specifier - get function format
 * @s: string format
 *
 * Return: number of bytes printed
 */

int (*get_specifier(char *s))(va_list printl, flags_t *flags)

{
	spf_t specifiers[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};
	int i;

	for (i = 0; specifiers[i].spf; i++)
	{
		if (*s == specifiers[i].spf[0])
		{
			return (specifiers[i].f);
		}
	}
	return (NULL);
}

/**
 * get_flag - get function flag
 * @s: string format
 * @flags: struct flags
 *
 * Return: if falg was valid
 */

int get_flag(char *s, flags_t *flags)
{
	int i = 0;

	switch (*s)
	{
		case '+':
			i = flags->plus_f = 1;
			break;
		case ' ':
			i = flags->space_f = 1;
			break;
		case '#':
			i = flags->hashtag_f = 1;
			break;
		case '-':
			i = flags->minus_f = 1;
			break;
		case '0':
			i = flags->zero_f = 1;
			break;
	}
	return (i);
}

/**
 * get_modifier - get function modifier
 * @s: string format
 * @flags: struct flags
 *
 * Return: if modifier was valid
 */
int get_modifier(char *s, flags_t *flags)
{
	int i = 0;

	switch (*s)
	{
		case 'h':
			i = flags->short_m = 1;
			break;
		case 'l':
			i = flags->long_m = 1;
			break;
	}
	return (i);
}

/**
 * get_width - get the width of string
 * @s: string format
 * @flags: struct flags
 * @printl: pointer argument
 *
 * Return: new pointer
 */
char *get_width(char *s, va_list printl, flags_t *flags)
{
	int d = 0;

	if (*s == '*')
	{
		d = va_arg(printl, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			d = d * 10 + (*s++ - '0');
	}
	flags->width = d;
	return (s);
}
