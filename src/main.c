/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filippo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:44:51 by filippo           #+#    #+#             */
/*   Updated: 2024/01/06 17:20:33 by filippo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_p.h"

static void	ft_prepare_for_next_input(t_shell *shell)
{
	free(shell->input);
}

void	ft_test(t_shell *shell, char *arg)
{
	shell->input_len = ft_strlen(arg);
	shell->input = arg;
	ft_parser(shell);
}

int	main(int argc, char **argv, char **env)
{
	t_shell	shell;

	ft_init_shell(&shell, env);
	if (argc != 1)
	{
		ft_test(&shell, argv[1]);
		ft_free_and_exit(&shell, EXIT_SUCCESS);
	}
//		ft_err(*argv, errno = EINVAL);
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
