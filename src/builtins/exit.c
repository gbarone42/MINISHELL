#include "../../include/minishell.h"




void shell_exit(t_shell *shell)
{
    int i;

    rl_clear_history();
    if(shell->input)
    {
        free(shell->input);
    }
    if (shell->prompt) // if it's not NULL
    {
        free(shell->prompt);
    }
    if (shell->env)
    {
        i = 0;
        while (shell->env[i])
            free(shell->env[i++]);
        free(shell->env);
    }
    if (shell->paths)
    {
        i = 0;
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
    // Free history
    for (i = 0; i < history_count; ++i)
    {
        free(history[i]);
    }
    exit(g_exit);
}
