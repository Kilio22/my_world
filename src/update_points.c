/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** Updates the projected points
*/

#include "world.h"

void update_points(map_t *map)
{
    sfVector3f point;

    for (int i = 0; i < map->rows; i++) {
        for (int j = 0; j < map->columns; j++) {
            point = (sfVector3f) {
                j * map->step,
                i * map->step,
                (map->grid[i][j]).altitude
            };
            (map->grid[i][j]).point = project_iso_point(point, map->offset);
        }
    }
}
