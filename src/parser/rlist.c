/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rlist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:56:34 by filippo           #+#    #+#             */
/*   Updated: 2024/01/23 15:17:55 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_rlist	*ft_new_rlnode(int type, char *filename)
{
	t_rlist	*output;

	output = malloc(sizeof(*output));
	if (!output)
		return (NULL);
	output->type = type;
	output->filename = filename;
	output->next = NULL;
	return (output);
}

void	ft_app_rlist(t_rlist **p_first, int type, char *filename)
{
	t_rlist	*first;
	t_rlist	*new;

	new = ft_new_rlnode(type, filename);
	if (!new)
// DOMANDA: cosa facciamo?
		ft_free_and_err(ft_ret_shell(NULL), "FT_NEW_ILNODE", errno = ENOMEM);
	first = *p_first;
	if (!first)
		*p_first = new;
	else
	{
		while (first->next)
			first = first->next;
		first->next = new;
	}
}

void	ft_free_rlist(t_rlist *head)
{
	t_rlist	*tmp;

	while (head)
	{
		free(head->filename);
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

void	ft_print_rlist(t_rlist *head)
{
	int		nredirections;

	nredirections = 0;
	while (head)
	{
		printf("\ttype: %d\n\tfilename: %s\n", head->type, head->filename);
		head = head->next;
		nredirections++;
	}
}
