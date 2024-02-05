/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:01:19 by gbarone           #+#    #+#             */
/*   Updated: 2024/02/05 19:44:45 by fcorri           ###   ########.fr       */
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
		ft__exit(shell);
	else if (!ft_strcmp(command, "cd"))
		ft__cd(shell, args);
	else if (!ft_strcmp(command, "echo"))
		handle_echo(args);
	else if (!ft_strcmp(command, "pwd"))
		print_current_directory();
	else if (!ft_strcmp(command, "export"))
		handle_export(shell, args);
	else if (!ft_strcmp(command, "unset"))
		handle_unset(shell, args);
	else if (!ft_strcmp(command, "env"))
		handle_env(shell);
	else if (!ft_strcmp(command, "readbuiltin"))
		shell->exit_status = 0;
}
