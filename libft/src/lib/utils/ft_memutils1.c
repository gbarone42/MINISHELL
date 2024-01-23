/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memutils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:35:37 by fcorri            #+#    #+#             */
/*   Updated: 2023/03/20 18:36:15 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	ft_read_word(uintptr_t src)
{
	unsigned short	right;
	unsigned short	left;
	unsigned short	size;

	size = sizeof(unsigned long);
	right = src & (size - 1);
	if (right == 0)
		return (*(unsigned long *)src);
	left = size - right;
	return (
		*(unsigned long *)(src - right) >> (right * 8)
		| *(unsigned long *)(src + left) << (left * 8)
	);
}

size_t	ft_chr_words(uintptr_t *p_dest, unsigned long input, size_t n)
{
	uintptr_t		dest;
	unsigned long	word;
	unsigned long	one;
	size_t			quozient;
	unsigned short	size;

	dest = *p_dest;
	one = 0x01010101;
	if (sizeof(unsigned long) > 4)
		one |= ((one << 16) << 16);
	size = sizeof(unsigned long);
	quozient = n / size;
	while (quozient--)
	{
		word = *((unsigned long *) dest) ^ input;
		word = ((word - one) & ~word) & (one << 7);
		if (word != 0)
			break ;
		n -= size;
		dest += size;
	}
	*p_dest = dest;
	return (n);
}

int	ft_cmp_bytes(uintptr_t *p_p1, uintptr_t *p_p2, size_t *p_n)
{
	uintptr_t		p1;
	uintptr_t		p2;
	unsigned short	remainder;
	unsigned short	size;

	p1 = *p_p1;
	p2 = *p_p2;
	size = sizeof(unsigned long);
	remainder = p1 & (size - 1);
	*p_n -= (size - remainder);
	while (size - remainder && *(unsigned char *)p1 == *(unsigned char *)p2)
	{
		remainder++;
		p1++;
		p2++;
	}
	*p_p1 = p1;
	*p_p2 = p2;
	return (size - remainder);
}

int	ft_cmp_words(uintptr_t *p_p1, uintptr_t *p_p2, size_t *p_n)
{
	uintptr_t		p1;
	uintptr_t		p2;
	size_t			quozient;
	unsigned short	size;

	p1 = *p_p1;
	p2 = *p_p2;
	size = sizeof(unsigned long);
	quozient = *p_n / size;
	*p_n -= quozient * size;
	while (quozient--)
	{
		if (*(unsigned long *)p1 != ft_read_word(p2))
		{
			*p_p1 = p1;
			*p_p2 = p2;
			return (ft_cmp_bytes(p_p1, p_p2, p_n));
		}
		p1 += size;
		p2 += size;
	}
	*p_p1 = p1;
	*p_p2 = p2;
	return (0);
}

size_t	ft_cpy_words(uintptr_t *p_dest, uintptr_t *p_src, size_t n)
{
	uintptr_t		dest;
	uintptr_t		src;
	unsigned short	quozient;
	unsigned short	size;

	dest = *p_dest;
	src = *p_src;
	size = sizeof(unsigned long);
	quozient = n / size;
	if (!quozient)
		return (n);
	n -= quozient * size;
	while (quozient--)
	{
		*(unsigned long *)dest = ft_read_word(src);
		dest += size;
		src += size;
	}
	*p_dest = dest;
	*p_src = src;
	return (n);
}
