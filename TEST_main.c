#include "shell.h"

/**
 * main - Entry point for the shell program.
 *
 * Description: This function initializes the shell, displays a
 * prompt, reads user input, parses the input into commands, and
 * executes the commands.
 *
 * Return: Always 0 (Success).
 */
int main(void)
{
	char *line = NULL; /* pointer stores input line */
	size_t len = 0; /* size of input buffer */
	ssize_t nread; /* number of characters read by getline */
	char **args; /* array of arguments parsed from input line */
	int status = 1; /* status of shell, 1 running 0 exit */

	while (status) /* loop until status is 0, exit command */
	{
		printf("($) "); /* display the prompt */
		nread = getline(&line, &len, stdin); /* read input line */
		if (nread == -1) /* check for error reading input */
		{
			free(line); /* free alloc mem for line */
			perror("getline"); /* print error message */
			exit(EXIT_FAILURE); /* exit with failure status */
		}
		args = parse_line(line); /* parse input into arguments */
		status = execute(args); /* execute parsed commands */
		free(args); /* free alloc mem for args */
	}
	free(line); /* free alloc mem for line before exiting */
	return (0); /* success status */
}
