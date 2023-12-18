#ifndef MINISHELL_P_H
#define MINISHELL_P_H

#include <curses.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <readline/history.h>
#include <readline/readline.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <termios.h>
#include <unistd.h>

# include "libft/libft.h"

#define INPUT_SIZE 4095
#define HISTORY_SIZE 100
#define TRUE 1
#define FALSE 0

#define PIPE '|'
#define DOUBLE_QUOTE '\"'
#define SINGLE_QUOTE '\''
#define REDIRECTION_OUTPUT '>'
#define REDIRECTION_INPUT '<'
#define HERE_DOCUMENT '<<'
#define APPEND_OUTPUT '>>'

#define WHITE "\033[0m"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define PURPLE "\033[1;35m"
#define CYAN "\033[1;36m"
#define GOLD "\033[1;94m"

typedef struct s_shell
{
	char	**env;
	char	*prompt;
} t_shell;

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

char	*ft_strjoin_decorator(char *first, char *second);
char	*ft_set_prompt(char *tmp);

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
