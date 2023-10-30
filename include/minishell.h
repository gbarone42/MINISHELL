#ifndef MINISHELL_H
# define MINISHELL_H


# include <stdbool.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <sys/time.h>
# include <sys/wait.h>
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

# define TRUE 1
# define FALSE 0

# define CLR_RMV "\033[0m"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define PURPLE "\033[1;35m"
# define CYAN "\033[1;36m"

typedef struct s_shell
{
	char	**env;
	int		in;
	int		out;
	//int		pipe[2];
	int		status;
	int 	exit;
	char	**paths;
	char	**export;
	char	*prompt;

}	t_shell;

extern int	g_exit;

////main
int main(int argc, char **argv, char **env);
void	ft_innit_shell(t_shell *shell, char **env);
void	shell_env(char **env, t_shell *shell);

////signal
void signal_handler(int sig);
char	**ft_get_env(char **env);


////tests
void testprintf(void);


void ft_minishell_simulator(char *str);


////utils1
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);

////utils2
char	*ft_strjoin(char const *s1, char const *s2);


#endif