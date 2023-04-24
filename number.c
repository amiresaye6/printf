#include "main.h"

/**
 * convert - convert function like itoa function
 * @num: the num to convert to anotehr type
 * @base: the base we want to convert to
 * @flags: argument flags
 * @params: parametere struct
 *
 * Return: string
 */

char *convert(long int num, int base, int flags, params_t *params)
{
	static char *a;
	static char b[50];
	char *ptr;
	char sign = 0;
	unsigned long n = num;
	(void)params;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}
	a = flags & CONVERT_UNSIGNED ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &b[49];
	*ptr = '\0';

	do {
		*--ptr = a[n % base];
		n /= base;
	} while (n != 0);
	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * print_unsigned - print unsigned numbers
 * @ap: argument pointer
 * @params: parameters struct
 * Return: string
 */

int print_unsigned(va_list ap, params_t *params)
{
	unsigned long l;

	if (params->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);
	params->unsign = 1;
	return (print_number(convert(l, 10, CONVERT_UNSIGNED, params),
		params));
}

/**
 * print_address - print addresses and pointers
 * @ap: argument pointer
 * @params: parameters struct
 * Return: string;
 */

int print_address(va_list ap, params_t *params)
{
	unsigned long int num = va_arg(ap, unsigned long int);
	char *str;

	if (!num)
		return (_puts("(nil)"));
	str = convert(num, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	*--str = 'x';
	*--str = '0';
	return (print_number(str, params));
}
