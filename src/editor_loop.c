/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** Contains the loop responsible of the editor
*/

#include "world.h"

int loop_editor(sfRenderWindow *window, map_t *map)
{ 
    while (sfRenderWindow_isOpen(window)) {
        if (analyse_events(window, map) == 1)
            break;
        draw_triangle(window, map);
        draw_2d_map(window, map);
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfBlack);
    }
    sfRenderWindow_close(window);
    sfRenderWindow_destroy(window);
    return (0);
}
