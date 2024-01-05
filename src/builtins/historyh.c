#include "../../include/minishell.h"

void add_to_history(t_history *history, char* command)
{
	add_history(command); // Assuming add_history is a function from a library
	if (history->count < HISTORY_SIZE)
	{
		history->entries[history->count++] = strdup(command);
		//free(history->entries[0]);
		
	}
	else
	{
		free(history->entries[0]);
		for (int i = 0; i < history->count - 1; ++i) {
			history->entries[i] = history->entries[i + 1];
		}
		history->entries[history->count - 1] = strdup(command);
	}
	 free(command);
}
//some memory issue here