/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:41:24 by sdel-gra          #+#    #+#             */
/*   Updated: 2024/01/28 19:14:11 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	heredoc_handler(t_shell *shell, char *delim)
{
	char	*line;
	int		heredoc_fd;

	write(1, ">", 1);
	line = get_next_line(shell->in);
	heredoc_fd = open("./.here_doc", O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if (heredoc_fd < 0)
		perror("heredoc");
	while (line)
	{
		if (!ft_strncmp(line, delim, ft_strlen(delim) + 1))
		{
			free(line);
			free(delim);
			close_fd(heredoc_fd);
			heredoc_fd = open("./.here_doc", O_RDONLY, 0666);
			return (heredoc_fd);
		}
		write(1, ">", 1);
		ft_putstr_fd(line, heredoc_fd);
		free(line);
		line = get_next_line(shell->in);
	}
	return (-1);
}

int	out_handler(t_clist *cmd)
{
	int	tmp;

	tmp = -1;
	if (cmd->redirections->type == OUTPUT)
		tmp = open(cmd->redirections->filename,
				O_CREAT | O_WRONLY | O_TRUNC, 0666);
	else if (cmd->redirections->type == APPEND)
		tmp = open(cmd->redirections->filename,
				O_CREAT | O_WRONLY | O_APPEND, 0666);
	else if (cmd->redirections->type == PRIOROUTPUT)
		tmp = STDOUT_FILENO;
	else if (cmd->redirections->type == DEVNULLOUT)
		tmp = open("/dev/null", O_APPEND, 0666);
	if (tmp < 0)
		perror(cmd->redirections->filename);
	return (tmp);
}

int	in_handler(t_shell *ms, t_clist *cmd)
{
	int	tmp;

	tmp = -1;
	if (cmd->redirections->type == INPUT)
		tmp = open(cmd->redirections->filename, O_RDONLY);
	else if (cmd->redirections->type == HEREDOC)
		tmp = heredoc_handler(ms,
				ft_strjoin(cmd->redirections->filename, "\n"));
	if (tmp < 0)
		perror(cmd->redirections->filename);
	return (tmp);
}

void	ft_redir(t_shell *ms, t_clist *cmd)
{
	t_rlist	*redir;
	int		type;

	redir = cmd->redirections;
	while (redir)
	{
		type = redir->type;
		if (type == OUTPUT
			|| type == APPEND
			|| type == PRIOROUTPUT
			|| type == DEVNULLOUT)
		{
			close_fd(cmd->out);
			cmd->out = out_handler(cmd);
		}
		else if (type == INPUT
			|| type == HEREDOC)
		{
			close_fd(cmd->in);
			cmd->in = in_handler(ms, cmd);
		}
		redir = redir->next;
	}
}
