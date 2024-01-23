/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_printer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:38:39 by fcorri            #+#    #+#             */
/*   Updated: 2023/03/22 16:26:35 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "default_printers.h"
#include "../specification.h"
#include "../utils.h"

static void	ft_build_null(void)
{
	char	*sub;

	sub = ft_strdup("(nil)");
	ft_new_default_printer(sub, 5);
}

static void	ft_build(char *sub, size_t sub_len, uintptr_t a, int space)
{
	while (a)
	{
		sub[--sub_len] = DIGITS_X[a % BASE_X];
		a /= BASE_X;
	}
	while (sub_len - 2 - space)
		sub[--sub_len] = '0';
	sub[--sub_len] = 'x';
	sub[--sub_len] = '0';
	if (space)
		sub[--sub_len] = ' ';
}

void	ft_new_pointer_printer(uintptr_t a)
{
	char	*sub;
	size_t	sub_len;
	int		tmp;

	if (!a)
		return (ft_build_null());
	if (a == (uintptr_t) -1)
		sub_len = sizeof(uintptr_t) * 2;
	else
		sub_len = ft_digits(a, BASE_X);
	tmp = g_specification->precision;
	if (tmp > 0 && (size_t)tmp > sub_len)
		sub_len = tmp;
	tmp = (g_specification->flags >> 3) & 1;
	sub_len += 2 + tmp;
	sub = ft_malloc_soul(sizeof(char) * sub_len);
	ft_build(sub, sub_len, a, tmp);
	ft_new_default_printer(sub, sub_len);
}
