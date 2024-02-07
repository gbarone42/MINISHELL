/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:30:32 by gbarone           #+#    #+#             */
/*   Updated: 2024/02/07 15:18:40 by filippo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft__env(t_shell *shell, char *input, int dquotes)
{
	char	**env;
	char	*var;
	char	*key;
	char	*value;

	env = shell->env;
	var = *env++;
	while (var)
	{
		if (dquotes)
		{
			var = ft_strdup(var);
			key = ft_strnstr(var, "=", -1);
			*key = '\0';
			key = var;
			value = key + 1;
			printf("%s%s=\"%s\"\n", input, key, value);
			free(var);
		}
		else
			printf("%s\n", var);
		var = *env++;
	}
	g_exit = 0;
}
