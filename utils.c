#include "main.h"

/**
 * is_printable - This evaluates if char is printable
 * @c: This is the char to be evaluated
 *
 * Return: 1 if c is printable, 0 otherwise
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - This appends ascci in hexadecimal code to buffer
 * @buffer: Array buffer of chars
 * @i: The index to start appending
 * @ascii_code: This is ASCII CODE
 * Return: Always 3
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	/** The hexa format code is always 2 digits long **/

	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - This verifies if char is a digit
 * @c: This is the char to be evaluated
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - This casts number to the specified size
 * @num: This is the number to be casted
 * @size: The number indicating type to be casted
 *
 * Return: Value of num casted
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - This casts number to the specified size
 * @num: This is the number to be casted
 * @size: The number indicating type to be casted
 *
 * Return: Value of num casted
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
