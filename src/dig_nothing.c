/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** dig_nothing
*/

#include "world.h"

void reset_corner_altitude(map_t *map, int i, int j)
{
    map->grid[i][j].altitude = 0;
    update_points(map);
}

void reset_corner(interface_t *face, map_t *map)
{
    int *index = transfer_indexes(NULL);

    if (index == NULL) {
        update_selected_point(face, map);
        index = transfer_indexes(NULL);
    }
    reset_corner_altitude(map, index[0], index[1]);
}

int reset_square_altitude(interface_t *face, map_t *map, int i, int j)
{
    if (!is_on_tile(face, &map->grid[i], j))
        return (0);
    map->grid[i][j].altitude = 0;
    map->grid[i][j + 1].altitude = 0;
    map->grid[i + 1][j + 1].altitude = 0;
    map->grid[i + 1][j].altitude = 0;
    update_points(map);
    return (1);
}

void reset_square(interface_t *face, map_t *map)
{
    int n_return = 0;

    for (int i = map->rows - 2; i >= 0; i--) {
        for (int j = map->columns - 2; j >= 0 && n_return == 0; j--)
            n_return = reset_square_altitude(face, map, i, j);
        if (n_return == 1)
            break;
    }
}
