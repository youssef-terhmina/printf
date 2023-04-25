#include "main.h"

/**
 * convert - converter function
 * @nb: number
 * @bs: base
 * @fl: argument flags
 * @flags: struct flags
 *
 * Return: string
 */
char *convert(long int nb, int bs, int fl, flags_t *flags)
{
	static char *array;
	static char buffer[50];
	char sgn = 0;
	char *ptr;
	unsigned long n = nb;
	(void)flags;

	if (!(fl & CONVERT_UNSIGNED) && nb < 0)
	{
		n = -nb;
		sgn = '-';

	}
	array = fl & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % bs];
		n /= bs;
	} while (n != 0);

	if (sgn)
		*--ptr = sgn;
	return (ptr);
}

/**
 * print_unsigned - prints unsigned integer numbers
 * @printl: argument pointer
 * @flags: struct flags
 *
 * Return: number of bytes printed
 */
int print_unsigned(va_list printl, flags_t *flags)
{
	unsigned long l;

	if (flags->long_m)
		l = (unsigned long)va_arg(printl, unsigned long);
	else if (flags->short_m)
		l = (unsigned short int)va_arg(printl, unsigned int);
	else
		l = (unsigned int)va_arg(printl, unsigned int);
	flags->sign = 1;
	return (print_number(convert(l, 10, CONVERT_UNSIGNED, flags), flags));
}



/**
 * print_address - prints address
 * @printl: argument pointer
 * @flags: struct flags
 *
 * Return: number of bytes printed
 */
int print_address(va_list printl, flags_t *flags)
{
	unsigned long int n = va_arg(printl, unsigned long int);
	char *str;

	if (!n)
		return (_puts("(nil)"));

	str = convert(n, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, flags);
	*--str = 'x';
	*--str = '0';
	return (print_number(str, flags));
}
