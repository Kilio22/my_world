/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** draw
*/

#include <math.h>
#include "world.h"

static sfVertexArray *create_triangle(sfVector2f points[3], sfColor color)
{
    sfVertexArray *v_array = sfVertexArray_create();
    sfVertex v1 = {.position = points[0], .color = color};
    sfVertex v2 = {.position = points[1], .color = color};
    sfVertex v3 = {.position = points[2], .color = color};

    sfVertexArray_append(v_array, v1);
    sfVertexArray_append(v_array, v2);
    sfVertexArray_append(v_array, v3);
    sfVertexArray_setPrimitiveType(v_array, sfTrianglesStrip);
    return (v_array);
}

void draw_square(sfRenderWindow *win, grid_point_t **point, int j, sfColor clr)
{
    sfVector2f points[3];
    sfVertexArray *v_array;

    points[0] = ((*point)[j]).point;
    points[1] = ((*point)[j + 1]).point;
    points[2] = ((*(point + 1))[j]).point;
    v_array = create_triangle(points, clr);
    sfRenderWindow_drawVertexArray(win, v_array, NULL);
    points[0] = ((*(point + 1))[j + 1]).point;
    v_array = create_triangle(points, clr);
    sfRenderWindow_drawVertexArray(win, v_array, NULL);
}