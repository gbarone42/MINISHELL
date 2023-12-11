/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filippo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:44:51 by filippo           #+#    #+#             */
/*   Updated: 2023/12/11 19:44:52 by filippo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_p.h"

int	g_exit = 0;

int	main(int ac, char **av, char **env)
{
	t_shell	my_shell;
	int		output;
	
	(void)ac;
	(void)av;
	printf("%sWelcome %s!%s\n", GREEN, getenv("USER"), CLR_RMV);
	output = ft_init_shell(&my_shell, env);
	if (output) {
		perror("Error initializing shell");
		exit(output);
	}
	ft_norm_signal();
	ft_minishell_simulator(&my_shell);
	return (EXIT_SUCCESS);
}
