/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** event
*/

#include "world.h"

void manage_arrows(princi_t *princi)
{
    if (princi->event.key.code == sfKeyLeft)
        princi->step_x -= 5;
    if (princi->event.key.code == sfKeyRight)
        princi->step_x += 5;
    if (princi->event.key.code == sfKeyDown)
        princi->step_y += 5;
    if (princi->event.key.code == sfKeyUp)
        princi->step_y -= 5;
    princi->my_points = create_2d_map(princi->map, princi);
}

int check_event(princi_t *princi)
{
    while (sfRenderWindow_pollEvent(princi->window, &princi->event)) {
        if (princi->event.type == sfEvtClosed)
            return (1);
        if (princi->event.type == sfEvtKeyPressed &&
princi->event.key.code >= sfKeyLeft && princi->event.key.code <= sfKeyDown)
            manage_arrows(princi);
    }
    return (0);
}
