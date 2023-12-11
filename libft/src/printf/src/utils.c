/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:36:25 by fcorri            #+#    #+#             */
/*   Updated: 2023/09/04 13:20:53 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "utils.h"

int	ft_atoi_decorator(char **p_input, size_t index)
{
	int		output;
	char	*input;

	input = *p_input + index;
	output = ft_atoi(input);
	while (ft_isdigit(*input))
		input++;
	*p_input = input - 1;
	return (output);
}

int	ft_digits(long num, int base)
{
	int	output;

	output = 0;
	if (num < 0)
		num *= -1;
	while (num)
	{
		output++;
		num /= base;
	}
	return (output);
}
