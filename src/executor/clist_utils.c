/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clist_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:53:55 by sdel-gra          #+#    #+#             */
/*   Updated: 2024/01/24 13:59:25 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_clist	*ft_last_clist(t_clist *cmd)
{
	t_clist	*next_lst;

	next_lst = cmd;
	if (next_lst != NULL)
		while (next_lst->next != NULL)
			next_lst = next_lst->next;
	return (next_lst);
}
