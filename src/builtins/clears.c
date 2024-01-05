#include "../../include/minishell.h"

//no builtin

void clear_screen(void)
{
    write(STDOUT_FILENO, "\033[H\033[J", 7);
}