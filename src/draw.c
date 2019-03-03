/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** draw
*/

#include "world.h"

sfVertexArray *create_triangle_se(sfVector2f **points, int i,
int j, sfColor **colors)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex v1 =
{.position = points[i + 1][j + 1], .color = colors[i + 1][j + 1]};
    sfVertex v2 = {.position = points[i][j + 1], .color = colors[i][j + 1]};
    sfVertex v3 = {.position = points[i + 1][j], .color = colors[i + 1][j]};

    sfVertexArray_append(vertex_array, v1);
    sfVertexArray_append(vertex_array, v2);
    sfVertexArray_append(vertex_array, v3);
    sfVertexArray_setPrimitiveType(vertex_array, sfTrianglesStrip);
    return (vertex_array);
}

sfVertexArray *create_triangle_first(sfVector2f **points,
int i, int j, sfColor **colors)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex vertex1 = {.position = points[i][j], .color = colors[i][j]};
    sfVertex vertex2 = {.position =
points[i][j + 1], .color = colors[i][j + 1]};
    sfVertex vertex3 = {.position =
points[i + 1][j], .color = colors[i + 1][j]};

    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_append(vertex_array, vertex3);
    sfVertexArray_setPrimitiveType(vertex_array, sfTrianglesStrip);
    return (vertex_array);
}

void manage_triangles(sfRenderWindow *window, map_t *map, int i, int j)
{
    sfVertexArray *vertex_array;

    if (i + 1 < map->props.rows && j + 1 < map->props.columns) {
        vertex_array = create_triangle_first(map->points, i, j, map->colors);
        sfRenderWindow_drawVertexArray(window, vertex_array, NULL);
        vertex_array = create_triangle_se(map->points, i, j, map->colors);
        sfRenderWindow_drawVertexArray(window, vertex_array, NULL);
    }
}

int draw_triangle(sfRenderWindow *window, map_t *map)
{
    for (int i = 0; i < map->props.rows; i++) {
        for (int j = 0; j < map->props.columns; j++) {
            manage_triangles(window, map, i, j);
        }
    }
    return (0);
}
