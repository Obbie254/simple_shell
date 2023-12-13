#ifndef MAIN_H
#define MAIN_H

#define PARTS_DELIMITER " \t\r\n\a\""

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void interactive_shell(void);
void none_interactive_shell(void);
char *get_line(void);
char **make_args(char *);
int cmd_execute(char **);
int _strcmp(char *, char *);


#endif
