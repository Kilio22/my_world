/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** draw
*/

#include "world.h"

sfVertexArray *create_triangle(sfVector2f *p1, sfVector2f *p2, sfVector2f *p3)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex vertex1 = {.position = *p1, .color = sfRed};
    sfVertex vertex2 = {.position = *p2, .color = sfRed};
    sfVertex vertex3 = {.position = *p3, .color = sfRed};

    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_append(vertex_array, vertex3);
    sfVertexArray_setPrimitiveType(vertex_array, sfTrianglesStrip);
    return (vertex_array);
}

sfVertexArray *create_line(sfVector2f *p1, sfVector2f *p2)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex vertex1 = {.position = *p1, .color = sfBlack};
    sfVertex vertex2 = {.position = *p2, .color = sfBlack};

    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_setPrimitiveType(vertex_array, sfLinesStrip);
    return (vertex_array);
}

int draw_2d_map(sfRenderWindow *window, map_t *map)
{
    sfVertexArray *vertex_array;
    sfVector2f **points = map->points;

    for (size_t i = 0; i < map->props.rows; i++) {
        for (size_t j = 0; j < map->props.columns; j++) {
            if (j + 1 < map->props.columns)
                vertex_array = create_line(&points[i][j], &points[i][j + 1]);
            sfRenderWindow_drawVertexArray(window, vertex_array, NULL);
            if (i + 1 < map->props.rows)
                vertex_array = create_line(&points[i][j], &points[i + 1][j]);
            sfRenderWindow_drawVertexArray(window, vertex_array, NULL);
        }
    }
    return (0);
}

void manage_triangles(sfRenderWindow *window, map_t *map, size_t i, size_t j)
{
    sfVertexArray *vertex_array;
    sfVector2f **points = map->points;

    if (i + 1 < map->props.rows && j + 1 < map->props.columns) {
        vertex_array =
create_triangle(&points[i][j], &points[i][j + 1], &points[i + 1][j]);
        sfRenderWindow_drawVertexArray(window, vertex_array, NULL);
        vertex_array =
create_triangle(&points[i + 1][j + 1], &points[i][j + 1], &points[i + 1][j]);
        sfRenderWindow_drawVertexArray(window, vertex_array, NULL);
    }
}

int draw_triangle(sfRenderWindow *window, map_t *map)
{
    for (size_t i = 0; i < map->props.rows; i++) {
        for (size_t j = 0; j < map->props.columns; j++) {
            manage_triangles(window, map, i, j);
        }
    }
    return (0);
}
