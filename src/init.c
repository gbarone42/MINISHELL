#include "minishell.h"

void	free_env_array(char **env_array)
{
	int	i;

	if (env_array)
	{
		i = 0;
		while (env_array[i])
		{
			free(env_array[i]);
			i++;
		}
		free(env_array);
	}
}

char	**ft_get_env_array(char **env)
{
	int			count;
	char		**env_array;
	int			i;

	i = 0;
	count = 0;
	while (env[count])
		count++;
	env_array = (char **)malloc(sizeof(char *) * (count + 1));
	if (!env_array)
	{
		exit(EXIT_FAILURE);
	}
	while (i < count)
	{
		env_array[i] = ft_strdup(env[i]);
		if (!env_array[i])
		{
			exit(EXIT_FAILURE);
		}
		i++;
	}
	env_array[count] = NULL;
	return (env_array);
}

int	copy_env_vars(t_shell *shell, char **env)
{
	shell->env_list = ft_get_env_array(env);
	if (!shell->env_list)
	{
		write(STDERR_FILENO, "Failed to allocate for env_list_copied.\n", 48);
		return (MEM_ERROR2);
	}
	return (0);
}

int	create_user(char **user)
{
	*user = ft_strjoin(PURPLE, getenv("USER"));
	if (!*user)
	{
		write(STDERR_FILENO, "Failed to allocate memory for user.\n", 37);
		return (MEM_ERROR);
	}
	return (0);
}

int	create_prompt2(t_shell *shell, char *user)
{
	char	*prompt_suffix;

	prompt_suffix = "@ASHellKETCHUM" CLR_RMV "$ ";
	shell->prompt = ft_strjoin(user, prompt_suffix);
	free(user);
	if (!shell->prompt)
	{
		write(STDERR_FILENO, "Failed to allocate memory for prompt.\n", 38);
		free_env_array(shell->env_list);
		return (MEM_ERROR3);
	}
	//printf("prompt: %s\n", shell->prompt);
	return (0);
}

int	ft_innit_user_and_prompt(t_shell *shell, char **env)
{
	char	*user;
	int		result;

	result = copy_env_vars(shell, env);
	if (result != 0)
		return (result);
	result = create_user(&user);
	if (result != 0)
	{
		free_env_array(shell->env_list);
		return (result);
	}
	return (create_prompt2(shell, user));
}

// int	ft_innit_user_and_prompt(t_shell *shell, char **env)
// {
// 	char	*user;
// 	char	**env_list_copied;
// 	char	*prompt_suffix;

// 	env_list_copied = ft_get_env_array(env);
// 	if (!env_list_copied)
// 	{
// 		write(STDERR_FILENO, "Failed to allocate for env_list_copied.\n", 48);
// 		return (MEM_ERROR2);
// 	}
// 	shell->env_list = env_list_copied;
// 	user = ft_strjoin(PURPLE, getenv("USER"));
// 	if (!user)
// 	{
// 		write(STDERR_FILENO, "Failed to allocate memory for user.\n", 37);
// 		free_env_array(env_list_copied);
// 		return (MEM_ERROR);
// 	}
// 	prompt_suffix = "@ASHellKETCHUM" CLR_RMV "$ ";
// 	shell->prompt = ft_strjoin(user, prompt_suffix);
// 	free(user);
// 	if (!shell->prompt)
// 	{
// 		write(STDERR_FILENO, "Failed to allocate memory for prompt.\n", 38);
// 		free_env_array(env_list_copied);
// 		return (MEM_ERROR3);
// 	}
// 	printf("prompt: %s\n", shell->prompt);
// 	return (0);
// }
int	ft_duplicate_std_fds(t_shell *shell)
{
	shell->in = dup(STDIN_FILENO);
	shell->out = dup(STDOUT_FILENO);
	if (shell->in == -1 || shell->out == -1)
	{
		write(STDERR_FILENO, "Failed to duplicate file descriptors\n", 38);
		free_env_array(shell->env_list);
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
