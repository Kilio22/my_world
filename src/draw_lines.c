/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** Everything here is about the displaying part of the map
*/

#include "world.h"

sfVertexArray *create_line_corner(sfVector2f p1, sfVector2f p2,
                        sfRenderWindow *win, map_t *map)
{
    int i = find_corner_color(win, map, p1);
    int j = find_corner_color(win, map, p2);
    sfColor color1 = (i == 1 ? sfWhite : sfBlack);
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex vertex1 = {.position = p1, .color = color1};
    sfColor color2 = (j == 1 ? sfWhite : sfBlack);
    sfVertex vertex2 = {.position = p2, .color = color2};

    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_setPrimitiveType(vertex_array, sfLinesStrip);
    return (vertex_array);
}

sfVertexArray *create_line(sfVector2f p1, sfVector2f p2,
                        sfRenderWindow *win, map_t *map)
{
    sfColor color = sfBlack;
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex vertex1 = {.position = p1, .color = color};
    sfVertex vertex2 = {.position = p2, .color = color};

    (void) win;
    (void) map;
    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_setPrimitiveType(vertex_array, sfLinesStrip);
    return (vertex_array);
}

static int draw_line_corner(sfRenderWindow *win, map_t *map, int i, int j)
{
    grid_point_t **grid = map->grid;
    sfVertexArray *v_array;

    if (j + 1 < map->columns) {
            v_array = create_line_corner((grid[i][j]).point,
(grid[i][j + 1]).point, win, map);
        sfRenderWindow_drawVertexArray(win, v_array, NULL);
    }
    if (i + 1 < map->rows) {
            v_array = create_line_corner((grid[i][j]).point,
(grid[i + 1][j]).point, win, map);
        sfRenderWindow_drawVertexArray(win, v_array, NULL);
    }
    return (0);
}

static int draw_line(sfRenderWindow *win, map_t *map, int i, int j)
{
    grid_point_t **grid = map->grid;
    sfVertexArray *v_array;

    if (j + 1 < map->columns) {
        if (map->mode == tile)
            v_array = create_line((grid[i][j]).point, (grid[i][j + 1]).point,
win, map);
        sfRenderWindow_drawVertexArray(win, v_array, NULL);
    }
    if (i + 1 < map->rows) {
        if (map->mode == tile)
            v_array = create_line((grid[i][j]).point, (grid[i + 1][j]).point,
win, map);
        sfRenderWindow_drawVertexArray(win, v_array, NULL);
    }
    return (0);
}

int draw_2d_map(sfRenderWindow *window, map_t *map)
{
    for (int i = 0; i < map->rows; i++) {
        for (int j = 0; j < map->columns; j++) {
            map->mode == tile ? draw_line(window, map, i, j) : draw_line_corner(window, map, i, j);
        }
    }
    return (0);
}
