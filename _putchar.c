#include "main.h"
/**
 * _puts - printing string
 * @s: string
 * Return: void
 */
int _puts(char *s)
{
	char *str = s; /* pointer to pointer lol */

	while (*s != '\0') /* if the character pointed is not nul */
		_putchar(*s++); /* print it and pass to the next char of the string */
	return (s - str); /* to give the lenghts */
}
/**
 * _putchar - to write each character
 * @c: char
 * Return: 1 or -1
 */
int _putchar(int c)
{
	static int x; /* number of bytes to be printed */
	static char adr[BUF_ZISE]; /* for the 1024 chars buffer adress*/

	if (c > -1)
		adr[x++] = c;
	if (c)
	{
		write(1, adr, x);
		x = 0;
	}
	return (1);
}
