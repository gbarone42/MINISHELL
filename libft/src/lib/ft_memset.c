/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:14:03 by fcorri            #+#    #+#             */
/*   Updated: 2023/03/20 18:35:21 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *p_dest, int c, size_t n)
{
	uintptr_t		dest;
	unsigned short	remainder;
	unsigned short	size;

	if (!n)
		return (p_dest);
	dest = (uintptr_t) p_dest;
	size = sizeof(unsigned long);
	if (n >= 4 * size)
	{
		remainder = dest & (size - 1);
		n -= (size - remainder);
		while (size - remainder++)
			*(unsigned char *)dest++ = (unsigned char) c;
		n = ft_set_words(&dest, ft_init_word(c), n);
	}
	while (n--)
		*(unsigned char *)dest++ = (unsigned char) c;
	return (p_dest);
}
