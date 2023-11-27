#include "../../include/minishell.h"


void handle_suspend(void)
{
    if (kill(getpid(), SIGTSTP) == -1) {
        perror("suspend");
    }
}
