#ifndef MAIN_H

#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define BUF_ZISE 1024
#define BUF_FLSH -1
#define NULL_STR "(null)"
#define FLAGS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define CNV_LC 1
#define CNV_UNS 2

/**
 * struct flags - flags struct
 *
 * @sign: flag if positive or negative value
 * @plus_f: if plus_f specified
 * @space_f: if space_f specified
 * @hashtag_f: if hashtag_f specified
 * @long_m: if long_m specified
 * @short_m: if short_m is specified
 * @width: field width specified
 * @precision: field precision specified
 * @zero_f: if zero_f specified
 * @minus_f: if minus_f specified
 *
 */


typedef struct flags
{
	unsigned int sign       : 1;
	unsigned int plus_f     : 1;
	unsigned int space_f    : 1;
	unsigned int hashtag_f  : 1;
	unsigned int long_m     : 1;
	unsigned int short_m    : 1;
	unsigned int width;
	unsigned int precision;
	unsigned int zero_f     : 1;
	unsigned int minus_f    : 1;
} flags_t;

/**
 * struct spf - struct token
 * @spf: token format
 * @f: fnct associated
 *
 */


typedef struct spf
{
	char *spf;
	int (*f)(va_list, flags_t *);
} spf_t;

/* prototypes */
int _printf(const char *format, ...);
int print_char(va_list printl, flags_t *flags);
int print_string(va_list printl, flags_t *flags);
int print_percent(va_list printl, flags_t *flags);
int print_int(va_list printl, flags_t *flags);
int print_S(va_list printl, flags_t *flags);
int print_binary(va_list printl, flags_t *flags);
int print_hex(va_list printl, flags_t *flags);
int print_HEX(va_list printl, flags_t *flags);
int print_octal(va_list printl, flags_t *flags);
int print_unsigned(va_list printl, flags_t *flags);
int print_address(va_list printl, flags_t *flags);
char *convert(long int nb, int bs, int fl, flags_t *flags);
int print_rev(va_list printl, flags_t *flags);
int print_rot13(va_list printl, flags_t *flags);
int print_from_to(char *start, char *stop, char *except);
int _puts(char *str);
int _putchar(int c);
int (*get_specifier(char *s))(va_list printl, flags_t *flags);
int get_print_func(char *s, va_list printl, flags_t *flags);
int get_flag(char *s, flags_t *flags);
int get_modifier(char *s, flags_t *flags);
char *get_width(char *s, va_list printl, flags_t *flags);
int _isdigit(int c);
int _strlen(char *s);
int print_number(char *str, flags_t *flags);
int print_number_right_shift(char *str, flags_t *flags);
int print_number_left_shift(char *str, flags_t *flags);
void init_flags(flags_t *flags, va_list printl);
char *get_precision(char *p, flags_t *flags, va_list printl);

#endif
