/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_num_printer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:42:05 by fcorri            #+#    #+#             */
/*   Updated: 2023/03/22 16:25:31 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "default_printers.h"
#include "../specification.h"

void	ft_new_default_num_printer(char *sub, size_t sub_len,
	void (*ft_num_build_string_right)(void))
{
	ft_new_default_printer(sub, sub_len);
	if (((g_specification->flags >> 1) & 1) && g_specification->precision == -1)
		g_printer->as_default_printer.ft_build_string_right
			= ft_num_build_string_right;
}
