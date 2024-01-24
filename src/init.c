#include "../include/minishell.h"

void free_env_array(char **env_array)
{
    if (env_array)
    {
        int i = 0;
        while (env_array[i])
        {
            free(env_array[i]);
            i++;
        }
        free(env_array);
    }
}

char **ft_get_env_array(char **env)
{
    int count = 0;
    while (env[count])
        count++;

    char **env_array = (char **)malloc(sizeof(char *) * (count + 1));
    if (!env_array)
    {
        // handle memory allocation failure
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < count; i++)
    {
        env_array[i] = ft_strdup(env[i]);
        if (!env_array[i])
        {
            // handle memory allocation failure
            // don't forget to free already allocated memory
            exit(EXIT_FAILURE);
        }
    }

    env_array[count] = NULL; // null-terminate the array
    return env_array;
}


int ft_innit_user_and_prompt(t_shell *shell, char **env)
{
    char *user;
    char **env_list_copied;
    char *prompt_suffix;

    env_list_copied = ft_get_env_array(env);
    if (!env_list_copied)
    {
        write(STDERR_FILENO, "Failed to allocate memory for env_list_copied.\n", 48);
        return(MEM_ERROR2);
    }
    shell->env_list = env_list_copied;
    user = ft_strjoin(PURPLE, getenv("USER"));
    if (!user)
    {
        write(STDERR_FILENO, "Failed to allocate memory for user.\n", 37);
        free_env_array(env_list_copied);
        return (MEM_ERROR);
    }
    prompt_suffix = "@ASHellKETCHUM" CLR_RMV "$ ";
    shell->prompt = ft_strjoin(user, prompt_suffix);
    free(user);
    if (!shell->prompt)
    {
        write(STDERR_FILENO, "Failed to allocate memory for prompt.\n", 38);
        free_env_array(env_list_copied);
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
