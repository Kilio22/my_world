/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** mouse
*/

#include "world.h"

int transfer_mouse_press(int tag)
{
    static int status = 0;

    if (tag == -1)
        return (status);
    else
        status = tag;
    return (-1);
}

void manage_mouse(map_t *map, sfRenderWindow *win)
{
    switch (transfer_mouse_press(-1)) {
        case -1:
            return;
        case 1:
            return (map->action(win, map));
        case 2:
            break;
        default:
            break;
    }
}