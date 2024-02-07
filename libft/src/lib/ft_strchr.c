/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:21:35 by fcorri            #+#    #+#             */
/*   Updated: 2024/02/07 16:04:14 by filippo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	tmp;

	tmp = *s++;
	while (tmp != (char) c)
	{
		if (!tmp)
			return (NULL);
		tmp = *s++;
	}
	return ((char *) s - 1);
}
