#include "../../include/minishell.h"

void handle_env(t_shell *shell)
{
	char	**env;

	env = shell->env;
	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
}
