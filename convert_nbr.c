#include "main.h"

/**
 * print_hex - prints unsigned hex numbers in lowercase
 * @printl: argument pointer
 * @flags: struct flags
 *
 * Return: number of bytes printed
 */
int print_hex(va_list printl, flags_t *flags)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (flags->long_m)
		l = (unsigned long)va_arg(printl, unsigned long);
	else if (flags->short_m)
		l = (unsigned short int)va_arg(printl, unsigned int);
	else
		l = (unsigned int)va_arg(printl, unsigned int);

	str = convert(l, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, flags);
	if (flags->hashtag_f && l)
	{
		*--str = 'x';
		*--str = '0';
	}
	flags->sign = 1;
	return (c += print_number(str, flags));
}

/**
 * print_HEX - prints unsigned hex numbers in uppercase
 * @printl: argument pointer
 * @flags: struct flags
 *
 * Return: number of bytes printed
 */
int print_HEX(va_list printl, flags_t *flags)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (flags->long_m)
		l = (unsigned long)va_arg(printl, unsigned long);
	else if (flags->short_m)
		l = (unsigned short int)va_arg(printl, unsigned int);
	else
		l = (unsigned int)va_arg(printl, unsigned int);

	str = convert(l, 16, CONVERT_UNSIGNED, flags);
	if (flags->hashtag_f && l)
	{
		*--str = 'X';
		*--str = '0';
	}
	flags->sign = 1;
	return (c += print_number(str, flags));
}
/**
 * print_binary - prints unsigned binary number
 * @printl: argument pointer
 * @flags: struct flags
 *
 * Return: number of bytes printed
 */
int print_binary(va_list printl, flags_t *flags)
{
	unsigned int n = va_arg(printl, unsigned int);
	char *str = convert(n, 2, CONVERT_UNSIGNED, flags);
	int c = 0;

	if (flags->hashtag_f && n)
		*--str = '0';
	flags->sign = 1;
	return (c += print_number(str, flags));
}

/**
 * print_octal - prints unsigned octal numbers
 * @printl: argument pointer
 * @flags: struct flags
 *
 * Return: number of bytes printed
 */
int print_octal(va_list printl, flags_t *flags)
{
	unsigned long l;
	char *str;
	int c = 0;

	if (flags->long_m)
		l = (unsigned long)va_arg(printl, unsigned long);
	else if (flags->short_m)
		l = (unsigned short int)va_arg(printl, unsigned int);
	else
		l = (unsigned int)va_arg(printl, unsigned int);
	str = convert(l, 8, CONVERT_UNSIGNED, flags);

	if (flags->hashtag_f && l)
		*--str = '0';
	flags->sign = 1;
	return (c += print_number(str, flags));
}

