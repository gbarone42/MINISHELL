/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_p.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 19:55:20 by filippo           #+#    #+#             */
/*   Updated: 2024/01/23 16:07:48 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_P_H
# define MINISHELL_P_H

# include <readline/readline.h>
# include <readline/history.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# include "../libft/build/inc/libft/libft.h"


# define WHITE	"\033[0m"
# define RED	"\033[1;31m"
# define GREEN	"\033[1;32m"
# define YELLOW	"\033[1;33m"
# define BLUE	"\033[1;34m"
# define PURPLE	"\033[1;35m"
# define CYAN	"\033[1;36m"
# define GOLD	"\033[1;94m"

enum
{
	INPUT = 0,
	OUTPUT = 1,
	APPEND = 2,
	HEREDOC = 3,
	PRIOR_OUTPUT = 4
};

typedef struct redirection
{
	int					type;
	char				*filename;
	struct redirection	*next;
}	t_rlist;

typedef struct command_node
{
	char				*pathname;
	char				**args;
	int					in;
	int					out;
	t_rlist				*redirections;
	struct command_node	*next;
}	t_clist;

typedef struct shell
{
	char	**env;
	char	**last_env;
	char	*prompt;
	char	*input;
	size_t	input_len;
	t_clist	*commands;
	int		exit_status;
}	t_shell;

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

#endif
