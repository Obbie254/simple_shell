//main.c
#include "main.h"

/**
 * main - This fxn checks shell call
 *
 * Return: 0 on success
 */
int main(void)
{
	//Is descriptor associated with terminal
	if (isatty(STDIN_FILENO) == 1)
	{
		interactive_shell();
	}
	else
	{
		none_interactive_shell();
	}
	return (0);
}
