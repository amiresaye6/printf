#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1

#define NULL_string "(null)"

#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

/**
 * struct parameters - parameters struct
 *
 * @unsign:       if unsigned value is passed
 * @plus_flag:    if "+" is passed
 * @space_flag:   if " " is passed
 * @hashtag_flag: if "#" is passed
 * @zero_flag:    if "0" passed
 * @minus_flag:   if "-" is passed
 *
 * @width:        field width specifier
 * @precision:    field precision specifier
 *
 * @h_modifier:   on if h_modifier is specified
 * @l_modifier:   on if l_modifier is specified
 *
 */
typedef struct parameters
{
	unsigned int unsign       : 1;
	unsigned int plus_flag    : 1;
	unsigned int space_flag   : 1;
	unsigned int hashtag_flag : 1;
	unsigned int zero_flag    : 1;
	unsigned int minus_flag   : 1;
	unsigned int width        : 1;
	unsigned int precision    : 1;

	unsigned int h_modifier   : 1;
	unsigned int l_modifier   : 1;
} params_t;

/**
 * struct specifier - struct token
 *
 * @specifier: format token
 * @f: the function to chose the specifier
 *
 */
typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, params_t *);
} specifier_t;

/* _put.c file */

int _puts(char *str);
int _putchar(int c);

/* ------------------ */

/* _function.c file */

int print_char(va_list ap, params_t *params);
int print_int(va_list ap, params_t *params);
int print_string(va_list ap, params_t *params);
int print_percent(va_list ap, params_t *params);
int print_S(va_list ap, params_t *params);

/* ------------------ */

/* number.c file */

char *convert(long int num, int base, int flags, params_t *params);
int print_unsigned(va_list ap, params_t *params);
int print_address(va_list ap, params_t *params);

/* ------------------ */

/* specifier.c file */

int (*get_specifier(char *s))(va_list ap, params_t *params);
int get_print_func(char *s, va_list ap, params_t *params);
int get_flag(char *s, params_t *params);
int get_modifier(char *s, params_t *params);
char *get_width(char *s, params_t *params, va_list ap);

/* ------------------ */

/* convert_number.c file */

int print_hex(va_list ap, params_t *params);
int print_HEX(va_list ap, params_t *params);
int print_binary(va_list ap, params_t *params);
int print_octa(va_list ap, params_t *params);

/* ----------------- */

/* simple_printers.c file */

int print_from_to(char *start, char *stop, char *except);
int print_rev(va_list ap, params_t *params);
int print_rot13(va_list ap, params_t *params);

/* ---------------- */

/* print_number.c file */

int _isdigit(int c);
int _strlen(cahr *s);
int print_number(char *str, params_t *params);
int print_number_left_shift(char *str, params_t *params);
int print_number_right_shift(char *str, params_t *params);

/* ---------------- */

/* params.c file */

void init_params(params_t *params, va_list ap);

/* ---------------- */

/* string_fields.c file */

char *get_precision(char *p, params_t *params, val_list);

/* ---------------- */

/* _printf.c file */

int _printf(coinst char *format, ...);

/* --------------- */

#endif
