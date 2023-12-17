#include "main.h"

/**
 * new_program - executes cmd that are not buildin cmds
 * @arguments: cmd and its flags (args from make_args)
 *
 * Return: 1 on success
 */
int new_program(char **arguments)
{
	int wstatus;
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		if (execvp(arguments[0], arguments) == -1)
			perror("error in new program; child process");
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		perror("error in new program; forking");
	else
	{
		while (!WIFEXITED(wstatus) && !WIFSIGNALED(wstatus))
			waitpid(pid, &wstatus, WUNTRACED);
	}
	return (-1);
}
