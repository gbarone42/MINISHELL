/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_starter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:34:19 by sdel-gra          #+#    #+#             */
/*   Updated: 2024/01/25 15:30:23 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	main_1(int argc, char **argv, char **env);

int	is_builtin_command(char *command)
{
	const char	*builtins[12];
	size_t		i;

	i = 0;
	if (command)
	{
		builtins[0] = "echo";
		builtins[1] = "cd";
		builtins[2] = "pwd";
		builtins[3] = "export";
		builtins[4] = "unset";
		builtins[5] = "env";
		builtins[6] = "exit";
		builtins[7] = "rm";
		builtins[8] = "mkdir";
		builtins[9] = "rmdir";
		builtins[10] = NULL;
		builtins[11] = NULL;
		while (builtins[i] != NULL)
			if (strcmp(command, builtins[i++]) == 0)
				return (1);
	}
	return (0);
}

void	path_finder(t_shell *px)
{
	char	**tmp;
	char	*tofree;
	int		i;

	i = 0;
	tmp = px->env_list;
	if (px->paths)
	{
		ft_free_char_p(px->paths);
		px->paths = NULL;
	}
	while (tmp && ft_strncmp("PATH=", *tmp, 5))
		tmp++;
	px->paths = ft_split((*tmp) + 5, ':');
	while (px->paths[i])
	{
		tofree = px->paths[i];
		px->paths[i] = ft_strjoin(px->paths[i], "/");
		ft_free_char(&tofree);
		i++;
	}
}

void	ft_exec_cmd(t_shell *ms)
{
	path_finder(ms);
	ft_prio_cmd(ms, &ms->commands);
	pipe(ms->fd_pipe);
	if (is_builtin_command(ms->commands->args[0]))
		builtins_call(ms, ms->commands);
	else
		ft_exec(ms);
}
/*
void	command_handler(t_shell *px, char **envp)
{
	char	**cmd;
	char	*paths;
	int		i;

	i = 0;
	cmd = ft_split(px->commands->cmd, ' ');
	while (px->paths[i])
	{
		paths = ft_strjoin(px->paths[i], cmd[0]);
		if (access(paths, F_OK | X_OK) == 0)
			break ;
		else
			ft_free_char(&paths);
		i++;
	}
	if (!paths)
		ft_free_tutto(px, &cmd, &paths);
	if (execve(paths, cmd, envp) == -1)
		write(1, "errore execve\n", 14);
}

void	child_handler(t_shell *ms, char *envp[], int fd_in)
{
	printf("\e[1;31mChild (PID: %d) executed cmd:\e[0m\n", getpid());
	if (1)//se ci sono redirection entra qua
		ft_redir(ms, fd_in);

	if (ms->commands->next)
    	dup2(ms->fd_pipe[1], 1);
	else
		dup2(ms->commands->out, 1);
	close(ms->fd_pipe[0]);
	command_handler(ms, envp);

}

void	ft_exec(t_shell *ms, char *envp[])
{
	pid_t	child_pid;
	int		i;
	int		fd_in;

	fd_in = 0;
	i = 0;
	path_finder(ms, envp);
	while (ms->commands)
	{
		pipe(ms->fd_pipe);
		child_pid = fork();
		if (child_pid == 0)
		{
			child_handler(ms, envp, fd_in);
		}
		else
		{
			close(ms->fd_pipe[1]);
			fd_in = ms->fd_pipe[0];
			waitpid(child_pid, 0, 0);
		}
		ms->commands = ms->commands->next;
		i++;
	}
}*/
