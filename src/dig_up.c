/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** dig
*/

#include "world.h"

void dig_up_corner2(map_t *map, int i, int j)
{
    map->grid[i][j].altitude += 1;
    update_points(map);
}

void dig_up_corner(map_t *map, sfRenderWindow *win)
{
    int check = 0;

    for (int i = 0; i < map->rows; i++) {
        for (int j = 0; j < map->columns; j++) {
            check = find_corner_color(win, map, map->grid[i][j].point);
            check == 1 ? dig_up_corner2(map, i, j) : 0;
        }
    }
}

void dig_up_tiles2(map_t *map, int i, int j)
{
    map->grid[i][j].altitude += 1;
    map->grid[i][j + 1].altitude += 1;
    map->grid[i + 1][j + 1].altitude += 1;
    map->grid[i + 1][j].altitude += 1;
    update_points(map);
}

void dig_up_tiles(map_t *map, sfRenderWindow *win)
{
    int check = 0;

    for (int i = 0; i < map->rows - 1; i++) {
        for (int j = 0; j < map->columns - 1; j++) {
            check = is_on_tile(win, map, &map->grid[i], j);
            check == 1 ? dig_up_tiles2(map, i, j) : 0;
        }
    }
}

void manage_dig_up(map_t *map, sfRenderWindow *win)
{
    if (map->mode == tile)
        dig_up_tiles(map, win);
    if (map->mode == corner)
        dig_up_corner(map, win);
}