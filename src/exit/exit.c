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

// The use of exit(g_exit); in shell_exit means that the main function’s return 0;
// is never reached. Depending on how you want to handle exit codes, this might be an issue.

// freeing components of shell. This should be done in all exit paths to prevent memory leaks.


void freeing_my_shell(t_shell **my_shell)
{
    if (my_shell != NULL && *my_shell != NULL)
    {
        // If t_shell contains pointers to dynamically allocated memory,
        // free them here before freeing the structure itself.
        // ...

        free(*my_shell); // Free the allocated memory for my_shell
        *my_shell = NULL; // Set the pointer to NULL to prevent use-after-free
    }
}