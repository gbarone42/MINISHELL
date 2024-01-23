/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 03:10:35 by badph             #+#    #+#             */
/*   Updated: 2024/01/23 19:18:35 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <time.h>

int	main_2(int argc, char *argv[], char *envp[]);
/*
static void	ft_prepare_for_next_input(t_shell *shell)
{
	free(shell->input);
	ft_free_clist(shell->commands);
}*/

int	ft_count_space(char *str)
{
	int i = 0;
	int out = 1;
	while (str && str[i])
	{
		if (str[i] == ' ')
				out++;		
		i++;
	}
	return out;
}

void	ft_minishell_simulator(t_shell *shell)//remove envp
{
	//t_pars	*command;

	while (1)
	{
		shell->input =  readline(shell->prompt);
		if (shell->input == NULL)
			ft_ctrld(shell);
		if (ft_isvalid(shell->input))
		{
			shell->input_len = ft_strlen(shell->input);
			shell->commands = ft_parser(shell);
			if (shell->commands)
			{//to add my executor
//				int n = ft_count_space(shell->input);
//				main_2(n , ft_split(shell->input, ' '), envp);
			}
			builtins_call(shell, shell->commands);
			add_to_history(&(shell->history), shell->input);
//			ft_prepare_for_next_input(shell);
		}
		else
			printf("Invalid input detected!\n");
	}
	free(shell->input);
}
