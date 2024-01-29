/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memutils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:33:54 by fcorri            #+#    #+#             */
/*   Updated: 2023/03/20 18:34:58 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	ft_init_word(unsigned char c)
{
	unsigned long	word;

	word = c | (c << 8);
	word |= word << 16;
	if (sizeof(unsigned long) > 4)
		word |= ((word << 16) << 16);
	return (word);
}

unsigned long	ft_init_one(void)
{
	unsigned long	one;

	one = 0x01010101;
	if (sizeof(unsigned long) > 4)
		one |= ((one << 16) << 16);
	return (one);
}

void	ft_move_word(uintptr_t dest, uintptr_t src)
{
	unsigned short	right;
	unsigned short	left;
	unsigned short	size;

	size = sizeof(unsigned long);
	right = dest & (size - 1);
	if (right == 0)
		*(unsigned long *)dest = *(unsigned long *)src;
	else
	{
		left = (size - right);
		*(unsigned long *)(dest + left) = (*(unsigned long *)(dest + left)
				>> right * 8) << right * 8
			| *(unsigned long *) src >> left * 8;
		*(unsigned long *)(dest - right) = (*(unsigned long *)(dest - right)
				<< left * 8) >> left * 8
			| *(unsigned long *) src << right * 8;
	}
}

size_t	ft_move_words(uintptr_t *p_dest, uintptr_t *p_src, size_t n)
{
	uintptr_t		dest;
	uintptr_t		src;
	size_t			quozient;
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
		dest -= size;
		src -= size;
		ft_move_word(dest, src);
	}
	*p_dest = (uintptr_t) dest - 1;
	*p_src = (uintptr_t) src - 1;
	return (n);
}

size_t	ft_set_words(uintptr_t *p_dest, unsigned long word, size_t n)
{
	unsigned long	*dest;
	size_t			quozient;
	unsigned short	size;

	dest = (unsigned long *) *p_dest;
	size = sizeof(unsigned long);
	quozient = n / size;
	if (!quozient)
		return (n);
	n -= quozient * size;
	while (quozient--)
		*dest++ = word;
	*p_dest = (uintptr_t) dest;
	return (n);
}
