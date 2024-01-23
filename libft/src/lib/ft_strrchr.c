/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:22:12 by fcorri            #+#    #+#             */
/*   Updated: 2022/10/22 16:47:47 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char		read;
	const char	*last;
	char		input;

	read = *s;
	last = NULL;
	input = c;
	while (read != '\0')
	{
		if (read == input)
			last = s;
		read = *++s;
	}
	if (read == input)
		last = s;
	return ((char *) last);
}
