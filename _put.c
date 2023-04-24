#include "main.h"

/**
 * _puts - prints a string then a new line
 * @str: the string to print
 *
 * Return: void
 */

void _puts(cha *str)
{
	char *a = str;

	while (*str)
		_putchar(*str++);
	return (str - a);
}

/**
 * _putchar - writes the char c into the standard output
 * @c: the char to print
 * Return: 1 if success and -1 if not.
 */
int _putchar(int c)
{
	static int i;
	static char b[OUTPUT_BUF_SIZE];

	if (c == BUF_FLUSH || i >= OUTPUT_BUT_SIZE)
	{
		write(1, b, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		b[i++] = c;
	return (1);
}
