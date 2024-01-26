#include "minishell.h"

char *create_new_env_variable(const char *name, const char *value)
{
	char *new_variable = (char *)malloc(strlen(name) + strlen(value) + 2);
	if (!new_variable)
	{
		printf("Memory allocation failed for env variable.\n");
		exit(EXIT_FAILURE);
	}

	ft_strcpy(new_variable, name);
	ft_strcat(new_variable, "=");
	ft_strcat(new_variable, value);

	return new_variable;
}

int update_existing_variable(t_shell *shell, const char *name, char *new_variable)
{
	int i = 0;
	while (shell->env_list[i] != NULL)
	{
		if (ft_strncmp(shell->env_list[i], name, strlen(name)) == 0 && shell->env_list[i][strlen(name)] == '=')
		{
			free(shell->env_list[i]);
			shell->env_list[i] = new_variable;
			return (1);
		}
		i++;
	}
	return (0);
}

void add_new_variable(t_shell *shell, char *new_variable, int env_size)
{
	shell->env_list = (char **)realloc(shell->env_list, (env_size + 2) * sizeof(char *));
	if (!shell->env_list)
	{
		perror("Memory allocation failed for env array.\n");
		exit(EXIT_FAILURE);
	}

	shell->env_list[env_size] = new_variable;
	shell->env_list[env_size + 1] = NULL;
}

void add_env_variable(t_shell *shell, const char *name, const char *value)
{
	char *new_variable = create_new_env_variable(name, value);
	printf("New variable: %s\n", new_variable);

	int found = update_existing_variable(shell, name, new_variable);

	if (!found)
	{
		int env_size = 0;
		while (shell->env_list[env_size] != NULL) env_size++;
		add_new_variable(shell, new_variable, env_size);
	}
}