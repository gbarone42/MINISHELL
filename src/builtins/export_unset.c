#include "../../include/minishell.h"

extern char **environ;  // External variable holding the environment

void print_environment()
{
    char **env = environ;
    while (*env) {
        printf("%s\n", *env);
        env++;
    }
}

void handle_unset(t_shell *shell, char **args)
{
    if (args[1] == NULL)
    {
        // Handle error or print a message when no arguments are provided
        printf("Usage: unset <variable>\n");
        return;
    }
    for (int i = 1; args[i] != NULL; ++i)
    {
        for (int j = 0; shell->env[j] != NULL; ++j)
        {
            if (strstr(shell->env[j], args[i]) == shell->env[j])
            {
                printf("Unsetting: %s\n", shell->env[j]);
                free(shell->env[j]);
                while (shell->env[j] != NULL)
                {
                    shell->env[j] = shell->env[j + 1];
                    ++j;
                }
            }
        }
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
            return true;
        }
    }

    return false;
}

void add_env_variable(t_shell *shell, const char *name, const char *value)
{
    // Create the new variable string
    char *new_variable = (char *)malloc(strlen(name) + strlen(value) + 2);
    if (!new_variable)
    {
        printf("Memory allocation failed for env variable.\n");
        exit(EXIT_FAILURE);
    }

    strcpy(new_variable, name);
    strcat(new_variable, "=");
    strcat(new_variable, value);

    printf("New variable: %s\n", new_variable);

    int found = 0;
    for (int i = 0; shell->env[i] != NULL; ++i) {
        if (strncmp(shell->env[i], name, strlen(name)) == 0 && shell->env[i][strlen(name)] == '=') {
            // Variable found, modify it
            free(shell->env[i]);  // Free the old value
            shell->env[i] = new_variable;
            found = 1;
            break;
        }
    }

    // If the variable wasn't found, add it to the end of the environment
    if (!found) {
        int env_size = 0;
        while (shell->env[env_size] != NULL) {
            env_size++;
        }

        shell->env = (char **)realloc(shell->env, (env_size + 2) * sizeof(char *));
        if (!shell->env) {
            fprintf(stderr, "Memory allocation failed for env array.\n");
            exit(EXIT_FAILURE);
        }

        shell->env[env_size] = new_variable;
        shell->env[env_size + 1] = NULL;
    }
}

void handle_export(t_shell *shell, char **args)
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
                add_env_variable(shell, name, value);
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
