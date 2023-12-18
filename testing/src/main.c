#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	char *buf = NULL;
	chdir("..");
	char *cwd = getcwd(buf, 0);
	printf("%s\n", cwd);
	free(cwd);
	return (0);
}

