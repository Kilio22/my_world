/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** Digs up when called
*/

#include "world.h"

static int icr_corner_altitude(sfRenderWindow *win, map_t *map, int i, int j)
{
    if (!find_corner_color(win, map, map->grid[i][j].point))
        return (0);
    map->grid[i][j].altitude += 1;
    update_points(map);
    return (1);
}

void dig_up_corner(sfRenderWindow *win, map_t *map)
{
    int n_return = 0;

    for (int i = map->rows - 1; i >= 0; i--) {
        for (int j = map->columns - 1; j >= 0 && n_return == 0; j--)
            n_return = icr_corner_altitude(win, map, i, j);
        if (n_return == 1)
            break;
    }
}

static int icr_square_alitude(sfRenderWindow *win, map_t *map, int i, int j)
{
    if (!is_on_tile(win, map, &map->grid[i], j))
        return (0);
    map->grid[i][j].altitude += 1;
    map->grid[i][j + 1].altitude += 1;
    map->grid[i + 1][j + 1].altitude += 1;
    map->grid[i + 1][j].altitude += 1;
    update_points(map);
    return (1);
}

void dig_up_square(sfRenderWindow *win, map_t *map)
{
    int n_return = 0;

    for (int i = map->rows - 2; i >= 0; i--) {
        for (int j = map->columns - 2; j >= 0 && n_return == 0; j--)
            n_return = icr_square_alitude(win, map, i, j);
        if (n_return == 1)
            break;
    }
}
