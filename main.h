#ifndef MAIN_H
#define MAIN_H

#define PARTS_DELIMITER " \t\r\n\a\""

/*----Libraries----*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/*----Prototypes----*/
/*--main.c--*/
void interactive_shell(void);
void none_interactive_shell(void);
char *get_line(void);
char **make_args(char *);

#endif
