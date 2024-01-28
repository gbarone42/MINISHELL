/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:41:24 by sdel-gra          #+#    #+#             */
/*   Updated: 2024/01/28 19:30:15 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	heredoc_handler(t_shell *shell, char *delim)
{
	char	*line;
	int		heredoc_fd;

	write(1, ">", 1);
	line = gnl(shell->in);
	heredoc_fd = open("./.here_doc", O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if (heredoc_fd < 0)
		perror("heredoc");
	while (line)
	{
		if (!ft_strncmp(line, delim, ft_strlen(delim) + 1))
		{
			free(line);
			line = NULL;
			close_fd(heredoc_fd);
			heredoc_fd = open("./.here_doc", O_RDONLY, 0666);
			return (heredoc_fd);
		}
		write(1, ">", 1);
		ft_putstr_fd(line, heredoc_fd);
		free(line);
		line = gnl(shell->in);
	}
	return (-1);
}

int	out_handler(t_rlist *redirections)
{
	int	tmp;

	tmp = -1;
	if (redirections->type == OUTPUT)
		tmp = open(redirections->filename,
				O_CREAT | O_WRONLY | O_TRUNC, 0666);
	else if (redirections->type == APPEND)
		tmp = open(redirections->filename,
				O_CREAT | O_WRONLY | O_APPEND, 0666);
	else if (redirections->type == PRIOROUTPUT)
		tmp = STDOUT_FILENO;
	else if (redirections->type == DEVNULLOUT)
		tmp = open("/dev/null", O_APPEND, 0666);
	if (tmp < 0)
		perror(redirections->filename);
	return (tmp);
}

int	in_handler(t_shell *ms, t_rlist *redirections)
{
	char	*tmp_char;
	int		tmp;

	tmp = -1;
	if (redirections->type == INPUT)
		tmp = open(redirections->filename, O_RDONLY);
	else if (redirections->type == HEREDOC)
	{
		tmp_char = ft_strjoin(redirections->filename, "\n");
		tmp = heredoc_handler(ms, tmp_char);
		tmp_char = ft_free_char(&tmp_char);
	}
	if (tmp < 0)
		perror(redirections->filename);
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
			cmd->out = out_handler(redir);
		}
		else if (type == INPUT
			|| type == HEREDOC)
		{
			close_fd(cmd->in);
			cmd->in = in_handler(ms, redir);
		}
		redir = redir->next;
	}
}
