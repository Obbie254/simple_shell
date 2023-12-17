#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

char *get_line(void);
void make_args(char *, char **);
int _path(char **cmd);
void print_env(char **);

void _puts(char *);
void _strcat(char *, char *);
int _strcmp(char *, char *);
int _putchar(char);

#endif
