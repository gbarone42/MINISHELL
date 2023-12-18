/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filippo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 23:15:30 by filippo           #+#    #+#             */
/*   Updated: 2023/12/18 23:18:27 by filippo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_p.h"

void ft_ctrld(t_shell *shell)
{
    if (errno)
	{
        write(STDERR_FILENO, "readline error: ", 17);
    }
    printf("\n");
    free(shell->input);
	// if $SHLVL == 0
    ft_free_and_exit(shell, EXIT_SUCCESS);
}

void	ft_set_signals(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, signal_handler);
}

void	signal_handler(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n \n", 3); //for the moment is double \newline
	g_exit = 130;
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

