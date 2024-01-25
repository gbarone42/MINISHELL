/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:40:37 by sdel-gra          #+#    #+#             */
/*   Updated: 2024/01/24 21:09:29 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_free_char(char **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
	return (*ptr);
}

void	ft_free_tutto(t_shell *px, char ***cmd, char **paths)
{
	int	i;

	i = 0;
	ft_free_char(paths);
	while (px->paths[i])
	{
		ft_free_char(px->paths + i);
		i++;
	}
	i = 0;
	while ((*cmd)[i])
	{
		ft_free_char((*cmd) + i);
		i++;
	}
	if (px->paths)
		free(px->paths);
	if (*cmd)
		free(*cmd);
}
