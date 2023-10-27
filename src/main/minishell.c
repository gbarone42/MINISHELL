#include "../../include/minishell.h"

void	ft_sig_init(int sign)
{
	(void)sign;
	int	g_status = 1;

	printf("ft_sig_init ");

	if(g_status == 130)
	{
		g_status = 130;
		write(STDOUT_FILENO, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}
 
void	ft_norm_signal(void)
{
	printf("ft_norm_signal ");

	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, ft_sig_init);
}

char	**ft_get_env(char **env)
{
	char	**my_env;
	int		i;

	i = 0;
	while (env != NULL && env[i])
		i++;
	my_env = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (env[i])
	{
		my_env[i] = ft_strdup(env[i]);
		i++;
	}
	my_env[i] = NULL;
	return (my_env);
}

int	main(int ac, char **av, char **env)
{

	char	*str;
	t_shell	*shell;


	shell = (t_shell *)ft_calloc(1, sizeof(t_shell));
	str = "okok";

	(void)ac;
	(void)av;

	testprintf();
	shell->env = ft_get_env(env);
	ft_norm_signal();
	printf("%sWelcome %s!%s\n", GREEN, getenv("USER"), CLR_RMV);
	while(FALSE)
	{
		printf("%s\n", str);
		add_history(str);
	}
    return (0);
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
