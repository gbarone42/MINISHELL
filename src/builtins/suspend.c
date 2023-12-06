#include "../../include/minishell.h"

//here i use getpid()

void handle_suspend(void)
{
    if (kill(getpid(), SIGTSTP) == -1) {
        perror("suspend");
    }
}
