/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 23:21:55 by filippo           #+#    #+#             */
/*   Updated: 2024/01/25 13:51:55 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
typedef struct s_shell
{
	pid_t		pid_child;
	int			fd_pipe[2];
	int			tmp_fd;
	t_history	history;
	int			in;
	int			out;
	char		**env;
	char		**last_env;
	char		*prompt;
	char		*input;
	char		**paths;
	size_t		input_len;
	t_clist		*commands;
	char		**env_list;
	char		**export;
}	t_shell;
*/

void	ft_free_history(t_shell *ms)
{
	int	i;

	i = 0;
	while (ms && ms->history.entries && ms->history.entries[i])
	{
		ms->history.entries[i] = ft_free(&ms->history.entries[i]);
		i++;
	}
}

void	ft_free_shell(t_shell *shell)
{
	ft_free_history(shell);
	shell->prompt = ft_free_char(&shell->prompt);
	shell->input = ft_free_char(&shell->input);
	ft_free_char_p(shell->paths);
	shell->paths = NULL;
	shell->commands = ft_free_clist(shell->commands);
	ft_free_char_p(shell->env_list);
	shell->env_list = NULL;
}

void	ft_free_and_err(t_shell *shell, char *caller, int error)
{
	ft_free_shell(shell);
	ft_err(caller, error);
}

void	ft_free_and_exit(t_shell *shell, int status)
{
	ft_free_shell(shell);
	exit(status);
}

void	ft_free_char_p(char **p)
{
	size_t	index;
	char	*value;

	index = 0;
	if (!p)
		return ;
	value = p[index++];
	while (value)
	{
		free(value);
		value = NULL;
		value = p[index++];
	}
	free(p);
}
