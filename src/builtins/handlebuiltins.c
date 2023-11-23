#include "../../include/minishell.h"

void handle_basic_builtins(t_shell *shell)
{
    if (!ft_strncmp(shell->input, "exit", 4))
    {
        shell_exit(shell);
    }
    else if (!ft_strncmp(shell->input, "cd", 2))
    {
        char **args = ft_split(shell->input, ' ');

        if (args && args[1])
        {
            // cd has arguments, attempt to change directory
            change_directory(shell, args[1]);
            free(args);
        }
        else
        {
            // cd without arguments, go to the home directory
            change_directory(shell, NULL);
        }
    }
    else if (!ft_strncmp(shell->input, "echo -n", 7))
    {
        handle_echo_n(shell->input);
    }
    else if (!ft_strncmp(shell->input, "echo", 4))
    {
        handle_echo(shell->input);
    }
    else if (!ft_strncmp(shell->input, "pwd", 3))
    {
        print_current_directory();
    }
    else if (!ft_strncmp(shell->input, "history", 7))
    {
        display_history();
    }
    else if (!ft_strncmp(shell->input, "export", 6))
    {
        handle_export(shell);
    }
    else if (!ft_strncmp(shell->input, "unset", 5))
    {
        handle_unset(shell);
    }
    else if (!ft_strncmp(shell->input, "env", 3))
    {
        handle_env(shell);
    }

}

// Function to handle other built-in commands (clear, ls, time, whoami)
void handle_other_builtins(t_shell *shell)
{
    if (!ft_strncmp(shell->input, "clear", 5))
    {
        clear_screen();
    }
    else if (!ft_strncmp(shell->input, "ls", 2))
    {
        print_current_directory_contents();
    }
    else if (!ft_strncmp(shell->input, "time", 4))
    {
        print_current_time();
    }
    else if (!ft_strncmp(shell->input, "whoami", 6))
    {
        whoami_command();
    }
    else if (!ft_strncmp(shell->input, "suspend", 7))
    {
        handle_suspend();
    }
    // else if (!ft_strncmp(shell->input, "find", 4))
    // {
    //     char **args = ft_split(shell->input, ' ');

    //     if (args && args[1])
    //     {
    //         find_files(".", args[1]);  // Assuming you want to search in the current directory
    //         free(args);
    //     }
    //     else
    //     {
    //         printf("Usage: find FILENAME\n");
    //     }
    // }
}

void builtins_call(t_shell *shell)
{
    // if (!ft_strncmp(shell->input, "exit", 5)
    //     || !ft_strncmp(shell->input, "cd", 3)
    //     || !ft_strncmp(shell->input, "echo -n", 7)
    //     || !ft_strncmp(shell->input, "echo", 4)
    //     || !ft_strncmp(shell->input, "pwd", 3)
    //     || !ft_strncmp(shell->input, "history", 7)
    //     || !ft_strncmp(shell->input, "export", 6)
    //     || !ft_strncmp(shell->input, "unset", 5)
    //     || !ft_strncmp(shell->input, "env", 3)
    //     || !ft_strncmp(shell->input, "clear", 5)
    //     || !ft_strncmp(shell->input, "ls", 2)
    //     || !ft_strncmp(shell->input, "time", 4)
    //     || !ft_strncmp(shell->input, "whoami", 6)
    //     || !ft_strncmp(shell->input, "suspend", 7))
    //{
        // The input matches a built-in command
        handle_basic_builtins(shell);
        handle_other_builtins(shell);
    //}
    // else
    // {
    //     // The input doesn't match any built-in commands, try to execute it
    //     t_pars *command;
    //     shell_parser(shell, &command);
    //     // Add additional conditions or error handling as needed
    //     if (shell->exit == 0)
    //         shell_executor(&command, shell);
    // }
}
