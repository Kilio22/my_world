/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** event_win2
*/

#include "world.h"

void transformation_mode_tool(interface_t *face, toolbox_t *tool)
{
    if (tool->state[3] == 0)
        face->viewmode = translation;
    if (tool->state[3] == 2)
        face->viewmode = rotation;
}

void update_button(toolbox_t *toolbox)
{
    for (int i = 0; i < 4; i++) {
        if (toolbox->state[i] == 1) {
            sfSprite_setColor(toolbox->sprites[i], sfRed);
            toolbox->state[i] = 2;
        }
    }
    for (int i = 4; i < NB_BUTTONS; i++) {
        toolbox->state[i] = 0;
        sfSprite_setColor(toolbox->sprites[i], sfWhite);
    }
}

void analyse_events_win2(sfEvent event, toolbox_t *tool, interface_t *face,
map_t *map)
{
    sfVector2f mouse_pos;

    if (event.type == sfEvtClosed)
        sfRenderWindow_close(tool->win);
    if (event.type == sfEvtMouseButtonPressed &&
event.mouseButton.button == sfMouseLeft) {
        mouse_pos.x = event.mouseButton.x;
        mouse_pos.y = event.mouseButton.y;
        is_on_button(tool, mouse_pos, face, map);
    }
    if (event.type == sfEvtMouseButtonReleased)
        update_button(tool);
    transformation_mode_tool(face, tool);
}