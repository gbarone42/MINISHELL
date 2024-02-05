/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 03:12:42 by badph             #+#    #+#             */
/*   Updated: 2024/02/05 17:36:58 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	signal_print(int sig)
{
	(void)sig;
	g_exit = 130;
	write(STDOUT_FILENO, "\n", 1);
}

// da farsi spiegare
int	ft_kill_child(int n)
{
	static int	pid = 0;

	if (n == -1)
		pid = 0;
	else if (pid)
	{
		kill(pid, SIGKILL);
		pid = 0;
	}
	else if (n)
		pid = n;
	return (0);
}

void	signal_handler(int sig)
{
	(void)sig;
	ft_kill_child(0);
	write(STDOUT_FILENO, "\n", 1);
	g_exit = 130;
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}
