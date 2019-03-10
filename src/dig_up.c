/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** dig
*/

#include "world.h"

static void dig_up_corner2(map_t *map, int i, int j)
{
    map->grid[i][j].altitude += 1;
    update_points(map);
}

void dig_up_corner(sfRenderWindow *win, map_t *map)
{
    int check = 0;

    for (int i = 0; i < map->rows; i++) {
        for (int j = 0; j < map->columns; j++) {
            check = find_corner_color(win, map, map->grid[i][j].point);
            check == 1 ? dig_up_corner2(map, i, j) : 0;
        }
    }
}

static void dig_up_tiles2(map_t *map, int i, int j)
{
    map->grid[i][j].altitude += 1;
    map->grid[i][j + 1].altitude += 1;
    map->grid[i + 1][j + 1].altitude += 1;
    map->grid[i + 1][j].altitude += 1;
    update_points(map);
}

void dig_up_square(sfRenderWindow *win, map_t *map)
{
    int check = 0;

    for (int i = 0; i < map->rows - 1; i++) {
        for (int j = 0; j < map->columns - 1; j++) {
            check = is_on_tile(win, map, &map->grid[i], j);
            check == 1 ? dig_up_tiles2(map, i, j) : 0;
        }
    }
}
