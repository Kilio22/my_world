/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** Everything here is about the displaying part of the map
*/

#include "world.h"

sfVertexArray *create_line(sfVector2f p1, sfVector2f p2)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex vertex1 = {.position = p1, .color = sfBlack};
    sfVertex vertex2 = {.position = p2, .color = sfBlack};

    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_setPrimitiveType(vertex_array, sfLinesStrip);
    return (vertex_array);
}

static void draw_line(sfRenderWindow *window, map_t *map, int i, int j)
{
    grid_point_t **grid = map->grid;
    sfVertexArray *v_array;

    if (j + 1 < map->columns) {
        v_array = create_line((grid[i][j]).point, (grid[i][j + 1]).point);
        sfRenderWindow_drawVertexArray(window, v_array, NULL);
    }
    if (i + 1 < map->rows) {
        v_array = create_line((grid[i][j]).point, (grid[i + 1][j]).point);
        sfRenderWindow_drawVertexArray(window, v_array, NULL);
    }
    return (0);
}

int draw_2d_map(sfRenderWindow *window, map_t *map)
{
    for (int i = 0; i < map->rows; i++) {
        for (int j = 0; j < map->columns; j++) {
            draw_line(window, map, i, j);
        }
    }
    return (0);
}
