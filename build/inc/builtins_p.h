/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_p.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:10:43 by sdel-gra          #+#    #+#             */
/*   Updated: 2024/02/07 15:25:14 by filippo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_P_H
# define BUILTINS_P_H

# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
# include <stdbool.h>
# include <errno.h>

# include "minishell.h"

# define INPUT_SIZE 4095
# define HISTORY_SIZE 100
# define PATH_MAX 4096

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
char	*ft_strcat(char *dest, const char *src);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strtok(char *str, char sep);
int		control_exist(char **arg, t_shell *shell);
int		ft_isvalid(const char *input);
int		ft_strcmp(char *s1, char *s2);
int		is_builtin_command(char *command);
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);
void	add_env_variable(t_shell *shell, const char *name, const char *value);
void	add_envv_variable(t_shell *shell, const char *name, const char *value);
void	add_to_history(t_history *history, char *command);
void	free_arr(char ***arr);
void	ft__exit(t_shell *shell, char **args);
void	ft_handle_builtins(t_shell *shell, t_clist *commands);
void	ft__cd(char **args);
void	ft__echo(char **args);
void	ft__env(t_shell *shell, char *input, int dquotes);
void	ft__export(t_shell *shell, char **args);
void	handle_unset(t_shell *shell, char **args);
void	ft__pwd(void);
void	process_env_variable(t_shell *shell, char *arg);
void	signal_handler(int sig);

#endif
