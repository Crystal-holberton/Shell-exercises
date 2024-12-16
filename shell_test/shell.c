#include "shell.h"

/**
 * execute_command - Parses and executes a command.
 * @command: The command to execute.
 * @prog_name: The name of the program (argv[0]).
 */
void execute_command(char *command, char *prog_name)
{
	char *args[MAX_ARGS];
	char *token;
	int i = 0;
	pid_t pid;
	int status;

	token = strtok(command, " ");
	while (token != NULL && i < MAX_ARGS - 1)
	{
		args[i++] = token;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;

	if (args[0] == NULL)
	{
		return;
	}

	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			perror(prog_name);
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		perror(prog_name);
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}
