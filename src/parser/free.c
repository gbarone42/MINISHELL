/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 23:21:55 by filippo           #+#    #+#             */
/*   Updated: 2024/01/23 14:37:17 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_free_shell(t_shell *shell)
{
	ft_free_char_p(shell->env);
	free(shell->prompt);
}

void	ft_free_and_err(t_shell *shell, char *caller, int error)
{
	ft_free_shell(shell);
	ft_err(caller, error);
}

void	ft_free_and_exit(t_shell *shell, int status)
{
	ft_free_shell(shell);
	exit(status);
}

void	ft_free_char_p(char **p)
{
	size_t	index;
	char	*value;

	index = 0;
	if (!p)
		return ;
	value = p[index++];
	while (value)
	{
		free(value);
		value = p[index++];
	}
	free(p);
}
