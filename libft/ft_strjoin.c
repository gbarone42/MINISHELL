/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:17:47 by sdel-gra          #+#    #+#             */
/*   Updated: 2022/10/05 18:17:55 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		j;
	int		i;
	char	*out;
	size_t	out_length;

	j = 0;
	i = 0;
	out_length = ft_strlen(s1) + ft_strlen(s2);
	out = malloc((out_length + 1) * sizeof(char));
	if (out)
	{
		while (s1[i])
			out[j++] = s1[i++];
		i = 0;
		while (s2[i])
			out[j++] = s2[i++];
		out[j] = '\0';
		return (out);
	}
	else
		return (NULL);
}
