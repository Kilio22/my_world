/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** reset_map
*/

#include "world.h"

void reset_map_altitude(map_t *map)
{
    for (int i = 0; i < map->rows; i++) {
        for (int j = 0; j < map->columns; j++)
            map->grid[i][j].altitude = 0;
    }
    update_points(map);
}