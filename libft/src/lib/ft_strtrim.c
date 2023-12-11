/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:39:14 by fcorri            #+#    #+#             */
/*   Updated: 2022/10/22 18:53:47 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	len = ft_strlen(s1);
	if (len == 0)
		return (ft_strdup(s1));
	while (ft_strchr(set, s1[len - 1]))
		len--;
	while (ft_strchr(set, s1[start++]))
		len--;
	return (ft_substr(s1, start - 1, len));
}
