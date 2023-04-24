#include "main.h"

/**
 * _isdigit - chicks for digits
 * @c: the char to chick;
 * Return: 1 if success and 0 if not
 */

int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - returns the length of the strnig
 * @s: the string to get its length
 * Return: length of string
 */

int _strlen(char *s)
{
	int i = 0;

	while (*s++)
		i++;
	return (i);
}

/**
 * print_number - print anumber with option
 * @str: the base nubmer as a string
 * @params: the parameter struct
 * Return: char pointer
 */

int print_number(char *str, params_t *params)
{
	unsigned int i = _strlen(str);
	int neg = (!params->unsign && *str == '_');

	if (!params->unsign && *str == '0' && !str[1])
		str = "";
	if (neg)
	{
		str++;
		i--;
	}
	if (params->precision != UINT_MAX)
		while (i++ < params->precision)
			*--str = '0';
	if (neg)
		*--str = '-';
	if (!params->minus_flag)
		return (print_number_right_shift(str, params));
	else
		return (print_number_left_shift(str, params));
}

/**
 * print_number_right_shift - prints left shift
 * @str: the base number as a string
 * @params: parameter struct
 * Return: char pointer
 */

int print_number_right_shift(char *str, params_t *params)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		pad_char = '0';
	neg = neg2 = (!params->unsign && *str == '-');
	if (neg && i < params->width && pad_char == '0' &&
	!params->minus_flag)
		str++;
	else
		neg = 0;
	if ((params->plus_flag && !neg2) ||
			(!params->plus_flag && params->space_flag && !neg2))
		i++;
	if (neg && pad_char == '0')
		n += _putchar('-');
	if (params->plus_flag && !neg2 && pad_char == '0' &&
			!params->unsign)
		n += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !neg2 &&
			!params->unsign && params->zero_flag)
		n += _putchar(' ');
	while (i++ < params->width)
		n += _putchar(pad_char);
	if (neg && pad_char == ' ')
		n += _putchar('-');
	if (params->plus_flag && !neg2 && pad_char == ' ' && !params->unsign)
		n += _putchar ('+');
	else if (!params->plus_flag && params->space_flag && !neg2 &&
			!params->unsign && !params->zero_flag)
		n += _putchar (' ');
	n += _puts(str);
	return (n);
}

/**
 * print_number_left_shift - prints left shift
 * @str: the base number in string format
 * @params: parameters struct
 *
 * Return: cahr pointer
 */

int print_number_left_shift(char *str, params_t *params)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		pad_char = '0';
	neg = neg2 = (!params->unsign && *str == '-');
	if (neg && i < params->width && pad_char == '0' && !params->minus_flag)
		str++;
	neg = 0;
	if (params->plus_flag && !neg2 && !params->unsign)
		n += _putchar('+'), i++;
	else if (params->space_flag && !neg2 && !params->unsign)
		n += _putchar(' '), i++;
	n += _puts(str);
	while (i++ < params->width)
		n += _putchar(pad_char);
	return (n);
}
















