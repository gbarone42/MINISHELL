/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_unset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:30:40 by gbarone           #+#    #+#             */
/*   Updated: 2024/01/25 17:09:03 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	handle_envv(t_shell *shell)
{
	char	**env;

	env = shell->env;
	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
}

void remove_env_variable(t_shell *shell, const char *var_name)
{
    int j;
    int k;
    
    j = 0;
    while (shell->env_list[j] != NULL)
    {
        if (strstr(shell->env_list[j], var_name) == shell->env_list[j])
        {
            printf("Unsetting: %s\n", shell->env_list[j]);
            free(shell->env_list[j]); // Free the memory for the matching environment variable
            // Shift remaining elements left to fill the gap
            k = j;
            while (shell->env_list[k] != NULL)
            {
                shell->env_list[k] = shell->env_list[k + 1];
                k++;
            }
            break; // Break when a match is found
        }
        j++;
    }
}

void handle_unset(t_shell *shell, char **args)
{
    int i;

    if (args[1] == NULL)
    {
        printf("Usage: unset <variable>\n");
        return;
    }
    i = 1;
    while (args[i] != NULL)
    {
        remove_env_variable(shell, args[i]);
        i++;
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
	int i;
	i = 0;
	// Check first character
	if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || str[i] == '_'))
	{
		return (true);
	}
	i = 1;
	// Check the rest of the string
	while (str[i] != '\0')
	{
		if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9') || str[i] == '_'))
		{
			return (true);
		}
		i++;
	}
	return (false);
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
    for (int i = 0; shell->env_list[i] != NULL; ++i)
    {
        if (strncmp(shell->env_list[i], name, strlen(name)) == 0 && shell->env_list[i][strlen(name)] == '=')
        {
            free(shell->env_list[i]);
            shell->env_list[i] = new_variable;
            found = 1;
            break;
        }
    }
    if (!found)
    {
        int env_size;
        env_size = 0;
        while (shell->env_list[env_size] != NULL)
        {
            env_size++;
        }

        shell->env_list = (char **)ft_realloc(shell->env_list, env_size * sizeof(char *), (env_size + 2) * sizeof(char *));
        if (!shell->env_list)
        {
            perror("Memory allocation failed for env array.\n");
            exit(EXIT_FAILURE);
        }

        shell->env_list[env_size] = new_variable;
        shell->env_list[env_size + 1] = NULL;
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