/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:01:19 by gbarone           #+#    #+#             */
/*   Updated: 2024/02/07 15:25:04 by filippo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_handle_builtins(t_shell *shell, t_clist *commands)
{
	char	**args;
	char	*command;

	args = commands->args;
	command = args[0];
	if (!ft_strcmp(command, "exit"))
		ft__exit(shell, args);
	else if (!ft_strcmp(command, "cd"))
		ft__cd(args);
	else if (!ft_strcmp(command, "echo"))
		ft__echo(args);
	else if (!ft_strcmp(command, "pwd"))
		ft__pwd();
	else if (!ft_strcmp(command, "export"))
		ft__export(shell, args);
	else if (!ft_strcmp(command, "unset"))
		handle_unset(shell, args);
	else if (!ft_strcmp(command, "env"))
		ft__env(shell, "", 0);
	else if (!ft_strcmp(command, "readbuiltin"))
		g_exit = 0;
}
