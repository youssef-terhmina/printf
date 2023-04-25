#include "main.h"

/**
 * _isdigit - checks if character is a digit
 * @c: character to check
 *
 * Return: 1 if digit, 0 otherwise
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - returns the length of a string
 * @s: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *s)
{
	int i = 0;

	while (*s++)
		i++;
	return (i);
}

/**
 * print_number - prints a number with options
 * @str: the base number as a string
 * @flags: struct flags
 *
 * Return: chars printed
 */
int print_number(char *str, flags_t *flags)
{
	unsigned int i = _strlen(str);
	int neg = (!flags->sign && *str == '-');

	if (!flags->precision && *str == '0' && !str[1])
		str = "";
	if (neg)
	{
		str++;
		i--;
	}
	if (flags->precision != UINT_MAX)
		while (i++ < flags->precision)
			*--str = '0';
	if (neg)
		*--str = '-';

	if (!flags->minus_f)
		return (print_number_right_shift(str, flags));
	else
		return (print_number_left_shift(str, flags));
}

/**
 * print_number_right_shift - prints a number with options
 * @str: the base number as a string
 * @flags: struct flags
 *
 * Return: chars printed
 */
int print_number_right_shift(char *str, flags_t *flags)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	if (flags->zero_f && !flags->minus_f)
		pad_char = '0';
	neg = neg2 = (!flags->sign && *str == '-');
	if (neg && i < flags->width && pad_char == '0' && !flags->minus_f)
		str++;
	else
		neg = 0;
	if ((flags->plus_f && !neg2) ||
		(!flags->plus_f && flags->space_f && !neg2))
		i++;
	if (neg && pad_char == '0')
		n += _putchar('-');
	if (flags->plus_f && !neg2 && pad_char == '0' && !flags->sign)
		n += _putchar('+');
	else if (!flags->plus_f && flags->space_f && !neg2 &&
		!flags->sign && flags->zero_f)
		n += _putchar(' ');
	while (i++ < flags->width)
		n += _putchar(pad_char);
	if (neg && pad_char == ' ')
		n += _putchar('-');
	if (flags->plus_f && !neg2 && pad_char == ' ' && !flags->sign)
		n += _putchar('+');
	else if (!flags->plus_f && flags->space_f && !neg2 &&
		!flags->sign && !flags->zero_f)
		n += _putchar(' ');
	n += _puts(str);
	return (n);
}

/**
 * print_number_left_shift - prints a number with options
 * @str: the base number as a string
 * @flags: struct flags
 *
 * Return: chars printed
 */
int print_number_left_shift(char *str, flags_t *flags)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	if (flags->zero_f && !flags->minus_f)
		pad_char = '0';
	neg = neg2 = (!flags->sign && *str == '-');
	if (neg && i < flags->width && pad_char == '0' && !flags->minus_f)
		str++;
	else
		neg = 0;

	if (flags->plus_f && !neg2 && !flags->sign)
		n += _putchar('+'), i++;
	else if (flags->space_f && !neg2 && !flags->sign)
		n += _putchar(' '), i++;
	n += _puts(str);
	while (i++ < flags->width)
		n += _putchar(pad_char);
	return (n);
}

