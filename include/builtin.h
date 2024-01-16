#ifndef BUILTIN_H
#define BUILTIN_H

#include <stdbool.h>
#include <readline/history.h>
#include <readline/readline.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>
#include <termios.h>
#include <curses.h>
#include <sys/ioctl.h>

#define INPUT_SIZE 4095
#define TRUE 1
#define FALSE 0
#define MEM_ERROR 42
#define MEM_ERROR2 43
#define MEM_ERROR3 44
#define HISTORY_SIZE 100

#define PIPE '|'
#define DOUBLE_QUOTE '\"'
#define SINGLE_QUOTE '\''
#define REDIRECTION_OUTPUT '>'
#define REDIRECTION_INPUT '<'
#define HERE_DOCUMENT '<<'
#define APPEND_OUTPUT '>>'

#define CLR_RMV "\033[0m"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define PURPLE "\033[1;35m"
#define CYAN "\033[1;36m"
#define GOLD "\033[1;94m"

typedef struct env_var_node
{
	char				*value;
	struct env_var_node	*next;
	struct env_var_node	*prev;
}	t_evlist;
typedef struct s_history
{
    char *entries[HISTORY_SIZE];
    int count;
} t_history;

typedef struct s_shell
{
    t_history history;
    char *prompt;
    int in;
    int out;
    t_evlist *env_list;
    char *input;
    char **paths;
    char **export;
} t_shell;

typedef struct s_parser
{
    // int id;
    // char **cmds;
    // int in;
    // int out;
    // int numred;
    // int *redirs;
    // char **redir_name;
    // bool exec;
    // struct s_parser *next;
    // struct s_parser *prev;
} t_pars;

typedef struct s_token
{
    // int id;
    // int type;
    // char *token;
    // struct s_token *next;
    // struct s_token *prev;
} t_tok;

extern int g_exit;

#ifndef HISTORY_H
#define HISTORY_H

#define HISTORY_SIZE 100

#ifndef PATH_MAX
#define PATH_MAX 4096

#endif


//extern char *history[HISTORY_SIZE];
//extern int history_count;

void free_env_list(t_evlist *env_list);

//exit
void shell_exit(t_shell *shell);
void freeing_my_shell(t_shell *my_shell);

//init
int ft_innit_shell(t_shell *shell, char **env);
char **ft_get_env(char **env);
void free_myenv(char **my_env);

//minishell
int main(int argc, char **argv, char **env);

//parsing
void shell_parser(t_shell *shell, t_pars **command);
char **input_handler(t_shell *shell);
int ft_count_pipes(const char *s, char pipe);
int pipe_handler_quote(const char *s, size_t *i);

//signal
void signal_handler(int sig);
void ft_ctrld(t_shell *shell);
void ft_norm_signal(void);

//simulation
void ft_minishell_simulator(t_shell *shell);

//tests
void testprintf(void);
void testprintf1(void);
void testprintf2(void);
void testprintf3(void);
void testprintf4(void);

//utils1
char *ft_strdup(const char *s);
size_t ft_strlen(const char *str);
void *ft_calloc(size_t count, size_t size);
int ft_strncmp(const char *s1, const char *s2, size_t n);
void ft_bzero(void *s, size_t n);

//utils2
char *ft_strjoin(char const *s1, char const *s2);
char **ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

//utils3
void *ft_memset(void *b, int c, size_t len);
void *ft_memcpy(void *dst, const void *src, size_t n);
int	ft_strcmp(char *s1, char *s2);

//valid
int ft_isvalid(const char *input);

///BUILDins

//cdd
void ft_handle_cd(t_shell *shell, char **args);
void change_directory(t_shell *shell, char *path);
void update_prompt(t_shell *shell);
void	get_current_directory(char *cwd);
char*	build_user_string(void);
char*	build_user_at_string(char *user);


//clears
void clear_screen(void);

//echos
void handle_echo(char **args);

//envv
void handle_env(t_shell *shell);

//exit
void shell_exit(t_shell *shell);

//export_unset
void handle_unset(t_shell *shell, char **args);


char *ft_strtok(char *str, char sep);
void print_environment();
bool contains_invalid_characters(const char *str);
void add_env_variable(t_shell *shell, const char *name, const char *value);
void handle_export(t_shell *shell, char **args);


//history
void free_args(char **args);
void handle_basic_builtin1(t_shell *shell, char **args);
void handle_basic_builtin2(t_shell *shell, char **args);
void handle_basic_builtins(t_shell *shell);
void handle_other_builtins(t_shell *shell);
void builtins_call(t_shell *shell);

//history
void add_to_history(t_history *history, char* command);
//void display_history(void);
void display_history(const t_history *history);

//lss
void print_current_directory_contents(void);

//pwds
void print_current_directory(void);

//suspend
void handle_suspend(void);

//timet
void print_current_time(void);

//whoami
void whoami_command();

#endif // HISTORY_H

#endif // MINISHELL_H
