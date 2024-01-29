/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_p.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:03:31 by fcorri            #+#    #+#             */
/*   Updated: 2024/01/27 20:01:52 by filippo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_P_H
# define PARSER_P_H

# include "minishell.h"

typedef struct redirection	t_rlist;

typedef struct command_node	t_clist;

typedef struct index_node	t_ilist;

typedef struct token_node	t_tlist;

void	ft_io_lists(t_tlist **token, t_clist *cmd);
char	**ft_args_1(t_tlist **token);
char	**ft_args_2(char **old_args, t_tlist **token, t_tlist *save);
int		ft_term(t_tlist **p_token, int token_type, char **buffer);
int		ft_check_grammar(t_tlist **p_first);

#endif
