/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:27:13 by fcorri            #+#    #+#             */
/*   Updated: 2022/10/20 16:26:22 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		d_len;
	size_t		s_len;
	size_t		index;

	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	index = -1;
	while (size > d_len + ++index + 1 && src[index])
		dst[d_len + index] = src[index];
	if (size < d_len + index)
		return (size + s_len);
	dst[d_len + index] = '\0';
	return (d_len + s_len);
}
