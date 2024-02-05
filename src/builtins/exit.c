/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:22:16 by gbarone           #+#    #+#             */
/*   Updated: 2024/02/05 18:13:07 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_array_memory(t_shell *shell)
{
	int	i;

	i = 0;
	if (shell->env)
	{
		ft_free_env(shell->env);
		shell->env = NULL;
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

void	ft__exit(t_shell *shell)
{
	printf("exit\n");
	ft_free_and_exit(shell, g_exit);
}
