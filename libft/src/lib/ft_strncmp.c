/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:22:06 by fcorri            #+#    #+#             */
/*   Updated: 2022/10/20 15:47:51 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (n == 0)
		return (0);
	while (n && s1[i] && s1[i] == s2[j])
	{
		n--;
		i++;
		j++;
	}
	if (n == 0)
		return ((unsigned char) s1[i - 1] - (unsigned char) s2[j - 1]);
	return ((unsigned char) s1[i] - (unsigned char) s2[j]);
}
