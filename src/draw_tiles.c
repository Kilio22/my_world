/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** draw
*/

#include <math.h>
#include <stdbool.h>
#include "world.h"

sfVertexArray *create_triangle_vertex(sfVector2f points[3], sfColor color)
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

void draw_square(sfRenderWindow *window, grid_point_t **point,
                 int j, sfColor color)
{
    sfVector2f points[3];
    sfVertexArray *v_array;

    points[0] = ((*point)[j]).point;
    points[1] = ((*point)[j + 1]).point;
    points[2] = ((*(point + 1))[j]).point;
    v_array = create_triangle_vertex(points, color);
    sfRenderWindow_drawVertexArray(window, v_array, NULL);
    points[0] = ((*(point + 1))[j + 1]).point;
    points[1] = ((*point)[j + 1]).point;
    points[2] = ((*(point + 1))[j]).point;
    v_array = create_triangle_vertex(points, color);
    sfRenderWindow_drawVertexArray(window, v_array, NULL);
}

int draw_tiles(sfRenderWindow *window, map_t *map)
{
    sfColor color;
    int check_color = 0;

    for (int i = 0; i < map->rows - 1; i++) {
        for (int j = 0; j < map->columns - 1; j++) {
            check_color = is_on_tile(window, map, &map->grid[i], j);
            color = (check_color == 1 ? sfBlue : sfRed);
            color = (map->mode == tile ? color : sfRed);
            draw_square(window, &map->grid[i], j, color);
        }
    }
    return (0);
}
