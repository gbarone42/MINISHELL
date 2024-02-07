/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:40:40 by sdel-gra          #+#    #+#             */
/*   Updated: 2024/02/07 14:16:57 by filippo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	excve_core(t_shell *shell, char *paths, char **cmd)
{
	if (access(paths, F_OK | X_OK) == 0)
	{
		execve(paths, cmd, shell->env);
		ft_free_and_err(shell, "execve", 127);
	}
}

void	command_handler(t_shell *shell, t_clist *cmd)
{
	char	**cmd_sp;
	char	*paths;
	int		i;

	i = 0;
	cmd_sp = cmd->args;
	if (cmd_sp[0][0] == '\0')
	{
		execve("/dev/null", cmd_sp, shell->env);
		ft_free_shell(shell);
		exit(127);
	}
	excve_core(shell, cmd_sp[0], cmd_sp);
	while (shell->paths && shell->paths[i])
	{
		paths = ft_strjoin(shell->paths[i], cmd_sp[0]);
		excve_core(shell, paths, cmd_sp);
		free(paths);
		i++;
	}
	if (cmd_sp[0])
		write(STDERR_FILENO, cmd_sp[0], ft_strlen(cmd_sp[0]));
	else
		write(STDERR_FILENO, " ", 1);
	ft_free_err_cmdnotf(shell, ": command not found\n", 127);
}

void	parent_handler(t_shell *shell)
{
	int	child_exit_status;

	signal(SIGINT, signal_print);
	signal(SIGQUIT, signal_print);
	waitpid(shell->pid_child, &child_exit_status, 0);
	close_fd(shell->fd_pipe[1]);
	close_fd(shell->tmp_fd);
	shell->tmp_fd = shell->fd_pipe[0];
	shell->fd_pipe[0] = -1;
	shell->fd_pipe[1] = -1;
	if (WIFEXITED(child_exit_status))
		g_exit = WEXITSTATUS(child_exit_status);
	else if (WIFSIGNALED(child_exit_status))
		g_exit = WEXITSTATUS(child_exit_status) + 128;
}

void	child_handler(t_shell *shell, t_clist *cmd, int i)
{
	signal(SIGQUIT, SIG_DFL);
	signal(SIGINT, SIG_DFL);
	redirs_fork(shell, cmd, i);
	if (is_builtin_command(cmd->args[0]))
	{
		ft_handle_builtins(shell, cmd);
		ft_free_and_exit(shell, g_exit);
	}
	else
		command_handler(shell, cmd);
}

void	ft_exec(t_shell *shell, int i)
{
	t_clist	*command;

	command = shell->commands;
	shell->tmp_fd = -1;
	while (command)
	{
		if (pipe(shell->fd_pipe) < 0)
			perror("pipe");
		else
		{
			shell->pid_child = fork();
			if (shell->pid_child == 0)
				child_handler(shell, command, i);
			else
				parent_handler(shell);
		}
		command = command->next;
		i++;
	}
}
