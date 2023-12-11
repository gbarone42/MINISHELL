/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percentage_printer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:08:32 by fcorri            #+#    #+#             */
/*   Updated: 2023/03/22 16:26:24 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "default_printers.h"

void	ft_percentage_init_string_len(void)
{
	g_printer->as_base.len = 1;
	g_printer->as_base.string = ft_malloc_soul(sizeof(char));
}

void	ft_new_percentage_printer(char c)
{
	char	*sub;

	sub = ft_malloc_soul(sizeof(char));
	*sub = c;
	ft_new_default_printer(sub, sizeof(char));
	g_printer->as_default_printer.ft_init_string_len
		= ft_percentage_init_string_len;
}
