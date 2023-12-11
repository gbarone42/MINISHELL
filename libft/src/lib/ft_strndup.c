/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 19:45:26 by fcorri            #+#    #+#             */
/*   Updated: 2023/03/12 19:45:29 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*output;

	output = ft_malloc_soul(n + 1);
	if (!output)
		return (NULL);
	ft_memcpy(output, s, n);
	output[n] = '\0';
	return (output);
}
