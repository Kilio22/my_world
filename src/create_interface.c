/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** Creates the interface of the main window
*/

#include "world.h"

interface_t *create_interface(void)
{
    interface_t *interface = malloc(sizeof(interface_t));
    sfVector2f vrec = {window_x, window_y};
    sfVector2i wrec = {window_x, window_y};

    interface->window = create_window(window_x, window_y, wrec, "World editor");
    interface->viewmode = translation;
    interface->mode = square;
    interface->view = sfView_create();
    interface->highlight = highlight_square;
    interface->action = dig_up_square;
    sfView_setSize(interface->view, vrec);
    return (interface);
}
