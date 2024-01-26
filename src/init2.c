/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 21:53:39 by sdel-gra          #+#    #+#             */
/*   Updated: 2024/01/26 16:46:31 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_env_array(char **env_array)
{
	int	i;

	if (env_array)
	{
		i = 0;
		while (env_array[i])
		{
			free(env_array[i]);
			i++;
		}
		free(env_array);
	}
}

char	**ft_get_env_array(char **env)
{
	int			count;
	char		**env_array;
	int			i;

	i = 0;
	count = 0;
	while (env[count])
		count++;
	env_array = (char **)malloc(sizeof(char *) * (count + 1));
	if (!env_array)
	{
		exit(EXIT_FAILURE);
	}
	while (i < count)
	{
		env_array[i] = ft_strdup(env[i]);
		if (!env_array[i])
		{
			exit(EXIT_FAILURE);
		}
		i++;
	}
	env_array[count] = NULL;
	return (env_array);
}

int	copy_env_vars(t_shell *shell, char **env)
{
	shell->env_list = ft_get_env_array(env);
	if (!shell->env_list)
	{
		write(STDERR_FILENO, "Failed to allocate for env_list_copied.\n", 48);
		return (MEM_ERROR2);
	}
	return (0);
}

int	create_user(char **user)
{
	*user = ft_strjoin(PURPLE, getenv("USER"));
	if (!*user)
	{
		write(STDERR_FILENO, "Failed to allocate memory for user.\n", 37);
		return (MEM_ERROR);
	}
	return (0);
}
