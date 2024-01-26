/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:30:29 by gbarone           #+#    #+#             */
/*   Updated: 2024/01/26 18:11:06 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	echo_no_arguments(void)
{
	printf("\n");
}

void	echo_with_arguments(char **args)
{
	int	i;

	i = 1;
	while (args[i])
	{
		printf("%s", args[i]);
		if (args[i + 1] != NULL)
		{
			printf(" ");
		}
		i++;
	}
	printf("\n");
}

void	echo_with_n_argument(char **args)
{
	int	i;

	i = 1;
	args++;
	while (args[i])
	{
		printf("%s", args[i]);
		if (args[i + 1] != NULL)
		{
			printf(" ");
		}
		i++;
	}
}

void	handle_echo(char **args)
{
	if (args[1] == NULL)
	{
		echo_no_arguments();
	}
	else if (ft_strcmp(args[1], "-n") == 0)
	{
		echo_with_n_argument(args);
	}
	else
	{
		echo_with_arguments(args);
	}
}
