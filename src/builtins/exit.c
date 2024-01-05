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
    int i;

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
}

void clear_shell_history(t_history *history)
{
    if (history != NULL) {
        for (int i = 0; i < history->count; ++i) {
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
    free_basic_memory(shell);
    free_array_memory(shell);
    clear_shell_history(&shell->history);
    exit_shell();
}
