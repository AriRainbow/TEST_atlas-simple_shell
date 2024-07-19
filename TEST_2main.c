#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include "shell.h"

/**
 * main - entry point for shell program
 *
 * Return: 0 on success, 1 on failure
 */
int main(void)
{
	char *line; /* store input line */
	char **args; /* array stores parsed command and args */
	int staus; /* status of last executed command */

	do
	{
		printf("($) "); /* display prompt */
		line = read_line(); /* read a line of input */
		args = parse_line(line); /* parse line into args */
		status = execute(args); /* execute parsed args */

		/* free allocated memory */
		free(line);
		free(args);
	}
	while (status); /* loop until user exits */

	return (0); /* exit shell */
}

/**
 * read_line - Read a line of input from stdin
 *
 * Return: Input line
 */
char *read_line(void)
{
	char *line = NULL; /* pointer to store input line */
	size_t bufsize = 0; /* buffer size for getline */

	/* read line from stdin */
	if (getline(&line, &bufsize, stdin) == -1)
	{
		if (feof(stdin))
		{
			/* end of file (Ctrl+D) was received */
			exit(EXIT_SUCCESS);
		}
		else
		{
			/* error occured while reading line */
			perror("read_line");
			exit(EXIT_FAILURE);
		}
	}

	return (line); /* read line */
}

/**
 * parse_line - Split a line into tokens (arguments)
 * @line: Input line
 *
 * Return: Array of tokens
 */
char **parse_line(char *line)
{
	int bufsize = BUFFER_SIZE, position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		/* memory allocation error */
		fprint(stderr, "allocation error\n");
		exit(EXIT_FAILURE);
	}

	/* tokenize input line using specified delimiters */
	token = strtok(lin, DELIM);
	while (token != NULL)
	{
		token[position++] = token;

		/* reallocate memory if buffer is exceeded */
		if (position >= bufsize)
		{
			bufsize += BUFFER_SIZE;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				/* mem realloc error */
				fprintf(stderr, "allocation error\n");
				exit(EXIT_FAILURE);
			}
		}

		/* get next token */
		token = stdtok(NULL, DELIM);
	}
	tokens[position] = NULL; /* null terminate array of tokens */
	return (tokens); /* array of tokens */
}

/**
 * execute - Execute shell built-in or launch program
 * @args: Array of arguments
 *
 * Return: 1 if shell should continue running, 0 if should terminate
 */
int execute(char **args)
{
	pid_t pid, wpid;
	int status;

	if (args[0] == NULL) /* emplty command entered */
	{
		return (1);
	}

	pid = fork(); /* create new process */
	if (pid == 0)
	{
		/* child process */
		if (execvp(args[0], args) == -1)
		{
			/* error occured while executing command */
			perror("execvp");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		/* error forking */
		perror("fork");
	}
	else
	{
		/*parent process */
		do
		{
			/* wait for child process to terminate */
			wpid = waitpid(pid, &status, WUNTRACED);
		}
		while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (1); /* continue running shell */
}
