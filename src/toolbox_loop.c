/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** toolbox_loop
*/

#include "world.h"

void check_tool_color(toolbox_t *tool, int i)
{
    if (tool->state[i] == 0)
        sfSprite_setColor(tool->sprites[i], sfWhite);
    if (tool->state[i] == 2)
        sfSprite_setColor(tool->sprites[i], sfRed);
}

void display_text(toolbox_t *tool)
{
    sfVector2i m = sfMouse_getPositionRenderWindow(tool->win);
    sfVector2f mouse = {m.x, m.y};
    sfVector2f text_pos = {m.x - 30, m.y + 20};

    for (int i = 0; i < 6; i++) {
        if (is_on_button_bool(tool->sprites[i], mouse)) {
            sfText_setPosition(tool->text[i], text_pos);
            sfRenderWindow_drawText(tool->win, tool->text[i], NULL);
        }
        if (is_on_button_bool(tool->sprites[i], mouse) && (tool->state[i] == 0
|| tool->state[i] == 2))
            sfSprite_setColor(tool->sprites[i], hover);
        else
            check_tool_color(tool, i);
    }
}

void display_toolbox(interface_t *face, toolbox_t *toolbox, map_t *map)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(toolbox->win, &event))
            analyse_events_win2(event, toolbox, face);
    for (int i = 0; i < 6; i++)
        sfRenderWindow_drawSprite(toolbox->win, toolbox->sprites[i], NULL);
    display_text(toolbox);
    check_zoom(toolbox, face);
    check_warning(map);
    sfRenderWindow_display(toolbox->win);
    sfRenderWindow_clear(toolbox->win, toolbox_color);
}