/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_starter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:34:19 by sdel-gra          #+#    #+#             */
/*   Updated: 2024/02/07 13:54:08 by filippo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin_command(char *command)
{
	char	*builtins[8];
	size_t	i;

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
			if (ft_strcmp(command, builtins[i++]) == 0)
				return (1);
	}
	return (0);
}

static void	ft_path_finder(t_shell *shell)
{
	char	**tmp;
	int		i;

	i = -1;
	tmp = shell->env;
	if (shell->paths)
		shell->paths = ft_free_char_p(shell->paths);
	while (*tmp && ft_strncmp("PATH=", *tmp, 5))
		tmp++;
	if (*tmp)
		shell->paths = ft_split((*tmp) + 5, ':');
	while (shell->paths && shell->paths[++i])
		shell->paths[i] = ft_strjoin_and_free_first(shell->paths[i], "/");
}

static void	ft_exec_onparent(t_shell *shell)
{
	t_clist	*commands;

	commands = shell->commands;
	if (is_builtin_command(commands->args[0]))
		ft_handle_builtins(shell, commands);
	else
	{
		shell->pid_child = fork();
		if (shell->pid_child == 0)
		{
			signal(SIGINT, SIG_DFL);
			signal(SIGQUIT, SIG_DFL);
			command_handler(shell, commands);
		}
		else
			parent_handler(shell);
	}
}

void	ft_exec_cmd(t_shell *shell)
{
	t_clist	*commands;

	commands = shell->commands;
	ft_path_finder(shell);
	if (commands->next)
	{
		ft_prio_cmd(shell, &commands);
		ft_exec(shell, 0);
	}
	else
	{
		if (commands->redirections)
		{
			ft_redir(shell, commands);
			if (commands->in > -1)
				dup2(commands->in, STDIN_FILENO);
			if (commands->out > -1)
				dup2(commands->out, STDOUT_FILENO);
		}
		ft_exec_onparent(shell);
		dup2(shell->in, STDIN_FILENO);
		dup2(shell->out, STDOUT_FILENO);
	}
}
