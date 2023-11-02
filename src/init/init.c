#include "../../include/minishell.h"

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
}

void	ft_innit_shell(t_shell *shell, char **env)
{
    char    *user;
	char **env_copied;

    user = ft_strjoin(PURPLE, getenv("USER"));
	printf("user: %s\n", user);
    printf("the pc user is %s%s\n", user, CLR_RMV);

	env_copied = ft_get_env(env); // Copy the environment
    shell->env = env_copied; 
	
	//printf("Copied Environment Variables:\n");
    // for (int i = 0; env_copied[i] != NULL; ++i)
	// {
    // 	printf("[%d] %s\n", i, env_copied[i]); // Print each environment variable
    // }
    shell->in = dup(STDIN_FILENO);
	shell->out = dup(STDOUT_FILENO);
	shell->prompt = ft_strjoin(user, "@ASHellKETCHUM" CLR_RMV " > ");
	printf("prompt: %s\n", shell->prompt);
	shell->paths = NULL;

	//shell->pipe[0] = -2;
	//shell->pipe[1] = -2;
	//shell->status = 0;
	//shell->exit = 0;
	//shell->env = NULL;
	//shell->export = NULL;
	//shell_env(env, shell);
    
	free(user);  
}








