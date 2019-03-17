/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** Functions used to highlight the corner the cursor is on
*/

#include "world.h"


static void display_vertex(sfRenderWindow *win, sfVertexArray *v_array)
{
    sfRenderWindow_drawVertexArray(win, v_array, NULL);
    sfVertexArray_destroy(v_array);
}

static int highlight_on_cursor(interface_t *face, map_t *map, int i)
{
    for (int j = map->columns - 1; j >= 0; j--) {
        draw_line_corner(face, map, i, j);
    }
    return (0);
}

static void highlight_point(sfRenderWindow *win, map_t *map, int i, int j)
{
    grid_point_t **grid = map->grid;
    sfVertexArray *v_array;

    if (i - 1 >= 0) {
        v_array = create_holding_line(grid[i - 1][j].point, grid[i][j].point);
        display_vertex(win, v_array);
    }
    if (i + 1 < map->rows) {
        v_array = create_holding_line(grid[i + 1][j].point, grid[i][j].point);
        display_vertex(win, v_array);
    }
    if (j - 1 >= 0) {
        v_array = create_holding_line(grid[i][j - 1].point, grid[i][j].point);
        display_vertex(win, v_array);
    }
    if (j + 1 < map->columns) {
        v_array = create_holding_line(grid[i][j + 1].point, grid[i][j].point);
        display_vertex(win, v_array);
    }
}

void highlight_corner(interface_t *face, map_t *map)
{
    int *indexes = transfer_indexes(NULL);

    if (indexes != NULL) {
        highlight_point(face->window, map, indexes[0], indexes[1]);
    } else {
        for (int i = map->rows - 1; i >= 0; i--) {
            highlight_on_cursor(face, map, i);
        }
    }
}
