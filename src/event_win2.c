/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** event_win2
*/

#include "world.h"

void update_button(toolbox_t *toolbox)
{
    for (int i = 0; i < 2; i++)
        if (toolbox->state[i] == 1) {
            sfSprite_setColor(toolbox->sprites[i], sfRed);
            toolbox->state[i] = 2;
        }
}

void analyse_events_win2(sfEvent event, toolbox_t *tool, map_t *map)
{
    sfVector2f mouse_pos;

    if (event.type == sfEvtClosed)
        sfRenderWindow_close(tool->win);
    if (event.type == sfEvtMouseButtonPressed &&
event.mouseButton.button == sfMouseLeft) {
        mouse_pos.x = event.mouseButton.x;
        mouse_pos.y = event.mouseButton.y;
        is_on_button(tool, mouse_pos, map);
    }
    if (event.type == sfEvtMouseButtonReleased)
        update_button(tool);
}