#include "main.h"

/**
 * main - main fxn of unix shell interpreter
 * @cmdc: args count
 * @cmd: args - cmd and flags
 * @env: the environment var
 * 
 * Return: 1 on success
 */
int main(int cmdc, char **cmd, char **env)
{
	char *buf = NULL;/*, *cmd[20];*/

	do {
		_puts("#cisfun$ ");
		buf = get_line();
		if (cmdc == 0 || _strcmp(buf, "\n") == 0)/*buf[0]=='\0'*/
		{
			free(buf);
			buf = NULL;
			continue;
		}
		if (_strcmp(buf, "exit\n") == 0)
		{
			free(buf);
			buf = NULL;
			exit(EXIT_SUCCESS);
		}
		if (_strcmp(buf, "env\n") == 0)
		{
			print_env(env);
			free(buf);
			buf = NULL;
			continue;
		}
		make_args(buf, cmd);
		_path(cmd);
		fork_fxn(cmd, buf);
	} while (1);
	exit(EXIT_SUCCESS);
}
