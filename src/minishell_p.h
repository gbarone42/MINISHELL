/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_p.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filippo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 19:55:20 by filippo           #+#    #+#             */
/*   Updated: 2024/01/04 23:30:51 by filippo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_P_H
# define MINISHELL_P_H

# include <readline/readline.h>
# include <readline/history.h>
# include <errno.h>

# include "libft/libft.h"

# define WHITE	"\033[0m"
# define RED	"\033[1;31m"
# define GREEN	"\033[1;32m"
# define YELLOW	"\033[1;33m"
# define BLUE	"\033[1;34m"
# define PURPLE	"\033[1;35m"
# define CYAN	"\033[1;36m"
# define GOLD	"\033[1;94m"

typedef struct double_size_t
{
	size_t	x;
	size_t	y;
}	t_dsize_t;

typedef struct env_var_node
{
	char				*value;
	struct env_var_node	*next;
	struct env_var_node	*prev;
}	t_evlist;

enum
{
	GENERAL_TOKEN = -1,
	PIPE_TOKEN = '|',
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
	size_t				index;
	struct index_node	*next;
}	t_ilist;

typedef struct token_node
{
	char				*data;
	int					type;
	t_ilist				*expand;
	struct token_node	*next;
}	t_tlist;

enum
{
	RED_IN = 0x1 << 0,
	RED_OUT = 0x1 << 1,
	RED_APP = 0x1 << 2,
	RED_HERE = 0x1 << 3
};

typedef struct command_node
{
	char			*command;
	char			*args;
	char			*infile;
	char			*outfile;
	char			*heredoc;
	int				redirections;
	struct clist	*next;
}	t_clist;

typedef struct shell
{
	t_evlist	*first_envv;
	t_evlist	*last_envv;
	char		*prompt;
	char		*input;
	size_t		input_len;
	t_clist		*commands;
}	t_shell;

t_shell		*ft_ret_shell(t_shell *p_shell);
void		ft_err(char *caller, int error);
void		ft_free_and_err(t_shell *shell, char *caller, int error);
void		ft_free_and_exit(t_shell *shell, int status);

void		ft_init_shell(t_shell *shell, char **env);
t_tlist		*ft_lexer(t_shell *shell, char *input, size_t input_len, int state);
t_clist		*ft_parser(t_shell *shell);

t_evlist	*ft_new_evlnode(char *value);
t_evlist	*ft_app_evlist(t_evlist *last, char *value);
void		ft_free_evlist(t_evlist *head);

t_tlist		*ft_new_tlnode(size_t len);
size_t		ft_app_tlist(size_t j, t_tlist **p_last, size_t len);
size_t		ft_app_tlist_decorator(t_dsize_t *i_j, t_tlist **p_last, \
	char c, size_t len);
void		ft_free_tlist(t_tlist *head);

t_ilist		*ft_new_ilnode(size_t index);
void		ft_app_ilist(t_ilist **p_last, size_t index);
void		ft_free_ilist(t_ilist *head);

char		*ft_strjoin_decorator(char *first, char *second);
char		*ft_strjoin_decorator(char *first, char *second);
void		ft_set_prompt(t_shell *shell);

#endif
