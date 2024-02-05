/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   historyh.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:30:48 by gbarone           #+#    #+#             */
/*   Updated: 2024/02/05 14:16:23 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_to_history(t_history *history, char	*command)
{
	int	i;

	i = -1;
	add_history(command);
	if (history->count < HISTORY_SIZE)
		history->entries[history->count++] = ft_strdup(command);
	else
	{
		free(history->entries[0]);
		while (++i < history->count - 1)
			history->entries[i] = history->entries[i + 1];
		history->entries[history->count - 1] = ft_strdup(command);
	}
	free(command);
}
