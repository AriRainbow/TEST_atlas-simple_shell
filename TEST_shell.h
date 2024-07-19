#ifndef SHELL_H
#define SHELL_H

#include <stdio.h> /* printf, perror, getline */
#include <stdlib.h> /* free, exit, EXIT_FAILURE */
#include <unistd.h> /* POSIX API functions */
#include <string.h> /* string manipualtion */

char **parse_line(char *line);
int execute(char **args);

#endif
