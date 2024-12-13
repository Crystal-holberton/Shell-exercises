#include "shell.h"

/**
 * execute_command - Parses and executes a command.
 * @command: The command to execute.
 * @prog_name: The name of the program (argv[0]).
 */
void execute_command(char *command, char *prog_name)
{
	char *args[MAX_ARGS];
	pid_t pid;
	int status;

	args[0] = command;
	args[1] = NULL;

	pid = fork();
	if (pid == 0)
	{
		if (execve(command, args, environ) == -1)
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
