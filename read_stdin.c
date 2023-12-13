#include "main.h"

/**
 * read_stdin - fxn reads line from stdin stream
 *
 * Return: pointer to the line that has been read
 */
char *read_stdin(void)
{
	int buffersize = 1024, i = 0, xter;
	char *input = malloc(sizeof(char) * buffersize);

	if (input == NULL)
	{
		fprintf(stderr, "memory allocation error; read_stdin");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		xter = getchar(); /*--reads xter 1 from stream--*/
		if (xter == EOF)
		{
			free(input);
			exit(EXIT_SUCCESS);
		}
		else if (xter == '\n')
		{
			input[i] = '\0';
			return (input);
		}
		else
			input[i] = xter;
		i++;
		if (i >= buffersize)
		{
			buffersize += buffersize;
			input = realloc(input, buffersize);
			if (input == NULL)
			{
				fprintf(stderr, "memory reallocation error");
				exit(EXIT_FAILURE);
			}
		}
	}
}
