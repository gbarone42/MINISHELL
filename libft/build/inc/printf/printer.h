/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:16:53 by fcorri            #+#    #+#             */
/*   Updated: 2023/03/22 20:04:46 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTER_H
# define PRINTER_H

typedef struct printer
{
	int		(*ft_print)(void);
	char	*string;
	size_t	len;
}	t_printer;

int		ft_super_final_write_n_free(void);

#endif
