#include "main.h"

/**
 * get_line - fxn reads stdin/ line
 *
 * Return: pointer to a string with stdin content
 */
char get_line(void)
{
	char *line = NULL;
	size_t buffersize = 0;

	if (getline(&line, &buffersize, stdin) == -1) /*--if getting line content fails--*/
	{
		if (feof(stdin)) /*--tests eof--*/
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(line);
			perror("Error on reading stdin");
			exit{EXIT_FAILURE};
		}
	}
	return (line);
}
