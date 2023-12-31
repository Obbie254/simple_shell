#include "main.h"

/**
 * interactive_shell - This our unix cmd line interpreter
 *
 * Return: void
 */
void interactive_shell(void)
{
	char *line, *prompt, **arguments;
	int current_status = -1;

	do {
		prompt = "me@simple_shell~$ ";
		_puts(prompt); /* printing the shell prompt */
		line = get_line(); /* reads line from stdin */
		arguments = make_args(line); /* breaks the input */
		current_status = cmd_execute(arguments);
		free(arguments);
		free(line);
		if (current_status >= 0)
			exit(current_status);
	} while (current_status == -1);
}
