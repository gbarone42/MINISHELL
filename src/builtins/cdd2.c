/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdd2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:30:19 by gbarone           #+#    #+#             */
/*   Updated: 2024/01/28 20:15:51 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_handle_cd(t_shell *shell, char **args)
{
	if (args && args[1])
	{
		change_directory(shell, args[1]);
	}
	else
	{
		change_directory(shell, NULL);
	}
}

void	change_directory(t_shell *shell, char *path)
{
	if (path == NULL)
	{
		path = getenv("HOME");
	}
	if (chdir(path) == 0)
	{
		update_prompt(shell);
	}
	else
	{
		shell->exit_status = 1;
		perror("cd");
	}
}

void	get_current_directory(char *cwd)
{
	if (getcwd(cwd, PATH_MAX) == NULL)
	{
		perror("getcwd");
		printf("Error: Unable to get the current working directory\n");
		exit(EXIT_FAILURE);
	}
}

char	*build_user_string(void)
{
	char	*user;

	user = ft_strjoin(PURPLE, getenv("USER"));
	if (!user)
	{
		perror("Error: Unable to allocate memory for user\n");
		exit(EXIT_FAILURE);
	}
	return (user);
}

char	*build_user_at_string(char *user)
{
	char	*user_at;

	user_at = ft_strjoin(user, "@ASHellKETCHUM");
	if (!user_at)
	{
		perror("Error: Unable to allocate memory for user_at\n");
		free(user);
		exit(EXIT_FAILURE);
	}
	return (user_at);
}
