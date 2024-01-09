#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int super_read(int fd, char *buffer, int len)
{
    static int call = 0;

    if (call++ < 10000000)
        return (read(fd, buffer, len));
    else
        return (-1);
}

void *super_malloc(size_t len)
{
    static int call = 0;

    if (call++ < 10000000)
        return (malloc(len));
    else
        return (NULL);
}

#include "get_next_line_bonus.h"

int main(void)
{
    int iteration = 0;
    char *buffer;
    while (iteration < 1040)
    {
        int fd = open("test.txt", O_RDONLY);
        buffer = get_next_line(fd);
        printf("fd %d : %s\n", fd, buffer);
        free(buffer);
        iteration++;
    }
}
