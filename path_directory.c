#include <stdio.h>
#include <string.h>

extern char **environ;
char *_getenv(const char *name);

void print_path_directories(void)
{
	char *path = _getenv("PATH");

	if (path)
	{
		char *dir = strtok(path, ":");

		while (dir)
		{
			printf("%s\n", dir);
			dir = strtok(NULL, ":");
		}
	}
	else
	{
		printf("PATH not found\n");
	}
}

int main(void)
{
	print_path_directories();
	return (0);
}
