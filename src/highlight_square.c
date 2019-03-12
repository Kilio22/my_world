/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** Functions used to highlight the square the cursor is on
*/

#include "world.h"

static int highlight_on_cursor(interface_t *face, map_t *map, int i)
{
    sfVertexArray *v_array;
    sfVector2f pos[2];

    for (int j = map->columns - 2; j >= 0; j--) {
        if (is_on_tile(face, &map->grid[i], j) == 1) {
            draw_square(face->window, &map->grid[i], j, sfWhite);
            draw_lines(face, map, i, j);
            pos[0] = map->grid[i + 1][j].point;
            pos[1] = map->grid[i + 1][j + 1].point;
            v_array = create_line(pos, sfBlack);
            sfRenderWindow_drawVertexArray(face->window, v_array, NULL);
            pos[0] = map->grid[i][j + 1].point;
            v_array = create_line(pos, sfBlack);
            sfRenderWindow_drawVertexArray(face->window, v_array, NULL);
            return (1);
        }
    }
    return (0);
}

void highlight_square(interface_t *face, map_t *map)
{
    for (int i = map->rows - 2; i >= 0; i--) {
        if (highlight_on_cursor(face, map, i) == 1)
            return;
    }
}
