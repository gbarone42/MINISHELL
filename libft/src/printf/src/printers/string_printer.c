/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_printer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:08:38 by fcorri            #+#    #+#             */
/*   Updated: 2023/03/22 16:27:18 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "default_printers.h"
#include "../specification.h"

void	ft_new_string_printer(char *s)
{
	char	*sub;
	size_t	sub_len;
	int		precision;

	sub = s;
	sub_len = ft_strlen(s);
	precision = g_specification->precision;
	if (!precision)
	{
		sub = "";
		sub_len = 0;
	}
	else if (!s)
	{
		sub = "(null)";
		if (0 < precision && precision < 6)
			sub_len = 0;
		else
			sub_len = 6;
	}
	else if ((size_t)precision < sub_len)
		sub_len = precision;
	sub = ft_strndup(sub, sub_len);
	ft_new_default_printer(sub, sub_len);
}
