#include "../../include/minishell.h"

int	g_exit = 0;

// The code has several hard-coded values (like ANSI color codes, and prompts)
// and magic numbers (like 130 for exit status), which would be better defined
// as constants or configurable through the environment or arguments.

int	main(int ac, char **av, char **env)
{

	//char	*str;
	t_shell	my_shell;
	int output;

	memset(&my_shell, 0, sizeof(t_shell));
	
	//shell = (t_shell *)ft_calloc(1, sizeof(t_shell));
	//str = "okok";
	
	(void)ac;
	(void)av;
	printf("%sWelcome %s!%s\n", GREEN, getenv("USER"), CLR_RMV);
	output = ft_innit_shell(&my_shell, env);//init
	if(output != 0)
	{
		//free();
		exit(output);
	}
	ft_norm_signal();//signals
	
	//str = readline(str);
	
	ft_minishell_simulator(&my_shell);


	    // In case ft_minishell_simulator returns without exiting, clean up.
    // if (my_shell != NULL) {
    //     shell_exit(&my_shell);
    // }
	// ft_destroy_shell(shell);

	return (EXIT_SUCCESS); //return(0a);
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