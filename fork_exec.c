#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
	int num_children = 5;
	char *args[] = {"/bin/ls", "-1", "/tmp", NULL};
	int i = 0;

	while (i < num_children)
	{
		pid_t pid = fork();
		if (pid < 0)
		{
			perror("fork failed");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			printf("Child %d executing 'ls -1 /tmp'\n", i + 1);
			if (execve("/bin/ls", args, NULL) == -1)
			{
				perror("execve failed");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			int status;

			wait(&status);
			if (WIFEXITED(status))
			{
				printf("Child %d exited with status %d\n", i + 1, WEXITSTATUS(status));
			}
			else
			{
				printf("Child %d did not exit successfully\n", i + 1);
			}
		}
		i++;
	}
	printf("All child processes completed.\n");
	return (0);
}
