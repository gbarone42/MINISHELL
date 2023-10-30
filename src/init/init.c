#include "../../include/minishell.h"

char	**ft_get_env(char **env)
{
	char	**my_env;
	int		i;

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

void	shell_env(char **env, t_shell *shell)
{	
	int		i;

	i = 0;
	while (env[i])
		i++;
	shell->env = (char **)ft_calloc(i + 1, sizeof(char *));

}

void	ft_innit_shell(t_shell *shell, char **env)
{
    char    *user;

    user = ft_strjoin(PURPLE, getenv("USER"));
    printf("the pc user is %s%s\n", user, CLR_RMV);
	shell->env = ft_get_env(env);
    shell->in = dup(STDIN_FILENO);
	shell->out = dup(STDOUT_FILENO);
	//shell->pipe[0] = -2;
	//shell->pipe[1] = -2;
	shell->status = 0;
	shell->exit = 0;
	shell->env = NULL;
	shell->paths = NULL;
	shell->export = NULL;
	printf("Creating prompt with user: %s\n", user);
	shell->prompt = ft_strjoin(user, "@AshellKetchum" CLR_RMV " > ");
	printf("Generated prompt: %s\n", shell->prompt);

    free(user);  

}
