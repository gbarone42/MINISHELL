/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:30:19 by gbarone           #+#    #+#             */
/*   Updated: 2024/01/26 16:17:56 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*create_envv_variable(const char *name, const char *value)
{
	size_t	size;
	char	*variable;

	size = ft_strlen(name) + 1;
	if (value && *value)
	{
		size += ft_strlen(value) + 1;
	}
	variable = (char *)malloc(size);
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

int	find_envv_variable(t_shell *shell, const char *name, const char *value)
{
	int	i;

	i = 0;
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

void	add_new_envv_variable(t_shell *shell, const char *name, const char *value)
{
	int		env_size;
	char	*new_variable;
	char	**new_env_list;

	env_size = 0;
	while (shell->env_list[env_size] != NULL)
	{
		env_size++;
	}
	new_variable = create_envv_variable(name, value);
	new_env_list = (char **)ft_realloc(shell->env_list, env_size * sizeof(char *), (env_size + 2) * sizeof(char *));
	if (!new_env_list)
	{
		perror("Memory allocation failed for env array.\n");
		exit(EXIT_FAILURE);
	}
	new_env_list[env_size] = new_variable;
	new_env_list[env_size + 1] = NULL;
	shell->env_list = new_env_list;
}

void	add_envv_variable(t_shell *shell, const char *name, const char *value)
{
	if (!find_envv_variable(shell, name, value))
	{
		add_new_envv_variable(shell, name, value);
	}
}
