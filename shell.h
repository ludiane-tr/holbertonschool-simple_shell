#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

int exec_cmd(char *argv[]);
char **tok_args(char *input_buffer);
void print_env(void);
int _error(void);

#endif
