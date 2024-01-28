/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:44:18 by sdel-gra          #+#    #+#             */
/*   Updated: 2024/01/28 18:30:21 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <sys/types.h>
# include <sys/uio.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# include "libft/libft.h"
# include "executor_p.h"
# include "builtins_p.h"
# include "parser_p.h"
# include "lexer_p.h"

# define WHITE	"\033[0m"
# define RED	"\033[1;31m"
# define GREEN	"\033[1;32m"
# define YELLOW	"\033[1;33m"
# define BLUE	"\033[1;34m"
# define PURPLE	"\033[1;35m"
# define CYAN	"\033[1;36m"
# define GOLD	"\033[1;94m"

# define SYNTAX_ERROR	"minishell: syntax error near unexpected token "

enum
{
	ND = -1,
	INPUT = 0,
	OUTPUT = 1,
	APPEND = 2,
	HEREDOC = 3,
	PRIOROUTPUT = 24,
	DEVNULLOUT = 25
};

typedef struct redirection
{
	int					type;
	char				*filename;
	struct redirection	*next;
}	t_rlist;

typedef struct command_node
{
	char				**args;
	int					in;
	int					out;
	int					is_first;
	t_rlist				*redirections;
	struct command_node	*next;
}	t_clist;

typedef struct s_shell
{
	pid_t		pid_child;
	int			fd_pipe[2];
	int			tmp_fd;
	t_history	history;
	int			in;
	int			out;
	char		**env;
	char		**last_env;
	char		*prompt;
	char		*input;
	char		**paths;
	size_t		input_len;
	t_clist		*commands;
	int			exit_status;
	char		**env_list;
	char		**export;
}	t_shell;

char		*ft_free(char **ptr);
void		ft_redir(t_shell *ms, t_clist *cmd);

void		ft_free_shell(t_shell *shell);
t_shell		*ft_ret_shell(t_shell *p_shell);
void		ft_err(char *caller, int error);

void		ft_free_and_err(t_shell *shell, char *caller, int error);
void		ft_free_and_exit(t_shell *shell, int status);
void		ft_free_char_p(char **first);

void		ft_init_shell(t_shell *shell, char **env);
t_clist		*ft_parser(t_shell *shell);

char		*ft_get_value_of(t_shell *shell, char *key, size_t len);
void		ft_print_char_p(char **p);

t_rlist		*ft_new_rlnode(int type, char *filename);
void		ft_app_rlist(t_rlist **p_first, int type, char *filename);
void		ft_free_rlist(t_rlist *head);
void		ft_print_rlist(t_rlist *head);

t_clist		*ft_new_clnode(void);
t_clist		*ft_free_clist(t_clist *head);
void		ft_print_clist(t_clist *head);

char		*ft_strjoin_and_free_first(char *first, char *second);
char		*ft_strjoin_and_free_second(char *first, char *second);
void		ft_set_prompt(t_shell *shell);

void		remove_env_variable(t_shell *shell, const char *var_name);

#endif
