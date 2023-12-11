/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specification.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:36:05 by fcorri            #+#    #+#             */
/*   Updated: 2023/04/01 19:07:27 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specification.h"

void	ft_reset_specification(void)
{
	g_specification->flags = 0;
	g_specification->width = 0;
	g_specification->precision = -1;
}
