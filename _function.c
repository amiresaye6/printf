#include "main.h"

/**
 * print_char - print characer
 * @ap: argumetn pointer
 * @params: parameter struct
 *
 * Return: number of bytes printed
 */

int print_char(va_list ap, params_t *params)
{
	char pad_char = ' ';
	unsigned int pad = 1, res = 0, c = va_arg(ap, int);

	if (params->minus_flag)
		res += _putchar(c);
	while (pad++ < params->width)
		res += _putchar(pad_char);
	if (!params->minus_flag)
		res += _putchar(c);
	return (res);
}

/**
 * print_int - print intger
 * @ap: argumetn pointer
 * @params: parameter struct
 *
 * Return: number of bytes printed
 */

int print_int(va_list ap, params_t *params)
{
	long l;

	if (params->l_modifier)
		l = va_arg(ap, long);
	else if (params->h_modifier)
		l = (short int)va_arg(ap, int);
	else
		l = (int)va_arg(ap, int);
	return (print_number(convert(l, 10, 0, params), params));
}

/**
 * print_string - print string
 * @ap: argumetn pointer
 * @params: parameter struct
 *
 * Return: number of bytes printed
 */

int print_string(va_list ap, params_t *params)
{
	char *str = va_arg(ap, char *), pad_char = ' ';
	unsigned int pad = 0, sum = 0, i = 0, j;
	(void)params;

	switch ((int)(!str))
	case 1:
		str = NULL_string;
	j = pad = params->precision;

	if (params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*str++);
		else
			sum += _puts(str);
	}
	while (j++ < params->width)
		sum += _putchar(pad_char);
	if (!params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*str++);
		else
			sum += _puts(str);
	}
	return (sum);
}

/**
 * print_percent - print percent
 * @ap: argumetn pointer
 * @params: parameter struct
 *
 * Return: number of bytes printed
 */

int print_percent(va_list ap, params_t *params)
{
	(void)ap;
	(void)params;
	return (_putchar('%'));
}

/**
 * print_S - print i dont remimber
 * @ap: argumetn pointer
 * @params: parameter struct
 *
 * Return: number of bytes printed
 */

int print_S(va_list ap, params_t *params)
{
	char *str = va_arg(ap, char *);
	char *h;
	int res = 0;

	if ((int)(!str))
		return (_puts(NULL_string));
	for ( ; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			res += _putchar('\\');
			res += _putchar('x');
			h = convert(*str, 16, 0, params);
			if (!h[1])
				res += _putchar('0');
			res += _puts(h);
		}
		else
			res += _putchar(*str);
	}
	return (res);

}
