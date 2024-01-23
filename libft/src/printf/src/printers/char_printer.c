/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_printer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:08:32 by fcorri            #+#    #+#             */
/*   Updated: 2023/03/22 16:25:07 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "default_printers.h"

void	ft_new_char_printer(char c)
{
	char	*sub;

	sub = ft_malloc_soul(sizeof(char));
	*sub = c;
	ft_new_default_printer(sub, sizeof(char));
}
