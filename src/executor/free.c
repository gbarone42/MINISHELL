/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:40:37 by sdel-gra          #+#    #+#             */
/*   Updated: 2024/01/19 16:40:38 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*ft_free_char(char **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
	return (*ptr);
}

void	ft_free_tutto(t_mshell *px, char ***cmd, char **cmd_path)
{
	int	i;

	i = 0;
	ft_free_char(cmd_path);
	while (px->cmd_path[i])
	{
		ft_free_char(px->cmd_path + i);
		i++;
	}
	i = 0;
	while ((*cmd)[i])
	{
		ft_free_char((*cmd) + i);
		i++;
	}
	if (px->cmd_path)
		free(px->cmd_path);
	if (*cmd)
		free(*cmd);
}
