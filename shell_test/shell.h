#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_ARGS 128

extern char **environ;

/* Function prototypes */
void execute_command(char *command, char *prog_name);
size_t _strlen(const char *str);
int _strcmp(const char *s1, const char *s2);

#endif /* SHELL_H */
