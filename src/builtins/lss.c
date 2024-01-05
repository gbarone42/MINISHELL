#include "../../include/minishell.h"
#include <time.h>

//no builtin
//here i use readdir(), its ookay
void print_current_directory_contents(void)
{
	DIR *dir = opendir(".");
	struct dirent *entry;

	if (dir == NULL)
	{
		perror("opendir");
		return;
	}

	while ((entry = readdir(dir)) != NULL)
	{
		printf("%s\n", entry->d_name);
	}

	closedir(dir);
}
