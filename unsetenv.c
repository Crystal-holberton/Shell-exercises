#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

int _unsetenv(const char *name)
{
	size_t len = strlen(name);
	char **env = environ, **target;

	while (*env)
	{
		if (strncmp(*env, name, len) == 0 && (*env)[len] == '=')
		{
			target = env;
			while (*target)
			{
				*target = *(target + 1);
				target++;
			}
			return (0);
		}
		env++;
	}
	return (0);
}

int main(void)
{
	_unsetenv("TEST_VAR");
	printf("TEST_VAR=%s\n", getenv("TEST_VAR"));
	return (0);
}
