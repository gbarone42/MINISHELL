/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   historyh.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:30:48 by gbarone           #+#    #+#             */
/*   Updated: 2024/01/10 16:33:22 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void add_to_history(t_history *history, char* command)
{
	add_history(command);
	if (history->count < HISTORY_SIZE)
	{
		history->entries[history->count++] = strdup(command);
	}
	else
	{
		free(history->entries[0]);
		for (int i = 0; i < history->count - 1; ++i) {
			history->entries[i] = history->entries[i + 1];
		}
		history->entries[history->count - 1] = strdup(command);
	}
	 free(command);
} 