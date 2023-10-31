#include "../../include/minishell.h"


void	signal_handler(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n \n", 3); //for the moment is double \newline
	g_exit = 130;
	//rl_on_new_line();
	//rl_replace_line("", 0);
	//rl_redisplay();
}

