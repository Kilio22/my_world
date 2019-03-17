/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** draw
*/

#include <math.h>
#include "world.h"

int find_texture(int a1, int a2, int a3, int a4)
{
    int biggest = a1 + a2 + a3 + a4;

    if (biggest >= -300 && biggest < -150)
        return (1);
    if (biggest < -300)
        return (5);
    if (biggest > 150 && biggest <= 400)
        return (2);
    if (biggest >= -150 && biggest < -50)
        return (3);
    if (biggest > 400)
        return (4);
    return (0);
}

void create_triangle(sfVector2f points[3], sfColor color, interface_t *face,
int i)
{
    sfVertexArray *v_array = sfVertexArray_create();
    sfVector2f p0 = {0, 0};
    sfVector2f p1 = {32, 0};
    sfVector2f p2 = {0, 32};
    sfVertex v1 = {.position = points[0], .texCoords = p0, .color = color};
    sfVertex v2 = {.position = points[1], .texCoords = p1, .color = color};
    sfVertex v3 = {.position = points[2], .texCoords = p2, .color = color};

    sfVertexArray_append(v_array, v1);
    sfVertexArray_append(v_array, v2);
    sfVertexArray_append(v_array, v3);
    sfVertexArray_setPrimitiveType(v_array, sfTrianglesStrip);
    sfRenderWindow_drawVertexArray(face->window, v_array, face->states[i]);
    sfVertexArray_destroy(v_array);
}

void draw_square(interface_t *face, grid_point_t **point, int j, sfColor clr)
{
    sfVector2f points[3];
    int i = find_texture(((*point)[j]).altitude, ((*point)[j + 1]).altitude,
((*(point + 1))[j]).altitude, ((*(point + 1))[j + 1]).altitude);

    points[0] = ((*point)[j]).point;
    points[1] = ((*point)[j + 1]).point;
    points[2] = ((*(point + 1))[j]).point;
    create_triangle(points, clr, face, i);
    points[0] = ((*(point + 1))[j + 1]).point;
    create_triangle(points, clr, face, i);
}
