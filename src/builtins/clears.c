/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clears.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:30:27 by gbarone           #+#    #+#             */
/*   Updated: 2024/01/10 17:17:55 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	clear_screen(void)
{
	write(STDOUT_FILENO, "\033[H\033[J", 7);
}
