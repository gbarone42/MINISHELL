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

