/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:40:40 by sdel-gra          #+#    #+#             */
/*   Updated: 2024/01/22 16:35:50 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	excve_core(t_mshell *ms, char *cmd_path, char **cmd)
{
	if (access(cmd_path, F_OK | X_OK) == 0)
	{
		execve(cmd_path, cmd, ms->env);
		perror("execve");
		//free CMDSP
		//FREE MS
		//FREE PATH(?)
	}
}

void	command_handler(t_mshell *ms, t_cmd *cmd)
{
	char	**cmd_sp;
	char	*cmd_path;
	int		i;

	i = 0;
	cmd_sp = ft_split(cmd->cmd_str, ' ');
	excve_core(ms, cmd_sp[0], cmd_sp);
	while (ms->cmd_path[i])
	{
		cmd_path = ft_strjoin(ms->cmd_path[i], cmd_sp[0]);
		excve_core(ms, cmd_path, cmd_sp);
		free(cmd_path);
		i++;
	}
	if (cmd_sp[0])
		write(STDERR_FILENO, cmd_sp[0], ft_strlen(cmd_sp[0]));
	else
		write(STDERR_FILENO, " ", 1);
	write(STDERR_FILENO, ": command not found\n", 21);
	//free ms
	//FREE CMD_SP
	exit(127);
}

void	parent_handler(t_mshell *ms)
{
	int	child_exit_stat;



	waitpid(ms->pid_child, &child_exit_stat, 0);
	//close(ms->fd_pipe[1]);
	//printf("%s\n", get_next_line(ms->fd_pipe[1]));
	close(ms->fd_pipe[1]);
	//printf("%d\n", ms->tmp_fd);
	ms->tmp_fd = ms->fd_pipe[0];
	//printf("%d\n", ms->tmp_fd);
	ms->fd_pipe[0] = -1;
	ms->fd_pipe[1] = -1;

	if (WIFEXITED(child_exit_stat))
		ms->exit_stat = WEXITSTATUS(child_exit_stat);
	else if (WIFSIGNALED(child_exit_stat))
		ms->exit_stat = WEXITSTATUS(child_exit_stat) + 128;
}


void	child_handler(t_mshell *ms, t_cmd *cmd)
{
	printf("\e[1;31mChild (PID: %d) executed cmd:\e[0m\n", getpid());
	if (cmd->is_first)
	{
		dup2(open("1", O_RDONLY), STDIN_FILENO);
	}
	else
	{
		dup2(ms->tmp_fd, STDIN_FILENO);
	}
	if (cmd->redirs)//se ci sono redirection entra qua
	{
		ft_redir(ms, cmd);//redir
		if (ms->tmp_fd > 0)
			dup2(cmd->in, ms->tmp_fd);
		else
			dup2(cmd->in, STDIN_FILENO);
	}
	if (cmd->next)
	{
		close(ms->fd_pipe[0]);
		dup2(ms->fd_pipe[1], STDOUT_FILENO);
		close(ms->fd_pipe[1]);
	}


	//else
		//dup2(cmd->out, 1);//normal redir after pipe
	// gestione se è una builtin da aggiungere
	// else fai command_handler
	command_handler(ms, cmd);
}

void	ft_exec(t_mshell *ms, char *envp[])
{
	int		i;

	i = 0;
	path_finder(ms, envp);
	ms->tmp_fd = STDIN_FILENO;
	while (ms->c_l)
	{
		if(pipe(ms->fd_pipe) < 0)
            perror("pipe");
        ms->pid_child = fork();
		if (ms->pid_child  == 0)
		{
			child_handler(ms, ms->c_l);
		}
		else
		{
			parent_handler(ms);
		}
		ms->c_l = ms->c_l->next;
		i++;
	}
}
