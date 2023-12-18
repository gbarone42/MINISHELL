#include "minishell_p.h"

void	ft_free_env_and_error_decorator(char **env, char *caller, char *message)
{
	size_t	index;

	index = -1;
	while (env[++index])
		free(env[index]);
	free(env);
	ft_error(caller, message);
}
