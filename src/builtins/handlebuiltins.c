#include "../../include/minishell.h"

void free_args(char **args)
{
    for (int i = 0; args[i]; i++)
    {
        free(args[i]);
    }
    free(args);
}


void handle_basic_builtin1(t_shell *shell, char **args)
{
    if (!ft_strncmp(shell->input, "exit", 5))
    { 
        free_args(args);
        shell_exit(shell);
    } 
    else if (!ft_strncmp(shell->input, "cd", 3))
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
}


void handle_basic_builtin2(t_shell *shell, char **args)
{
    if (!ft_strncmp(shell->input, "pwd", 4))
    {
        print_current_directory();
    }
    else if (!ft_strncmp(shell->input, "history", 8))
    {
        display_history();
    }
    else if (args && args[0] && !ft_strcmp(args[0], "export")) 
    { 
        //handle_export(shell, args);
        handle_export(shell, args);
    }
    //else if (!ft_strncmp(shell->input, "unset", 6))
    else if (args && args[0] && !ft_strcmp(args[0], "unset"))

    {
        handle_unset(shell, args);
    }
    else if (!ft_strncmp(shell->input, "env", 4))
    {
        handle_env(shell);
    }
    free_args(args);
}

void handle_basic_builtins(t_shell *shell)
{
    printf("Input before comparison: %s\n", shell->input);
    char **args = ft_split(shell->input, ' ');
    printf("First command of Input after comparison: %s\n", args[0]);
    for (int i = 0; args[i]; i++) {
        printf("Arg[%d]: %s\n", i, args[i]);
    }

    handle_basic_builtin1(shell, args);
    handle_basic_builtin2(shell, args);
}

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

}

void builtins_call(t_shell *shell)
{

        handle_basic_builtins(shell);
        handle_other_builtins(shell);

}

// Function to handle other built-in commands (clear, ls, time, whoami)