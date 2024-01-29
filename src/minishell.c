/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 21:58:19 by sdel-gra          #+#    #+#             */
/*   Updated: 2024/01/26 17:29:14 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_exit = 0;

int	main(int ac, char **av, char **env)
{
	int		output;
	t_shell	my_shell;

	(void)ac;
	(void)av;
	memset(&my_shell, 0, sizeof(t_shell));
	my_shell.pid_child = -1;
	printf("%sWelcome %s!%s\n", GREEN, getenv("USER"), CLR_RMV);
	output = ft_innit_shell(&my_shell, env);
	if (output != 0)
	{
		perror("Error initializing shell");
		exit(output);
	}
	ft_minishell_simulator(&my_shell);
	return (EXIT_SUCCESS);
}
