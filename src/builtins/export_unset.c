#include "../../include/minishell.h"


extern char **environ;  // External variable holding the environment

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
char *ft_strtok(char *str, char sep)
{
    static char *last = NULL;

    if (str != NULL) {
        last = str;
    } else if (last == NULL || *last == '\0') {
        return NULL;
    }

    char *token_start = last;

    while (*last != '\0' && *last != sep) {
        last++;
    }

    if (*last != '\0') {
        *last = '\0';
        last++;
    }

    return token_start;
}

void print_environment()\
{
    char **env = environ;
    while (*env) {
        printf("%s\n", *env);
        env++;
    }
}


bool contains_invalid_characters(const char *str)
{
    if (!((str[0] >= 'a' && str[0] <= 'z') || (str[0] >= 'A' && str[0] <= 'Z') || str[0] == '_'))
    {
        return true;
    }

    // Check the rest of the characters
    for (int i = 1; str[i] != '\0'; ++i)
    {
        // Check if the character is a letter, number, or underscore
        if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9') || str[i] == '_'))
        {
            return true; // Invalid character found
        }
    }

    return false; // No invalid characters found
}

void add_env_variable(const char *name, const char *value)
{
    // Check if the variable name is valid
    // if (contains_invalid_characters(name)) {
    //     fprintf(stderr, "Invalid variable name: %s\n", name);
    //     return;
    // }
    // Create the new variable string
    char *new_variable = (char *)malloc(strlen(name) + strlen(value) + 2);
    if (!new_variable)
    {
        printf("Memory allocation failed for env variable.\n");
        exit(EXIT_FAILURE);
    }
}

void handle_export(char **args)
{
    if (args[1] == NULL) {
        // Print the environment if no arguments provided
        print_environment();
    }
    else
    {
        // Parse and set or modify environment variables
    char *name  = ft_strtok(args[1], '=');
    char *value = ft_strtok(NULL, '=');
        if (name != NULL && value != NULL)
        {
            if (contains_invalid_characters(name))
            {
                printf("Invalid variable name: %s\n", name);
            }
            else
            {
                printf("Name: %s\n", name);
                printf("Value: %s\n", value);
                add_env_variable(name, value);
                //set_or_modify_env_variable(name, value);
            }
        }
        else
        {
            // Handle error or print a message
            printf("Invalid export syntax: %s\n", args[1]);
        }
    }
}









// // Function to set or modify an environment variable
// void set_or_modify_env_variable(const char *name, const char *value) {
//     // Find the variable in the environment
//     char **current = environ;
//     while (*current) {
//         if (strncmp(*current, name, strlen(name)) == 0 && (*current)[strlen(name)] == '=') {
//             // Variable found, modify it
//             char *modified_var = (char *)malloc(strlen(name) + strlen(value) + 2);
//             sprintf(modified_var, "%s=%s", name, value);
//             free(*current); // Free the existing string
//             *current = modified_var;
//             return;
//         }
//         current++;
//     }

//     // If the variable wasn't found, create a new one
//     int env_size = 0;
//     while (environ[env_size]) {
//         env_size++;
//     }

//     environ = (char **)realloc(environ, (env_size + 2) * sizeof(char *));
//     environ[env_size] = (char *)malloc(strlen(name) + strlen(value) + 2);
//     sprintf(environ[env_size], "%s=%s", name, value);
//     environ[env_size + 1] = NULL;
// }

// // Function to print the current environment variables
// void print_environment() {
//     char **env = environ;
//     while (*env) {
//         printf("%s\n", *env);
//         env++;
//     }
// }

// // Minishell handle_export function
// void handle_export(char **args)
// {
//     if (args[1] == NULL) {
//         // Print the environment if no arguments provided
//         print_environment();
//     } else {
//         // Parse and set or modify environment variables
//         char *name = strtok(args[1], "=");
//         char *value = strtok(NULL, "=");

//         if (name != NULL && value != NULL) {
//             set_or_modify_env_variable(name, value);
//         } else {
//             // Handle error or print a message
//             printf("Invalid export syntax: %s\n", args[1]);
//         }
//     }
// }










// // extern char **environ;

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

//         // Free the allocated memory for each string in variable_and_value
//         for (int i = 0; variable_and_value[i]; ++i)
//         {
//             free(variable_and_value[i]);
//         }

//         // Free the array itself
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