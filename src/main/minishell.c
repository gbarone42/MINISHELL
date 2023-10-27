#include "../../include/minishell.h"

int	main(int ac, char **av)
{

	char	*str;

	str = "okok";

	(void)ac;
	(void)av;

	ft_norm_signal();
	printf("%sWelcome %s!%s\n", GREEN, getenv("USER"), CLR_RMV);
	while(TRUE)
	{
		printf("%s\n", str);
		add_history(str);
	}
    return (0);
}

void	ft_sig_init(int sign)
{
	(void)sign;
	int	g_status = 1;

	if(g_status == 130)
	{
		g_status = 130;
		write(STDOUT_FILENO, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}
 
static void	ft_norm_signal(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, ft_sig_init);
}


//what is an enviroment variable?

/*
static void	ft_norm_signal(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, ft_sig_init);
}

void	ft_sig_init(int sign)
{
	(void)sign;
	g_status = 130;
	write(STDOUT_FILENO, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	ft_sig_term(t_shell *shell)
{
	ft_clear_history(shell);
	write(STDOUT_FILENO, "exit\n", 5);
	ft_free_exit(shell);
}*/
