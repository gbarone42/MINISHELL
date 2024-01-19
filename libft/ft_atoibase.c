/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoibase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:52:01 by sdel-gra          #+#    #+#             */
/*   Updated: 2023/10/15 17:04:26 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoib(char *s, char *b, int base_len)
{
	int	out;
	int	sign;
	int	i;

	i = 0;
	out = 0;
	sign = 1;
	while (ft_iswhitespace(s[i]))
		i++;
	if (s[i] == '+' || s[i] == '-')
		if (s[i++] == '-')
			sign = -1;
	while (s[i] && ft_strchr_i(b, ft_toupper(s[i])) != -1)
	{
		out = out * base_len;
		out = out + ft_strchr_i(b, ft_toupper(s[i]));
		i++;
	}
	return (out * sign);
}
