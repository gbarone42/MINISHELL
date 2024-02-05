/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_p.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:03:31 by fcorri            #+#    #+#             */
/*   Updated: 2024/02/05 13:05:23 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_P_H
# define PARSER_P_H

# include "minishell.h"

# define SYNTAX_ERROR	"minishell: syntax error near unexpected token "

typedef struct redirection	t_rlist;

typedef struct command_node	t_clist;

typedef struct index_node	t_ilist;

typedef struct token_node	t_tlist;

void	ft_io_lists(t_tlist **token, t_clist *cmd);
char	**ft_args_1(t_tlist **token);
char	**ft_args_2(char **old_args, t_tlist **token, t_tlist *save);
int		ft_term(t_tlist **p_token, int token_type, char **buffer);
int		ft_check_grammar(t_tlist **p_first);

t_rlist	*ft_new_rlnode(int type, char *filename);
void	ft_app_rlist(t_rlist **p_first, int type, char *filename);
void	ft_free_rlist(t_rlist *head);
void	ft_print_rlist(t_rlist *head);

#endif
