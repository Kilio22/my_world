/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** event
*/

#include "world.h"

void resize_window(interface_t *face, sfSizeEvent size)
{
    sfView_setSize(face->view, (sfVector2f){size.width, size.height});
}

void analyse_events(interface_t *face, map_t *map, sfEvent event,
                    toolbox_t *tool)
{
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(face->window);
        sfRenderWindow_close(tool->win);
    }
    if (event.type == sfEvtKeyReleased)
        update_button(tool);
    if (event.type == sfEvtKeyPressed)
        analyse_key_pressed(face, map, event.key.code, tool);
    if (event.type == sfEvtMouseWheelMoved)
        manage_zoom(face, event);
    if (event.type == sfEvtResized)
        resize_window(face, event.size);
    if (event.type == 9 || event.type == 10)
        analyse_click(event, event.mouseButton.button);
}
