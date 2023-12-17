#include "main.h"

/**
 * get_line - fxn reads stdin/ line
 *
 * Return: pointer to a string with stdin content
 */
char *get_line(void)
{
	char *input = NULL;
	size_t buffersize = 0;

	if (getline(&input, &buffersize, stdin) == -1) /*if getline fails*/
	{
		if (feof(stdin)) /*--tests eof--*/
		{
			free(input);
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(input);
			perror("Error on reading stdin");
			exit(EXIT_FAILURE);
		}
	}
	return (input);
}

/**
 * make_args - fxn tokenilizes the input string
 * @buff: input string
 * @args: array (cmd and its flags)
 *
 * Return: void
 */
void make_args(char *buff, char **args)
{
	char *ptr;
	int i = 0;

	ptr = strtok(buff, " \n");
	while (ptr)
	{
		args[i] = ptr;
		ptr = strtok(NULL, " \n");
		i++;
	}
	args[i] = NULL;
}

/**
 * _path - fxn adds a path to the command given
 * @args: cmd and flags
 *
 * Return: 1 on success, 0 otherwise
 */
int _path(char **args)
{
	const char *PATH[5];
	unsigned int i = 0;
	struct stat st;

	PATH[0] = "/usr/local/bin/ls";
	PATH[1] = "/bin/";
	PATH[2] = "/sbin";
	PATH[3] = "/usr/bin/";
	PATH[4] = "NULL";
	while (PATH[i])
	{
		char string[120] = "";

		strcat(string, PATH[i]);
		strcat(string, args[0]);
		if (stat(string, &st) == 0)
		{
			args[0] = string;
			return (0);
		}
		i++;
	}
	return (-1);
}

/**
 * print_env - fxn prints the environment user is at
 * @env: environment
 *
 * Return: void
 */
void print_env(char **env)
{
	int i = 0;
	char *str;

	while (env[i])
	{
		str = env[i++];
		puts(str);
	}
}
