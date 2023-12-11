/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:01:48 by fcorri            #+#    #+#             */
/*   Updated: 2023/06/22 17:11:24 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*output;
	unsigned int	index;
	char			c;

	output = ft_malloc_soul(sizeof(char) * (ft_strlen(s) + 1));
	if (!output)
		return (NULL);
	index = 0;
	c = s[index];
	while (c)
	{
		output[index] = f(index, c);
		c = s[++index];
	}
	output[index] = '\0';
	return (output);
}
