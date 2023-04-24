#include "main.h"

/**
 * _printf - a function that produces output according to a format.
 *
 * @format: the format with which we will handel the input string
 * @...:    the string we will handl
 *
 * Return: the number or cahracters printed without the '\0'
 */

int _printf(const char *format, ...)
{
	int res = 0;
	char *ptr, *st;
	va_list ap;
	params_t params = PARAMS_INIT;

	va_start(ap, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (ptr = (char *)format; *p; p++)
	{
		init_params(&params, ap);
		if (*p != '%')
		{
			res += _putchar(*ptr);
			continue;
		}
		st = ptr;
		ptr++;
		while (get_flag(ptr, &params))
			ptr++;
		ptr = get_width(ptr, &params, ap);
		ptr = get_precision(ptr, &params, ap);
		if (get_modifier(p, &params))
			ptr++;
		if (!get_specifier(ptr))
			res += print_format_to(st, ptr, params.l_modifier ||
					params.l_modifier ? ptr - 1 : 0);
		else
			res += get_print_func(ptr, ap, &params);
	}
	_putchar(VUF_FLUSH);
	va_end(ap);
	return (res);
}
