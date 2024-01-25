/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 03:10:35 by badph             #+#    #+#             */
/*   Updated: 2024/01/25 15:06:38 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <time.h>

/*
static void	ft_prepare_for_next_input(t_shell *shell)
{
	//ft_free_char_p(&shell->input);
	shell->commands = ft_free_clist(shell->commands);
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
			shell->input = NULL;
			shell->commands = ft_free_clist(shell->commands);
		}
		else
			printf("Invalid input detected!\n");
	}
	free(shell->input);
}
