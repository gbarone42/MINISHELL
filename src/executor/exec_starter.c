/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_starter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:34:19 by sdel-gra          #+#    #+#             */
/*   Updated: 2024/01/26 19:56:05 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main_1(int argc, char **argv, char **env);

int	is_builtin_command(char *command)
{
	const char	*builtins[8];
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
		builtins[7] = "readbuiltin";
		builtins[8] = NULL;
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
	while (*tmp && ft_strncmp("PATH=", *tmp, 5))
		tmp++;
	if (*tmp)
		px->paths = ft_split((*tmp) + 5, ':');
	while (px->paths && px->paths[i])
	{
		tofree = px->paths[i];
		px->paths[i] = ft_strjoin(px->paths[i], "/");
		ft_free_char(&tofree);
		i++;
	}
}

void	ft_check_cmd(t_shell *ms)
{
	if (ms && ms->commands && ms->commands->redirections
		&& ms->commands->args == NULL)
		ms->commands->args = ft_split("", ' ');
}

void	ft_exec_cmd(t_shell *ms)
{
	ft_check_cmd(ms);
	path_finder(ms);
	if (ms->commands && ms->commands->next)
	{
		ft_prio_cmd(ms, &ms->commands);
		pipe(ms->fd_pipe);
		ft_exec(ms, 0);
	}
	else if (ms->commands)
	{
		if (ms->commands->redirections)
		{
			ft_redir(ms, ms->commands);
			if (ms->commands->in > -1)
				dup2(ms->commands->in, STDIN_FILENO);
			if (ms->commands->out > -1)
				dup2(ms->commands->out, STDOUT_FILENO);
		}
		if (is_builtin_command(ms->commands->args[0]))
		{
			builtins_call(ms, ms->commands);
			//ft_free_shell(ms);
		}
		else
		{
			ms->pid_child = fork();
			if (ms->pid_child == 0)
			{
				signal(SIGINT, SIG_DFL);
				signal(SIGQUIT, SIG_DFL);
				command_handler(ms, ms->commands);
			}
			else
				parent_handler(ms);
		}
		dup2(ms->in, STDIN_FILENO);
		dup2(ms->out, STDOUT_FILENO);
	}
}
