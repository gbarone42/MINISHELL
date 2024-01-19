/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:25:20 by sdel-gra          #+#    #+#             */
/*   Updated: 2022/10/11 16:36:42 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_search_min(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			j;

	j = 0;
	i = 0;
	while (i < start && s[i])
		i++;
	while (j < len && s[i])
	{
		j++;
		i++;
	}
	return (j);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*out;
	size_t	i;
	size_t	slen;

	i = 0;
	slen = ft_search_min(s, start, len);
	out = (char *) malloc((slen + 1) * sizeof(char));
	if (!out || !s)
		return (out);
	while (i < slen && s[start])
	{
		out[i] = s[start];
		i++;
		start++;
	}
	out[i] = '\0';
	return (out);
}
