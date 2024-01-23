/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:44:51 by filippo           #+#    #+#             */
/*   Updated: 2024/01/23 16:19:38 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_prepare_for_next_input(t_shell *shell)
{
	free(shell->input);
	ft_free_clist(shell->commands);
}

static void	ft_test(t_shell *shell, char **argv)
{
	char	*input;

	input = *++argv;
	while (*argv)
		input = ft_strjoin(ft_strjoin(input, " "), *++argv);
	shell->input_len = ft_strlen(input);
	shell->input = input;
	ft_parser(shell);
	ft_free_and_exit(shell, EXIT_SUCCESS);
}

static void	ft_execute(t_shell *shell)
{
	(void) shell;
}

int	main_1(int argc, char **argv, char **env)
{
	t_shell	shell;

	ft_init_shell(&shell, env);
	if (argc != 1)
		ft_test(&shell, argv);
//		ft_err(*argv, errno = EINVAL);
	while (1)
	{
		shell.input = readline(shell.prompt);
		if (!ft_strncmp(shell.input, "exit", 4))
			break ;
		shell.input_len = ft_strlen(shell.input);
		shell.commands = ft_parser(&shell);
		if (shell.commands)
			ft_execute(&shell);
		ft_prepare_for_next_input(&shell);
	}
	ft_free_and_exit(&shell, EXIT_SUCCESS);
	return (0);
}
