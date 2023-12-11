/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_printer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:37:27 by fcorri            #+#    #+#             */
/*   Updated: 2023/03/22 16:27:26 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "default_printers.h"
#include "../specification.h"
#include "../utils.h"

void	ft_unsigned_build_string_right(void)
{
	size_t	index;
	char	*string;
	size_t	len;
	size_t	sub_len;

	index = 0;
	string = g_printer->as_base.string;
	len = g_printer->as_base.len;
	sub_len = g_printer->as_default_printer.sub_len;
	while (index < len - sub_len)
		string[index++] = '0';
	ft_memcpy(string + index, g_printer->as_default_printer.sub, sub_len);
}

static void	ft_build(char *sub, size_t sub_len, unsigned int u)
{
	while (u)
	{
		sub[--sub_len] = DIGITS_D[u % BASE_D];
		u /= BASE_D;
	}
	while (sub_len)
		sub[--sub_len] = '0';
}

void	ft_new_unsigned_printer(unsigned int u)
{
	int		precision;
	char	*sub;
	size_t	sub_len;

	precision = g_specification->precision;
	if (!u && precision)
		sub_len = 1;
	else
		sub_len = ft_digits(u, BASE_D);
	if (precision > 0 && (size_t)precision > sub_len)
		sub_len = precision;
	sub = ft_malloc_soul(sizeof(char) * sub_len);
	ft_build(sub, sub_len, u);
	ft_new_default_num_printer(sub, sub_len, ft_unsigned_build_string_right);
}
