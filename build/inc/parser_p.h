/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_p.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:03:31 by fcorri            #+#    #+#             */
/*   Updated: 2024/01/26 19:38:51 by fcorri           ###   ########.fr       */
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
char	**ft_args(t_tlist **token);
int		ft_term(t_tlist **p_token, int token_type, char **buffer);
int		ft_check_grammar(t_tlist **p_first);

#endif
