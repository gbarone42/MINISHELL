/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_p.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filippo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 19:55:20 by filippo           #+#    #+#             */
/*   Updated: 2024/01/08 17:53:10 by fcorri           ###   ########.fr       */
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

typedef struct env_var_node
{
	char				*value;
	struct env_var_node	*next;
	struct env_var_node	*prev;
}	t_evlist;

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
	int			exit_status;
}	t_shell;

t_shell		*ft_ret_shell(t_shell *p_shell);
void		ft_err(char *caller, int error);
void		ft_free_and_err(t_shell *shell, char *caller, int error);
void		ft_free_and_exit(t_shell *shell, int status);

void		ft_init_shell(t_shell *shell, char **env);
t_clist		*ft_parser(t_shell *shell);

t_evlist	*ft_new_evlnode(char *value);
t_evlist	*ft_app_evlist(t_evlist *last, char *value);
void		ft_free_evlist(t_evlist *head);
char		*ft_get_value_of(t_shell *shell, char *key, size_t len);

char		*ft_strjoin_and_free_first(char *first, char *second);
char		*ft_strjoin_and_free_second(char *first, char *second);
void		ft_set_prompt(t_shell *shell);

#endif
