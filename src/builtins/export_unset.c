#include "../../include/minishell.h"

void handle_envv(t_shell *shell)
{
    t_evlist *current = shell->env_list; // Assuming env_list is a pointer to the first node of the linked list
    while (current)
    {
        printf("%s\n", current->value);
        current = current->next;
    }
}
void handle_unset(t_shell *shell, char **args)
{
    if (args[1] == NULL)
    {
        printf("Usage: unset <variable>\n");
        return;
    }
    for (int i = 1; args[i] != NULL; ++i)
    {
        t_evlist *current = shell->env_list;
        while (current != NULL)
        {
            if (strstr(current->value, args[i]) == current->value)
            {
                printf("Unsetting: %s\n", current->value);
                if (current->prev)
                    current->prev->next = current->next;
                if (current->next)
                    current->next->prev = current->prev;

                if (current == shell->env_list) // Update the head of the list if necessary
                    shell->env_list = current->next;
                free(current->value);
                free(current);
                break;
            }
            current = current->next;
        }
    }
}

char *ft_strtok(char *str, char sep)
{
	static char *last = NULL;

	if (str != NULL)
	{
		last = str;
	} else if (last == NULL || *last == '\0')
	{
		return NULL;
	}
	char *token_start = last;
	while (*last != '\0' && *last != sep)
	{
		last++;
	}
	if (*last != '\0')
	{
		*last = '\0';
		last++;
	}
	return token_start;
}

bool contains_invalid_characters(const char *str)
{
	if (!((str[0] >= 'a' && str[0] <= 'z') || (str[0] >= 'A' && str[0] <= 'Z') || str[0] == '_'))
	{
		return true;
	}

	for (int i = 1; str[i] != '\0'; ++i)
	{
		if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9') || str[i] == '_'))
		{
			return true;
		}
	}

	return false;
}

// void *ft_realloc(void *ptr, size_t old_size, size_t new_size)
// {
// 	void *new_ptr;

// 	if (ptr == NULL)
// 		return malloc(new_size);
// 	if (!new_size)
// 	{
// 		free(ptr);
// 		return NULL;
// 	}
// 	new_ptr = malloc(new_size);
// 	if (!new_ptr)
// 	{
// 		perror("Memory allocation failed for realloc.\n");
// 		exit(EXIT_FAILURE);
// 	}
// 	size_t copy_size = (old_size < new_size) ? old_size : new_size;
// 	ft_memcpy(new_ptr, ptr, copy_size);
// 	free(ptr);
// 	return new_ptr;
// }

void add_env_variable(t_shell *shell, const char *name, const char *value)
{
    char *new_variable = (char *)malloc(strlen(name) + strlen(value) + 2);
    if (!new_variable)
    {
        printf("Memory allocation failed for env variable.\n");
        exit(EXIT_FAILURE);
    }

    strcpy(new_variable, name);
    strcat(new_variable, "=");
    strcat(new_variable, value);

    t_evlist *current = shell->env_list;
    int found = 0;
    while (current != NULL)
    {
        if (strncmp(current->value, name, strlen(name)) == 0 && current->value[strlen(name)] == '=')
        {
            free(current->value);
            current->value = new_variable;
            found = 1;
            break;
        }
        current = current->next;
    }

    if (!found)
    {
        t_evlist *new_node = (t_evlist *)malloc(sizeof(t_evlist));
        if (!new_node)
        {
            perror("Memory allocation failed for new env node.\n");
            exit(EXIT_FAILURE);
        }
        new_node->value = new_variable;
        new_node->next = shell->env_list;
        new_node->prev = NULL;
        if (shell->env_list)
            shell->env_list->prev = new_node;
        shell->env_list = new_node;
    }

    printf("New variable: %s\n", new_variable);
}

void handle_export(t_shell *shell, char **args)
{
	if (args[1] == NULL)
	{
		handle_envv(shell);
	}
	else
	{
	char *name  = ft_strtok(args[1], '=');
	char *value = ft_strtok(NULL, '=');
		if (name != NULL && value != NULL)
		{
			if (contains_invalid_characters(name))
			{
				printf("Invalid variable name: %s\n", name);
			}
			else
			{
				printf("Name: %s\n", name);
				printf("Value: %s\n", value);
				add_env_variable(shell, name, value);
			}
		}
		else
		{
			printf("Invalid export syntax: %s\n", args[1]);
		}
	}
}

