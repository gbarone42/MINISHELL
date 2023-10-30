#include "../../include/minishell.h"

int	g_exit = 0;

static void	ft_norm_signal(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, signal_handler);
}


int	main(int ac, char **av, char **env)
{

	char	*str;
	t_shell	*shell;


	shell = (t_shell *)ft_calloc(1, sizeof(t_shell));
	str = "okok";
	(void)ac;
	(void)av;
	printf("%sWelcome %s!%s\n", GREEN, getenv("USER"), CLR_RMV);
	ft_innit_shell(shell, env);

	ft_norm_signal();
	ft_minishell_simulator(str);
    return (0);
}