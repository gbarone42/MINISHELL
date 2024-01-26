/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:40:40 by sdel-gra          #+#    #+#             */
/*   Updated: 2024/01/26 15:01:33 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	excve_core(t_shell *ms, char *paths, char **cmd)
{
	if (access(paths, F_OK | X_OK) == 0)
	{
		execve(paths, cmd, ms->env_list);
		ft_free_and_err(ms, "execve", 126);
	}
}

void	command_handler(t_shell *ms, t_clist *cmd)
{
	char	**cmd_sp;
	char	*paths;
	int		i;

	i = 0;
	cmd_sp = cmd->args;
	if (cmd_sp[0][0] == '\0')
	{
		execve("/dev/null", cmd_sp, ms->env_list);
		ft_free_shell(ms);
		exit(127);
	}
	excve_core(ms, cmd_sp[0], cmd_sp);
	while (ms->paths && ms->paths[i])
	{
		paths = ft_strjoin(ms->paths[i], cmd_sp[0]);
		excve_core(ms, paths, cmd_sp);
		free(paths);
		i++;
	}
	if (cmd_sp[0])
		write(STDERR_FILENO, cmd_sp[0], ft_strlen(cmd_sp[0]));
	else
		write(STDERR_FILENO, " ", 1);
	ft_free_and_err(ms, ": command not found\n", 127);
}

void	parent_handler(t_shell *ms)
{
	int	child_exit_status;

	waitpid(ms->pid_child, &child_exit_status, 0);
	close(ms->fd_pipe[1]);
	ms->tmp_fd = ms->fd_pipe[0];
	ms->fd_pipe[0] = -1;
	ms->fd_pipe[1] = -1;

	if (WIFEXITED(child_exit_status))
		ms->exit_status = WEXITSTATUS(child_exit_status);
	else if (WIFSIGNALED(child_exit_status))
		ms->exit_status = WEXITSTATUS(child_exit_status) + 128;
}


void	child_handler(t_shell *ms, t_clist *cmd, int i)
{
	//printf("\e[1;31mChild (PID: %d) executed cmd:\e[0m\n", getpid());
	//redirection
	// first pipe redir 
	// second redirs
	// 3 close redirs
	if (i > 0)
	{
		dup2(ms->tmp_fd, STDIN_FILENO);
	}
	if (cmd->next)
	{
		close(ms->fd_pipe[0]);
		cmd->out = ms->fd_pipe[1];
	}
	if (cmd -> redirections)
	{
		ft_redir(ms, cmd);
		if (ms->tmp_fd > 0)
			dup2(cmd->in, ms->tmp_fd);
		else
			dup2(cmd->in, STDIN_FILENO);
	}
	/*
	else
	{
		dup2(ms->tmp_fd, STDIN_FILENO);
	}*/
	if (cmd->out != -1 && cmd->out != -2)
	{
		dup2(cmd->out, STDOUT_FILENO);
	}
	close(ms->fd_pipe[1]);
	//	se ci sono redirs o pipe dup2(cmd->out, STDOUT_FILENO);
	//else
		//dup2(cmd->out, 1);//normal redir after pipe
	// gestione se è una builtin da aggiungere
	// else fai command_handler
	command_handler(ms, cmd);
}

void	ft_exec(t_shell *ms)
{
	int		i;
	t_clist	*iter;

	iter = ms->commands;
	i = 0;
	ms->tmp_fd = STDIN_FILENO;
	while (iter)
	{
		if (pipe(ms->fd_pipe) < 0)
			perror("pipe");
		ms->pid_child = fork();
		if (ms->pid_child == 0)
		{
			child_handler(ms, iter, i);
		}
		else
		{
			parent_handler(ms);
		}
		iter = iter->next;
		i++;
	}
}
