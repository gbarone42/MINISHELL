/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 03:10:35 by badph             #+#    #+#             */
/*   Updated: 2024/01/23 18:40:55 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <time.h>

/*
static void	ft_prepare_for_next_input(t_shell *shell)
{
	free(shell->input);
	ft_free_clist(shell->commands);
}*/

void	ft_minishell_simulator(t_shell *shell)//remove envp
{
	//t_pars	*command;

	while (1)
	{
		shell->input = readline(shell->prompt);
		if (shell->input == NULL)
			ft_ctrld(shell);
		if (ft_isvalid(shell->input))
		{
			shell->input_len = ft_strlen(shell->input);
			shell->commands = ft_parser(shell);
			if (shell->commands)
			{
				ft_exec_cmd(shell);
			}
//			builtins_call(shell);
			add_to_history(&(shell->history), shell->input);
//			ft_prepare_for_next_input(shell);
		}
		else
			printf("Invalid input detected!\n");
	}
	free(shell->input);
}
