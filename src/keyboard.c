/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** keyboard
*/

#include "world.h"

void change_mode(map_t *map)
{
    if (map->mode == tile)
        map->mode = corner;
    else
        map->mode = tile;
}

void manage_arrows(sfEvent event, map_t *map)
{
    if (event.key.code == sfKeyLeft)
        map->offset.x += 5;
    if (event.key.code == sfKeyRight)
        map->offset.x -= 5;
    if (event.key.code == sfKeyDown)
        map->offset.y -= 5;
    if (event.key.code == sfKeyUp)
        map->offset.y += 5;
    update_points(map);
}

void analyse_key_pressed(sfEvent event, map_t *map)
{
    if (event.key.code >= sfKeyLeft && event.key.code <= sfKeyDown)
        manage_arrows(event, map);
    if (event.key.code == sfKeyS)
        change_mode(map);
}