/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** Saves the given map
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "my_printf.h"
#include "world.h"

static void write_map_in_file(map_t *map, int fd, int i)
{
    for (int j = 0; j < map->columns; j++) {
        if (j == map->columns - 1)
            my_dprintf(fd, "%d\n", map->grid[i][j].altitude);
        else
            my_dprintf(fd, "%d ", map->grid[i][j].altitude);
    }
}

int save_map(map_t *map)
{
    int fd;

    if (my_access(map->name, 1))
        return (-1);
    fd = open(map->name, O_CREAT | O_WRONLY, FILE_RIGHTS);
    if (fd == -1)
        return (-1);
    my_dprintf(fd, "%d %d\n", map->rows, map->columns);
    for (int i = 0; i < map->rows; i++)
        write_map_in_file(map, fd, i);
    close(fd);
    return (0);
}
