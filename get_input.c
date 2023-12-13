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
