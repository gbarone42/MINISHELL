#include "../../build/minishell.h"

char **ft_get_env(char **env)
{
    char **my_env = NULL;
    int i = 0;
    int j = 0;

    // Count the number of strings in the env array
    while (env && env[i])
        i++;

    // Allocate memory for the duplicated environment
    my_env = (char **)malloc(sizeof(char *) * (i + 1));
    if (!my_env) {
        write(STDERR_FILENO, "Memory allocation failed.\n", 26);
        exit(EXIT_FAILURE);
    }

    for (j = 0; j < i; j++) {
        my_env[j] = ft_strdup(env[j]);
        if (!my_env[j])
        {
            write(STDERR_FILENO, "Memory allocation failed for env variable.\n", 42);
            // Clean up the allocated memory before exiting
            for (int k = 0; k < j; k++)
            {
                free(my_env[k]);
            }
            free(my_env);
            //free(env);
            exit(EXIT_FAILURE);
        }
    }
    my_env[j] = NULL;

    return my_env;
}


void free_all_memory(t_shell *shell, char **env_copied)
{
    // Free duplicated environment variables
    free_myenv(env_copied);

    // Free prompt
    free(shell->prompt);

    // Add more free calls for other dynamically allocated memory in your structure

    // Close duplicated file descriptors if needed
    close(shell->in);
    close(shell->out);
}

void free_myenv(char **my_env)
{
    if (my_env)
    {
        for (int i = 0; my_env[i] != NULL; i++) {
            free(my_env[i]); // Free each string in the array
        }
        free(my_env); // Free the array itself
    }
}

////////////////////////////////might want to change the function return type to int?

int ft_innit_shell(t_shell *shell, char **env)
{
    char    *user;
    char    **env_copied;
    char    *prompt_suffix;
    
    // Initialize prompt to NULL
    shell->prompt = NULL;

    user = ft_strjoin(PURPLE, getenv("USER"));

    if (!user)
    {
        write(STDERR_FILENO, "Failed to allocate memory for user.\n", 37 );
        free(user);
        return (MEM_ERROR); 
    }

    env_copied = ft_get_env(env);
    if (!env_copied)
    {
        write(STDERR_FILENO, "Failed to allocate memory for env_copied.\n", 43 );
        free(user);
        free_myenv(env_copied);
        return(MEM_ERROR2);
    }

    //shell->env = env_copied;    
    shell->in = dup(STDIN_FILENO);
    shell->out = dup(STDOUT_FILENO);

    if (shell->in == -1 || shell->out == -1)
    {
        write(STDERR_FILENO, "Failed to duplicate file descriptors\n", 38);
        free_all_memory(shell, env_copied);
        return MEM_ERROR; // or another appropriate error code
    }

    prompt_suffix = "@ASHellKETCHUM" CLR_RMV " > ";
    shell->prompt = ft_strjoin(user, prompt_suffix);
    free(user);

    if (!shell->prompt)
    {
        write(STDERR_FILENO, "Failed to allocate memory for prompt.\n", 38);
        free_all_memory(shell, env_copied);
        return(MEM_ERROR3);
    }

    printf("prompt: %s\n", shell->prompt);

    // Initialize other members of shell if needed
    free_myenv(env_copied);
    shell->paths = NULL;
    shell->export = NULL;

    return(0);
}

//Ensure you have mechanisms in place elsewhere in your code to free shell->env, shell->prompt,
//and other dynamically allocated members of the shell structure when you're done with them.






