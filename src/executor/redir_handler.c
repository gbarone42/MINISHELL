
#include "../includes/minishell.h"

int	heredoc_handler(t_mshell *shell, char *delim)
{
	char	*line;
	int		heredoc_fd;

	write(1, ">", 1);
	line = get_next_line(shell->infile);
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
		line = get_next_line(shell->infile);
	}
	return (-1);
}

int	out_handler(t_cmd *cmd)
{
	int	tmp;

	tmp = -1;
	if (cmd->redirs->type == OUTPUT)
		tmp = open(cmd->redirs->str, O_CREAT | O_WRONLY | O_TRUNC, 0666);
	else if (cmd->redirs->type == APPEND)
		tmp = open(cmd->redirs->str, O_CREAT | O_WRONLY | O_APPEND, 0666);
	if (tmp < 0)
		perror(cmd->redirs->str);
	return (tmp);
}


int	in_handler(t_mshell *ms, t_cmd *cmd)
{
	int	tmp;

	tmp = -1;
	if (cmd->redirs->type == INPUT)
		tmp = open(cmd->redirs->str, O_RDONLY);
	else if (cmd->redirs->type == HEREDOC)
		tmp = heredoc_handler(ms, ft_strjoin(cmd->redirs->str, "\n"));
	if (tmp < 0)
		perror(cmd->redirs->str);
	return (tmp);
}

void	ft_redir(t_mshell *ms, t_cmd *cmd)
{
	while (cmd->redirs)
	{
		if (cmd->redirs->type == OUTPUT || cmd->redirs->type == APPEND)
		{
			close_fd(cmd->out);
			cmd->out = out_handler(cmd);
		}
		else if (cmd->redirs->type == INPUT || cmd->redirs->type == HEREDOC)
		{
			close_fd(cmd->in);
			cmd->in = in_handler(ms, cmd);
		}
		cmd->redirs = cmd->redirs->next;
	}
}
