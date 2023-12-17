#include "main.h"

/**
 * _puts - a function that prints a string
 * @str: string input
 * Return: string
 */

void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '\n')
		{
			_putchar('\n');
			continue;
		}
		_putchar(str[i]);
	}
}

/**
 * _strcat - concatenates two strings
 *
 * @dest: the string @src is added to
 * @src: the string to be appended
 *
 * Return: void
 */

void _strcat(char *dest, char *src)
{
	int len1; /* string length for src */
	int len2; /* string length for dest */
	int i;

	len1 = 0;
	len2 = 0;

	while (src[len1] != '\0')
		len1++;

	while (dest[len2] != '\0')
		len2++;

	for (i = 0; i <= len1; i++)
	{
		dest[len2] = src[i];
		len2++;
	}
}

/**
 * _strcmp - compares two strings values
 * @s1: string 1
 * @s2: string 2
 * Return: the difference in s1 and s2
 */

int _strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}

/**
 * _putchar - writes character c to stdout
 * @c: char to be printed
 * Return: on success 1
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
