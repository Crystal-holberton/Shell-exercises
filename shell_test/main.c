#include "shell.h"

/**
 * main - Entry point of the shell program.
 * @argc: Argument count.
 * @argv: Argument vector.
 *
 * Return: 0 on success, or the error code on failure.
 */
int main(int argc, char **argv)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	(void)argc;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "#cisfun$ ", 9);
		}

		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			free(line);
			if (isatty(STDIN_FILENO))
			{
				write(STDOUT_FILENO, "\n", 1);
			}
			break;
		}

		line[read - 1] = '\0';
		if (_strlen(line) > 0)
			execute_command(line, argv[0]);
	}

	return (0);
}
