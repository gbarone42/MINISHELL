/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specification.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:17:31 by fcorri            #+#    #+#             */
/*   Updated: 2023/04/01 19:11:16 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPECIFICATION_H
# define SPECIFICATION_H

typedef struct printing_specification
{
	int	flags;
	int	width;
	int	precision;
}	t_printing_specification;

extern t_printing_specification	*g_specification;

void	ft_reset_specification(void);

#endif
