/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** Has the same behavious as the access command
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/* Right now, the function only keeps the mode == 0 */

static int is_folder(const char *pathname)
{
    int fd = open(pathname, __O_DIRECTORY);

    close(fd);
    if (fd != -1)
        return (1);
    return (0);
}

int my_access(const char *pathname, int mode)
{
    int fd;

    if (mode != 0)
        return (0);
    if (is_folder(pathname))
        return (0);
    fd = open(pathname, O_RDONLY);
    close(fd);
    if (fd != -1)
        return (1);
    return (0);
}
