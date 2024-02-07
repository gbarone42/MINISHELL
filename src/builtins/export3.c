/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:30:19 by gbarone           #+#    #+#             */
/*   Updated: 2024/02/07 16:08:54 by filippo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_arg(char *arg, char **name, char **value)
{
	*name = ft_strtok(arg, '=');
	*value = ft_strtok(NULL, '=');
}

void	handle_name_only(t_shell *shell, char *name)
{
	char	*new_name;

	new_name = ft_strjoin(name, "=");
	if (new_name != NULL)
	{
		if (contains_invalid_characters(new_name))
			printf("Invalid variable new_name: %s\n", new_name);
		else
			add_envv_variable(shell, new_name, "");
		free(new_name);
	}
	else
		printf("Invalid export syntax: %s\n", name);
}

void	validate_and_add_env_variable(t_shell *shell, char *name, char *value)
{
	if (contains_invalid_characters(name))
		printf("Invalid variable name: %s\n", name);
	else
		add_env_variable(shell, name, value);
}

void	validate_and_add_envv_variable(t_shell *shell, char *name)
{
	if (contains_invalid_characters(name))
		printf("Invalid variable name: %s\n", name);
	else
		add_envv_variable(shell, name, "");
}

void	process_env_variable(t_shell *shell, char *arg)
{
	char	*name;
	char	*value;

	if (control_exist(&arg, shell) == 1)
		return ;
	parse_arg(arg, &name, &value);
	if (value == NULL && strchr(shell->input, '='))
		handle_name_only(shell, name);
	else if (name != NULL)
	{
		if (value == NULL)
			validate_and_add_envv_variable(shell, name);
		else
			validate_and_add_env_variable(shell, name, value);
	}
	else
		printf("Invalid export syntax: %s\n", arg);
}
