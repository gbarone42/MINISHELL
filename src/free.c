/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 23:21:55 by filippo           #+#    #+#             */
/*   Updated: 2024/02/05 19:42:37 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_free_history(t_shell *shell)
{
	char	**entries;
	int		i;

	if (!shell)
		return ;
	entries = shell->history->entries;
	i = -1;
	while (entries[++i])
		entries[i] = ft_free(&entries[i]);
	free(shell->history);
}

void	ft_free_shell(t_shell *shell)
{
	ft_free_history(shell);
	shell->prompt = ft_free_char(&shell->prompt);
	shell->input = ft_free_char(&shell->input);
	shell->paths = ft_free_char_p(shell->paths);
	shell->commands = ft_free_clist(shell->commands);
	shell->env = ft_free_char_p(shell->env);
}

void	ft_free_and_err(t_shell *shell, char *caller, int error)
{
	if (shell)
		ft_free_shell(shell);
	ft_err(caller, error);
}

void	ft_free_and_exit(t_shell *shell, int status)
{
	ft_free_shell(shell);
	exit(status);
}

char	**ft_free_char_p(char **p)
{
	size_t	index;
	char	*value;

	index = 0;
	if (!p)
		return (NULL);
	value = p[index++];
	while (value)
	{
		free(value);
		value = NULL;
		value = p[index++];
	}
	free(p);
	return (NULL);
}
