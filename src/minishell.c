#include "minishell.h"

int	g_exit = 0;

int	main(int ac, char **av, char **env)
{
	int		output;
	t_shell	my_shell;

	(void)ac;
	(void)av;
	memset(&my_shell, 0, sizeof(t_shell));
	printf("%sWelcome %s!%s\n", GREEN, getenv("USER"), CLR_RMV);
	output = ft_innit_shell(&my_shell, env);
	if (output != 0)
	{
		perror("Error initializing shell");
		exit(output);
	}
	ft_norm_signal();
	ft_minishell_simulator(&my_shell);
	return (EXIT_SUCCESS);
}
