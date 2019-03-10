/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** Contains the loop responsible of the editor
*/

#include "world.h"

int loop_editor(sfRenderWindow *window, map_t *map)
{
    sfEvent event;
    sfSprite *cursor = load_cursor();

    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event))
            analyse_events(window, map, event);
        manage_mouse(map, window);
        sfRenderWindow_setView(window, map->view);
        draw_tiles(window, map);
        map->highlight(window, map);
        update_cursor_position(map, window, cursor);
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfBlack);
    }
    sfRenderWindow_destroy(window);
    return (0);
}
