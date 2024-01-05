#include "../../include/minishell.h"

void handle_envv(t_shell *shell)
{
    char **env = shell->env;
    while (*env)
    {
        printf("%s\n", *env);
        env++;
    }
}

void handle_unset(t_shell *shell, char **args)
{
    if (args[1] == NULL)
    {
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
                for (int k = j; shell->env[k] != NULL; ++k)
                {
                    shell->env[k] = shell->env[k + 1];
                }

                break;
            }
        }
    }
}
char *ft_strtok(char *str, char sep)
{
    static char *last = NULL;

    if (str != NULL)
    {
        last = str;
    } else if (last == NULL || *last == '\0')
    {
        return NULL;
    }
    char *token_start = last;
    while (*last != '\0' && *last != sep)
    {
        last++;
    }
    if (*last != '\0')
    {
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

    for (int i = 1; str[i] != '\0'; ++i)
    {
        if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9') || str[i] == '_'))
        {
            return true;
        }
    }

    return false;
}

void *ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
    void *new_ptr;

    if (ptr == NULL)
        return malloc(new_size);
    if (!new_size)
    {
        free(ptr);
        return NULL;
    }
    new_ptr = malloc(new_size);
    if (!new_ptr)
    {
        perror("Memory allocation failed for realloc.\n");
        exit(EXIT_FAILURE);
    }
    size_t copy_size = (old_size < new_size) ? old_size : new_size;
    ft_memcpy(new_ptr, ptr, copy_size);
    free(ptr);
    return new_ptr;
}

void add_env_variable(t_shell *shell, const char *name, const char *value)
{
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
    for (int i = 0; shell->env[i] != NULL; ++i)
    {
        if (strncmp(shell->env[i], name, strlen(name)) == 0 && shell->env[i][strlen(name)] == '=')
        {
            free(shell->env[i]);
            shell->env[i] = new_variable;
            found = 1;
            break;
        }
    }
    if (!found)
    {
        int env_size = 0;
        while (shell->env[env_size] != NULL)
        {
            env_size++;
        }

        shell->env = (char **)ft_realloc(shell->env, env_size * sizeof(char *), (env_size + 2) * sizeof(char *));
        if (!shell->env)
        {
            perror("Memory allocation failed for env array.\n");
            exit(EXIT_FAILURE);
        }

        shell->env[env_size] = new_variable;
        shell->env[env_size + 1] = NULL;
    }
}

void handle_export(t_shell *shell, char **args)
{
    if (args[1] == NULL)
    {
        handle_envv(shell);
    }
    else
    {
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
            }
        }
        else
        {
            printf("Invalid export syntax: %s\n", args[1]);
        }
    }
}
