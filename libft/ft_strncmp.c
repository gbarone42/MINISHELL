/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 20:14:26 by sdel-gra          #+#    #+#             */
/*   Updated: 2022/10/11 20:14:27 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		dif;

	i = 0;
	while (i < n && (*(s1 + i) || *(s2 + i)))
	{
		dif = *((unsigned char *)s1 + i) - *((unsigned char *)s2 + i);
		if (dif)
			return (dif);
		i++;
	}
	return (0);
}
