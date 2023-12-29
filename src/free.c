/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filippo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 23:21:55 by filippo           #+#    #+#             */
/*   Updated: 2023/12/29 11:54:41 by filippo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_p.h"

static void	ft_free_shell(t_shell *shell)
{
	ft_free_vlist(shell->first_envv);
	free(shell->prompt);
	ft_free_tlist(shell->tokens);
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
