/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:20:52 by fcorri            #+#    #+#             */
/*   Updated: 2023/03/20 18:35:09 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	uintptr_t		dest;
	unsigned short	remainder;
	unsigned short	size;

	if (n == 0)
		return (NULL);
	dest = (uintptr_t) s;
	size = sizeof(unsigned long);
	if (n >= 4 * size)
	{
		remainder = dest & (size - 1);
		n -= (size - remainder);
		while (size - remainder++)
			if (*((unsigned char *) dest++) == (unsigned char) c)
				return ((void *)(dest - 1));
		n = ft_chr_words(&dest, ft_init_word(c), n);
	}
	while (n--)
	{
		if (*((unsigned char *) dest++) == (unsigned char) c)
			return ((void *)(dest - 1));
	}
	return (NULL);
}
