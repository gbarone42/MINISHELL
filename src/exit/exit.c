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
        // Free dynamically allocated members of t_shell
        if ((*my_shell)->prompt != NULL) {
            free((*my_shell)->prompt);
            (*my_shell)->prompt = NULL;
        }

        if ((*my_shell)->env != NULL) {
            // Assuming env is a NULL-terminated array of strings
            int i = 0;
            while ((*my_shell)->env[i] != NULL) {
                free((*my_shell)->env[i]); // Free each string
                i++;
            }
            free((*my_shell)->env); // Free the array of strings
            (*my_shell)->env = NULL;
        }

        // ... Free other dynamically allocated members if any ...

        // Now free the shell structure itself
        free(*my_shell);
        *my_shell = NULL; // Prevent use-after-free
    }
}