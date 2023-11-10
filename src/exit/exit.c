#include "../../build/minishell.h"

void	shell_exit(t_shell *shell)
{
	int	i;

	rl_clear_history();
	free(shell->input);
	shell->input = NULL;
	free(shell->prompt);
	shell->prompt = NULL;
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

// The use of exit(g_exit); in shell_exit means that the main function’s return 0;
// is never reached. Depending on how you want to handle exit codes, this might be an issue.
