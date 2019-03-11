/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** event
*/

#include "world.h"

void resize_window(map_t *map, sfSizeEvent size)
{
    sfView_setSize(map->view, (sfVector2f){size.width, size.height});
}

void analyse_events(sfRenderWindow *window, map_t *map, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event.type == sfEvtKeyPressed)
        analyse_key_pressed(window, map, event.key.code);
    if (event.type == sfEvtMouseWheelMoved)
        manage_zoom(window, map, event);
    if (event.type == sfEvtResized)
        resize_window(map, event.size);
    if (event.type == 9 || event.type == 10)
        analyse_click(event, event.mouseButton.button);
}
