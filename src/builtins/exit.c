#include "../../include/minishell.h"

void free_basic_memory(t_shell *shell)
{
	if (shell->input)
	{
		free(shell->input);
	}
	if (shell->prompt)
	{
		free(shell->prompt);
	}
}

void free_array_memory(t_shell *shell)
{
    // Free the environment variables linked list
    if (shell->env_list)
    {
        free_env_list(shell->env_list);
        shell->env_list = NULL; // Set to NULL after freeing
    }

    // Free paths array
    if (shell->paths)
    {
        int i = 0;
        while (shell->paths[i])
            free(shell->paths[i++]);
        free(shell->paths);
        shell->paths = NULL; // Set to NULL after freeing
    }

    // Free export array
    if (shell->export)
    {
        int i = 0;
        while (shell->export[i])
            free(shell->export[i++]);
        free(shell->export);
        shell->export = NULL; // Set to NULL after freeing
    }
}


void clear_shell_history(t_history *history)
{
	if (history != NULL)
	{
		for (int i = 0; i <= history->count; ++i)
		{
			//printf("freeing history->entries[%d]\n", i);
			//printf("history->entries[%d] = %s\n", i, history->entries[i]);
			free(history->entries[i]);
		
		}
		history->count = 0;
	}
}

void exit_shell()
{
	exit(g_exit);
}

void shell_exit(t_shell *shell)
{	
	clear_shell_history(&shell->history);
	free_basic_memory(shell);
	free_array_memory(shell);
	exit_shell();
}
