#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int _putchar(char c);
void _print(char *str);
int execute_cmd(char **args);

#endif /* MAIN_H */
