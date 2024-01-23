/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_hex_printer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 19:54:36 by fcorri            #+#    #+#             */
/*   Updated: 2023/03/22 16:26:03 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "default_printers.h"

void	ft_new_max_hex_printer(unsigned int x)
{
	ft_new_hex_printer(x, 'X', DIGITS_XX);
}
