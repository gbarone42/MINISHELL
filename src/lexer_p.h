/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_p.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filippo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 00:19:35 by filippo           #+#    #+#             */
/*   Updated: 2024/01/05 19:10:41 by filippo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_P_H
# define LEXER_P_H

# include "minishell_p.h"

typedef struct double_size_t
{
	size_t	x;
	size_t	y;
}	t_dsize_t;

enum
{
	GENERAL_TOKEN = -1,
	PIPE_TOKEN = '|',
	LF_TOKEN = '\n',
	GREATER_TOKEN = '>',
	DGREATER_TOKEN = '>' + 1,
	LESSER_TOKEN = '<',
	DLESSER_TOKEN = '<' + 1,
	NULL_TOKEN = '\0'
};

enum
{
	NULL_STATE,
	GENERAL_STATE,
	QUOTE_STATE = '\'',
	DQUOTE_STATE = '\"'
};

typedef struct index_node
{
	char				*index;
	struct index_node	*next;
}	t_ilist;

typedef struct token_node
{
	char				*data;
	int					type;
	t_ilist				*expand;
	struct token_node	*next;
}	t_tlist;

t_tlist		*ft_new_tlnode(size_t len);
size_t		ft_app_tlist(size_t j, t_tlist **p_last, size_t len);
size_t		ft_app_tlist_decorator(t_dsize_t *i_j, t_tlist **p_last, \
	char c, size_t len);
void		ft_free_tlist(t_tlist *head);

t_ilist		*ft_new_ilnode(char *index);
void		ft_app_ilist(t_ilist **p_last, char *index);
void		ft_free_ilist(t_ilist *head);

t_tlist		*ft_lexer(t_shell *shell, char *input, size_t input_len, int state);

#endif
