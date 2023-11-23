#include "../../build/minishell.h"



void clearCurrentLine()
{
    printf("\r\033[K");
    fflush(stdout);
}

void	ft_norm_signal(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, signal_handler);
}

void	signal_handler(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n \n", 3); //for the moment is double \newline
	g_exit = 130;
	rl_on_new_line(); //tells the readline library that you have moved to a new line and that it should prepare to read input from a new line.
	clearCurrentLine();
	rl_redisplay();//causes readline to update the display based on the contents of the current readline buffer, which your signal_handler has just cleared.
}

