#include "../../include/minishell.h"


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