/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:33:13 by sdel-gra          #+#    #+#             */
/*   Updated: 2024/01/26 19:49:58 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redirs_fork(t_shell *ms, t_clist *cmd, int i)
{
	if (i == 0 && cmd && cmd->next)
	{
		cmd->in = STDIN_FILENO;
		cmd->out = ms->fd_pipe[1];
		close_fd(ms->fd_pipe[0]);
	}
	else if (i > 0 && cmd && cmd->next)
	{
		cmd->in = ms->tmp_fd;
		cmd->out = ms->fd_pipe[1];
		close_fd(ms->fd_pipe[0]);
	}
	else if (i > 0 && cmd && !cmd->next)
	{
		cmd->in = ms->tmp_fd;
		cmd->out = STDOUT_FILENO;
		close_fd(ms->fd_pipe[1]);
		close_fd(ms->fd_pipe[0]);
	}
	if (cmd -> redirections)
		ft_redir(ms, cmd);
	dup2(cmd->in, STDIN_FILENO);
	dup2(cmd->out, STDOUT_FILENO);
}
