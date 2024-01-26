/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_p.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:10:43 by sdel-gra          #+#    #+#             */
/*   Updated: 2024/01/26 20:05:11 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_P_H
# define BUILTINS_P_H

# ifndef HISTORY_SIZE
#  define HISTORY_SIZE 100
# endif

# ifndef PATH_MAX
#  define PATH_MAX 4096
# endif

# include <stdbool.h>
# include "minishell.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <dirent.h>
# include <string.h>
# include <errno.h>
# include <termios.h>
# include <curses.h>
# include <sys/ioctl.h>
# include "minishell.h"

# define INPUT_SIZE 4095
# define TRUE 1
# define FALSE 0
# define MEM_ERROR 42
# define MEM_ERROR2 43
# define MEM_ERROR3 44
# define HISTORY_SIZE 100

# define PIPE '|'
# define DOUBLE_QUOTE '\"'
# define SINGLE_QUOTE '\''
# define REDIRECTION_OUTPUT '>'
# define REDIRECTION_INPUT '<'
# define HERE_DOCUMENT '<<'
# define APPEND_OUTPUT '>>'

# define CLR_RMV "\033[0m"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define PURPLE "\033[1;35m"
# define CYAN "\033[1;36m"
# define GOLD "\033[1;94m"

typedef struct env_var_node
{
	char				*value;
	struct env_var_node	*next;
	struct env_var_node	*prev;
}	t_evlist;
typedef struct s_history
{
	char	*entries[HISTORY_SIZE];
	int		count;
}	t_history;

typedef struct s_shell		t_shell;

typedef struct command_node	t_clist;

//extern char *history[HISTORY_SIZE];
//extern int history_count;
extern int					g_exit;

void	free_env_array(char **env_array);
char	**ft_get_env_array(char **env);

//exit
void	shell_exit(t_shell *shell);
void	freeing_my_shell(t_shell *my_shell);

//init
int		ft_innit_shell(t_shell *shell, char **env);
char	**ft_get_env(char **env);
void	free_myenv(char **my_env);

//minishell
int		main(int argc, char **argv, char **env);

//parsing
void	shell_parser(t_shell *shell);
char	**input_handler(t_shell *shell);
int		ft_count_pipes(const char *s, char pipe);
int		pipe_handler_quote(const char *s, size_t *i);

//signal
void	signal_handler(int sig);
void	ft_ctrld(t_shell *shell);
void	ft_norm_signal(void);

//simulation
void	ft_minishell_simulator(t_shell *shell);

//tests
void	testprintf(void);
void	testprintf1(void);
void	testprintf2(void);
void	testprintf3(void);
void	testprintf4(void);

//utils1
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t count, size_t size);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_bzero(void *s, size_t n);

//utils2
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

//utils3
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strcpy(char *dest, const char *src);
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strcpy(char *dest, const char *src);
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);
char	*ft_strcat(char *dest, const char *src);

//valid
int		ft_isvalid(const char *input);

///BUILDins

//cdd
void	ft_handle_cd(t_shell *shell, char **args);
void	change_directory(t_shell *shell, char *path);
void	update_prompt(t_shell *shell);
void	get_current_directory(char *cwd);
char	*build_user_string(void);
char	*build_user_at_string(char *user);

//clears
void	clear_screen(void);

//echos
void	handle_echo(char **args);

//envv
void	handle_env(t_shell *shell);
void	handle_envv(t_shell *shell);

//exit
void	shell_exit(t_shell *shell);

//export_unset
void	handle_unset(t_shell *shell, char **args);

char	*ft_strtok(char *str, char sep);
void	print_environment(void);
bool	contains_invalid_characters(const char *str);
void	add_env_variable(t_shell *shell, const char *name, const char *value);
void	handle_export(t_shell *shell, char **args);

//history
void	free_args(char **args);
void	handle_basic_builtin1(t_shell *shell, char **args);
void	handle_basic_builtin2(t_shell *shell, char **args);
void	handle_basic_builtins(t_shell *shell, t_clist *commands);
void	handle_other_builtins(t_shell *shell);
void	builtins_call(t_shell *shell, t_clist *commands, int i);
int		is_builtin_command(char *command);

//history
void	add_to_history(t_history *history, char *command);
//void display_history(void);
void	display_history(const t_history *history);

//lss
void	print_current_directory_contents(void);
// RXCSO
//pwds
void	print_current_directory(void);

//suspend
void	handle_suspend(void);

//timet
void	print_current_time(void);

//whoami
void	whoami_command(void);
bool	contains_invalid_characters(const char *str);
bool	contains_invalid_characters(const char *str);

void	handle_export(t_shell *shell, char **args);
void	process_env_variable(t_shell *shell, char *arg);
void	handle_export(t_shell *shell, char **args);
void	process_env_variable(t_shell *shell, char *arg);

//v
void	add_env_variable(t_shell *shell, const char *name, const char *value);
void	add_new_variable(t_shell *shell, char *new_variable, int env_size);
char	*create_new_env_variable(const char *name, const char *value);
int		update_existing_var(t_shell *shell,
			const char *name, char *new_variable);

//vv
void	add_envv_variable(t_shell *shell, const char *name, const char *value);
void	add_new_envv_variable(t_shell *shell,
			const char *name, const char *value);
int		find_envv_variable(t_shell *shell, const char *name, const char *value);
char	*create_envv_variable(const char *name, const char *value);

int		create_user(char **user);
int		copy_env_vars(t_shell *shell, char **env);
int		create_user(char **user);
int		copy_env_vars(t_shell *shell, char **env);
char	**ft_get_env_array(char **env);
void	free_env_array(char **env_array);

#endif // MINISHELL_H
