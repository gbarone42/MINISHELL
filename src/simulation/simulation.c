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
            if (!ft_strncmp(shell->input, "exit", 5) || shell->input == NULL)
            {  
                
			  printf("iqwdoiyg  qdoyqgdoyqgdoywegfoywqgfoqwyfgowqyfegoy");
                //shell_exit(shell);
            }
            print_count++;
            sleep(3); // Adding a sleep of 1 second between iterations.
        }
        else
        {
            sleep(3); // This will ensure that the loop doesn't run too fast after the message is printed 3 times.
        }
    }
    if (g_exit == 130)
    {
        printf("CTRL + C\n");
    }
}





// void	shell_exit(t_shell *shell)
// {
// 	int	i;

// 	rl_clear_history();
// 	free(shell->input);
// 	free(shell->prompt);
// 	i = 0;
// 	while (shell->env[i])
// 		free(shell->env[i++]);
// 	free(shell->env);
// 	i = 0;
// 	if (shell->paths)
// 	{
// 		while (shell->paths[i])
// 			free(shell->paths[i++]);
// 		free(shell->paths);
// 	}
// 	if (shell->export)
// 	{
// 		i = 0;
// 		while (shell->export[i])
// 			free(shell->export[i++]);
// 		free(shell->export);
// 	}
// 	exit(g_exit);
// }