#include "main.h"

int main(int argc, char **argv, char **env)
{
	char *buf = NULL, *str, *cmd[20];
	size_t buflen = 0;

	do {
		_puts(":) ");
		buf = get_line();
		if (buf[0] == '\0' || _strcmp(buf, "\n") == 0)
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
		if (fork() == 0)
		{
			str = argv[0];
			execve(cmd[0], cmd, env);
			_puts(str);
			_puts("No such file or directory");
			_putchar('\n');
			exit(EXIT_SUCCESS);
		}
		else
		{
			wait(NULL);
			free(buf);
			buf = NULL;
		}
	} while (1);
	exit(EXIT_SUCCESS);
}
