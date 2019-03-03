/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** Manages the 3D projections on the 2D window
*/

#include "world.h"

sfVector2f project_iso_point(int x, int y, int z, sfVector2f offset)
{
    sfVector2f my_2d_point = {0, 0};

    my_2d_point.x = offset.x + cos(ANGLE_X) * x - cos(ANGLE_X) * y;
    my_2d_point.y = offset.y + sin(ANGLE_Y) * x + sin(ANGLE_Y) * y - z;
    return (my_2d_point);
}

sfVector2f **create_2d_map(map_t *map)
{
    sfVector2f **my_points;

    my_points = malloc(sizeof(sfVector2f *) * map->props.rows);
    for (int i = 0; i < map->props.rows; i++) {
        my_points[i] = malloc(sizeof(sfVector2f) * map->props.columns);
        for (int j = 0; j < map->props.columns; j++)
            my_points[i][j] = project_iso_point(j * STEP_WINDOW,
i * STEP_WINDOW, map->grid[i][j], map->props.offset);
    }
    return (my_points);
}
