#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * print_unsigned - this Prints unsigned number
 * @types: List of arguments
 * @buffer: array buffer to handle print
 * @flags: this Calculates active flags
 * @width: this gets the width
 * @precision: Precision of specification
 * @size: Size of specifier
 * Return: char number printed.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/** PRINTING OF UNSIGNED NUMBER IN OCTAL **/
/**
 * print_octal - This prints unsigned number in octal notation
 * @types: List of arguments
 * @buffer: Array buffer to handle print
 * @flags: This calculates active flags
 * @width: This Get the width
 * @precision: Precision of specification
 * @size: Size of Specifier
 * Return: Char number printed
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/** PRINTING UNSIGNED NUMBER IN HEXADECIMAL **/
/**
 * print_hexadecimal - This prints unsigned number in hexadecimal
 * @types: List of arguments
 * @buffer: Array Buffer to handle print
 * @flags:  This calculates active flags
 * @width: Get the width
 * @precision: Precision of specification
 * @size: Size of specifier
 * Return: Char number printed
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/** PRINTING UNSIGNED NUMBER IN UPPER HEXADECIMAL **/
/**
 * print_hexa_upper - This prints unsigned number in upper hexadecimal
 * @types: List of arguments
 * @buffer: Array buffer to handle print
 * @flags:  This calculates active flags
 * @width: Get the width
 * @precision: Precision of specification
 * @size: Size of specifier
 * Return: Char number printed
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/** PRINTING HEXX NUM IN LOWER OR UPPER **/
/**
 * print_hexa - THis prints a hexadecimal number in lower or upper
 * @types: List of arguments
 * @map_to: Array values to map the number to
 * @buffer: Array buffer to handle print
 * @flags:  This calculates active flags
 * @flag_ch: This calculates active flags
 * @width: get the width
 * @precision: Precision of specification
 * @size: Size of specifier
 * @size: Size of specification
 * Return: Char number printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
