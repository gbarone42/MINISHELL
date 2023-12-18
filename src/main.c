/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filippo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:44:51 by filippo           #+#    #+#             */
/*   Updated: 2023/12/18 17:30:41 by filippo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_p.h"

int	main(int ac, char **av, char **env)
{
	t_shell	my_shell;
	
	(void)ac;
	(void)av;
	if (ft_init_shell(&my_shell, env))
		ft_error("ft_init_shell", "Error initializing the shell");
	//ft_norm_signal();
	//ft_minishell_simulator(&my_shell);
	return (EXIT_SUCCESS);
}
