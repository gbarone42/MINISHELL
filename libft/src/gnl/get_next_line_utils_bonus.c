/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:01:10 by fcorri            #+#    #+#             */
/*   Updated: 2023/05/09 17:45:16 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl/get_next_line_bonus.h"

void	*ft_calloc_gnl(size_t nmemb, size_t size)
{
	size_t	output;
	size_t	buffer_size;

	buffer_size = nmemb * size;
	if (buffer_size && (buffer_size < nmemb || buffer_size < size))
		buffer_size = -1;
	output = (size_t) malloc(buffer_size);
	if (!output)
		return (NULL);
	if (!buffer_size)
		return ((void *)output);
	output += (buffer_size - 1);
	buffer_size -= (output % sizeof(unsigned long) + 1);
	while (output % sizeof(unsigned long))
		*(char *)output-- = 0;
	*(char *)output = 0;
	while (buffer_size >= sizeof(unsigned long))
	{
		output -= sizeof(unsigned long);
		*(unsigned long *)output = 0;
		buffer_size -= sizeof(unsigned long);
	}
	while (buffer_size--)
		*(char *)output-- = 0;
	return ((void *)output);
}

static void	ft_check_word(char *src, unsigned long input, char **p_output,
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

	input = c | (c << 8);
	input |= (input << 16);
	if (sizeof(unsigned long) > 4)
		input |= ((input << 16) << 16);
	output = NULL;
	zero = NULL;
	while (!zero)
	{
		ft_check_word(src, input, &output, &zero);
		if (output && (output <= zero || !zero))
			return (output);
		src += sizeof(unsigned long);
	}
	return (NULL);
}

char	*ft_strchr_gnl(char *src, char c)
{
	char	byte;
	size_t	size;

	size = sizeof(unsigned long);
	while ((size_t) src % size)
	{
		byte = *src++;
		if (byte == c)
			return ((char *)(src - 1));
		if (byte == '\0')
			return (NULL);
	}
	return (ft_check_words((char *)src, c));
}
