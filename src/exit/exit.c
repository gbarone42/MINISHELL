#include "../../include/minishell.h"

void	shell_exit(t_shell *shell)
{
	int	i;


	testprintf1();

	rl_clear_history();
	free(shell->input);
	free(shell->prompt);
	i = 0;
	while (shell->env[i])
		free(shell->env[i++]);
	free(shell->env);
	i = 0;
	if (shell->paths)
	{
		while (shell->paths[i])
			free(shell->paths[i++]);
		free(shell->paths);
	}
	if (shell->export)
	{
		i = 0;
		while (shell->export[i])
			free(shell->export[i++]);
		free(shell->export);
	}
	exit(g_exit);
}
