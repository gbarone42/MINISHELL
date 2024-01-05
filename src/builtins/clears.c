#include "../../include/minishell.h"

void clear_screen(void)
{
    write(STDOUT_FILENO, "\033[H\033[J", 7);
}
