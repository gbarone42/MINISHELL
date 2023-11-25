#include "../include/minishell.h"

void ft_ctrld(t_shell *shell)
{
    if (errno) {
        write(STDERR_FILENO, "readline error: ", 17);
    }
    printf("\n");
    free(shell->input);
    shell_exit(shell);
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
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}



//signal(SIGQUIT, SIG_IGN); --> 
//ignores the SIGQUIT signal, which is typically triggered by pressing Ctrl +

//signal(SIGINT, signal_handler); -->
//when you press Ctrl + C, the SIGINT signal is sent to the process and signal_handler, is then called to handle this signal.

//rl_on_new_line(); //tells the readline library that you have moved to a new line and that it should prepare to read input from a new line.
//rl_replace_line("", 0);// clears the current readline input buffer. This effectively clears the line where the user was typing when Ctrl+C was pressed.
//rl_redisplay();//causes readline to update the display based on the contents of the current readline buffer, which your signal_handler has just cleared.