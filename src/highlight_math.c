/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** mouse_interaction
*/

#include <stdbool.h>
#include <math.h>
#include "world.h"

static sfVector2f compare_points(sfVector2f p1, sfVector2f p2, sfVector2f old)
{
    if (distance_between_points(p1, p2) < distance_between_points(p1, old))
        return (p2);
    return (old);
}

int is_closest_corner(interface_t *face, map_t *map, sfVector2f point)
{
    sfVector2i m = sfMouse_getPositionRenderWindow(face->window);
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(face->window, m,
face->view);
    grid_point_t **grid = map->grid;
    sfVector2f a_point = {0, 0};

    for (int i = 0; i < map->rows; i++) {
        for (int j = 0; j < map->columns; j++) {
            a_point = compare_points(mouse, (grid[i][j]).point, a_point);
        }
    }
    if (a_point.x == point.x && a_point.y == point.y)
        return (1);
    return (0);
}

static bool verif_tile(sfVector2f p, sfVector2f p1,
                       sfVector2f p2, sfVector2f p3)
{
    float v1 = 0.0;
    float v2 = 0.0;
    float v3 = 0.0;
    bool is_neg;
    bool is_pos;

    v1 = calcul_points(p, p1, p2);
    v2 = calcul_points(p, p2, p3);
    v3 = calcul_points(p, p3, p1);

    is_neg = (v1 < 0) || (v2 < 0) || (v3 < 0);
    is_pos = (v1 > 0) || (v2 > 0) || (v3 > 0);
    return !(is_neg && is_pos);
}

int is_on_tile(interface_t *face, grid_point_t **point, int j)
{
    sfVector2f points[3];
    sfVector2i m = sfMouse_getPositionRenderWindow(face->window);
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(face->window, m,
face->view);

    points[0] = ((*point)[j]).point;
    points[1] = ((*point)[j + 1]).point;
    points[2] = ((*(point + 1))[j]).point;
    if (verif_tile(mouse, points[0], points[1], points[2]) == true)
        return (1);
    points[0] = ((*(point + 1))[j + 1]).point;
    points[1] = ((*point)[j + 1]).point;
    points[2] = ((*(point + 1))[j]).point;
    if (verif_tile(mouse, points[0], points[1], points[2]) == true)
        return (1);
    return (0);
}
