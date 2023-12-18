#include "minishell_p.h"

static char **ft_get_env(char **env)
{
    char **my_env = NULL;
    int i = 0;

    while (env && env[i])
        i++;
    my_env = (char **)malloc(sizeof(char *) * (i + 1));
    if (!my_env)
    {
        write(STDERR_FILENO, "Memory allocation failed.\n", 27);
        exit(EXIT_FAILURE);
    }
    for (int j = 0; j < i; j++)
    {
        my_env[j] = ft_strdup(env[j]);
        if (!my_env[j])
        {
            write(STDERR_FILENO, "Memory allocation failed for env variable.\n", 44);
            while (j > 0)
            {
                free(my_env[j - 1]);
                j--;
            }
            free(my_env);
            exit(EXIT_FAILURE);
        }
    }
    my_env[i] = NULL;
    return my_env;
}

static void	ft_init_user_and_prompt(t_shell *shell, char **env)
{
    char *user;
    char **env_copied = ft_get_env(env);
    char *prompt_suffix = "@ASHellKETCHUM" CLR_RMV "$ ";

    if (!env_copied)
		ft_error("ft_gen_env", "Failed to allocate memory for env_copied.");
    shell->env = env_copied;
    user = ft_strjoin(PURPLE, getenv("USER"));
    if (!user)
		ft_free_and_error(env_copied, "ft_strjoin", "Failed to allocate memory for user.");
    shell->prompt = ft_strjoin(user, prompt_suffix);
    free(user);
    if (!shell->prompt)
		ft_free_and_error(env_copied, "ft_strjoin", "Failed to allocate memory for user.");
}

static int ft_duplicate_std_fds(t_shell *shell)
{
    shell->in = dup(STDIN_FILENO);
    shell->out = dup(STDOUT_FILENO);

    if (shell->in == -1 || shell->out == -1)
    {
        write(STDERR_FILENO, "Failed to duplicate file descriptors\n", 38);
        free_myenv(shell->env);
        free(shell->prompt);
        return MEM_ERROR;
    }

    shell->paths = NULL;
    shell->export = NULL;

    return 0;
}

void	ft_init_shell(t_shell *shell, char **env)
{
	int result;

    ft_init_user_and_prompt(shell, env);
    ft_duplicate_std_fds(shell);
}
