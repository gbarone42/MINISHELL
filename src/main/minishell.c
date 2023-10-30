#include "../../include/minishell.h"

int	g_exit = 0;

void	signal_handler(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n \n", 3); //for the moment is double \newline
	g_exit = 130;
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

static void	ft_norm_signal(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, signal_handler);
}


void ft_minishell_simulator(char *str)
{
	int	print_count = 0;

    while (g_exit == 0)
    {
        if (print_count <= 10)
        {
            printf("%s\n", str);
            add_history(str);
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

int	main(int ac, char **av, char **env)
{

	char	*str;
	t_shell	*shell;


	shell = (t_shell *)ft_calloc(1, sizeof(t_shell));
	str = "okok";
	(void)ac;
	(void)av;
	
	ft_innit_shell(shell, env);
	printf("%sWelcome %s!%s\n", GREEN, getenv("USER"), CLR_RMV);
	ft_norm_signal();
	ft_minishell_simulator(str);
    return (0);
}`