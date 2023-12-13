#include "main.h"

/**
 * cmd_execute - fxn checks if cmd (first arg)entered matches
 * builtin cmd
 * @arguments: parts from make_agrs (cmd and flags)
 *
 * Return: 1 0n success, 0 on fail.
 */
int cmd_execute(char **arguments)
{
	char list_buildin_cmd[] = {
		"cd",
		"env",
		"exit"
	};
	int (*buildin_fxn[])(char **) = {
		&own_cd,
		&own_env,
		&own_exit
	};
	int i;

	if (arguments[0] == NULL)
		return (-1);
	for (i = 0; i < sizeof(list_buildin_cmd) / sizeof(char *); i++)
	{
		if (_strcmp(arguments[0], list_buildin_cmd[i]) == 0)
			return ((*buildin_fxn[i])(arguments));
	}
	return (new_program(arguments));
}
