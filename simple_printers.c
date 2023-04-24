#include "main.h"

/**
 * print_from_to - prints  a range of chars addresses
 * @start: start address
 * @stop: stop address
 * @except: except address (like %, flags, modifiers, specifiers)
 * Return: number of bytes printed
 */

int print_from_to(char *start, char *stop, char *except)
{
	int sum = 0;

	while (start <= stop)
	{
		if (start != except)
			sum += _putchar(*start);
		start++;
	}
	return (sum);
}

/**
 * print_rev - prints the string in reverse
 * @ap: string to print in rev
 * @params: the parameters struct
 *
 * Return: number of bytes prnited
 */

int print_rev(va_list ap, params_t *params)
{
	int len, sum = 0;
	char *str = va_arg(ap, char *);
	(void)params;

	if (str)
	{
		for (len = 0; *str; str++)
			len++;
		for (; len > 0; len--, str--)
			sum += _putchar(*str);
	}
	return (sum);
}

/**
 * print_rot13 - prints the string in rot 13 format
 * @ap: the string
 * @params: the parameters struct
 * Return: nubmer of bytes printed
 */
int print_rot13(va_list ap, params_t *params)
{
	int i = 0, index = 0;
	int res = 0;
	char arr[] =
		"NOPQRSTUVWXYZABCDEFGHIGKLM    nopqrstuvwxyzabcdefghigklm";
	char *a = va_arg(ap, char *);
	(void)params;

	while (a[i])
	{
		if ((a[i] >= 'A' && a[i] <= 'Z')
		|| (a[i] >= 'a' && a[i] <= 'z'))
		{
			index = a[i] - 65;
			res += _putchar(arr[index]);
		}
		else
			res += _putchar(a[i]);
		i++;
	}
	return (res);
}
