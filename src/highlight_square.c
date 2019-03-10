/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** Functions used to highlight the square the cursor is on
*/

#include "world.h"

static int highlight_on_cursor(sfRenderWindow *win, map_t *map, int i)
{
    for (int j = map->columns - 2; j >= 0; j--) {
        if (is_on_tile(win, map, &map->grid[i], j) == 1) {
            draw_square(win, &map->grid[i], j, sfWhite);
            draw_lines(win, map, i, j);
            draw_lines(win, map, i + 1, j); // dans certains cas c'est pas ouf
            draw_lines(win, map, i, j + 1); // dans certains cas c'est pas ouf
            return (1);
        }
    }
    return (0);
}

void highlight_square(sfRenderWindow *win, map_t *map)
{
    for (int i = map->rows - 2; i >= 0; i--) {
        if (highlight_on_cursor(win, map, i) == 1)
            return;
    }
}
