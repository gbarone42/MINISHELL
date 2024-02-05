/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 21:53:39 by sdel-gra          #+#    #+#             */
/*   Updated: 2024/02/05 14:24:49 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_env(char **env)
{
	int	index;

	if (!env)
		return ;
	index = 0;
	while (env[index])
		free(env[index++]);
	free(env);
}

static void	ft_duplicate_std_fds(t_shell *shell)
{
	int	fd;

	fd = dup(STDIN_FILENO);
	if (fd == -1)
		ft_free_and_err(shell, "DUP", errno);
	shell->in = fd;
	fd = dup(STDOUT_FILENO);
	if (fd == -1)
		ft_free_and_err(shell, "DUP", errno);
	shell->out = fd;
}

static void	ft_init_env(t_shell *shell, char **env)
{
	size_t	index;
	char	**last;
	char	*value;

	if (!env || !*env)
		ft_free_and_err(shell, "FT_INIT_ENV", errno = ENOENT);
	index = 0;
	while (env[index])
		index++;
	last = malloc(sizeof(last) * ++index);
	if (!last)
		ft_free_and_err(shell, "FT_INIT_ENV", errno = ENOMEM);
	shell->env = last;
	index = 0;
	value = env[index];
	while (value)
	{
		value = ft_strdup(value);
		if (!value)
			ft_free_and_err(shell, "INIT_ENV: FT_STRDUP", errno = ENOMEM);
		last[index++] = value;
		value = env[index];
	}
	last[index] = NULL;
	shell->last_env = last;
}

static void	ft_init_history(t_shell *shell)
{
	shell->history = malloc(sizeof(t_history));
	if (!shell->history)
		ft_free_and_err(shell, "INIT HISTORY: malloc", errno = ENOMEM);
	memset(shell->history, 0, sizeof(t_history));
	if (errno)
		ft_free_and_err(shell, "INIT_HISTORY: memset", errno = ENOMEM);
}

void	ft_init_shell(t_shell *shell, char **env)
{
	ft_ret_shell(shell);
	errno = 0;
	memset(shell, 0, sizeof(t_shell));
	if (errno)
		ft_free_and_err(shell, "INIT_SHELL: memset", errno);
	ft_init_history(shell);
	ft_init_env(shell, env);
	ft_duplicate_std_fds(shell);
	shell->pid_child = -1;
	shell->paths = NULL;
	shell->export = NULL;
}
