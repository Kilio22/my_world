/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** Manages the 3D projections on the 2D window
*/

#include "world.h"

sfVector2f project_iso_point(sfVector3f point, map_t *map)
{
    sfVector2f offset = map->offset;
    sfVector2f point_2d = {0, 0};
    double angle_x = map->angle[0];
    double angle_y = map->angle[1];

    point_2d.x = offset.x + cos(angle_x) * point.x - cos(angle_x) * point.y;
    point_2d.y = offset.y + sin(angle_y) * point.x + sin(angle_y) * point.y;
    point_2d.y -= point.z;
    return (point_2d);
}
