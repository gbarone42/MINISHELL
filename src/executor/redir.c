/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:33:13 by sdel-gra          #+#    #+#             */
/*   Updated: 2024/01/28 20:05:10 by sdel-gra         ###   ########.fr       */
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

static char	*ft_addone(char *s, int size)
{
	char	*new;

	if (!s || !(*s) || size < 0)
		return (NULL);
	new = malloc(size + 1);
	if (!new)
		return (NULL);
	new[size] = '\0';
	while (--size >= 0)
		new[size] = s[size];
	if (s)
		free(s);
	return (new);
}

void	heredoc_handler_prio(t_shell *shell, char *delim)
{
	char	*line;

	write(1, ">", 1);
	line = gnl(shell->in);
	while (line)
	{
		if (!ft_strncmp(line, delim, ft_strlen(delim) + 1))
		{
			free(line);
			line = NULL;
			break ;
		}
		write(1, ">", 1);
		printf("%s", line);
		free(line);
		line = gnl(shell->in);
	}
}

char	*gnl(int fd)
{
	int		i;
	char	*buf;
	int		rd;	

	if (fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	i = 0;
	buf = malloc(1);
	if (!buf)
		return (NULL);
	while (1)
	{
		rd = read(fd, &buf[i], 1);
		if (rd <= 0 || buf[i] == '\n')
			break ;
		buf = ft_addone(buf, i + 1);
		i++;
	}
	if (rd <= 0)
	{
		free(buf);
		return (NULL);
	}
	buf = ft_addone(buf, i + 1);
	return (buf);
}
