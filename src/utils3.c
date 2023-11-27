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


