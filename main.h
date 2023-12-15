#ifndef MAIN_H
#define MAIN_H

#define PARTS_DELIMITER " \t\r\n\a\""
extern char **environ;

#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/*int own_cd(char **arguments);*/
int own_env(char **arguments);
int own_exit(char **arguments);

void interactive_shell(void);
void none_interactive_shell(void);
char *get_line(void);
char **make_args(char *);
int cmd_execute(char **);
int _strcmp(char *, char *);
int cmd_execute(char **);
int new_program(char **);
char *read_stdin(void);
void _puts(char *str);
int _putchar(char c);

#endif
