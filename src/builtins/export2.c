/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:30:19 by gbarone           #+#    #+#             */
/*   Updated: 2024/02/05 20:41:51 by filippo          ###   ########.fr       */
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
	variable = ft_calloc(1, size);
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
	while (shell->env[i] != NULL)
	{
		if (ft_strncmp(shell->env[i], name, ft_strlen(name)) == 0
			&& (shell->env[i][ft_strlen(name)] == '='
			|| shell->env[i][ft_strlen(name)] == '\0'))
		{
			free(shell->env[i]);
			shell->env[i] = create_envv_variable(name, value);
			return (1);
		}
		i++;
	}
	return (0);
}

void	add_new_envv_var(t_shell *shell, const char *name, const char *value)
{
	int		env_size;
	char	*new_variable;
	char	**new_env;

	env_size = 0;
	while (shell->env[env_size] != NULL)
	{
		env_size++;
	}
	new_variable = create_envv_variable(name, value);
	new_env = (char **)ft_realloc(shell->env,
			env_size * sizeof(char *), (env_size + 2) * sizeof(char *));
	if (!new_env)
	{
		perror("Memory allocation failed for env array.\n");
		exit(EXIT_FAILURE);
	}
	new_env[env_size] = new_variable;
	new_env[env_size + 1] = NULL;
	shell->env = new_env;
}

void	add_envv_variable(t_shell *shell, const char *name, const char *value)
{
	if (!find_envv_variable(shell, name, value))
	{
		add_new_envv_var(shell, name, value);
	}
}
