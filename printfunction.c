#include "main.h"
/**
 * _printf - printing anything
 * @format: format of the str
 * Return: printed
 */
int _printf(const char *format, ...)
{
	va_list printl;
	int printall = 0;
	char *point, *opoint;
	flags_t flags = FLAGS_INIT;

	va_start(printl, format);

	if (format == NULL)
		return (-1); /* check if format is not null */
	if (format[0] == '%' && format[1] == '\0') /* check if specifier selected */
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && format[2] == '\0')
		return (-1);
	point = (char *)format;
	while (*point != '\0') /* if the function pointer was not null */
	{
		init_flags(&flags, printl); /* initialize the flags defined previously */
		if (*point != '%') /* if it does not start with the specifier sign */
		{
			printall += _putchar(*point);
			continue;
		}
		opoint = point;
		point++;
		for ( ; get_flag(point, &flags); ) /* named function following the header */
			point++;
		point = get_width(point, printl, &flags);
		point = get_precision(point, &flags, printl);
		if (get_modifier(point, &flags))
			point++;
		if (get_specifier(point) == NULL) /* if no specifier, used print from to*/
			printall += print_from_to(opoint, point,
					flags.long_m || flags.short_m ? point - 1 : 0);
		else
			printall += get_print_func(point, printl, &flags);
		point++;
	}
	_putchar(BUF_FLSH);
	va_end(printl);
	return (printall);
}
/**
 * main - function
 * Return: 0
 */
int main(void)
{
	printf("Just compile pls'\n'");
	return 0;
}
