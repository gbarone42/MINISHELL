/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:56:34 by filippo           #+#    #+#             */
/*   Updated: 2024/01/25 22:24:11 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_get_value_of(t_shell *shell, char *key, size_t len)
{
	char	**env;
	size_t	index;
	char	*value;

	env = shell->env;
	index = 0;
	value = env[index++];
	while (value)
	{
		if (!ft_strncmp(value, key, len))
			return (ft_strdup(value + len + 1));
		value = env[index++];
	}
	return (ft_strdup(""));
}
