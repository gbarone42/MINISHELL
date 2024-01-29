/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:56:06 by fcorri            #+#    #+#             */
/*   Updated: 2022/10/19 18:23:56 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	index;

	if (size != 0)
	{
		index = -1;
		while (++index < size - 1 && src[index])
			dst[index] = src[index];
		dst[index] = 0;
	}
	return (ft_strlen(src));
}
