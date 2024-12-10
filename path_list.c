#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct PathNode
{
	char *directory;
	struct PathNode *next;
} PathNode;

PathNode *build_path_list(void)
{
	char *path = getenv("PATH");

	if (!path)
	{
		return (NULL);
	}
	
	PathNode *head = NULL, *current = NULL;
	char *dir = strtok(path, ":");

	while (dir)
	{
		PathNode *new_node = malloc(sizeof(PathNode));
		if (!new_node)
		{
			perror("malloc");
			return (NULL);
		}
		new_node->directory = strdup(dir);
		new_node->next = NULL;

		if (!head)
		{
			head = new_node;
		}
		else
		{
			current->next = new_node;
		}
		current = new_node;
		dir = strtok(NULL, ":");
	}
	return (head);
}

void free_path_list(PathNode *head)
{
	while (head)
	{
		PathNode *temp = head;
		head = head->next;
		free(temp->directory);
		free(temp);
	}
}

int main(void)
{
	PathNode *path_list = build_path_list();
	PathNode *current = path_list;

	while (current)
	{
		printf("%s\n", current->directory);
		current = current->next;
	}
	free_path_list(path_list);
	return (0);
}
