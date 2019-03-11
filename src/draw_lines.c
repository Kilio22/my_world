/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** Everything here is about the displaying part of the map
*/

#include "world.h"

static sfVertexArray *create_line_corner(sfVector2f p1, sfVector2f p2,
                                         sfRenderWindow *win, map_t *map)
{
    int i = find_corner_color(win, map, p1);
    int j = find_corner_color(win, map, p2);
    sfVertexArray *vertex_array;
    sfVertex vertex = {.position = p1, .color = sfWhite};

    if (i == 0 && j == 0)
        return (NULL);
    vertex_array = sfVertexArray_create();
    if (i == 0)
        vertex.color = sfBlack;
    sfVertexArray_append(vertex_array, vertex);
    vertex.position = p2;
    if (j == 0)
        vertex.color = sfBlack;
    else
        vertex.color = sfWhite;
    sfVertexArray_append(vertex_array, vertex);
    sfVertexArray_setPrimitiveType(vertex_array, sfLinesStrip);
    return (vertex_array);
}

int draw_line_corner(sfRenderWindow *win, map_t *map, int i, int j)
{
    grid_point_t **grid = map->grid;
    sfVertexArray *v_array;

    if (j + 1 < map->columns) {
            v_array = create_line_corner((grid[i][j]).point,
(grid[i][j + 1]).point, win, map);
        if (v_array != NULL)
            sfRenderWindow_drawVertexArray(win, v_array, NULL);
    }
    if (i + 1 < map->rows) {
            v_array = create_line_corner((grid[i][j]).point,
(grid[i + 1][j]).point, win, map);
        if (v_array != NULL)
            sfRenderWindow_drawVertexArray(win, v_array, NULL);
    }
    return (0);
}

static sfVertexArray *create_line(sfVector2f points[2], sfColor color)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex vertex1 = {.position = points[0], .color = color};
    sfVertex vertex2 = {.position = points[1], .color = color};

    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_setPrimitiveType(vertex_array, sfLinesStrip);
    return (vertex_array);
}

void draw_lines(sfRenderWindow *win, map_t *map, int i, int j)
{
    grid_point_t **grid = map->grid;
    sfColor color = sfBlack;
    sfVertexArray *v_array;
    sfVector2f points[2];

    points[0] = (grid[i][j]).point;
    if (j + 1 < map->columns) {
        points[1] = (grid[i][j + 1]).point;
        v_array = create_line(points, color);
        sfRenderWindow_drawVertexArray(win, v_array, NULL);
    }
    if (i + 1 < map->rows) {
        points[1] = (grid[i + 1][j]).point;
        v_array = create_line(points, color);
        sfRenderWindow_drawVertexArray(win, v_array, NULL);
    }
}