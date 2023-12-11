/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_printer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:41:32 by fcorri            #+#    #+#             */
/*   Updated: 2023/09/04 13:19:17 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "default_printers.h"
#include "../specification.h"

static void	ft_default_init_string_len(void)
{
	size_t	len;
	int		width;

	len = g_printer->as_default_printer.sub_len;
	width = g_specification->width;
	if ((size_t)width > len)
		len = width;
	g_printer->as_base.len = len;
	g_printer->as_base.string = ft_malloc_soul(sizeof(char) * len);
}

static void	ft_build_string_left(void)
{
	size_t	index;
	char	*string;
	size_t	len;

	index = g_printer->as_default_printer.sub_len;
	string = g_printer->as_base.string;
	len = g_printer->as_base.len;
	ft_memcpy(string, g_printer->as_default_printer.sub, index);
	while (index < len)
		string[index++] = ' ';
}

static void	ft_default_build_string_right(void)
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
		string[index++] = ' ';
	ft_memcpy(string + index, g_printer->as_default_printer.sub, sub_len);
}

int	ft_default_template_print(void)
{
	int	output;

	g_printer->as_default_printer.ft_init_string_len();
	if (g_specification->flags & (1 << 2))
		ft_build_string_left();
	else
		g_printer->as_default_printer.ft_build_string_right();
	output = ft_super_final_write_n_free();
	free(g_printer->as_default_printer.sub);
	return (output);
}

void	ft_new_default_printer(char *sub, size_t sub_len)
{
	g_printer->as_base.ft_print = ft_default_template_print;
	g_printer->as_default_printer.ft_init_string_len
		= ft_default_init_string_len;
	g_printer->as_default_printer.ft_build_string_right
		= ft_default_build_string_right;
	g_printer->as_default_printer.sub = sub;
	g_printer->as_default_printer.sub_len = sub_len;
}
