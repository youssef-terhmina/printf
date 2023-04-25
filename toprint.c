#include "main.h"

/**
 * print_char - printing char
 * @printl: printing point
 * @flags: struct
 * Return: print
 */
int print_char(va_list printl, flags_t *flags)
{
	char spacechar = ' ';
	unsigned int space = 1, printall = 0, ch = va_arg(printl, int);

	if (flags->minus_f)
		printall += _putchar(ch);
	for (; space++ < flags->width; )
		printall += _putchar(spacechar);
	if (!flags->minus_f)
		printall += _putchar(ch);
	return (printall);
}
/**
 * print_int - printing int
 * @printl: printing point
 * @flags: struct
 * Return: print
 */
int print_int(va_list printl, flags_t *flags)
{
	long l;

	if (flags->long_m)
		l = va_arg(printl, long);
	if (flags->short_m)
		l = (short int)va_arg(printl, int);
	else
		l = (int)va_arg(printl, int);
	return (print_number(convert(l, 10, 0, flags), flags));
}
/**
 * print_string - printing string
 * @printl: printing point
 * @flags: struct
 * Return: print
 */
int print_string(va_list printl, flags_t *flags)
{
	char *string = va_arg(printl, char *), spacechar = ' ';
	unsigned int space = 0, printall = 0, i = 0, j;

	(void)flags;
	switch ((int)(!string))
		case 1:
			string = NULL_STR;

	j = space = _strlen(string);
	if (flags->precision < space)
		j = space = flags->precision;

	if (flags->minus_f)
	{
		if (flags->precision != UINT_MAX)
			for (i = 0; i < space; i++)
				printall += _putchar(*string++);
		else
			printall += _puts(string);
	}
	for (; j++ < flags->width; )
		printall += _putchar(spacechar);
	if (!flags->minus_f)
	{
		if (flags->precision != UINT_MAX)
			for (i = 0; i < space; i++)
				printall += _putchar(*string++);
		else
			printall += _puts(string);
	}
	return (printall);
}
/**
 * print_percent - print percent
 * @printl: printing point
 * @flags: struct
 * Return: print
 */
int print_percent(va_list printl, flags_t *flags)
{
	(void)printl;
	(void)flags;
	return (_putchar('%'));
}

/**
 * print_S - custom format specifier
 * @printl: printing point
 * @flags: struct
 * Return: print
 */
int print_S(va_list printl, flags_t *flags)
{
	char *string = va_arg(printl, char *);
	char *hed;
	int printall = 0;

	if ((int)(!string))
		return (_puts(NULL_STR));
	while (*string)
	{
		if ((*string > 0 && *string < 32) || *string >= 127)
		{
			printall += _putchar('\\');
			printall += _putchar('x');
			hed = convert(*string, 16, 0, flags);
			if (!hed[1])
				printall += _putchar('0');
			printall += _puts(hed);
		}
		else
		{
			printall += _putchar(*string);
		}
	}
	return (printall);
}
