#include "../../include/minishell.h"



// extern char **environ;

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

// void set_or_modify_env_variable(const char *name, const char *value) {
//     // Find the variable in the environment
//     char **current = environ;
//     char **new_environment = NULL;
//     int new_size = 0;

//     while (*current) {
//         if (ft_strncmp(*current, name, ft_strlen(name)) == 0 && (*current)[ft_strlen(name)] == '=') {
//             // Variable found, modify it
//             printf("%s=%s\n", name, value);  // Directly print the formatted string
//         } else {
//             // Copy existing variables to the new environment
//             new_environment = (char **)realloc(new_environment, (new_size + 2) * sizeof(char *));
//             new_environment[new_size] = strdup(*current);
//             new_size++;
//         }

//         current++;
//     }

//     // If the variable wasn't found, create a new one
//     if (new_environment) {
//         new_environment[new_size] = (char *)malloc(ft_strlen(name) + ft_strlen(value) + 2);
//         printf("%s=%s\n", name, value);  // Directly print the formatted string
//         new_size++;
//     }

//     // Null-terminate the new environment
//     new_environment[new_size] = NULL;

//     // Replace the original environment with the new one
//     environ = new_environment;
// }


// void handle_export(char **args)
// {
//     // Check if there are arguments after 'export'
//     if (args && args[1]) {
//         // Assuming args[1] is in the form VARIABLE_NAME=value
//         char *variable_assignment = args[1];

//         // Split the variable_assignment into variable and value
//         char **variable_and_value = ft_split(variable_assignment, '=');

//         // Check if the split was successful and contains at least one element
//         if (variable_and_value && variable_and_value[0]) {
//             // Set or modify the environment variable
//             set_or_modify_env_variable(variable_and_value[0], variable_and_value[1]);
//         }

//         // Free the allocated memory for each string in variable_and_value
//         for (int i = 0; variable_and_value[i]; ++i) {
//             free(variable_and_value[i]);
//         }

//         // Free the array itself
//         free(variable_and_value);
//     } else {
//         // If no arguments provided, print the list of environment variables
//         char **env = environ;
//         while (*env) {
//             printf("%s\n", *env);
//             env++;
//         }
//     }
// }



// void handle_unset(t_shell *shell)
// {
//     // Check if there are arguments after 'unset'
//     if (shell->input && shell->input[0] != '\0') {
//         // Unset the environment variable
//         unsetenv(shell->input);
//     } else {
//         // If no arguments provided, print an error message
//         printf("Usage: unset VARIABLE_NAME\n");
//     }
// }




void handle_export(t_shell *shell, char **args)
{
    // Check if there are arguments after 'export'
    if (args && args[1])
    {
        // Assuming args[1] is in the form VARIABLE_NAME=value
        char *variable_assignment = args[1];

        // Split the variable_assignment into variable and value
        char **variable_and_value = ft_split(variable_assignment, '=');

        // Check if the split was successful and contains at least one element
        if (variable_and_value && variable_and_value[0])
        {
            // Set the environment variable
            if (variable_and_value[1])
                setenv(variable_and_value[0], variable_and_value[1], 1);
            else
                setenv(variable_and_value[0], "", 1);
        }

        // Free the allocated memory for each string in variable_and_value
        for (int i = 0; variable_and_value[i]; ++i)
        {
            free(variable_and_value[i]);
        }

        // Free the array itself
        free(variable_and_value);
    }
    else
    {
        // If no arguments provided, print the list of environment variables
        char **env = shell->env;
        while (*env)
        {
            printf("%s\n", *env);
            env++;
        }
    }
}

// void handle_export(t_shell *shell, char **args)
// {
//     // Check if there are arguments after 'export'
//     if (args && args[1])
//     {
//         // Assuming args[1] is in the form VARIABLE_NAME=value
//         char *variable_assignment = args[1];

//         // Split the variable_assignment into variable and value
//         char **variable_and_value = ft_split(variable_assignment, '=');

//         // Check if the split was successful and contains at least one element
//         if (variable_and_value && variable_and_value[0])
//         {
//             // Set the environment variable
//             if (variable_and_value[1])
//                 setenv(variable_and_value[0], variable_and_value[1], 1);
//             else
//                 setenv(variable_and_value[0], "", 1);
//         }

//         // Free the allocated memory
//         free(variable_and_value);
//     }
//     else
//     {
//         // If no arguments provided, print the list of environment variables
//         char **env = shell->env;
//         while (*env)
//         {
//             printf("%s\n", *env);
//             env++;
//         }
//     }
// }