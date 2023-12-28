/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filippo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 22:42:17 by filippo           #+#    #+#             */
/*   Updated: 2023/12/27 16:23:47 by filippo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_p.h"

static void	ft_init_env(t_shell *shell, char **env)
{
	t_vlist *last;

	if (!env || !*env)
		ft_err("ft_copy_env", errno = ENOENT);
	last = ft_new_vlnode(*env++);
	if (!last)
		ft_err("ft_new_slnode", errno = ENOMEM);
	shell->first_envv = last;
	while (*env)
	{
		last = ft_append_vlist(last, *env++);
		if (!last)
			ft_free_and_err(shell, "FT_APPEND_VLIST", errno = ENOMEM);
	}
	shell->last_envv = last;
}

void	ft_init_shell(t_shell *shell, char **env)
{
	ft_init_env(shell, env);
	//! come settiamo il prompt?
	ft_set_prompt(shell);
	//ft_set_signals();
}
