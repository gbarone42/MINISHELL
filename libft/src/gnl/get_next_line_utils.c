/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:01:10 by fcorri            #+#    #+#             */
/*   Updated: 2023/05/09 17:44:37 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl/get_next_line.h"

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

static void	ft_check_word(void *src, unsigned long input, char **p_output,
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
		while (*(char *)(src + index) != (char) input)
			index++;
		*p_output = (char *)(src + index);
	}
	zero = ((zero - one) & ~zero) & (one << 7);
	if (zero != 0)
	{
		while (*(char *)src)
			src++;
		*p_zero = (char *)src;
	}
}

static char	*ft_check_words(size_t src, char c)
{
	unsigned long	input;
	char			*output;
	char			*zero;
	size_t			size;

	input = c | (c << 8);
	input |= (input << 16);
	if (sizeof(unsigned long) > 4)
		input |= ((input << 16) << 16);
	output = NULL;
	zero = NULL;
	size = sizeof(unsigned long);
	while (!zero)
	{
		ft_check_word((void *)src, input, &output, &zero);
		if (output && (output <= zero || !zero))
			return (output);
		src += size;
	}
	return (NULL);
}

char	*ft_strchr_gnl(char *p_src, char c)
{
	char	byte;
	size_t	size;
	size_t	src;

	src = (size_t)p_src;
	size = sizeof(unsigned long);
	while (src % size)
	{
		byte = *(char *)src;
		if (byte == c)
			return ((char *)src);
		if (byte == '\0')
			return (NULL);
		src++;
	}
	return (ft_check_words(src, c));
}
