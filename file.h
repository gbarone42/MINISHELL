#ifndef MINISHELL_H
# define MINISHELL_H


#include <stdbool.h>
#include <readline/history.h>
#include <readline/readline.h>
#include <signal.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <stdio.h>       // for printf
#include <stdlib.h>      // for malloc, free
#include <unistd.h>      // for write, access, open, read, close, fork, etc.
#include <sys/wait.h>    // for wait, waitpid, wait3, wait4
#include <signal.h>      // for signal, sigaction, sigemptyset, sigaddset, kill
#include <sys/types.h>   // for getpid, getppid
#include <sys/stat.h>    // for stat, lstat, fstat
#include <fcntl.h>       // for open, O_RDONLY, O_WRONLY, O_CREAT, etc.
#include <dirent.h>      // for opendir, readdir, closedir
#include <string.h>      // for strerror
#include <errno.h>       // for perror
#include <termios.h>     // for termios functions (e.g., tcsetattr, tcgetattr)
#include <curses.h>      // for tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs
#include <sys/ioctl.h>   // for ioctl




#endif