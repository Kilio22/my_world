/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** manage_viewmode
*/

#include "world.h"

void manage_rotate(sfKeyCode key, map_t *map)
{
    if (key == sfKeyLeft)
        map->angle_degrees[0] += 1;
    if (key == sfKeyRight)
        map->angle_degrees[0] -= 1;
    if (key == sfKeyDown)
        map->angle_degrees[1] -= 1;
    if (key == sfKeyUp)
        map->angle_degrees[1] += 1;
    map->angle[0] = IN_RADIANS(map->angle_degrees[0]);
    map->angle[1] = IN_RADIANS(map->angle_degrees[1]);
    update_points(map);
}

void manage_translation(sfKeyCode key, map_t *map)
{
    if (key == sfKeyLeft)
        map->offset.x += 15;
    if (key == sfKeyRight)
        map->offset.x -= 15;
    if (key == sfKeyDown)
        map->offset.y -= 15;
    if (key == sfKeyUp)
        map->offset.y += 15;
    update_points(map);
}
