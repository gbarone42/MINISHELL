/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:01:44 by fcorri            #+#    #+#             */
/*   Updated: 2024/01/24 13:58:19 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_remove_initial_spaces(const char **str)
{
	char	c;

	c = **str;
	while (c == ' '
		|| c == '\f'
		|| c == '\n'
		|| c == '\r'
		|| c == '\t'
		|| c == '\v')
	{
		*str += 1;
		c = **str;
	}
}

static int	ft_is_sign(const char **ptr)
{
	char	c;

	c = **ptr;
	if (c != '-' && c != '+')
		return (1);
	*ptr += 1;
	if (c == '-')
		return (-1);
	return (1);
}

static int	ft_overflow(int sign)
{
	if (sign > 0)
		return (-1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	long	output;
	long	temp;
	int		sign;
	char	digit;

	output = 0;
	ft_remove_initial_spaces(&nptr);
	sign = ft_is_sign(&nptr);
	digit = *nptr;
	while (ft_isdigit(digit))
	{
		temp = output * 10 + (digit - '0');
		if (temp < output)
			return (ft_overflow(sign));
		output = temp;
		digit = *++nptr;
	}
	output *= sign;
	return (output);
}
