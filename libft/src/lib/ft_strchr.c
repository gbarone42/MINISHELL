/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:21:35 by fcorri            #+#    #+#             */
/*   Updated: 2023/01/16 15:58:57 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_init(unsigned long *input, char c)
{
	unsigned long	word;

	word = c | (c << 8);
	word |= (word << 16);
	if (sizeof(unsigned long) > 4)
		word |= ((word << 16) << 16);
	*input = word;
}

static void	ft_checkword(char *src, unsigned long input, char **p_output,
	char **p_zero)
{
	unsigned long	output;
	unsigned long	zero;
	unsigned long	one;
	size_t			index;

	one = 0x01010101L;
	if (sizeof(unsigned long) > 4)
		one |= ((one << 16) << 16);
	zero = (*(unsigned long *)src);
	output = zero ^ input;
	output = ((output - one) & ~output) & (one << 7);
	index = 0;
	if (output != 0)
	{
		while (src[index] != (char) input)
			index++;
		*p_output = src + index;
	}
	zero = ((zero - one) & ~zero) & (one << 7);
	if (zero != 0)
	{
		while (*src)
			src++;
		*p_zero = src;
	}
}

static char	*ft_check_words(char *src, char c)
{
	unsigned long	input;
	char			*output;
	char			*zero;

	ft_init(&input, c);
	output = NULL;
	zero = NULL;
	while (!zero)
	{
		ft_checkword(src, input, &output, &zero);
		if (output && (output <= zero || !zero))
			return (output);
		src += sizeof(unsigned long);
	}
	return (NULL);
}

char	*ft_strchr(const char *src, int c)
{
	char	byte;
	size_t	size;

	size = sizeof(unsigned long);
	while ((size_t) src % size)
	{
		byte = *src++;
		if (byte == (char) c)
			return ((char *)(src - 1));
		if (byte == '\0')
			return (NULL);
	}
	return (ft_check_words((char *)src, c));
}
