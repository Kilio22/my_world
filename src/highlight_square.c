/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** Functions used to highlight the square the cursor is on
*/

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

static void draw_highlighted_square(interface_t *face, grid_point_t **point,
                                    int j, sfColor clr)
{
    sfVector2f points[3];
    sfVertexArray *v_array;

    points[0] = ((*point)[j]).point;
    points[1] = ((*point)[j + 1]).point;
    points[2] = ((*(point + 1))[j]).point;
    v_array = create_triangle(points, clr);
    sfRenderWindow_drawVertexArray(face->window, v_array, NULL);
    points[0] = ((*(point + 1))[j + 1]).point;
    v_array = create_triangle(points, clr);
    sfRenderWindow_drawVertexArray(face->window, v_array, NULL);
}

static int highlight_on_cursor(interface_t *face, map_t *map, int i)
{
    sfVertexArray *v_array;
    sfVector2f pos[2];

    for (int j = map->columns - 2; j >= 0; j--) {
        if (is_on_tile(face, &map->grid[i], j) == 1) {
            draw_highlighted_square(face, &map->grid[i], j, trans_white);
            draw_lines(face, map, i, j);
            pos[0] = map->grid[i + 1][j].point;
            pos[1] = map->grid[i + 1][j + 1].point;
            v_array = create_line(pos, sfBlack);
            sfRenderWindow_drawVertexArray(face->window, v_array, NULL);
            pos[0] = map->grid[i][j + 1].point;
            v_array = create_line(pos, sfBlack);
            sfRenderWindow_drawVertexArray(face->window, v_array, NULL);
            return (1);
        }
    }
    return (0);
}

void highlight_square(interface_t *face, map_t *map)
{
    for (int i = map->rows - 2; i >= 0; i--) {
        if (highlight_on_cursor(face, map, i) == 1)
            return;
    }
}
