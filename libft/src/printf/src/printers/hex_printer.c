/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:40:56 by fcorri            #+#    #+#             */
/*   Updated: 2023/03/23 16:40:20 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "default_printers.h"
#include "../specification.h"
#include "../utils.h"

void	ft_hex_build_string_right(void)
{
	size_t	index;
	char	*string;
	size_t	len;
	size_t	sub_len;
	char	second;

	index = 0;
	string = g_printer->as_base.string;
	len = g_printer->as_base.len;
	sub_len = g_printer->as_default_printer.sub_len;
	second = *(g_printer->as_default_printer.sub + 1);
	if (len != sub_len && second == g_printer->as_hex_printer.ch)
	{
		string[index++] = '0';
		string[index++] = g_printer->as_hex_printer.ch;
		len += 2;
		g_printer->as_default_printer.sub += 2;
	}
	while (index < len - sub_len)
		string[index++] = '0';
	ft_memcpy(string + index, g_printer->as_default_printer.sub, sub_len);
	if (len != sub_len && second == g_printer->as_hex_printer.ch)
		g_printer->as_default_printer.sub -= 2;
}

static void	ft_build(char *sub, size_t sub_len, unsigned int x, char *base)
{
	int	tmp;

	if (!sub_len)
		return ;
	tmp = 0;
	if (!x)
		sub[--sub_len] = '0';
	else
	{
		while (x)
		{
			sub[--sub_len] = base[x % BASE_X];
			x /= BASE_X;
		}
		if (g_specification->flags & 1)
		{
			tmp = 2;
			sub[0] = '0';
			sub[1] = g_printer->as_hex_printer.ch;
		}
	}
	while (sub_len - tmp)
		sub[--sub_len] = '0';
}

void	ft_new_hex_printer(unsigned int x, char ch, char *base)
{
	int		precision;
	char	*sub;
	size_t	sub_len;

	precision = g_specification->precision;
	if (!x && precision)
		sub_len = 1;
	else
		sub_len = ft_digits(x, 16);
	if (precision > 0 && (size_t)precision > sub_len)
		sub_len = precision;
	if (x && (g_specification->flags & 1))
		sub_len += 2;
	sub = ft_malloc_soul(sizeof(char) * sub_len);
	if (sub_len == 1)
		sub[sub_len] = '\0';
	ft_new_default_num_printer(sub, sub_len, ft_hex_build_string_right);
	g_printer->as_hex_printer.ch = ch;
	ft_build(sub, sub_len, x, base);
}
