#include "../../include/minishell.h"


void handle_unset(t_shell *shell)
{
    // Check if there are arguments after 'unset'
    if (shell->input && shell->input[0] != '\0') {
        // Unset the environment variable
        unsetenv(shell->input);
    } else {
        // If no arguments provided, print an error message
        printf("Usage: unset VARIABLE_NAME\n");
    }
}



void handle_export(t_shell *shell)
{
    // Check if there are arguments after 'export'
    if (shell->input && shell->input[0] != '\0')
    {
        // Split the input into variable and value
        char **args = ft_split(shell->input, '=');

        // Check if the split was successful and contains at least one element
        if (args && args[0])
        {
            // Set the environment variable
            if (args[1])
                setenv(args[0], args[1], 1);
            else
                setenv(args[0], "", 1);
        }

        // Free the allocated memory
        free(args);
    }
    else
    {
        // If no arguments provided, print the list of environment variables
        char **env = shell->env;
        while (*env) {
            printf("%s\n", *env);
            env++;
        }
    }
}