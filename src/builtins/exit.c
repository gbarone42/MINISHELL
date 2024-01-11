/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:22:16 by gbarone           #+#    #+#             */
/*   Updated: 2024/01/11 18:23:40 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_basic_memory(t_shell *shell)
{
	if (shell->input)
	{
		free(shell->input);
	}
	if (shell->prompt)
	{
		free(shell->prompt);
	}
}

void	free_array_memory(t_shell *shell)
{
	int	i;

	i = 0;
	if (shell->env_list)
	{
		free_env_list(shell->env_list);
		shell->env_list = NULL;
	}
	if (shell->paths)
	{
		while (shell->paths[i])
			free(shell->paths[i++]);
		free(shell->paths);
		shell->paths = NULL;
	}
	if (shell->export)
	{
		i = 0;
		while (shell->export[i])
			free(shell->export[i++]);
		free(shell->export);
		shell->export = NULL;
	}
}

void	clear_shell_history(t_history *history)
{
	int	i;

	i = 0;
	if (history != NULL)
	{
		while (i < history->count)
		{
			free(history->entries[i]);
			i++;
		}
		history->count = 0;
	}
}

void	exit_shell(void)
{
	exit(g_exit);
}

void	shell_exit(t_shell *shell)
{
	clear_shell_history(&shell->history);
	free_basic_memory(shell);
	free_array_memory(shell);
	exit_shell();
}
