/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:30:19 by gbarone           #+#    #+#             */
/*   Updated: 2024/02/07 14:22:09 by filippo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft__cd(char **args)
{
	char	*path;

	path = args[1];
	if (path == NULL)
		path = getenv("HOME");
	if (chdir(path))
	{
		g_exit = 1;
		perror("cd");
	}
	else
		g_exit = 0;
}
