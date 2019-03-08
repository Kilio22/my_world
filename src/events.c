/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** event
*/

#include "world.h"

void manage_arrows(sfEvent event, map_t *map)
{
    if (event.key.code == sfKeyLeft)
        map->offset.x -= 5;
    if (event.key.code == sfKeyRight)
        map->offset.x += 5;
    if (event.key.code == sfKeyDown)
        map->offset.y += 5;
    if (event.key.code == sfKeyUp)
        map->offset.y -= 5;
    update_points(map);
}

int analyse_events(sfRenderWindow *window, map_t *map)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            return (1);
        if (event.type == sfEvtKeyPressed &&
event.key.code >= sfKeyLeft && event.key.code <= sfKeyDown)
            manage_arrows(event, map);
    }
    return (0);
}
