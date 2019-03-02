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

int draw_2d_map(princi_t *princi, sfVector2f **points)
{
    sfVertexArray *vertex_array;

    for (int i = 0; i < MAP_Y; i++) {
        for (int j = 0; j < MAP_X; j++) {
            if (j + 1 < MAP_X)
                vertex_array = create_line(&points[i][j], &points[i][j + 1]);
            sfRenderWindow_drawVertexArray(princi->window, vertex_array, NULL);
            if (i + 1 < MAP_Y)
                vertex_array = create_line(&points[i][j], &points[i + 1][j]);
            sfRenderWindow_drawVertexArray(princi->window, vertex_array, NULL);
        }
    }
    return (0);
}

void manage_triangles(princi_t *princi, int i, int j, sfVector2f **points)
{
    sfVertexArray *vertex_array;

    if (i + 1 < MAP_Y && j + 1 < MAP_X) {
        vertex_array =
create_triangle(&points[i][j], &points[i][j + 1], &points[i + 1][j]);
        sfRenderWindow_drawVertexArray(princi->window, vertex_array, NULL);
        vertex_array =
create_triangle(&points[i + 1][j + 1], &points[i][j + 1], &points[i + 1][j]);
        sfRenderWindow_drawVertexArray(princi->window, vertex_array, NULL);
    }
}

int draw_triangle(princi_t *princi, sfVector2f **points)
{
    for (int i = 0; i < MAP_Y; i++) {
        for (int j = 0; j < MAP_X; j++) {
            manage_triangles(princi, i, j, points);
        }
    }
    return (0);
}
