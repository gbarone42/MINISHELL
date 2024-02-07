/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:30:57 by gbarone           #+#    #+#             */
/*   Updated: 2024/02/07 14:19:57 by filippo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft__pwd(void)
{
	char	*cd;

	cd = ft_calloc(sizeof(char), PATH_MAX);
	if (getcwd(cd, PATH_MAX))
	{
		printf("%s\n", cd);
		g_exit = 0;
	}
	else
	{
		perror("pwd");
		g_exit = 1;
	}
	free(cd);
}
