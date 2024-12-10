#include <stdio.h>
#include <string.h>

extern char **environ;

char *_getenv(const char *name)
{
	char **env = environ;
	size_t len = strlen(name);

	while (*env)
	{
		if (strncmp(*env, name, len) == 0 && (*env)[len] == '=')
		{
			return (*env + len + 1);
		}
		env++;
	}
	return (NULL);
}

int main(void)
{
	const char *var = "PATH";
	char *value = _getenv(var);

	if (value)
	{
		printf("%s=%s\n", var, value);
	}
	else
	{
		printf("%s not found\n", var);
	}
	return (0);
}