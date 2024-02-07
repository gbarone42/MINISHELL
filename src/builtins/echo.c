/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:30:29 by gbarone           #+#    #+#             */
/*   Updated: 2024/02/07 14:20:19 by filippo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft__echo(char **args)
{
	int		index;
	int		n;
	char	*arg;

	arg = args[1];
	if (!arg)
		printf("\n");
	else
	{
		index = 1;
		n = !ft_strcmp("-n", arg);
		if (n)
			index++;
		arg = args[index++];
		while (arg)
		{
			printf("%s", arg);
			if (args[index])
				printf(" ");
			arg = args[index++];
		}
		if (!n)
			printf("\n");
	}
	g_exit = 0;
}
