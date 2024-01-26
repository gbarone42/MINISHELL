/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 20:18:17 by filippo           #+#    #+#             */
/*   Updated: 2024/01/26 12:37:26 by filippo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_shell	*ft_ret_shell(t_shell *p_shell)
{
	static t_shell	*shell;

	if (!shell)
		shell = p_shell;
	return (shell);
}

void	ft_err(char *caller, int error)
{
	perror(caller);
	exit(error);
}
