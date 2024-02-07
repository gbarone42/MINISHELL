/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:22:16 by gbarone           #+#    #+#             */
/*   Updated: 2024/02/07 14:17:55 by filippo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft__exit_with(t_shell *shell, char **args)
{
	int		index;
	char	*arg;
	char	c;

	index = 0;
	arg = args[1];
	c = arg[index++];
	while (c && ft_isdigit(c))
		c = arg[index++];
	if (c)
	{
		errno = EINVAL;
		ft_free_and_err(shell, "exit", 2);
	}
	if (args[2])
	{
		errno = E2BIG;
		perror("exit");
		g_exit = 1;
		return (0);
	}
	ft_free_and_exit(shell, ft_atoi(args[1]) & 0xFF);
	return (1);
}

void	ft__exit(t_shell *shell, char **args)
{
	int		exit;

	exit = 1;
	printf("exit\n");
	if (args && args[1])
		exit = ft__exit_with(shell, args);
	if (exit)
		ft_free_and_exit(shell, g_exit);
}
