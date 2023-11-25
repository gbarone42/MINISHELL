#include "../../include/minishell.h"

void free_args(char **args) {
    for (int i = 0; args[i]; i++) {
        free(args[i]);
    }
    free(args);
}

void handle_basic_builtins(t_shell *shell)
{   
    printf("Input before comparison: %s\n", shell->input);
    char **args = ft_split(shell->input, ' ');
    printf("First command of Input after comparison: %s\n", args[0]);
    for (int i = 0; args[i]; i++)
    {
        printf("Arg[%d]: %s\n", i, args[i]);
    }
    
    if (!ft_strncmp(shell->input, "exit", 5))
    { 
        free_args(args);
        shell_exit(shell);
    }
    else if (!ft_strncmp(args[0], "cd", 3))
    {
        ft_handle_cd(shell, args);
    }
    else if (!ft_strncmp(shell->input, "echo -n", 8))
    {
        handle_echo_n(shell->input);
    }
    else if (!ft_strncmp(shell->input, "echo", 5))
    {
        handle_echo(shell->input);
    }
    else if (!ft_strncmp(shell->input, "pwd", 4))
    {
        print_current_directory();
    }
    else if (!ft_strncmp(shell->input, "history", 8))
    {
        display_history();
    }
    else if (!ft_strncmp(shell->input, "export", 7))
    {
        handle_export(shell);
    }
    else if (!ft_strncmp(shell->input, "unset", 6))
    {
        handle_unset(shell);
    }
    else if (!ft_strncmp(shell->input, "env", 4))
    {
        handle_env(shell);
    }
    for (int i = 0; args[i]; i++)
    {
        free(args[i]);
    }
    // Free the memory allocated for args
    free(args);
} 

// Function to handle other built-in commands (clear, ls, time, whoami)
void handle_other_builtins(t_shell *shell)
{
    if (!ft_strncmp(shell->input, "clear", 6))
    {
        clear_screen();
    }
    else if (!ft_strncmp(shell->input, "ls", 3))
    {
        print_current_directory_contents();
    }
    else if (!ft_strncmp(shell->input, "time", 5))
    {
        print_current_time();
    }
    else if (!ft_strncmp(shell->input, "whoami", 7))
    {
        whoami_command();
    }
    else if (!ft_strncmp(shell->input, "suspend", 8))
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
