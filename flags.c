#include "main.h"
/**
 * init_flags - initializing flags
 * @flags: struct
 * @printl: valist
 * Return: None
 */
void init_flags(flags_t *flags, va_list printl)
{
	flags->sign = 0;
	flags->plus_f = 0;
	flags->space_f  = 0;
	flags->hashtag_f = 0;
	flags->long_m = 0;
	flags->short_m = 0;
	flags->width = 0;
	flags->zero_f = 0;
	flags->minus_f = 0;
	flags->precision = UINT_MAX;
	(void)printl;
}
