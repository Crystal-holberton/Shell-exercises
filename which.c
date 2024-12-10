#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

void find_in_path(const char *filename)
{
	char *path_env = getenv("PATH");

	if (path_env == NULL)
	{
		fprintf(stderr, "Error: PATH environment variableis not set.\n");
		return;
	}

	char *path_copy = strdup(path_env);

	if (path_copy == NULL)
	{
		perror("strdup");
		return;
	}

	char *dir = strtok(path_copy, ":");
	struct stat stat_buf;

	while (dir != NULL)
	{
		char full_path[4096];
		snprintf(full_path, sizeof(full_path), "%s%s", dir, filename);

		if (stat(full_path, &stat_buf) == 0 && access(full_path, X_OK) == 0)
		{
			printf("%s\n", full_path);
			free(path_copy);
			return;
		}
		dir = strtok(NULL, ":");
	}
	printf("Command '%s' not found in PATH.\n", filename);
	free(path_copy);
}

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s filename\n", argv[0]);
		return (1);
	}
	find_in_path(argv[1]);
	return (0);
}
