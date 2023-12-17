#include "main.h"

/**
 * none_interactive_shell - This is our unix cmd line interpreter
 *
 * Return: void
 */
void none_interactive_shell(void)
{
	char *input, **arguments;
	int current_status = -1;

	do {
		input = read_stdin();
		arguments = make_args(input);
		current_status = cmd_execute(arguments);
		free(input);
		free(arguments);
		if (current_status >= 0)/*--exitting with status--*/
			exit(current_status);
	} while (current_status == -1);
}
