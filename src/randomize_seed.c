/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** randomize_seed
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void setup_random_seed(void)
{
    int fd = open("/dev/urandom", O_RDONLY);
    unsigned int seed;
    ssize_t n_read;

    if (fd == -1) {
        srand(84);
    } else {
        n_read = read(fd, &seed, sizeof(seed));
        if (n_read != sizeof(seed))
            srand(84);
        else
            srand(seed);
        close(fd);
    }
}
