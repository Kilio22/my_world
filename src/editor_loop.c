/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** Contains the loop responsible of the editor
*/

#include "world.h"

void display_toolbox(interface_t *face, toolbox_t *toolbox, map_t *map)
{
    sfEvent event;

    (void) map;
    while (sfRenderWindow_pollEvent(toolbox->win, &event))
            analyse_events_win2(event, toolbox, face);
    for (int i = 0; i < 6; i++)
        sfRenderWindow_drawSprite(toolbox->win, toolbox->sprites[i], NULL);
    check_zoom(toolbox, face);
    sfRenderWindow_display(toolbox->win);
    sfRenderWindow_clear(toolbox->win, toolbox_color);
}

int loop_editor(interface_t *face, map_t *map, toolbox_t *tool)
{
    sfEvent event;

    while (sfRenderWindow_isOpen(face->window)) {
        while (sfRenderWindow_pollEvent(face->window, &event))
            analyse_events(face, map, event, tool);
        manage_mouse(face, map);
        sfRenderWindow_setView(face->window, face->view);
        draw_tiles(face, map);
        face->highlight(face, map);
        sfRenderWindow_display(face->window);
        sfRenderWindow_clear(face->window, sfBlack);
        display_toolbox(face, tool, map);
    }
    sfRenderWindow_destroy(face->window);
    return (0);
}
