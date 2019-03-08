/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** Manages the 3D projections on the 2D window
*/

#include "world.h"

sfVector2f project_iso_point(sfVector3f point, sfVector2f offset)
{
    sfVector2f point_2d = {0, 0};

    point_2d.x = offset.x + cos(ANGLE_X) * point.x - cos(ANGLE_X) * point.y;
    point_2d.y = offset.y + sin(ANGLE_Y) * point.x + sin(ANGLE_Y) * point.y;
    point_2d.y -= point.z;
    return (point_2d);
}
