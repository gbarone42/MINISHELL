#include "../include/minishell.h"

char **ft_get_env(char **env)
{
    char **my_env = NULL;
    int i = 0;
    int j = 0;

    while (env && env[i])
        i++;
    my_env = (char **)malloc(sizeof(char *) * (i + 1));
    if (!my_env) {
        write(STDERR_FILENO, "Memory allocation failed.\n", 27);
        exit(EXIT_FAILURE);
    }
    for (j = 0; j < i; j++) {
        my_env[j] = ft_strdup(env[j]);
        if (!my_env[j])
        {
            write(STDERR_FILENO, "Memory allocation failed for env variable.\n", 44);
            while (j > 0) {
                free(my_env[j - 1]);
                j--;
            }
            free(my_env);
            exit(EXIT_FAILURE);
        }
    }
    my_env[j] = NULL;
    return my_env;
}


void free_myenv(char **my_env)
{
    if (my_env)
    {
        for (int i = 0; my_env[i] != NULL; i++) {
            free(my_env[i]); // Free each string in the array
        }
        free(my_env);
    }
}

int	ft_innit_shell(t_shell *shell, char **env)
{
    char    *user;
    char    **env_copied;
    char    *prompt_suffix;
    
    user = ft_strjoin(PURPLE, getenv("USER"));

    if (!user)
    {
        write(STDERR_FILENO, "Failed to allocate memory for user.\n", 37 );
        return (MEM_ERROR); 
    }
    env_copied = ft_get_env(env);
    if (!env_copied)
    {
        write(STDERR_FILENO, "Failed to allocate memory for env_copied.\n", 43 );
        free(user);
        return(MEM_ERROR2);
    }
    shell->env = env_copied; 
    shell->in = dup(STDIN_FILENO);
    shell->out = dup(STDOUT_FILENO);

    if (shell->in == -1 || shell->out == -1)
    {
        write(STDERR_FILENO, "Failed to duplicate file descriptors\n", 38);
        free_myenv(env_copied);
        free(shell->prompt);
        return MEM_ERROR;
    }
    prompt_suffix = "@ASHellKETCHUM" CLR_RMV "$ ";
    shell->prompt = ft_strjoin(user, prompt_suffix);

    free(user);
    if (!shell->prompt)
    {
        write(STDERR_FILENO, "Failed to allocate memory for prompt.\n", 38);
        free_myenv(env_copied);
        return(MEM_ERROR3);
    }
    printf("prompt: %s\n", shell->prompt);
    shell->paths = NULL;
    shell->export = NULL;
    //free_myenv(env_copied);
    return(0);
}




