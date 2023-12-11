/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:19:52 by fcorri            #+#    #+#             */
/*   Updated: 2023/08/21 19:01:47 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*node;

	if (!lst || !del)
		return ;
	node = *lst;
	tmp = node->next;
	del(node->content);
	free(node);
	*lst = tmp;
}
