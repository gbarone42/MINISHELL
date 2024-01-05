/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:27:44 by fcorri            #+#    #+#             */
/*   Updated: 2024/01/05 19:45:40 by filippo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*output;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	output = ft_calloc(len1 + len2 + 1, 1);
	if (!output)
		return (NULL);
	if (len1 + len2 + 1 != 1)
	{
		ft_strlcpy(output, s1, len1 + 1);
		ft_strlcat(output + len1, s2, len2 + 1);
	}
	return (output);
}
