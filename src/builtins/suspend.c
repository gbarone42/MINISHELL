#include "../../include/minishell.h"


void handle_suspend(void)
{
    // Send a SIGTSTP signal to suspend the shell
    if (kill(getpid(), SIGTSTP) == -1) {
        perror("suspend");
    }
}
