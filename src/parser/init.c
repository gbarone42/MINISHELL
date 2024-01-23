/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 22:42:17 by filippo           #+#    #+#             */
/*   Updated: 2024/01/23 14:37:13 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_init_env(t_shell *shell, char **env)
{
	size_t	index;
	char	**last;
	char	*value;

	if (!env || !*env)
		ft_err("FT_INIT_ENV", errno = ENOENT);
	index = 0;
	while (env[index])
		index++;
	last = malloc(sizeof(last) * ++index);
	if (!last)
		ft_err("FT_INIT_ENV", errno = ENOMEM);
	shell->env = last;
	index = 0;
	value = env[index];
	while (value)
	{
		value = ft_strdup(value);
		if (!value)
			ft_free_and_err(shell, "FT_STRDUP", errno = ENOMEM);
		last[index++] = value;
		value = env[index];
	}
	last[index] = NULL;
	shell->last_env = last;
}

void	ft_init_shell(t_shell *shell, char **env)
{
	ft_ret_shell(shell);
	ft_init_env(shell, env);
	//! come settiamo il prompt?
	ft_set_prompt(shell);
	//ft_set_signals();
}
