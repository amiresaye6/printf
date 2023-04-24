#include "main.h"

/**
 * get_specifier - find teh format
 * @str: the format string
 * Return: numper of printded pytes
 */

int (*get_specifier(char *str))(va_list ap, params_t *params)
{
	specifier_t specifiers[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octa},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};
	int i = 0;

	while (specifiers[i].specifier)
	{
		if (*str == specifiers[i].specifier[0])
			return (specifiers[i].f);
	}
	return (NULL);
}

/**
 * get_print_func - finds teh format function
 * @str: teh format string
 * @ap: tha argumet pointer
 * @params: the parameters struct
 * Return: number of bytes printed
 */

int get_print_func(char *str, va_list ap, params_t *params)
{
	int (*f)(va_list, params_t *) = get_specifier(str);

	if (f)
		return (f(ap, params));
	return (0);
}

/**
 * get_flag - find the flag function
 * @str: the format string
 * @params: the parameters struct
 * Return:  if flag is valid
 */

int get_flag(char *str, params_t *params)
{
	int i = 0;

	switch (*str)
	{
		case '+':
			i = params->plus_flag    = 1;
			break;
		case '-':
			i = params->minus_flag   = 1;
			break;
		case ' ':
			i = params->space_flag   = 1;
			break;
		case '#':
			i = params->hashtag_flag = 1;
			break;
		case '0':
			i = params->zero_flag    = 1;
			break;
	}
	return (i);
}

/**
 * get_modifier - finds the modifier function
 * @str: the format string
 * @params: the parameters sturnct
 * Return: if modifier was valid
 */

int get_modifier(char *str, params_t *params)
{
	int i = 0;

	switch (*str)
	{
		case 'h':
			i = params->h_modifier = 1;
			break;
		case 'l':
			i = params->l_modifier = 1;
			break;
	}
	return (i);
}

/**
 * get_width - gets teh width from teh format string
 * @str: the fomat string
 * @params: the parameters struct
 * @ap: the argument pointer
 * Return: new pointer
 */

char *get_width(char *str, params_t *params, va_list ap)
{
	int d = 0;

	if (*str == '*')
	{
		d = va_arg(ap, int);
		str++;
	}
	else
	{
		while (_isdigit(*str))
			d = d * 10 + (*str++ - '0');
	}
	params->width = d;
	return (str);
}
