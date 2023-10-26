#include "../../include/minishell.h"

int	main(int ac, char **av)
{

	(void)ac;
	(void)av;
	printf("%sWelcome %s!%s\n", GREEN, getenv("USER"), CLR_RMV);
    return (0);
}


