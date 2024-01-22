/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlebuiltins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:01:19 by gbarone           #+#    #+#             */
/*   Updated: 2024/01/22 11:49:00 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_args(char **args)
{
	int		i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

void	handle_basic_builtin1(t_shell *shell, char **args)
{
	if (!ft_strncmp(shell->input, "exit", 5))
	{
		free_args(args);
		shell_exit(shell);
	}
	else if (args && args[0] && !ft_strcmp(args[0], "cd"))
	{
		ft_handle_cd(shell, args);
	}
	if (args && args[0] && strcmp(args[0], "echo") == 0)
	{
		handle_echo(args);
	}
}

void	handle_basic_builtin2(t_shell *shell, char **args)
{
	if (!ft_strncmp(shell->input, "pwd", 4))
	{
		print_current_directory();
	}
	else if (args && args[0] && !ft_strcmp(args[0], "export"))
	{
		handle_export(shell, args);
	}
	else if (args && args[0] && !ft_strcmp(args[0], "unset"))
	{
		handle_unset(shell, args);
	}
	else if (!ft_strncmp(shell->input, "env", 4))
	{
		handle_env(shell);
	}
	free_args(args);
}

void	handle_basic_builtins(t_shell *shell)
{
	char	**args;
	int		i;

	i = 0;
	printf("Input before comparison: %s\n", shell->input);
	args = ft_split(shell->input, ' ');
	printf("First command of Input after comparison: %s\n", args[0]);
	while (args[i])
	{
		printf("arg[%d]: %s\n", i, args[i]);
		i++;
	}
	handle_basic_builtin1(shell, args);
	handle_basic_builtin2(shell, args);
}

void	handle_other_builtins(t_shell *shell)
{
	if (!ft_strncmp(shell->input, "clear", 6))
	{
		clear_screen();
	}
	else if (!ft_strncmp(shell->input, "ls", 3))
	{
		print_current_directory_contents();
	}
}

void	builtins_call(t_shell *shell)
{
	handle_basic_builtins(shell);
	handle_other_builtins(shell);
}
