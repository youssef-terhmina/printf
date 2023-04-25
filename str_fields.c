#include "main.h"

/**
 * get_precision - gets the precision of string
 * @p: string format
 * @flags: struct flags
 * @printl: the argument pointer
 *
 * Return: new pointer
 */
char *get_precision(char *p, flags_t *flags, va_list printl)
{
	int d = 0;

	if (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		d = va_arg(printl, int);
		p++;
	}
	else
	{
		while (_isdigit(*p))
			d = d * 10 + (*p++ - '0');
	}
	flags->precision = d;
	return (p);
}
