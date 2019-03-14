/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** update_map_size
*/

#include "world.h"

void delete_row(map_t *map)
{
    grid_point_t **point = malloc(sizeof(grid_point_t *) * (map->rows - 1));

    if (map->rows <= 1)
        return;
    for (int i = 0; i < map->rows - 1; i++)
        point[i] = map->grid[i];
    free(map->grid);
    map->grid = point;
    map->rows -= 1;
    update_points(map);
}

void add_row(map_t *map)
{
    grid_point_t **point = malloc(sizeof(grid_point_t *) * (map->rows + 1));

    for (int i = 0; i < map->rows; i++)
        point[i] = map->grid[i];
    point[map->rows] = malloc(sizeof(grid_point_t) * map->columns);
    for (int i = 0; i < map->columns; i++)
        point[map->rows][i].altitude = 0;
    free(map->grid);
    map->grid = point;
    map->rows += 1;
    update_points(map);
}

void delete_column(map_t *map)
{
    grid_point_t *point;

    if (map->columns <= 1)
        return;
    for (int i = 0; i < map->rows; i++) {
        point = malloc(sizeof(grid_point_t) * (map->columns - 1));
        for (int j = 0; j < (map->columns - 1); j++)
            point[j] = map->grid[i][j];
        free(map->grid[i]);
        map->grid[i] = point;
    }
    map->columns -= 1;
    update_points(map);
}

void add_column(map_t *map)
{
    grid_point_t *point;

    for (int i = 0; i < map->rows; i++) {
        point = malloc(sizeof(grid_point_t) * (map->columns + 1));
        for (int j = 0; j < map->columns; j++)
            point[j] = map->grid[i][j];
        point[map->columns].altitude = 0;
        free(map->grid[i]);
        map->grid[i] = point;
    }
    map->columns += 1;
    update_points(map);
}
