/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:38:12 by fcorri            #+#    #+#             */
/*   Updated: 2023/04/01 20:03:11 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "default_printers.h"

int	ft_super_final_write_n_free(void)
{
	int		output;
	char	*string;

	string = g_printer->as_base.string;
	output = write(1, string, g_printer->as_base.len);
	free(string);
	return (output);
}
