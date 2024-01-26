/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 21:53:39 by sdel-gra          #+#    #+#             */
/*   Updated: 2024/01/26 16:45:04 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	create_prompt2(t_shell *shell, char *user)
{
	char	*prompt_suffix;

	prompt_suffix = "@ASHellKETCHUM" CLR_RMV "$ ";
	shell->prompt = ft_strjoin(user, prompt_suffix);
	free(user);
	if (!shell->prompt)
	{
		write(STDERR_FILENO, "Failed to allocate memory for prompt.\n", 38);
		free_env_array(shell->env_list);
		return (MEM_ERROR3);
	}
	//printf("prompt: %s\n", shell->prompt);
	return (0);
}

int	ft_innit_user_and_prompt(t_shell *shell, char **env)
{
	char	*user;
	int		result;

	result = copy_env_vars(shell, env);
	if (result != 0)
		return (result);
	result = create_user(&user);
	if (result != 0)
	{
		free_env_array(shell->env_list);
		return (result);
	}
	return (create_prompt2(shell, user));
}

int	ft_duplicate_std_fds(t_shell *shell)
{
	shell->in = dup(STDIN_FILENO);
	shell->out = dup(STDOUT_FILENO);
	if (shell->in == -1 || shell->out == -1)
	{
		write(STDERR_FILENO, "Failed to duplicate file descriptors\n", 38);
		free_env_array(shell->env_list);
		free(shell->prompt);
		return (MEM_ERROR);
	}
	shell->paths = NULL;
	shell->export = NULL;
	return (0);
}

int	ft_innit_shell(t_shell *shell, char **env)
{
	int	result;

	result = ft_innit_user_and_prompt(shell, env);
	if (result != 0)
		return (result);
	result = ft_duplicate_std_fds(shell);
	if (result != 0)
		return (result);
	ft_ret_shell(shell);
	return (0);
}
