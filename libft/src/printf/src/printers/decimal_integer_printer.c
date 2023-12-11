/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_integer_printer.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:37:11 by fcorri            #+#    #+#             */
/*   Updated: 2023/03/22 16:25:16 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "default_printers.h"
#include "../specification.h"
#include "../utils.h"

void	ft_di_build_string_right(void)
{
	size_t	index;
	char	*string;
	size_t	len;
	size_t	sub_len;
	char	first;

	index = 0;
	string = g_printer->as_base.string;
	len = g_printer->as_base.len;
	sub_len = g_printer->as_default_printer.sub_len;
	first = *(g_printer->as_default_printer.sub);
	if (first == '+' || first == '-' || first == ' ')
	{
		string[index++] = first;
		len++;
		g_printer->as_default_printer.sub++;
	}
	while (index < len - sub_len)
		string[index++] = '0';
	ft_memcpy(string + index, g_printer->as_default_printer.sub, sub_len);
	if (first == '+' || first == '-' || first == ' ')
		g_printer->as_default_printer.sub--;
}

static void	ft_build(char *sub, size_t sub_len, int di, int flags)
{
	long	di_copy;

	di_copy = di;
	if (di < 0)
		di_copy *= -1;
	while (di_copy)
	{
		sub[--sub_len] = DIGITS_D[di_copy % BASE_D];
		di_copy /= BASE_D;
	}
	if (di < 0 || ((flags >> 3) & 1) || ((flags >> 4) & 1))
		di_copy = 1;
	while (sub_len - di_copy)
		sub[--sub_len] = '0';
	if (di >= 0)
	{
		if ((flags >> 4) & 1)
			sub[--sub_len] = '+';
		else if ((flags >> 3) & 1)
			sub[--sub_len] = ' ';
	}
	else
		sub[--sub_len] = '-';
}

void	ft_new_decimal_integer_printer(int di)
{
	int		tmp;
	char	*sub;
	size_t	sub_len;

	tmp = g_specification->precision;
	if (!di && tmp)
		sub_len = 1;
	else
		sub_len = ft_digits(di, BASE_D);
	if (tmp > 0 && (size_t)tmp > sub_len)
		sub_len = tmp;
	tmp = g_specification->flags;
	if (di < 0 || ((tmp >> 3) & 1) || ((tmp >> 4) & 1))
		sub_len += 1;
	sub = ft_malloc_soul(sizeof(char) * sub_len);
	ft_build(sub, sub_len, di, tmp);
	ft_new_default_num_printer(sub, sub_len, ft_di_build_string_right);
}
