/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 03:10:35 by badph             #+#    #+#             */
/*   Updated: 2024/01/24 16:31:51 by gbarone          ###   ########.fr       */
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
			add_to_history(&(shell->history), shell->input);
//			ft_prepare_for_next_input(shell);
		}
		else
			printf("Invalid input detected!\n");
	}
	free(shell->input);
}
