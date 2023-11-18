#ifndef MINISHELL_H
# define MINISHELL_H


# include <stdbool.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <sys/time.h>
# include <stdio.h>       // for printf
# include <stdlib.h>      // for malloc, free
# include <unistd.h>      // for write, access, open, read, close, fork, etc.
# include <sys/wait.h>    // for wait, waitpid, wait3, wait4
# include <signal.h>      // for signal, sigaction, sigemptyset, sigaddset, kill
# include <sys/types.h>   // for getpid, getppid
# include <sys/stat.h>    // for stat, lstat, fstat
# include <fcntl.h>       // for open, O_RDONLY, O_WRONLY, O_CREAT, etc.
# include <dirent.h>      // for opendir, readdir, closedir
# include <string.h>      // for strerror
# include <errno.h>       // for perror
# include <termios.h>     // for termios functions (e.g., tcsetattr, tcgetattr)
# include <curses.h>      // for tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs
# include <sys/ioctl.h>   // for ioctl
//# include <limits.h>	//for PATHMAX

# define INPUT_SIZE 4095

# define TRUE 1
# define FALSE 0
# define MEM_ERROR 42
# define MEM_ERROR2 43
# define MEM_ERROR3 44


# define PIPE '|'
# define DOUBLE_QUOTE '\"'
# define SINGLE_QUOTE '\''
# define REDIRECTION_OUTPUT '>'
# define REDIRECTION_INPUT '<'
# define HERE_DOCUMENT '<<'
# define APPEND_OUTPUT '>>'

//
// # define SINGLE_QUOTE 39
// # define DOUBLE_QUOTE 34


# define CLR_RMV "\033[0m"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define PURPLE "\033[1;35m"
# define CYAN "\033[1;36m"
# define GOLD "\033[1;94m"

typedef struct s_shell
{
	char	*prompt;
	int		in;
	int		out;
	char	**env;
	char	*input;
	char	**paths;
	char	**export;
	//int		pipe[2];
	//int		status;
	//int 	exit;
	

}	t_shell;


typedef struct s_parser
{
	// int				id;
	// char			**cmds;

	// int				in;
	// int				out;

	// int				numred;
	// int				*redirs;
	// char			**redir_name;

	// bool			exec;

	// struct s_parser	*next;
	// struct s_parser	*prev;
}					t_pars;

typedef struct s_token
{
	// int				id;
	// int				type;
	// char			*token;

	// struct s_token	*next;
	// struct s_token	*prev;
}					t_tok;


extern int	g_exit;


//exit/////////////////////////////////////////////exit
//
void	shell_exit(t_shell *shell);
void	freeing_my_shell(t_shell *my_shell);




//init///////////////////////////////////////////////init
//
int	ft_innit_shell(t_shell *shell, char **env);
char	**ft_get_env(char **env);
void free_myenv(char **my_env); ///to be put into another file?


//minishell//////////////////////////////////////////minishell
//
int main(int argc, char **argv, char **env);




//parsing///////////////////////////////////////////parsing
//
void	shell_parser(t_shell *shell, t_pars **command);
char	**input_handler(t_shell *shell);
int ft_count_pipes(const char *s, char pipe);
int pipe_handler_quote(const char *s, size_t *i);



//signal/////////////////////////////////////////////signal
//
void signal_handler(int sig);
void	ft_norm_signal(void);




//simulation/////////////////////////////////////////simulation
//
void ft_minishell_simulator(t_shell *shell);




//test////////////////////////////////////////////tests
//
void testprintf(void);
void testprintf1(void);
void testprintf2(void);
void testprintf3(void);
void testprintf4(void);



//utils1/////////////////////////////////////////////utils1
//
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t count, size_t size);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_bzero(void *s, size_t n);



//utils2/////////////////////////////////////////////utils2
//
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dst, char *src, size_t size);



//utils3/////////////////////////////////////////////utils2
//
void *ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);



//valid////////////////////////////////////////////valid
//
int	ft_isvalid(const char *input);




#endif