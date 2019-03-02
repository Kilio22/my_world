/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** math
*/

#include "world.h"

sfVector2f project_iso_point(int x, int y, int z, princi_t *princi)
{
    sfVector2f my_2d_point = {0, 0};

    my_2d_point.x = cos(ANGLE_X) * x - cos(ANGLE_X) * y + princi->step_x;
    my_2d_point.y = sin(ANGLE_Y) * y + sin(ANGLE_Y) * x - z + princi->step_y;
    return (my_2d_point);
}

sfVector2f **create_2d_map(int **my_3d_map, princi_t *princi)
{
    sfVector2f **my_points;

    my_points = malloc(sizeof(sfVector2f *) * (MAP_Y));
    for (int i = 0; i < MAP_Y; i++) {
        my_points[i] = malloc(sizeof(sfVector2f) * MAP_X);
        for (int j = 0; j < MAP_X; j++)
            my_points[i][j] =
project_iso_point(j * STEP_WINDOW, i * STEP_WINDOW, my_3d_map[i][j], princi);
    }
    return (my_points);
}