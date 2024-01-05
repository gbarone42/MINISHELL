#include "testing_p.h"

int main(int argc, char **argv, char **envp)
{
	char	*newargv[] = {"/usr/bin/bash", "-c", "./test", NULL};

	(void) argc;
	(void) argv;
	execve("/usr/bin/bash", newargv, envp);
	perror("execve");
	exit(EXIT_FAILURE);
}
