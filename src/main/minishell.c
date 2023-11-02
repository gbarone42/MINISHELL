#include "../../include/minishell.h"

int	g_exit = 0;

static void	ft_norm_signal(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, signal_handler);
}


int	main(int ac, char **av, char **env)
{

	//char	*str;
	t_shell	shell;


	//shell = (t_shell *)ft_calloc(1, sizeof(t_shell));

	//str = "okok";
	
	(void)ac;
	(void)av;
	printf("%sWelcome %s!%s\n", GREEN, getenv("USER"), CLR_RMV);
	ft_innit_shell(&shell, env);//init
	ft_norm_signal();//signals
	
	//str = readline(str);
	
	ft_minishell_simulator(&shell);

	// ft_destroy_shell(shell);

    return (0); //return(EXIT_SUCCESS);
}         


//while (!shell->exit)
//


// EXIT_SUCCESS is defined as 0
// EXIT_FAILURE is defined as 1
// 
//	they are both defined in <stdlib.h>



// void ft_destroy_shell(t_shell *shell) {
//     if (shell->env) {
//         for (int i = 0; shell->env[i] != NULL; ++i) {
//             free(shell->env[i]); // Free each string
//         }
//         free(shell->env); // Free the array
//     }
//
//     if (shell->prompt) {
//         free(shell->prompt); // Free the prompt string if it was allocated
//     }
//
//     // ...free any other dynamically allocated fields within `shell`...
//
//     free(shell); // Finally, free the shell structure itself
// }