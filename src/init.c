#include "../include/minishell.h"

void	free_env_list(t_evlist *env_list)
{
	while (env_list)
	{
		t_evlist *next_node = env_list->next;
		free(env_list->value); // Free the string value
		free(env_list); // Free the node itself
		env_list = next_node;
	}
}

t_evlist *ft_get_env_list(char **env)
{
	t_evlist *env_list = NULL;
	t_evlist *tail = NULL;

	for (int i = 0; env && env[i]; ++i)
	{
		t_evlist *new_node = (t_evlist *)malloc(sizeof(t_evlist));
		if (!new_node)
		{
			write(STDERR_FILENO, "Memory allocation failed for env node.\n", 40);//41
			free_env_list(env_list); // Free already allocated nodes
			exit(EXIT_FAILURE);
		}
		new_node->value = ft_strdup(env[i]);
		if (!new_node->value)
		{
			write(STDERR_FILENO, "Memory allocation failed for env variable.\n", 44);
			free(new_node);
			free_env_list(env_list); // Free already allocated nodes
			exit(EXIT_FAILURE);
		}
		new_node->next = NULL;
		new_node->prev = tail;
		if (tail)
			tail->next = new_node;
		else
			env_list = new_node; // This is the first node
		tail = new_node;
	}
	return (env_list);
}


int ft_innit_user_and_prompt(t_shell *shell, char **env)
{
	char		*user;
	t_evlist	*env_list_copied; // Assuming this is a linked list
	char		*prompt_suffix;

	env_list_copied = ft_get_env_list(env); // New function to convert env array to linked list
	if (!env_list_copied)
	{
		write(STDERR_FILENO, "Failed to allocate memory for env_list_copied.\n", 48);
		return(MEM_ERROR2);
	}
	shell->env_list = env_list_copied; // Use env_list instead of env
	user = ft_strjoin(PURPLE, getenv("USER"));
	if (!user)
	{
		write(STDERR_FILENO, "Failed to allocate memory for user.\n", 37);//38
		free_env_list(env_list_copied); // New function to free the env list
		return (MEM_ERROR);
	}
	prompt_suffix = "@ASHellKETCHUM" CLR_RMV "$ ";
	shell->prompt = ft_strjoin(user, prompt_suffix);
	free(user);
	if (!shell->prompt)
	{
		write(STDERR_FILENO, "Failed to allocate memory for prompt.\n", 38);
		free_env_list(env_list_copied); // New function to free the env list
		return(MEM_ERROR3);
	}
	printf("prompt: %s\n", shell->prompt);
	return (0);
}

int ft_duplicate_std_fds(t_shell *shell)
{
	shell->in = dup(STDIN_FILENO);
	shell->out = dup(STDOUT_FILENO);

	if (shell->in == -1 || shell->out == -1)
	{
		write(STDERR_FILENO, "Failed to duplicate file descriptors\n", 38);
		free_env_list(shell->env_list);
		free(shell->prompt);
		return (MEM_ERROR);
	}
	shell->paths = NULL;
	shell->export = NULL;
	return (0);
}

int	ft_innit_shell(t_shell *shell, char **env)
{
	int	result;

	result = ft_innit_user_and_prompt(shell, env);
	if (result != 0)
		return (result);
	result = ft_duplicate_std_fds(shell);
	if (result != 0)
		return (result);
	ft_ret_shell(shell);
	return (0);
}
