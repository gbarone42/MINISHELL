/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlebuiltins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:01:19 by gbarone           #+#    #+#             */
/*   Updated: 2024/01/26 18:33:05 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_args(char **args)
{
	int		i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

void	handle_basic_builtin1(t_shell *shell, char **args)
{
	if (!ft_strncmp(args[0], "exit", 5))
	{
		//free_args(args);
		shell_exit(shell);
	}
	else if (args && args[0] && !ft_strcmp(args[0], "cd"))
	{
		ft_handle_cd(shell, args);
	}
	if (args && args[0] && ft_strcmp(args[0], "echo") == 0)
	{
		handle_echo(args);
	}
}

void	handle_basic_builtin2(t_shell *shell, char **args)
{
	if (!ft_strncmp(args[0], "pwd", 4))
	{
		print_current_directory();
	}
	else if (args && args[0] && !ft_strcmp(args[0], "export"))
	{
		handle_export(shell, args);
	}
	else if (args && args[0] && !ft_strcmp(args[0], "unset"))
	{
		handle_unset(shell, args);
	}
	else if (!ft_strncmp(args[0], "env", 4))
	{
		handle_env(shell);
	}
}

void	handle_basic_builtins(t_shell *shell, t_clist *commands)
{
	handle_basic_builtin1(shell, commands->args);
	handle_basic_builtin2(shell, commands->args);
}

void	builtins_call(t_shell *shell, t_clist *commands, int i)
{
	if (i == 0 && commands && commands->next)
	{
		commands->in = STDIN_FILENO;
		commands->out = shell->fd_pipe[1];
		close_fd(shell->fd_pipe[0]);
	}
	else if (i > 0 && commands && commands->next)
	{
		commands->in = shell->tmp_fd;
		commands->out = shell->fd_pipe[1];
		close_fd(shell->fd_pipe[0]);
	}
	else if (i > 0 && commands && !commands->next)
	{
		commands->in = shell->tmp_fd;
		commands->out = STDOUT_FILENO;
		close_fd(shell->fd_pipe[1]);
		close_fd(shell->fd_pipe[0]);
	}
	if (commands -> redirections)
		ft_redir(shell, commands);
	if (commands->in > -1)
		dup2(commands->in, STDIN_FILENO);
	else
		dup2(STDIN_FILENO, STDIN_FILENO);
	dup2(commands->out, STDOUT_FILENO);
	handle_basic_builtins(shell, commands);
	close_fd(commands->out);
	close_fd(commands->in);
	dup2(shell->in, STDIN_FILENO);
	dup2(shell->out, STDOUT_FILENO);
}
