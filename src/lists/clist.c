/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:52:44 by filippo           #+#    #+#             */
/*   Updated: 2024/02/05 20:42:24 by filippo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_p.h"

t_clist	*ft_new_clnode(void)
{
	t_clist	*output;

	output = ft_calloc(1, sizeof(*output));
	if (!output)
		return (NULL);
	output->args = NULL;
	output->in = -1;
	output->out = -1;
	output->redirections = NULL;
	output->next = NULL;
	return (output);
}

t_clist	*ft_free_clist(t_clist *head)
{
	int		file;
	t_clist	*tmp;

	while (head)
	{
		ft_free_char_p(head->args);
		file = head->in;
		if (file)
			close_fd(file);
		file = head->out;
		if (file)
			close_fd(file);
		ft_free_rlist(head->redirections);
		tmp = head;
		head = head->next;
		free(tmp);
	}
	return (NULL);
}
