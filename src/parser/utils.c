/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 20:18:17 by filippo           #+#    #+#             */
/*   Updated: 2024/01/23 14:38:17 by sdel-gra         ###   ########.fr       */
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
	(void) error;
	perror(caller);
	exit(EXIT_FAILURE);
}
