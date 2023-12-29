/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filippo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:44:51 by filippo           #+#    #+#             */
/*   Updated: 2023/12/29 11:54:05 by filippo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_p.h"

static void	ft_prepare_for_next_input(t_shell *shell)
{
	free(shell->input);
	ft_free_tlist(shell->tokens);
	shell->ntokens = 0;
}

int	main(int argc, char **argv, char **env)
{
	t_shell	shell;

	if (argc != 1)
		ft_err(*argv, errno = EINVAL);
	ft_init_shell(&shell, env);
	while (1)
	{
		shell.input = readline(shell.prompt);
		if (!shell.input)
			break ;
		shell.input_len = ft_strlen(shell.input);
		ft_parser(&shell);
		/*
		if (shell.commands)
			ft_execute(&shell);
		*/
		ft_prepare_for_next_input(&shell);
	}
	ft_free_and_exit(&shell, EXIT_SUCCESS);
}
