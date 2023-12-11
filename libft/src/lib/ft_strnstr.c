/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:27:03 by fcorri            #+#    #+#             */
/*   Updated: 2022/10/18 18:19:00 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*little)
		return ((char *) big);
	i = 0;
	j = 0;
	while (i < len && big[i])
	{
		if (big[i] == little[j])
		{
			if (little[++j] == '\0')
				return ((char *) big + i - j + 1);
		}
		else
		{
			i -= j;
			j = 0;
		}
		i++;
	}
	return (NULL);
}
