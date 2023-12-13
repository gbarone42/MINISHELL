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

// Function to free array memory (env, paths, export)
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

// Function to clear history
void clear_shell_history()
{
    // Assuming a function like rl_clear_history() exists
    // rl_clear_history(); 

    int i;
    for (i = 0; i < history_count; ++i)
    {
        free(history[i]);
    }
}

// Function to exit the shell
void exit_shell()
{
    exit(g_exit);
}

// Modified shell_exit function
void shell_exit(t_shell *shell)
{
    free_basic_memory(shell);
    free_array_memory(shell);
    clear_shell_history();
    exit_shell();
}


//here i use rl_clear_history(), free(), exit()

// void shell_exit(t_shell *shell)
// {
//     int i;

//     rl_clear_history();
//     if(shell->input)
//     {
//         free(shell->input);
//     }
//     if (shell->prompt) // if it's not NULL
//     {
//         free(shell->prompt);
//     }
//     if (shell->env)
//     {
//         i = 0;
//         while (shell->env[i])
//             free(shell->env[i++]);
//         free(shell->env);
//     }
//     if (shell->paths)
//     {
//         i = 0;
//         while (shell->paths[i])
//             free(shell->paths[i++]);
//         free(shell->paths);
//     }
//     if (shell->export)
//     {
//         i = 0;
//         while (shell->export[i])
//             free(shell->export[i++]);
//         free(shell->export);
//     }
//     // Free history
//     for (i = 0; i < history_count; ++i)
//     {
//         free(history[i]);
//     }
//     exit(g_exit);
// }
