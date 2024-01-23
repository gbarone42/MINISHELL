/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_soul.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 19:45:50 by fcorri            #+#    #+#             */
/*   Updated: 2023/03/20 18:37:33 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_malloc_soul(size_t size)
{
	if (size % sizeof(unsigned long) == 0)
		return (malloc(size));
	else
		return (malloc(sizeof(unsigned long)
				* (size / sizeof(unsigned long) + 1)));
}
