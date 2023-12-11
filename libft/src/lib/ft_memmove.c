/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:21:17 by fcorri            #+#    #+#             */
/*   Updated: 2023/03/20 18:33:33 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *p_dest, const void *p_src, size_t n)
{
	uintptr_t		dest;
	uintptr_t		src;
	unsigned short	remainder;
	unsigned short	size;

	if (!n || p_dest == p_src)
		return (p_dest);
	if (p_src > p_dest)
		return (ft_memcpy(p_dest, p_src, n));
	dest = (uintptr_t) p_dest + n - 1;
	src = (uintptr_t) p_src + n - 1;
	size = sizeof(unsigned long);
	if (n >= 4 * size)
	{
		remainder = src & (size - 1);
		n -= remainder + 1;
		while (remainder--)
			*(unsigned char *)dest-- = *(unsigned char *)src--;
		*(unsigned char *)dest = *(unsigned char *)src;
		n = ft_move_words(&dest, &src, n);
	}
	while (n--)
		*(unsigned char *)dest-- = *(unsigned char *) src--;
	return (p_dest);
}
