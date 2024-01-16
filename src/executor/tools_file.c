#include "../includes/minishell.h"

void	close_fd(int fd)
{
	if (fd > -1)
		close(fd);
}
