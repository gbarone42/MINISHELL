/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   export_unset.c									 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: sdel-gra <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/01/10 16:30:40 by gbarone		   #+#	#+#			 */
/*   Updated: 2024/01/25 21:54:56 by sdel-gra		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "minishell.h"

char *create_envv_variable(const char *name, const char *value)
{
    size_t size = ft_strlen(name) + 1;
    if (value && *value)
    {
        size += ft_strlen(value) + 1;
    }

    char *variable = (char *)malloc(size);
    if (!variable)
    {
        perror("Memory allocation failed for env variable.\n");
        exit(EXIT_FAILURE);
    }
    ft_strcpy(variable, name);
    if (value && *value)
    {
        ft_strcat(variable, "=");
        ft_strcat(variable, value);
    }
    return (variable);
}


int find_envv_variable(t_shell *shell, const char *name, const char *value)
{
    int i = 0;
    while (shell->env_list[i] != NULL)
    {
        if (ft_strncmp(shell->env_list[i], name, ft_strlen(name)) == 0 &&
            (shell->env_list[i][ft_strlen(name)] == '=' || shell->env_list[i][ft_strlen(name)] == '\0'))
        {
            free(shell->env_list[i]);
            shell->env_list[i] = create_envv_variable(name, value);
            return (1);
        }
        i++;
    }
    return (0);
}


void add_new_envv_variable(t_shell *shell, const char *name, const char *value)
{
    int env_size = 0;
    while (shell->env_list[env_size] != NULL)
    {
        env_size++;
    }

    char *new_variable = create_envv_variable(name, value);

    char **new_env_list = (char **)ft_realloc(shell->env_list, env_size * sizeof(char *), (env_size + 2) * sizeof(char *));
    if (!new_env_list)
    {
        perror("Memory allocation failed for env array.\n");
        exit(EXIT_FAILURE);
    }

    new_env_list[env_size] = new_variable;
    new_env_list[env_size + 1] = NULL;

    shell->env_list = new_env_list;
}


void add_envv_variable(t_shell *shell, const char *name, const char *value)
{
    if (!find_envv_variable(shell, name, value))
    {
        add_new_envv_variable(shell, name, value);
    }
}

char *create_new_env_variable(const char *name, const char *value)
{
    char *new_variable = (char *)malloc(strlen(name) + strlen(value) + 2);
    if (!new_variable)
    {
        printf("Memory allocation failed for env variable.\n");
        exit(EXIT_FAILURE);
    }

    ft_strcpy(new_variable, name);
    ft_strcat(new_variable, "=");
    ft_strcat(new_variable, value);

    return new_variable;
}

int update_existing_variable(t_shell *shell, const char *name, char *new_variable)
{
    int i = 0;
    while (shell->env_list[i] != NULL)
    {
        if (ft_strncmp(shell->env_list[i], name, strlen(name)) == 0 && shell->env_list[i][strlen(name)] == '=')
        {
            free(shell->env_list[i]);
            shell->env_list[i] = new_variable;
            return (1);
        }
        i++;
    }
    return (0);
}

void add_new_variable(t_shell *shell, char *new_variable, int env_size)
{
    shell->env_list = (char **)realloc(shell->env_list, (env_size + 2) * sizeof(char *));
    if (!shell->env_list)
    {
        perror("Memory allocation failed for env array.\n");
        exit(EXIT_FAILURE);
    }

    shell->env_list[env_size] = new_variable;
    shell->env_list[env_size + 1] = NULL;
}

void add_env_variable(t_shell *shell, const char *name, const char *value)
{
    char *new_variable = create_new_env_variable(name, value);
    printf("New variable: %s\n", new_variable);

    int found = update_existing_variable(shell, name, new_variable);

    if (!found)
    {
        int env_size = 0;
        while (shell->env_list[env_size] != NULL) env_size++;
        add_new_variable(shell, new_variable, env_size);
    }
}

void process_env_variable(t_shell *shell, char *arg)
{
    char *name;
    char *value;

	name  = ft_strtok(arg, '=');
	value = ft_strtok(NULL, '=');
    if (name != NULL)
    {
        if (contains_invalid_characters(name))
            printf("Invalid variable name: %s\n", name);
        else
        {
            if (value == NULL)
            {
                add_envv_variable(shell, name, "");
            }
            else
            {
                add_env_variable(shell, name, value);
            }
        }
    }
    else
        printf("Invalid export syntax: %s\n", arg);
}

void handle_export(t_shell *shell, char **args)
{
    if (args[1] == NULL)
    {
        handle_envv(shell);
    }
    else
    {
        process_env_variable(shell, args[1]);
    }
}
