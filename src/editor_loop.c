/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** Contains the loop responsible of the editor
*/

#include "world.h"

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
        if (map->name == NULL) {
            sfRenderWindow_close(face->window);
            sfRenderWindow_close(tool->win);
        }
    }
    sfRenderWindow_destroy(face->window);
    sfRenderWindow_destroy(tool->win);
    return (0);
}
