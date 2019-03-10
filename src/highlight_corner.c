/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** Functions used to highlight the corner the cursor is on
*/

#include "world.h"

static int highlight_on_cursor(sfRenderWindow *win, map_t *map, int i)
{
    for (int j = map->columns - 1; j >= 0; j--) {
        draw_line_corner(win, map, i, j);
    }
    return (0);
}

void highlight_corner(sfRenderWindow *win, map_t *map)
{
    for (int i = map->rows - 1; i >= 0; i--) {
        highlight_on_cursor(win, map, i);
    }
}
