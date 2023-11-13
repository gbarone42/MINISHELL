#include "../include/minishell.h"

void *ft_memset(void *b, int c, size_t len)
{
    if (b == NULL || len == 0) {
        return NULL;
    }
    unsigned char *ptr = (unsigned char *)b;
    unsigned char value = (unsigned char)c;
    size_t i = 0;
    while (i < len) {
        ptr[i] = value;
        i++;
    }
    return b;
}

// In this version, the function still checks for null pointers and zero length.
// It then uses a while loop to set the memory locations to the specified value until the entire range is covered.
// The variable i is incremented within the loop to keep track of the progress.
// This implementation achieves the same functionality as the previous version but uses a while loop instead of a for loop.


void *ft_memcpy(void *dst, const void *src, size_t n)
{
    size_t i = 0;
    char *s1 = (char *)dst;
    const char *s2 = (const char *)src;

    while (i < n) {
        s1[i] = s2[i];
        i++;
    }

    return dst;
}


