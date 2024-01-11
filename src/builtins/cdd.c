/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:30:19 by gbarone           #+#    #+#             */
/*   Updated: 2024/01/10 17:17:09 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_handle_cd(t_shell *shell, char **args)
{
	printf("Input for 'cd': %s\n", shell->input);
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
		printf("Changed to directory: %s\n", path);
		update_prompt(shell);
	}
	else
	{
		perror("cd");
	}
}

void	free_memory(char *usr, char *usr_at, \
	char *useratcolon, char *promsufx)
{
	free(usr);
	free(usr_at);
	free(useratcolon);
	free(promsufx);
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

char*	build_user_string(void)
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

char*	build_user_at_string(char *user)
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

char*	build_user_at_colon_string(char *user_at)
{
	char	*user_at_colon;

	user_at_colon = ft_strjoin(user_at, ":");
	if (!user_at_colon)
	{
		perror("Error: Unable to allocate memory for user_at_colon\n");
		free_memory(NULL, user_at, NULL, NULL);
		exit(EXIT_FAILURE);
	}
	return (user_at_colon);
}

char*	build_prompt_suffix(void)
{
	char	*prompt_suffix;

	prompt_suffix = ft_strjoin(CLR_RMV, "$ ");
	if (!prompt_suffix)
	{
		perror("Error: Unable to allocate memory for prompt_suffix\n");
		exit(EXIT_FAILURE);
	}
	return (prompt_suffix);
}

void	create_prompt(t_shell *shell, char *user_at_colon, \
	char *cwd, char *prompt_suffix)
{
	shell->prompt = (char *)malloc(strlen(user_at_colon) +\
					strlen(cwd) + strlen(prompt_suffix) + 1);
	if (!shell->prompt)
	{
		perror("Error: Unable to allocate memory for the new prompt\n");
		exit(EXIT_FAILURE);
	}
	strcpy(shell->prompt, user_at_colon);
	strcat(shell->prompt, cwd);
	strcat(shell->prompt, prompt_suffix);
	printf("Updated prompt: %s\n", shell->prompt);
}

void	update_prompt(t_shell *shell)
{
	char	cwd[PATH_MAX];
	char	*user;
	char	*user_at;
	char	*user_at_colon;
	char	*prompt_suffix;

	get_current_directory(cwd);
	free(shell->prompt);
	user = build_user_string();
	user_at = build_user_at_string(user);
	user_at_colon = build_user_at_colon_string(user_at);
	prompt_suffix = build_prompt_suffix();
	create_prompt(shell, user_at_colon, cwd, prompt_suffix);
	free_memory(user, user_at, user_at_colon, prompt_suffix);
}
