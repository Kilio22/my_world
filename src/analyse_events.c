/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** event
*/

#include "world.h"

int check_clock_save_status(interface_t *face)
{
    sfTime time;
    float seconds;

    time = sfClock_getElapsedTime(face->clock_save);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.3) {
        sfClock_restart(face->clock_save);
        return (1);
    }
    return (0);
}

void resize_window(interface_t *face, sfSizeEvent size)
{
    sfView_setSize(face->view, (sfVector2f){size.width, size.height});
}

void analyse_events(interface_t *face, map_t *map, sfEvent event,
                    toolbox_t *tool)
{
    if (event.type == sfEvtClosed || event.key.code == sfKeyEscape) {
        sfRenderWindow_close(face->window);
        sfRenderWindow_close(tool->win);
    }
    if (event.key.control == sfTrue && event.key.code == sfKeyS
&& check_clock_save_status(face))
        save_map(map);
    if (event.key.control == sfTrue && event.key.code == sfKeyO
&& check_clock_save_status(face))
        load_new_map(face, map);
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
