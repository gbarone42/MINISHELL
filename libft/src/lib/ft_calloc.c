/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:32:46 by fcorri            #+#    #+#             */
/*   Updated: 2023/08/05 17:51:02 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	buffer_len;
	size_t	word_size;
	char	*output;

	buffer_len = nmemb * size;
	if (buffer_len < nmemb || buffer_len < size)
		buffer_len = 0;
	output = ft_malloc_soul(buffer_len);
	if (!output)
		return (NULL);
	word_size = sizeof(unsigned long);
	if (buffer_len % word_size != 0)
		buffer_len = word_size * (buffer_len / word_size + 1);
	ft_memset(output, 0, buffer_len);
	return (output);
}
