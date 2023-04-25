#include "main.h"

/**
 * print_from_to - prints a range of char addresses
 * @start: start address
 * @stop: stop address
 * @except: except address
 *
 * Return: number of bytes printed
 */
int print_from_to(char *start, char *stop, char *except)
{
	int sm = 0;

	while (start <= stop)
	{
		if (start != except)
			sm += _putchar(*start);
		start++;
	}
	return (sm);
}

/**
 * print_rev - prints string in reverse
 * @printl: string argument
 * @flags: struct flags
 *
 * Return: number of bytes printed
 */
int print_rev(va_list printl, flags_t *flags)
{
	int len, sm = 0;
	char *str = va_arg(printl, char *);
	(void)flags;

	if (str)
	{
		for (len = 0; *str; str++)
			len++;
		str--;
		for (; len > 0; len--, str--)
			sm += _putchar(*str);
	}
	return (sm);
}

/**
 * print_rot13 - prints string in rot13
 * @printl: string argument
 * @flags: struct flags
 *
 * Return: number of bytes printed
 */
int print_rot13(va_list printl, flags_t *flags)
{
	int i, index;
	int count = 0;
	char arr[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(printl, char *);
	(void)flags;

	i = 0;
	index = 0;
	while (a[i])
	{
		if ((a[i] >= 'A' && a[i] <= 'Z')
		    || (a[i] >= 'a' && a[i] <= 'z'))
		{
			index = a[i] - 65;
			count += _putchar(arr[index]);
		}
		else
			count += _putchar(a[i]);
		i++;
	}
	return (count);
}

