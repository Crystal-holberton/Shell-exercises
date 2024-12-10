#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **split_string(const char *str)
{
	char *copy = strdup(str);
	char *token;
	char **array = malloc(1024 * sizeof(char *));
	int i = 0;

	token = strtok(copy, " \t\n");
	while (token)
	{
		array[i++] = strdup(token);
		token = strtok(NULL, " \t\n");
	}
	array[i] = NULL;
	free(copy);
	return (array);
}

int main(void)
{
	char *input = "This is a sample input string";
	char **words = split_string(input);
	int i = 0;

	while (words[i])
	{
		printf("%s\n", words[i]);
		free(words[i]);
		i++;
	}
	free(words);
	return (0);
}
