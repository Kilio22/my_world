/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** Draws the overall map
*/

#include "world.h"

sfColor get_color_fromheight(int altitude)
{
    sfColor color;

    (void) altitude;
    color = sfGreen;
    return (color);
}

static void call_draw_square(sfRenderWindow *win, map_t *map, int i, int j)
{
    sfColor square_color = get_color_fromheight((map->grid[i][j]).altitude);

    if (i < map->rows - 1 && j < map->columns - 1)
        draw_square(win, &map->grid[i], j, square_color);
}

int draw_tiles(interface_t *face, map_t *map)
{
    for (int i = 0; i < map->rows; i++) {
        for (int j = 0; j < map->columns; j++) {
            call_draw_square(face->window, map, i, j);
            draw_lines(face, map, i, j);
        }
    }
    return (0);
}
