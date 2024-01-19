/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:08:07 by sdel-gra          #+#    #+#             */
/*   Updated: 2023/10/15 17:04:48 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (ft_islower(c))
		return (c - 32);
	return (c);
}

char	*ft_toupper_str(char *s)
{
	int		i;
	char	c;

	i = 0;
	while (s && s[i])
	{
		c = ft_toupper(s[i]);
		s[i] = c;
		i++;
	}
	return (s);
}
