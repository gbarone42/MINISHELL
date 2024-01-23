/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tlist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:52:44 by filippo           #+#    #+#             */
/*   Updated: 2024/01/23 15:19:50 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tlist	*ft_new_tlnode(size_t len)
{
	char	*value;
	t_tlist	*output;

	value = ft_malloc_soul(++len * sizeof(char));
	if (!value)
		return (NULL);
	output = malloc(sizeof(*output));
	if (!output)
	{
		free(value);
		return (NULL);
	}
	*value = '\0';
	output->data = value;
	output->type = NULL_TOKEN;
	output->expand = NULL;
	output->next = NULL;
	return (output);
}

size_t	ft_app_tlist(size_t j, t_tlist **p_last, size_t len)
{
	t_tlist	*last;
	t_tlist	*new;

	if (j)
	{
		last = *p_last;
		last->data[j] = '\0';
		new = ft_new_tlnode(len);
		if (!new)
			ft_free_and_err(ft_ret_shell(NULL), \
				"FT_NEW_TLNODE", errno = ENOMEM);
		last->next = new;
		*p_last = new;
	}
	return (0);
}

void	ft_free_tlist(t_tlist *head)
{
	t_tlist	*tmp;

	while (head)
	{
		free(head->data);
		ft_free_ilist(head->expand);
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

size_t	ft_app_tlist_decorator(t_dsize_t *i_j, t_tlist **p_last, \
	char c, size_t len)
{
	static t_shell	*shell;
	t_tlist			*last;
	char			next;
	int				index;
	int				type;

	if (!shell)
		shell = ft_ret_shell(NULL);
	ft_app_tlist(i_j->y, p_last, len);
	last = *p_last;
	last->data[0] = c;
	type = c;
	index = 1;
	next = shell->input[i_j->x];
	if (c != '|' && c != '\n' && next == c)
	{
		last->data[index++] = c;
		type++;
		i_j->x++;
	}
	last->type = type;
	return (ft_app_tlist(index, p_last, len - 1));
}

void	ft_print_tlist(t_tlist *first)
{
	int		ntokens;
	t_ilist	*expand;

	ntokens = 0;
	printf("-----LEXER-----\n\n");
	while (first->next)
	{
		printf("Data: %s\nType: %d\nExpand: ", first->data, first->type);
		expand = first->expand;
		first = first->next;
		ntokens++;
		if (!expand)
		{
			printf("\n\n");
			continue ;
		}
		while (expand->next)
		{
			printf("%lu, ", expand->index);
			expand = expand->next;
		}
		printf("%lu\n\n", expand->index);
	}
	printf("ntokens: %d\n", ntokens);
}
