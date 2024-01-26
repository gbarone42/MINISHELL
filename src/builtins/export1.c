/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:30:19 by gbarone           #+#    #+#             */
/*   Updated: 2024/01/26 18:03:53 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*create_new_env_variable(const char *name, const char *value)
{
	char	*new_variable;

	new_variable = (char *)malloc(strlen(name) + ft_strlen(value) + 2);
	if (!new_variable)
	{
		printf("Memory allocation failed for env variable.\n");
		//exit(EXIT_FAILURE);
		ft_free_and_err(ft_ret_shell(NULL), "create_new_env_variable", errno = ENOMEM);// ma serve proprio?
	}
	ft_strcpy(new_variable, name);
	ft_strcat(new_variable, "=");
	ft_strcat(new_variable, value);
	return (new_variable);
}

int	update_existing_var(t_shell *shell, const char *name, char *new_variable)
{
	int	i;

	i = 0;
	while (shell->env_list[i] != NULL)
	{
		if (ft_strncmp(shell->env_list[i], name, ft_strlen(name))
			== 0 && shell->env_list[i][strlen(name)] == '=')
		{
			free(shell->env_list[i]);
			shell->env_list[i] = new_variable;
			return (1);
		}
		i++;
	}
	return (0);
}

void	add_new_variable(t_shell *shell, char *new_variable, int env_size)
{
	size_t	old_size;
	size_t	new_size;

	old_size = env_size * sizeof(char *);
	new_size = (env_size + 2) * sizeof(char *);
	shell->env_list = (char **)ft_realloc(shell->env_list, old_size, new_size);
	if (!shell->env_list)
	{
		perror("Memory allocation failed for env array.\n");
		exit(EXIT_FAILURE);
	}
	shell->env_list[env_size] = new_variable;
	shell->env_list[env_size + 1] = NULL;
}

void	add_env_variable(t_shell *shell, const char *name, const char *value)
{
	char	*new_variable;
	int		found;
	int		env_size;

	new_variable = create_new_env_variable(name, value);
	printf("New variable: %s\n", new_variable);
	found = update_existing_var(shell, name, new_variable);
	if (!found)
	{
		env_size = 0;
		while (shell->env_list[env_size] != NULL)
			env_size++;
		add_new_variable(shell, new_variable, env_size);
	}
}
