/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:52:44 by filippo           #+#    #+#             */
/*   Updated: 2024/01/26 16:50:11 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_p.h"

t_clist	*ft_new_clnode(void)
{
	t_clist	*output;

	output = malloc(sizeof(*output));
	if (!output)
		return (NULL);
	output->pathname = NULL;
	output->args = NULL;
	// da rivedere inizializzazione default file descriptors
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
		free(head->pathname);
		ft_free_char_p(head->args);
		file = head->in;
		// file != STD_IN
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

void	ft_print_clist(t_clist *head)
{
	int	ncommands;

	ncommands = 0;
	printf("\n-----PARSER-----\n\n");
	while (head)
	{
		printf("pathname: %s\n", head->pathname);
		printf("args: ");
		ft_print_char_p(head->args);
		printf("in: %d\n", head->in);
		printf("out: %d\n", head->out);
		printf("redirections: \n");
		ft_print_rlist(head->redirections);
		printf("\n");
		head = head->next;
		ncommands++;
	}
	printf("ncommands: %d\n", ncommands);
}
