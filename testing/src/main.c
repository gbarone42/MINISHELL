#include "testing_p.h"

int main(void)
{
	char *cwd = getcwd(NULL, 0);
	printf("%s\n", cwd);
	free(cwd);
	return (0);
}
