/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_p.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filippo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 19:55:20 by filippo           #+#    #+#             */
/*   Updated: 2023/12/28 01:36:43 by filippo          ###   ########.fr       */
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

typedef struct var_node
{
	char			*value;
	struct var_node	*next;
	struct var_node	*prev;
}	t_vlist;

enum
{
	GENERAL_TOKEN = -1,
	PIPE_TOKEN = '|',
	QOUTE_TOKEN = '\'',
	DQUOTE_TOKEN = '\"',
	GREATER_TOKEN = '>',
	LESSER_TOKEN = '<',
	NULL_TOKEN = '\0'
};

enum
{
	NULL_STATE,
	GENERAL_STATE,
	QUOTE_STATE,
	DQUOTE_STATE
};

typedef struct token_node
{
	char				*data;
	int					type;
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
	t_vlist	*first_envv;
	t_vlist	*last_envv;
	char	*prompt;
	char	*input;
// se riservisse oltre al lexer
	size_t	input_len;
	t_tlist	*tokens;
	t_clist	*commands;
}	t_shell;

/*
extern int	g_exit;
extern char	*history[HISTORY_SIZE];
extern int	history_count;

void	ft_exit_shell(t_shell *shell);
void	ft_free_shell(t_shell *my_shell);
*/

void	ft_err(char *caller, int error);
void	ft_free_and_err(t_shell *shell, char *caller, int error);
void	ft_free_and_exit(t_shell *shell, int status);

void	ft_init_shell(t_shell *shell, char **env);
void	ft_lexer(t_shell *shell, char *input, size_t input_len, int state);
void	ft_parser(t_shell *shell);
void	ft_execute(t_shell *shell);

t_vlist	*ft_new_vlnode(char *value);
t_vlist	*ft_append_vlist(t_vlist *last, char *value);
void	ft_free_vlist(t_vlist *head);

t_tlist	*ft_new_tlnode(size_t len);
size_t	ft_append_tlist(t_shell *shell, size_t j, t_tlist **p_last, size_t len);
size_t	ft_append_tlist_decorator(t_shell *shell, t_dsize_t j_len, t_tlist **p_last, char c);
void	ft_free_tlist(t_tlist *head);

char	*ft_strjoin_decorator(char *first, char *second);
char	*ft_strjoin_decorator(char *first, char *second);
void	ft_set_prompt(t_shell *shell);

/*
//parsing
void	ft_parse(t_shell *shell, t_pars **command);
char	**ft_handle_input(t_shell *shell);
int		ft_count_pipes(const char *s, char pipe);
int		ft_pipe_handler_quote(const char *s, size_t *i);

//signal
void	ft_handle_signal(int sig);
void	ft_ctrld(t_shell *shell);
void	ft_norm_signal(void);

//simulation
void	ft_minishell_simulator(t_shell *shell);

//valid
int		ft_is_valid(const char *input);

//built-ins

//cd
void	ft_handle_cd(t_shell *shell, char **args);
void	ft_change_directory(t_shell *shell, char *path);
void	ft_update_prompt(t_shell *shell);

//echo
// possiamo usare un parametro int n
void	ft_handle_echo(char *input);
void	ft_handle_echo_n(char *input);

//env
void	ft_handle_env(t_shell *shell);

//exit
void	ft_shell_exit(t_shell *shell);

//export_unset
void	ft_handle_unset(t_shell *shell, char **args);

char	*ft_strtok(char *str, char sep);
void	ft_print_environment();
bool	ft_contains_invalid_characters(const char *str);
void	ft_add_env_variable(t_shell *shell, const char *name, const char *value);
void	ft_handle_export(t_shell *shell, char **args);

//history
void	ft_free_args(char **args);
void	ft_handle_basic_builtin1(t_shell *shell, char **args);
void	ft_handle_basic_builtin2(t_shell *shell, char **args);
void	ft_handle_basic_builtins(t_shell *shell);
void	ft_handle_other_builtins(t_shell *shell);
void	ft_builtins_call(t_shell *shell);

//history
void	ft_add_to_history(char* command);
void	ft_display_history(void);

//pwd
void	ft_print_current_directory(void);
*/

#endif // MINISHELL_H
