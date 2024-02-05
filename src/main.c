/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 21:58:19 by sdel-gra          #+#    #+#             */
/*   Updated: 2024/02/05 14:17:20 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_exit = 0;

static void	ft_null_input(t_shell *shell)
{
	if (errno)
		write(STDERR_FILENO, "readline error\n", 15);
	ft__exit(shell);
}

static void	ft_prepare_for_next_input(t_shell *shell)
{
	add_to_history(shell->history, shell->input);
	shell->commands = ft_free_clist(shell->commands);
}

int	main(int argc, char **argv, char **env)
{
	t_shell	shell;

	if (argc > 1)
		ft_free_and_err(NULL, argv[0], errno = E2BIG);
	ft_init_shell(&shell, env);
	while (1)
	{
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, signal_handler);
		shell.input = readline(BLUE "minishell" WHITE "$ ");
		if (shell.input == NULL)
			ft_null_input(&shell);
		else if (ft_isvalid(shell.input))
		{
			shell.input_len = ft_strlen(shell.input);
			shell.commands = ft_parser(&shell);
			if (shell.commands)
				ft_exec_cmd(&shell);
			ft_prepare_for_next_input(&shell);
		}
		else
			printf("Invalid input detected!\n");
	}
	return (EXIT_FAILURE);
}
