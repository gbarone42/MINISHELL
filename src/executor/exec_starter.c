/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_starter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:34:19 by sdel-gra          #+#    #+#             */
/*   Updated: 2024/01/25 18:32:14 by sdel-gra         ###   ########.fr       */
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
	if(ms && ms->commands && ms->commands->redirections && ms->commands->args == NULL)
		ms->commands->args = ft_split("", ' ');
}

void	ft_exec_cmd(t_shell *ms)
{
	ft_check_cmd(ms);
	path_finder(ms);
	ft_prio_cmd(ms, &ms->commands);
	pipe(ms->fd_pipe);
	if (is_builtin_command(ms->commands->args[0]))
		builtins_call(ms, ms->commands);
	else
		ft_exec(ms);
}
