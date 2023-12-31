#include "main.h"

/**
 * make_args - fxn that breaks line input into args/strings
 * @string: input to be split
 *
 * Return: pointer to a new array
 */
char **make_args(char *string)
{
	int i = 0;
	int buffersize = 64;
	char *part;
	char **parts = malloc(buffersize * sizeof(char *));

	if (!parts)
	{
		_puts("allocation error in make_args: parts\n");
		exit(EXIT_FAILURE);
	}
	part = strtok(string, PARTS_DELIMITER);
	for (; part != NULL; i++)
	{
		if (part[0] == '#')/*-for comments-*/
			break;
		parts[i] = part;
		if (i >= buffersize)
		{
			buffersize += buffersize;
			parts = realloc(parts, buffersize * sizeof(char *));
			if (!parts)
			{
				_puts("reallocation error in make_args: parts\n");
				exit(EXIT_FAILURE);
			}
		}
		part = strtok(NULL, PARTS_DELIMITER);
	}
	parts[i] = NULL;
	return (parts);
}
