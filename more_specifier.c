#include "main.h"

/**
 * print_string_S - Prints a string
 * @args: Argument list containing the string to be printed
 *
 * Return: The number of characters printed
 */
int print_string_S(va_list args)
{
	char *str;
	int i = 0;
	int count = 0;

	str = va_arg(args, char *);
	if (str == NULL)
		return (_puts("(null)"));

	while (str[i])
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			count += _putchar('\\');
			count += _putchar('x');
			count += print_upper_hexa_char(str[i]);
		}
		else
		{
			count += _putchar(str[i]);
		}
		i++;
	}
	return (count);
}
/**
 * print_upper_hexa_char - Prints the upper-case hexadecimal representation
 * @c: The character to be printed in hexadecimal
 *
 * Return: The number of characters printed
 */
int print_upper_hexa_char(unsigned char c)
{
	int count = 0;
	int first_digit, second_digit;

	first_digit = c / 16;
	if (first_digit < 10)
	{
		count += _putchar(first_digit + '0');
	}
	else
	{
		count += _putchar(first_digit - 10 + 'A');
	}

	second_digit = c % 16;
	if (second_digit < 10)
	{
		count += _putchar(second_digit + '0');
	}
	else
	{
		count += _putchar(second_digit - 10 + 'A');
	}

	return (count);
}

