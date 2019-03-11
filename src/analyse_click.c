/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** Analyses the click
*/

#include "world.h"

static void reset_mouse_click(void)
{
    transfer_indexes((void *) 1);
    transfer_mouse_press(0);
}

void analyse_click(sfEvent event, sfMouseButton clicked)
{
    int current_mouse_id = transfer_mouse_press(-1);

    if (event.type == sfEvtMouseButtonReleased) {
        if (clicked == sfMouseLeft && current_mouse_id == 1)
            reset_mouse_click();
        if (clicked == sfMouseRight && current_mouse_id == 2)
            reset_mouse_click();
    } else if (event.type == sfEvtMouseButtonPressed) {
        if (current_mouse_id != 0)
            return;
        if (clicked == sfMouseLeft)
            transfer_mouse_press(1);
        else if (clicked == sfMouseRight)
            transfer_mouse_press(2);
    }
}
