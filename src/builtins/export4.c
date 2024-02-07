/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:30:19 by gbarone           #+#    #+#             */
/*   Updated: 2024/02/07 16:15:21 by filippo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*extract_var_name(char *input)
{
	char	**var_split;
	char	*var;

	var_split = ft_split(input, '=');
	var = ft_strdup(var_split[0]);
	free_arr(&var_split);
	return (var);
}

int	compare_env_vars(char *var, char **env)
{
	int		i;
	char	**var_split;

	i = 0;
	while (env[i])
	{
		// errato
		var_split = ft_split(env[i], '=');
		if (ft_strlen(var_split[0]) == ft_strlen(var)
			&& ft_strncmp(var, var_split[0], ft_strlen(var)) == 0)
		{
			free_arr(&var_split);
			return (1);
		}
		free_arr(&var_split);
		i++;
	}
	return (0);
}

int	handle_assignment_present(char *input, t_shell *shell)
{
	char	*var;

	var = extract_var_name(input);
	if (compare_env_vars(var, shell->env))
	{
		remove_env_variable(shell, var);
		free(var);
		return (0);
	}
	free(var);
	return (-1);
}
