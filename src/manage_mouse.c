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
    status = tag;
    return (-1);
}

void manage_mouse(interface_t *face, map_t *map)
{
    switch (transfer_mouse_press(-1)) {
        case 1:
            return (face->action(face, map));
        case 2:
            return (face->action(face, map));
        default:
            break;
    }
}
