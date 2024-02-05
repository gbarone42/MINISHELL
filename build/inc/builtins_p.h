/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_p.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:10:43 by sdel-gra          #+#    #+#             */
/*   Updated: 2024/02/05 19:45:21 by fcorri           ###   ########.fr       */
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

extern int					g_exit;

bool	contains_invalid_characters(const char *str);
bool	contains_invalid_characters(const char *str);
bool	contains_invalid_characters(const char *str);
char	**ft_get_env(char **env);
char	**ft_get_env_array(char **env);
char	**ft_get_env_array(char **env);
char	**input_handler(t_shell *shell);
char	*build_user_at_string(char *user);
char	*build_user_string(void);
char	*create_envv_variable(const char *name, const char *value);
char	*create_new_env_variable(const char *name, const char *value);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strtok(char *str, char sep);
int		control_exist(char **arg, t_shell *shell);
int		copy_env_vars(t_shell *shell, char **env);
int		copy_env_vars(t_shell *shell, char **env);
int		create_user(char **user);
int		create_user(char **user);
int		find_envv_variable(t_shell *shell, const char *name, const char *value);
int		ft_count_pipes(const char *s, char pipe);
int		ft_isvalid(const char *input);
int		ft_strcmp(char *s1, char *s2);
int		is_builtin_command(char *command);
int		pipe_handler_quote(const char *s, size_t *i);
int		update_existing_var(t_shell *shell, const char *name, char *new_variable);
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);
void	add_env_variable(t_shell *shell, const char *name, const char *value);
void	add_env_variable(t_shell *shell, const char *name, const char *value);
void	add_envv_variable(t_shell *shell, const char *name, const char *value);
void	add_new_envv_variable(t_shell *shell, const char *name, const char *value);
void	add_new_variable(t_shell *shell, char *new_variable, int env_size);
void	add_to_history(t_history *history, char *command);
void	change_directory(t_shell *shell, char *path);
void	clear_screen(void);
void	display_history(const t_history *history);
void	free_arr(char ***arr);
void	free_env_array(char **env_array);
void	free_myenv(char **my_env);
void	freeing_my_shell(t_shell *my_shell);
void	ft__exit(t_shell *shell);
void	ft_free_env(char **env);
void	ft_handle_builtins(t_shell *shell, t_clist *commands);
void	ft__cd(t_shell *shell, char **args);
void	get_current_directory(char *cwd);
void	handle_echo(char **args);
void	handle_env(t_shell *shell);
void	handle_envv(t_shell *shell);
void	handle_export(t_shell *shell, char **args);
void	handle_export(t_shell *shell, char **args);
void	handle_export(t_shell *shell, char **args);
void	handle_other_builtins(t_shell *shell);
void	handle_suspend(void);
void	handle_unset(t_shell *shell, char **args);
void	print_current_directory(void);
void	print_current_directory_contents(void);
void	print_current_time(void);
void	print_environment(void);
void	process_env_variable(t_shell *shell, char *arg);
void	process_env_variable(t_shell *shell, char *arg);
void	shell_exit(t_shell *shell);
void	shell_parser(t_shell *shell);
void	signal_handler(int sig);
void	update_prompt(t_shell *shell);
void	whoami_command(void);

#endif
