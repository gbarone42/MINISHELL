/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 21:53:22 by sdel-gra          #+#    #+#             */
/*   Updated: 2024/01/25 21:53:24 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_isvalid(const char *input)
{
	size_t	length;
	size_t	i;

	length = ft_strlen(input);
	if (input == NULL)
	{
		return (0);
	}
	if (length == 0 || length > INPUT_SIZE)
	{
		return (0);
	}
	i = 0;
	while (input[i])
	{
		if (input[i] < 32 || input[i] == 127)
		{
			return (0);
		}
		i++;
	}
	return (1);
}
