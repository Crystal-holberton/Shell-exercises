#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

int _setenv(const char *name, const char *value, int overwrite)
{
	size_t len = strlen(name);
	char **env = environ;
	char *new_var;

	while (*env)
	{
		if (strncmp(*env, name, len) == 0 && (*env)[len] == '=')
		{
			if (!overwrite)
			{
				return (0);
			}
			new_var = malloc(len + strlen(value) + 2);
			if (!new_var)
			{
				return (-1);
			}
			sprintf(new_var, "%s=%s", name, value);
			*env = new_var;
			return (0);
		}
		env++;
	}
	new_var = malloc(len + strlen(value) + 2);
	if (!new_var)
	{
		return (-1);
	}
	sprintf(new_var, "%s=%s", name, value);
	*env = new_var;
	*(env + 1) = NULL;
	return (0);
}

int main(void)
{
	_setenv("TEST_VAR", "HelloWorld", 1);
	printf("TEST_VAR=%s\n", getenv("TEST_VAR"));
	return (0);
}

