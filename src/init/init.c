#include "../../include/minishell.h"
/*
char	**ft_get_env(char **env)
{
	char	**my_env;
	int		i;


	//printf("ft_get_env called correctly \n");
	i = 0;
	while (env != NULL && env[i])
		i++;
	my_env = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (env[i])
	{
		my_env[i] = ft_strdup(env[i]);
		i++;
	}
	my_env[i] = NULL;
	return (my_env);
}*/










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
    if (!my_env)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    j = 0;
    while (env && env[j])
    {
        my_env[j] = ft_strdup(env[j]);
        if (!my_env[j])
        {
            fprintf(stderr, "Memory allocation failed for env variable.\n");
            exit(EXIT_FAILURE);
        }
        j++;
    }
    my_env[j] = NULL;

    return my_env;
}






////////////////////////////////might want to change the function return type to int?

int	ft_innit_shell(t_shell *shell, char **env)
{
    char    *user;
	char **env_copied;
	char *prompt_suffix;
	
    user = ft_strjoin(PURPLE, getenv("USER"));

    if (!user)
    {
        fprintf(stderr, "Failed to allocate memory for user.\n");
        // You might want to set some flag or take some action here to handle the error.
        return (MEM_ERROR); // Exit the function early as we cannot proceed without user
    }
	env_copied = ft_get_env(env);
    if (!env_copied)
    {
        fprintf(stderr, "Failed to allocate memory for env_copied.\n");
        free(user); // Make sure to free user before returning
        // Again, handle the error as necessary
        return(MEM_ERROR2); // Exit the function early as we cannot proceed without env_copied
    }

	prompt_suffix = "@ASHellKETCHUM" CLR_RMV " > ";
	printf("user: %s\n", user);
    printf("the pc user is %s%s\n", user, CLR_RMV);
    shell->env = env_copied; 	
	//printf("Copied Environment Variables:\n");
    // for (int i = 0; env_copied[i] != NULL; ++i)
	// {
    // 	printf("[%d] %s\n", i, env_copied[i]); // Print each environment variable
    // }
    shell->in = dup(STDIN_FILENO);
	shell->out = dup(STDOUT_FILENO);
	shell->prompt = ft_strjoin(user, prompt_suffix);


    ////note: FREEING THE 'user'

    if (!shell->prompt)
    {
        fprintf(stderr, "Failed to allocate memory for prompt.\n");
        free(user); // Free resources before returning
        free(env_copied); // Assuming this function frees the entire env_copied array
        return(MEM_ERROR3); // Exit the function early as we cannot proceed without prompt
    }
	printf("prompt: %s\n", shell->prompt);
	shell->paths = NULL;
	shell->export = NULL;
	//shell->pipe[0] = -2;
	//shell->pipe[1] = -2;
	//shell->status = 0;
	//shell->exit = 0;
	//shell->env = NULL;
	//shell_env(env, shell);
	free(user);
    return(0);
}

//Ensure you have mechanisms in place elsewhere in your code to free shell->env, shell->prompt,
//and other dynamically allocated members of the shell structure when you're done with them.






