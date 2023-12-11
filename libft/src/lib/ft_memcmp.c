/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:21:08 by fcorri            #+#    #+#             */
/*   Updated: 2022/10/20 16:42:44 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	uintptr_t	p1;
	uintptr_t	p2;
	short		output;

	if (n == 0)
		return (0);
	p1 = (uintptr_t) s1;
	p2 = (uintptr_t) s2;
	if (n >= 4 * sizeof(unsigned long)
		&& (ft_cmp_bytes(&p1, &p2, &n) || ft_cmp_words(&p1, &p2, &n)))
		return (*(unsigned char *)p1 - *(unsigned char *)p2);
	while (n--)
	{
		output = *(unsigned char *)p1++ - *(unsigned char *)p2++;
		if (output != 0)
			return (output);
	}
	return (0);
}
