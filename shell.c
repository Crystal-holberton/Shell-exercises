#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

/**
 * main - super simple shell
 * Return: Always 0
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	pid_t pid;
	int status;

	while (1)
	{
		printf("#cisfun$ ");
		fflush(stdout);
		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			printf("\n");
			break;
		}
		line[nread - 1] = '\0';
		if (strlen(line) == 0)
		{
			continue;
		}
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			break;
		}
		if (pid == 0)
		{
			char *argv[] = {line, NULL};

			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("execve");
			}
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(&status);
		}
	}
	free(line);
	return 0;
}
