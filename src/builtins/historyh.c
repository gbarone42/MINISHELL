#include "../../include/minishell.h"

#define HISTORY_SIZE 100

char* history[HISTORY_SIZE];
int history_count = 0;
//manca il free
void add_to_history(char* command)
{
    add_history(command);
    if (history_count < HISTORY_SIZE)
    {
        history[history_count++] = strdup(command);
    }
    else
    {
        free(history[0]);
        for (int i = 0; i < history_count - 1; ++i)
        {
            history[i] = history[i + 1];
        }
        history[history_count - 1] = strdup(command);
    }
}

void display_history(void)
{
    for (int i = 0; i < history_count; ++i)
    {
        printf("%d: %s\n", i + 1, history[i]);
    }
}
