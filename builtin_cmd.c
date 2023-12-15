#include "main.h"

/**
 * _putchar - writes character c to stdout
 * @c: char to be printed
 * Return: on success 1
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
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
		_putchar(str[i]);
	}
	_putchar('\n');
}
/**
 * own_env - prints the env of agrs
 * @arguments: arg that matches env
 *
 * Return: 1 on success, 0 otherwise
 */
int own_env(char **arguments)
{
	int i = 0;
	char *str;

	str = arguments[i++];
	while (arguments[i])
	{
		_puts(str);
		return (0);
	}
	return (-1);
}
/**
 * own_exit - our own exit fxn
 * @arguments: arg that matches exit
 *
 * Return: 1 on success
 */
int own_exit(char **arguments)
{
	if (arguments)
		exit(EXIT_SUCCESS);
	return (-1);
}
