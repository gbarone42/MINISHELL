#include "../../include/minishell.h"

// static void	ft_norm_signall(void)
// {
// 	signal(SIGQUIT, SIG_IGN);
// 	signal(SIGINT, signal_handler);
// }


void ft_minishell_simulator(t_shell *shell)
{
	int	print_count = 0;

    while (g_exit == 0)
    {
        if (print_count <= 10)
        {   
            //ft_norm_signall();
            shell->input = readline(shell->prompt);
            //printf("%s\n", shell->prompt);
            add_history(shell->prompt);
            print_count++;
            sleep(3); // Adding a sleep of 1 second between iterations.
        }
        else
        {
            sleep(3); // This will ensure that the loop doesn't run too fast after the message is printed 3 times.
        }
    }
    if (g_exit == 130) {
        printf("CTRL + C\n");
    }
}