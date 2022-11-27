#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 4096

void exit_sys(const char *err);

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        fprintf(stderr, "Wrong number of arguments!...\n");
        exit(EXIT_FAILURE);
    }

    int fds;
    if ((fds = open(argv[1], O_RDONLY)) == -1)
        exit_sys(argv[1]);

    int fdd;
    if ((fdd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU | S_IRGRP | S_IROTH)) == -1)
        exit_sys(argv[2]);

    char buf[BUFFER_SIZE];
    ssize_t read_result;
    while ((read_result = read(fds, buf, BUFFER_SIZE)) > 0)
    {
        ssize_t write_size;
        if ((write_size = write(fdd, buf, read_result)) == -1)
            exit_sys("write");
        if (write_size != read_result)
        {
            fprintf(stderr, "Cannot write file!...\n");
            exit(EXIT_FAILURE);
        }
    }

    if (read_result == -1)
        exit_sys("read");

    close(fds);
    close(fdd);
}

void exit_sys(const char *err)
{
    perror(err);

    exit(EXIT_FAILURE);
}